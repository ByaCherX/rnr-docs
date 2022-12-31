<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">

# React.Component
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center;">React - Component</h1>

>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db
This page contains a detailed API reference for the React component class definition. It assumes you’re familiar with fundamental React concepts, such as Components and Props, as well as State and Lifecycle. If you’re not, read them first.

## Overview
React lets you define components as classes or functions. Components defined as classes currently provide more features which are described in detail on this page. To define a React component class, you need to extend `React.Component`:
```jsx
class Welcome extends React.Component {
  render() {
    return <h1>Hello, {this.props.name}</h1>;
  }
}
```
The only method you must define in a `React.Component` subclass is called `render()`. All the other methods described on this page are optional.

### The Component Lifecycle
Each component has several “lifecycle methods” that you can override to run code at particular times in the process. You can use this lifecycle diagram as a cheat sheet. In the list below, commonly used lifecycle methods are marked as bold. The rest of them exist for relatively rare use cases.

#### Mounting
These methods are called in the following order when an instance of a component is being created and inserted into the DOM:
* [constructor()]()
* [static getDerivedStateFromProps()]()
* [render()]()
* [componentDidMount()]()

#### Updating
An update can be caused by changes to props or state. These methods are called in the following order when a component is being re-rendered:
* [static getDerivedStateFromProps()]()
* [shouldComponentUpdate]()
* [render()]()
* [getSnapshotBeforeUpdate()]()
* [componentDidUpdate()]()

#### Unmounting
This method is called when a component is being removed from the DOM:
* [componentWillUnmount()]()

#### Error Handling
These methods are called when there is an error during rendering, in a lifecycle method, or in the constructor of any child component.
* [static getDerivedStateFromError()]()
* [componentDidCatch()]()

### Other APIs
Each component also provides some other APIs:
* [setState()]()
* [forceUpdate()]()

### Class Properties
* [defaultProps]()
* [displayName]()

### Instance Properties
* [props]()
* [state]()

# Reference

## Commonly Used Lifecycle Methods
The methods in this section cover the vast majority of use cases you’ll encounter creating React components. For a visual reference, check out this lifecycle diagram.

### render()
The `render()` method is the only required method in a class component.

When called, it should examine `this.props` and `this.state` and return one of the following types:

* **React elements.** Typically created via JSX. For example, ``<div />`` and ``<MyComponent />`` are React elements that instruct React to render a DOM node, or another user-defined component, respectively.
* **Arrays and fragment.** Let you return multiple elements from render. See the documentation on fragments for more details.
* **Portals.** Let you render children into a different DOM subtree. See the documentation on portals for more details.
* **String and numbers.** These are rendered as text nodes in the DOM.
* **Booleans or null.** Render nothing. (Mostly exists to support ``return test && <Child />`` pattern, where test is boolean.)

The `render()` function should be pure, meaning that it does not modify component state, it returns the same result each time it’s invoked, and it does not directly interact with the browser.

If you need to interact with the browser, perform your work in `componentDidMount()` or the other lifecycle methods instead. Keeping `render()` pure makes components easier to think about.

### constructor()
```jsx
constructor(props)
```
The constructor for a React component is called before it is mounted. When implementing the constructor for a `React.Component` subclass, you should call `super(props)` before any other statement. Otherwise, `this.props` will be undefined in the constructor, which can lead to bugs.

Typically, in React constructors are only used for two purposes:
* Initializing local state by assigning an object to `this.state`.
* Binding event handler methods to an instance.

You **should not call setState()** in the `constructor()`. Instead, if your component needs to use local state, **assign the initial state to `this.state`** directly in the constructor:
```jsx
constructor(props) {
  super(props);
  // Don't call this.setState() here!
  this.state = { counter: 0 };
  this.handleClick = this.handleClick.bind(this);
}
```
Constructor is the only place where you should assign `this.state` directly. In all other methods, you need to use `this.setState()` instead.


### componentDidMount()
`componentDidMount()` is invoked immediately after a component is mounted (inserted into the tree). Initialization that requires DOM nodes should go here. If you need to load data from a remote endpoint, this is a good place to instantiate the network request.

This method is a good place to set up any subscriptions. If you do that, don’t forget to unsubscribe in `componentWillUnmount()`.

You **may call setState() immediately** in `componentDidMount()`. It will trigger an extra rendering, but it will happen before the browser updates the screen. This guarantees that even though the `render()` will be called twice in this case, the user won’t see the intermediate state. Use this pattern with caution because it often causes performance issues. In most cases, you should be able to assign the initial state in the `constructor()` instead. It can, however, be necessary for cases like modals and tooltips when you need to measure a DOM node before rendering something that depends on its size or position.

### componentDidUpdate()
```jsx
componentDidUpdate(prevProps, prevState, snapshot)
```
`componentDidUpdate()` is invoked immediately after updating occurs. This method is not called for the initial render.

Use this as an opportunity to operate on the DOM when the component has been updated. This is also a good place to do network requests as long as you compare the current props to previous props (e.g. a network request may not be necessary if the props have not changed).

