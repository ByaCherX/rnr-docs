<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">Test Renderer</h1>
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">React - Test Renderer</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

**Importing**
```jsx
import TestRenderer from 'react-test-renderer'; // ES6
const TestRenderer = require('react-test-renderer'); // ES5 with npm
```

## Overview

This package provides a React renderer that can be used to render React components to pure JavaScript objects, without depending on the DOM or a native mobile environment.

Essentially, this package makes it easy to grab a snapshot of the platform view hierarchy (similar to a DOM tree) rendered by a React DOM or React Native component without using a browser or jsdom.

**Example**
```jsx
import TestRenderer from 'react-test-renderer';

function Link(props) {
  return <a href={props.page}>{props.children}</a>;
}

const testRenderer = TestRenderer.create(
  <Link page="https://www.facebook.com/">Facebook</Link>
);

console.log(testRenderer.toJSON());
// { type: 'a',
//   props: { href: 'https://www.facebook.com/' },
//   children: [ 'Facebook' ] }
```
You can use Jest’s snapshot testing feature to automatically save a copy of the JSON tree to a file and check in your tests that it hasn’t changed: Learn more about it.
```jsx
import TestRenderer from 'react-test-renderer';

function MyComponent() {
  return (
    <div>
      <SubComponent foo="bar" />
      <p className="my">Hello</p>
    </div>
  )
}

function SubComponent() {
  return (
    <p className="sub">Sub</p>
  );
}

const testRenderer = TestRenderer.create(<MyComponent />);
const testInstance = testRenderer.root;

expect(testInstance.findByType(SubComponent).props.foo).toBe('bar');
expect(testInstance.findByProps({className: "sub"}).children).toEqual(['Sub']);
```

### TestRenderer
* TestRenderer.create()
* TestRenderer.act()

### TestRenderer instance
* testRenderer.toJSON()
* testRenderer.toTree()
* testRenderer.update()
* testRenderer.unmount()
* testRenderer.getInstance()
* testRenderer.root

### TestInstance
* testInstance.find()
* testInstance.findByType()
* testInstance.findByProps()
* testInstance.findAll()
* testInstance.findAllByType()
* testInstance.findAllByProps()
* testInstance.instance
* testInstance.type
* testInstance.props
* testInstance.parent
* testInstance.children

## Reference

### TestRenderer.create()
```jsx
TestRenderer.create(element, options);
```
Create a `TestRenderer` instance with the passed React element. It doesn’t use the real DOM, but it still fully renders the component tree into memory so you can make assertions about it. Returns a TestRenderer instance.

### TestRenderer.act()
```jsx
TestRenderer.act(callback);
```
Similar to the act() helper from react-dom/test-utils, `TestRenderer.act` prepares a component for assertions. Use this version of `act()` to wrap calls to `TestRenderer.create` and `testRenderer.update`.

```jsx
import {create, act} from 'react-test-renderer';
import App from './app.js'; // The component being tested

// render the component
let root; 
act(() => {
  root = create(<App value={1}/>)
});

// make assertions on root 
expect(root.toJSON()).toMatchSnapshot();

// update with some different props
act(() => {
  root.update(<App value={2}/>);
})

// make assertions on root 
expect(root.toJSON()).toMatchSnapshot();
```

### testRenderer.toJSON()
```jsx
testRenderer.toJSON()
```
Return an object representing the rendered tree. This tree only contains the platform-specific nodes like `<div>` or `<View>` and their props, but doesn’t contain any user-written components. This is handy for [snapshot testing]().

### testRenderer.toTree()
```jsx
testRenderer.toTree()
```
Return an object representing the rendered tree. The representation is more detailed than the one provided by `toJSON()`, and includes the user-written components. You probably don’t need this method unless you’re writing your own assertion library on top of the test renderer.

### testRenderer.update()
```jsx
testRenderer.update(element)
```
Re-render the in-memory tree with a new root element. This simulates a React update at the root. If the new element has the same type and key as the previous element, the tree will be updated; otherwise, it will re-mount a new tree.

### testRenderer.unmount()
```jsx
testRenderer.unmount()
```
Unmount the in-memory tree, triggering the appropriate lifecycle events.

### testRenderer.getInstance()
```jsx
testRenderer.getInstance()
```
Return the instance corresponding to the root element, if available. This will not work if the root element is a function component because they don’t have instances.

### testRenderer.root
```jsx
testRenderer.root
```
Returns the root “test instance” object that is useful for making assertions about specific nodes in the tree. You can use it to find other “test instances” deeper below.

### testInstance.find()
```jsx
testInstance.find(test)
```
Find a single descendant test instance for which `test(testInstance)` returns true. If `test(testInstance)` does not return true for exactly one test instance, it will throw an error.

### testInstance.findByType()
```jsx
testInstance.findByType(type)
```
Find a single descendant test instance with the provided `type`. If there is not exactly one test instance with the provided `type`, it will throw an error.

### testInstance.findByProps()
```jsx
testInstance.findByProps(props)
```
Find a single descendant test instance with the provided `props`. If there is not exactly one test instance with the provided `props`, it will throw an error.

### testInstance.findAll()
```jsx
testInstance.findAll(test)
```
Find all descendant test instances for which `test(testInstance)` returns true.

### testInstance.findAllByType()
```jsx
testInstance.findAllByType(type)
```
Find all descendant test instances with the provided type.

### testInstance.findAllByProps()
```jsx
testInstance.findAllByProps(props)
```
Find all descendant test instances with the provided props.

### testInstance.instance
```jsx
testInstance.instance
```
The component instance corresponding to this test instance. It is only available for class components, as function components don’t have instances. It matches the this value inside the given component.

### testInstance.type
```jsx
testInstance.type
```
The component type corresponding to this test instance. For example, a `<Button />` component has a type of Button.

### testInstance.props
```jsx
testInstance.props
```
The props corresponding to this test instance. For example, a `<Button size="small" />` component has {size: 'small'} as props.

### testInstance.parent
```jsx
testInstance.parent
```
The parent test instance of this test instance.

### testInstance.children
```jsx
testInstance.children
```
The children test instances of this test instance.

## Ideas
You can pass `createNodeMock` function to `TestRenderer.create` as the option, which allows for custom mock refs. `createNodeMock` accepts the current element and should return a mock ref object. This is useful when you test a component that relies on refs.
```jsx
import TestRenderer from 'react-test-renderer';

class MyComponent extends React.Component {
  constructor(props) {
    super(props);
    this.input = null;
  }
  componentDidMount() {
    this.input.focus();
  }
  render() {
    return <input type="text" ref={el => this.input = el} />
  }
}

let focused = false;
TestRenderer.create(
  <MyComponent />,
  {
    createNodeMock: (element) => {
      if (element.type === 'input') {
        // mock a focus function
        return {
          focus: () => {
            focused = true;
          }
        };
      }
      return null;
    }
  }
);
expect(focused).toBe(true);
```

























