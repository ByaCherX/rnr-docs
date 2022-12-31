<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">

<h1 style="text-align:center">Test Utilities</h1>
=======
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">React - Test Utilities</h1>
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

**Importing**
```jsx
import ReactTestUtils from 'react-dom/test-utils'; // ES6
var ReactTestUtils = require('react-dom/test-utils'); // ES5 with npm
```

## Overview
`ReactTestUtils` makes it easy to test React components in the testing framework of your choice. At Facebook we use Jest for painless JavaScript testing. Learn how to get started with Jest through the Jest website’s React Tutorial.

* act()
* mockComponent()
* isElement()
* isElementOfType()
* isDOMComponent()
* isCompositeComponent()
* isCompositeComponentWithType()
* findAllInRenderedTree()
* scryRenderedDOMComponentsWithClass()
* findRenderedDOMComponentWithClass()
* scryRenderedDOMComponentsWithTag()
* findRenderedDOMComponentWithTag()
* scryRenderedComponentsWithType()
* findRenderedComponentWithType()
* renderIntoDocument()
* Simulate

## Reference

### act()
To prepare a component for assertions, wrap the code rendering it and performing updates inside an `act()` call. This makes your test run closer to how React works in the browser.

For example, let’s say we have this `Counter` component:
```jsx
class Counter extends React.Component {
  constructor(props) {
    super(props);
    this.state = {count: 0};
    this.handleClick = this.handleClick.bind(this);
  }
  componentDidMount() {
    document.title = `You clicked ${this.state.count} times`;
  }
  componentDidUpdate() {
    document.title = `You clicked ${this.state.count} times`;
  }
  handleClick() {
    this.setState(state => ({
      count: state.count + 1,
    }));
  }
  render() {
    return (
      <div>
        <p>You clicked {this.state.count} times</p>
        <button onClick={this.handleClick}>
          Click me
        </button>
      </div>
    );
  }
}
```
Here is how we can test it:
```jsx
import React from 'react';
import ReactDOM from 'react-dom';
import { act } from 'react-dom/test-utils';
import Counter from './Counter';

let container;

beforeEach(() => {
  container = document.createElement('div');
  document.body.appendChild(container);
});

afterEach(() => {
  document.body.removeChild(container);
  container = null;
});

it('can render and update a counter', () => {
  // Test first render and componentDidMount
  act(() => {
    ReactDOM.render(<Counter />, container);
  });
  const button = container.querySelector('button');
  const label = container.querySelector('p');
  expect(label.textContent).toBe('You clicked 0 times');
  expect(document.title).toBe('You clicked 0 times');

  // Test second render and componentDidUpdate
  act(() => {
    button.dispatchEvent(new MouseEvent('click', {bubbles: true}));
  });
  expect(label.textContent).toBe('You clicked 1 times');
  expect(document.title).toBe('You clicked 1 times');
});
```
* Don’t forget that dispatching DOM events only works when the DOM container is added to the `document`. You can use a library like [React Testing Library](https://testing-library.com/docs/react-testing-library/intro/) to reduce the boilerplate code.
* The recipes document contains more details on how `act()` behaves, with examples and usage.

### mockComponent()
```jsx
mockComponent(
  componentClass,
  [mockTagName]
)
```
Pass a mocked component module to this method to augment it with useful methods that allow it to be used as a dummy React component. Instead of rendering as usual, the component will become a simple `<div>` (or other tag if `mockTagName` is provided) containing any provided children.

### isElement()
```jsx
isElement(element)
```
Returns true if element is any React element.

### isElementOfType()
```jsx
isElementOfType(
  element,
  componentClass
)
```
Returns true if element is a React element whose type is of a React componentClass.

### isDOMComponent()
```jsx
isDOMComponent(instance)
```
Returns true if instance is a DOM component (such as a `<div>` or `<span>`).

### isCompositeComponent()
```jsx
isCompositeComponent(instance)
```
Returns true if instance is a user-defined component, such as a class or a function.

### isCompositeComponentWithType()
```jsx
isCompositeComponentWithType(
  instance,
  componentClass
)
```
Returns true if instance is a component whose type is of a React componentClass.

### findAllInRenderedTree()
```jsx
findAllInRenderedTree(
  tree,
  test
)
```
Traverse all components in tree and accumulate all components where test(component) is true. This is not that useful on its own, but it’s used as a primitive for other test utils.

### scryRenderedDOMComponentsWithClass()
```jsx
scryRenderedDOMComponentsWithClass(
  tree,
  className
)
```
Finds all DOM elements of components in the rendered tree that are DOM components with the class name matching className.

### findRenderedDOMComponentWithClass()
```jsx
findRenderedDOMComponentWithClass(
  tree,
  className
)
```
Like scryRenderedDOMComponentsWithClass() but expects there to be one result, and returns that one result, or throws exception if there is any other number of matches besides one.

### scryRenderedDOMComponentsWithTag()
```jsx
scryRenderedDOMComponentsWithTag(
  tree,
  tagName
)
```
Finds all DOM elements of components in the rendered tree that are DOM components with the tag name matching tagName.

### findRenderedDOMComponentWithTag()
```jsx
findRenderedDOMComponentWithTag(
  tree,
  tagName
)
```
Like scryRenderedDOMComponentsWithTag() but expects there to be one result, and returns that one result, or throws exception if there is any other number of matches besides one.

### scryRenderedComponentsWithType()
```jsx
scryRenderedComponentsWithType(
  tree,
  componentClass
)
```
Finds all instances of components with type equal to componentClass.

### findRenderedComponentWithType()
```jsx
findRenderedComponentWithType(
  tree,
  componentClass
)
```
Same as scryRenderedComponentsWithType() but expects there to be one result and returns that one result, or throws exception if there is any other number of matches besides one.

### renderIntoDocument()
```jsx
renderIntoDocument(element)
```
Render a React element into a detached DOM node in the document. This function requires a DOM. It is effectively equivalent to:

const domContainer = document.createElement('div');
ReactDOM.render(element, domContainer);

## Other Utilities

### Simulate
```jsx
Simulate.{eventName}(
  element,
  [eventData]
)
```
Simulate an event dispatch on a DOM node with optional `eventData` event data.

### Clicking an element
```jsx
// <button ref={(node) => this.button = node}>...</button>
const node = this.button;
ReactTestUtils.Simulate.click(node);
```

### Changing the value of an input field and then pressing ENTER.
```jsx
// <input ref={(node) => this.textInput = node} />
const node = this.textInput;
node.value = 'giraffe';
ReactTestUtils.Simulate.change(node);
ReactTestUtils.Simulate.keyDown(node, {key: "Enter", keyCode: 13, which: 13});
```