You **may call `setState()` immediately** in `componentDidUpdate()` but note that **it must be wrapped in a condition** like in the example above, or you’ll cause an infinite loop. It would also cause an extra re-rendering which, while not visible to the user, can affect the component performance. If you’re trying to “mirror” some state to a prop coming from above, consider using the prop directly instead. Read more about [why copying props into state causes bugs](https://en.reactjs.org/blog/2018/06/07/you-probably-dont-need-derived-state.html).

If your component implements the `getSnapshotBeforeUpdate()` lifecycle (which is rare), the value it returns will be passed as a third “snapshot” parameter to `componentDidUpdate()`. Otherwise this parameter will be undefined.

### componentWillUnmount()
`componentWillUnmount()` is invoked immediately before a component is unmounted and destroyed. Perform any necessary cleanup in this method, such as invalidating timers, canceling network requests, or cleaning up any subscriptions that were created in `componentDidMount()`.

You **should not call setState()** in `componentWillUnmount()` because the component will never be re-rendered. Once a component instance is unmounted, it will never be mounted again.

## Rarely Used Lifecycle Methods
The methods in this section correspond to uncommon use cases. They’re handy once in a while, but most of your components probably don’t need any of them. You can see most of the methods below on this lifecycle diagram if you click the “Show less common lifecycles” checkbox at the top of it.

### shouldComponentUpdate()
```jsx
shouldComponentUpdate(nextProps, nextState)
```
Use `shouldComponentUpdate()` to let React know if a component’s output is not affected by the current change in state or props. The default behavior is to re-render on every state change, and in the vast majority of cases you should rely on the default behavior.

`shouldComponentUpdate()` is invoked before rendering when new props or state are being received. Defaults to true. This method is not called for the initial render or when `forceUpdate()` is used.

This method only exists as a [**performance optimization**](..). Do not rely on it to “prevent” a rendering, as this can lead to bugs. **Consider using the built-in PureComponent** instead of writing `shouldComponentUpdate()` by hand. `PureComponent` performs a shallow comparison of props and state, and reduces the chance that you’ll skip a necessary update.

If you are confident you want to write it by hand, you may compare `this.props` with `nextProps` and `this.state` with `nextState` and return false to tell React the update can be skipped. Note that returning false does not prevent child components from re-rendering when their state changes.

We do not recommend doing deep equality checks or using `JSON.stringify()` in `shouldComponentUpdate()`. It is very inefficient and will harm performance.

Currently, if `shouldComponentUpdate()` returns false, then UNSAFE_componentWillUpdate(), render(), and componentDidUpdate() will not be invoked. In the future React may treat `shouldComponentUpdate()` as a hint rather than a strict directive, and returning false may still result in a re-rendering of the component.

### getSnapshotBeforeUpdate()
```jsx
getSnapshotBeforeUpdate(prevProps, prevState)
```
`getSnapshotBeforeUpdate()` is invoked right before the most recently rendered output is committed to e.g. the DOM. It enables your component to capture some information from the DOM (e.g. scroll position) before it is potentially changed. Any value returned by this lifecycle method will be passed as a parameter to `componentDidUpdate()`.

This use case is not common, but it may occur in UIs like a chat thread that need to handle scroll position in a special way.

## Other APIs
Unlike the lifecycle methods above (which React calls for you), the methods below are the methods you can call from your components.

There are just two of them: `setState()` and `forceUpdate()`.

### setState()
```jsx
setState(updater, [callback])
```
`setState()` enqueues changes to the component state and tells React that this component and its children need to be re-rendered with the updated state. This is the primary method you use to update the user interface in response to event handlers and server responses.

Think of `setState()` as a request rather than an immediate command to update the component. For better perceived performance, React may delay it, and then update several components in a single pass. React does not guarantee that the state changes are applied immediately.

**!!!! This Content is writing later !!!!**

### forceUpdate()
```jsx
component.forceUpdate(callback)
```
By default, when your component’s state or props change, your component will re-render. If your `render()` method depends on some other data, you can tell React that the component needs re-rendering by calling `forceUpdate()`.

Calling `forceUpdate()` will cause `render()` to be called on the component, skipping `shouldComponentUpdate()`. This will trigger the normal lifecycle methods for child components, including the `shouldComponentUpdate()` method of each child. React will still only update the DOM if the markup changes.

Normally you should try to avoid all uses of `forceUpdate()` and only read from `this.props` and `this.state` in `render()`.

## Class Properties

### defaultProps
`defaultProps` can be defined as a property on the component class itself, to set the default props for the class. This is used for `undefined` props, but not for `null` props. For example:
```jsx
class CustomButton extends React.Component {
  // ...
}

CustomButton.defaultProps = {
  color: 'blue'
};
```
If `props.color` is not provided, it will be set by default to `'blue'`:
```jsx
render() {
  return <CustomButton /> ; // props.color will be set to blue
}
```
If `props.color` is set to `null`, it will remain `null`:
```jsx
render() {
  return <CustomButton color={null} /> ; // props.color will remain null
}
```

### displayName
The `displayName` string is used in debugging messages. Usually, you don’t need to set it explicitly because it’s inferred from the name of the function or class that defines the component. You might want to set it explicitly if you want to display a different name for debugging purposes or when you create a higher-order component, see Wrap the Display Name for Easy Debugging for details.

## Instance Properties

### props
`this.props` contains the props that were defined by the caller of this component. See Components and Props for an introduction to props.

In particular, `this.props.children` is a special prop, typically defined by the child tags in the JSX expression rather than in the tag itself.

### state
The state contains data specific to this component that may change over time. The state is user-defined, and it should be a plain JavaScript object.

If some value isn’t used for rendering or data flow (for example, a timer ID), you don’t have to put it in the state. Such values can be defined as fields on the component instance.

See State and Lifecycle for more information about the state.

Never mutate this.state directly, as calling setState() afterwards may replace the mutation you made. Treat this.state as if it were immutable.





