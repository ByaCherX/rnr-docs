<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">React - Hooks API Reference</h1>

This page describes the APIs for the built-in Hooks in React.

If you’re new to Hooks, you might want to check out [the overview]() first.

---
* Basic Hooks
  - useState
  - useEffect
  - useContext
* Additional Hooks
  - useReducer
  - useCallback
  - useMemo
  - useRef
  - useImperativeHandle
  - useLayoutEffect
  - useDebugValue

## Basic Hooks

### useState
```jsx
const [state, setState] = useState(initialState);
```
Returns a stateful value, and a function to update it.

During the initial render, the returned state (`state`) is the same as the value passed as the first argument (`initialState`).

The `setState` function is used to update the state. It accepts a new state value and enqueues a re-render of the component.
```jsx
setState(newState);
```
During subsequent re-renders, the first value returned by useState will always be the most recent state after applying updates.

#### Functional updates
If the new state is computed using the previous state, you can pass a function to `setState`. The function will receive the previous value, and return an updated value. Here’s an example of a counter component that uses both forms of `setState`:
```jsx
function Counter({initialCount}) {
  const [count, setCount] = useState(initialCount);
  return (
    <>
      Count: {count}
      <button onClick={() => setCount(initialCount)}>Reset</button>
      <button onClick={() => setCount(prevCount => prevCount - 1)}>-</button>
      <button onClick={() => setCount(prevCount => prevCount + 1)}>+</button>
    </>
  );
}
```
The ”+” and ”-” buttons use the functional form, because the updated value is based on the previous value. But the “Reset” button uses the normal form, because it always sets the count back to the initial value.

If your update function returns the exact same value as the current state, the subsequent rerender will be skipped completely.

#### Lazy initial state
The `initialState` argument is the state used during the initial render. In subsequent renders, it is disregarded. If the initial state is the result of an expensive computation, you may provide a function instead, which will be executed only on the initial render:
```jsx
const [state, setState] = useState(() => {
  const initialState = someExpensiveComputation(props);
  return initialState;
});
```

### useEffect
```jsx
useEffect(didUpdate);
```
Mutations, subscriptions, timers, logging, and other side effects are not allowed inside the main body of a function component (referred to as React’s render phase). Doing so will lead to confusing bugs and inconsistencies in the UI.

Instead, use `useEffect`. The function passed to `useEffect` will run after the render is committed to the screen. Think of effects as an escape hatch from React’s purely functional world into the imperative world.

By default, effects run after every completed render, but you can choose to fire them only when certain values have changed.

#### Cleaning up an effect
Often, effects create resources that need to be cleaned up before the component leaves the screen, such as a subscription or timer ID. To do this, the function passed to `useEffect` may return a clean-up function. For example, to create a subscription:
```jsx
useEffect(() => {
  const subscription = props.source.subscribe();
  return () => {
    // Clean up the subscription
    subscription.unsubscribe();
  };
});
```
The clean-up function runs before the component is removed from the UI to prevent memory leaks. Additionally, if a component renders multiple times (as they typically do), the **previous effect is cleaned up before executing the next effect**. In our example, this means a new subscription is created on every update. To avoid firing an effect on every update, refer to the next section.

#### Timing of effects
Unlike `componentDidMount` and `componentDidUpdate`, the function passed to `useEffect` fires after layout and paint, during a deferred event. This makes it suitable for the many common side effects, like setting up subscriptions and event handlers, because most types of work shouldn’t block the browser from updating the screen.

However, not all effects can be deferred. For example, a DOM mutation that is visible to the user must fire synchronously before the next paint so that the user does not perceive a visual inconsistency. (The distinction is conceptually similar to passive versus active event listeners.) For these types of effects, React provides one additional Hook called useLayoutEffect. It has the same signature as `useEffect`, and only differs in when it is fired.

Although `useEffect` is deferred until after the browser has painted, it’s guaranteed to fire before any new renders. React will always flush a previous render’s effects before starting a new update.

#### Conditionally firing an effect
The default behavior for effects is to fire the effect after every completed render. That way an effect is always recreated if one of its dependencies changes.

However, this may be overkill in some cases, like the subscription example from the previous section. We don’t need to create a new subscription on every update, only if the `source` prop has changed.

To implement this, pass a second argument to `useEffect` that is the array of values that the effect depends on. Our updated example now looks like this:
```jsx
useEffect(
  () => {
    const subscription = props.source.subscribe();
    return () => {
      subscription.unsubscribe();
    };
  },
  [props.source],
);
```
The array of dependencies is not passed as arguments to the effect function. Conceptually, though, that’s what they represent: every value referenced inside the effect function should also appear in the dependencies array. In the future, a sufficiently advanced compiler could create this array automatically.

### useContext
```jsx
const value = useContext(MyContext);
```
Accepts a context object (the value returned from `React.createContext`) and returns the current context value for that context. The current context `value` is determined by the value prop of the nearest `<MyContext.Provider>` above the calling component in the tree.

When the nearest `<MyContext.Provider>` above the component updates, this Hook will trigger a rerender with the latest context value passed to that `MyContext` provider. Even if an ancestor uses React.memo or shouldComponentUpdate, a rerender will still happen starting at the component itself using `useContext`.

Don’t forget that the argument to useContext must be the context object itself:

* **Correct:** `useContext(MyContext)`
* **Incorrect:** `useContext(MyContext.Consumer)`
* **Incorrect:** `useContext(MyContext.Provider)`

A component calling `useContext` will always re-render when the context value changes. If re-rendering the component is expensive, you can optimize it by using memoization.

## Additional Hooks
The following Hooks are either variants of the basic ones from the previous section, or only needed for specific edge cases. Don’t stress about learning them up front.

### useReducer
```jsx
const [state, dispatch] = useReducer(reducer, initialArg, init);
```
An alternative to useState. Accepts a reducer of type `(state, action) => newState`, and returns the current state paired with a `dispatch` method. (If you’re familiar with Redux, you already know how this works.)

`useReducer` is usually preferable to `useState` when you have complex state logic that involves multiple sub-values or when the next state depends on the previous one. `useReducer` also lets you optimize performance for components that trigger deep updates because you can pass dispatch down instead of callbacks.

Here’s the counter example from the useState section, rewritten to use a reducer:
```jsx
const initialState = {count: 0};

function reducer(state, action) {
  switch (action.type) {
    case 'increment':
      return {count: state.count + 1};
    case 'decrement':
      return {count: state.count - 1};
    default:
      throw new Error();
  }
}

function Counter() {
  const [state, dispatch] = useReducer(reducer, initialState);
  return (
    <>
      Count: {state.count}
      <button onClick={() => dispatch({type: 'decrement'})}>-</button>
      <button onClick={() => dispatch({type: 'increment'})}>+</button>
    </>
  );
}
```

#### Specifying the initial state
There are two different ways to initialize `useReducer` state. You may choose either one depending on the use case. The simplest way is to pass the initial state as a second argument:
```jsx
const [state, dispatch] = useReducer(
  reducer,
  {count: initialCount}
);
```

### useCallback
```jsx
const memoizedCallback = useCallback(
  () => {
    doSomething(a, b);
  },
  [a, b],
);
```
Pass an inline callback and an array of dependencies. `useCallback` will return a memoized version of the callback that only changes if one of the dependencies has changed. This is useful when passing callbacks to optimized child components that rely on reference equality to prevent unnecessary renders (e.g. `shouldComponentUpdate`).

### useMemo
```jsx
const memoizedValue = useMemo(() => computeExpensiveValue(a, b), [a, b]);
```
Pass a “create” function and an array of dependencies. `useMemo` will only recompute the memoized value when one of the dependencies has changed. This optimization helps to avoid expensive calculations on every render.

Remember that the function passed to `useMemo` runs during rendering. Don’t do anything there that you wouldn’t normally do while rendering. For example, side effects belong in `useEffect`, not `useMemo`.

If no array is provided, a new value will be computed on every render.

**You may rely on useMemo as a performance optimization, not as a semantic guarantee**. In the future, React may choose to “forget” some previously memoized values and recalculate them on next render, e.g. to free memory for offscreen components. Write your code so that it still works without `useMemo` — and then add it to optimize performance.

### useRef
```jsx
const refContainer = useRef(initialValue);
```
`useRef` returns a mutable ref object whose `.current` property is initialized to the passed argument (`initialValue`). The returned object will persist for the full lifetime of the component.

A common use case is to access a child imperatively:
```jsx
function TextInputWithFocusButton() {
  const inputEl = useRef(null);
  const onButtonClick = () => {
    // `current` points to the mounted text input element
    inputEl.current.focus();
  };
  return (
    <>
      <input ref={inputEl} type="text" />
      <button onClick={onButtonClick}>Focus the input</button>
    </>
  );
}
```
Essentially, `useRef` is like a “box” that can hold a mutable value in its `.current` property.

You might be familiar with refs primarily as a way to [access the DOM](). If you pass a ref object to React with `<div ref={myRef} />`, React will set its .current property to the corresponding DOM node whenever that node changes.

However, `useRef()` is useful for more than the `ref` attribute. It’s handy for keeping any mutable value around similar to how you’d use instance fields in classes.

This works because `useRef()` creates a plain JavaScript object. The only difference between useRef() and creating a `{current: ...}` object yourself is that `useRef` will give you the same ref object on every render.

Keep in mind that `useRef` doesn’t notify you when its content changes. Mutating the `.current` property doesn’t cause a re-render. If you want to run some code when React attaches or detaches a ref to a DOM node, you may want to use a callback ref instead.

### useImperativeHandle
```jsx
useImperativeHandle(ref, createHandle, [deps])
```
`useImperativeHandle` customizes the instance value that is exposed to parent components when using `ref`. As always, imperative code using refs should be avoided in most cases. `useImperativeHandle` should be used with forwardRef:
```jsx
function FancyInput(props, ref) {
  const inputRef = useRef();
  useImperativeHandle(ref, () => ({
    focus: () => {
      inputRef.current.focus();
    }
  }));
  return <input ref={inputRef} ... />;
}
FancyInput = forwardRef(FancyInput);
```
In this example, a parent component that renders `<FancyInput ref={inputRef} />` would be able to call `inputRef.current.focus()`.

### useLayoutEffect
The signature is identical to `useEffect`, but it fires synchronously after all DOM mutations. Use this to read layout from the DOM and synchronously re-render. Updates scheduled inside `useLayoutEffect` will be flushed synchronously, before the browser has a chance to paint.

Prefer the standard `useEffect` when possible to avoid blocking visual updates.

### useDebugValue
```jsx
useDebugValue(value)
```
`useDebugValue` can be used to display a label for custom hooks in React DevTools.

For example, consider the `useFriendStatus` custom Hook described in “Building Your Own Hooks”:
```jsx
function useFriendStatus(friendID) {
  const [isOnline, setIsOnline] = useState(null);

  // ...

  // Show a label in DevTools next to this Hook
  // e.g. "FriendStatus: Online"
  useDebugValue(isOnline ? 'Online' : 'Offline');

  return isOnline;
}
```

> [!IMPORTANT]
> For more detailed information and questions about Hooks: https://en.reactjs.org/docs/hooks-faq.html







