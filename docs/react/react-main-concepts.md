<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<<<<<<< HEAD
<link rel="stylesheet" href="../../lib/doc_style.css">
=======
<link rel="stylesheet" href="../source.css">
>>>>>>> bd2eb553b592b1e2a0d0cfa22bee14b12f0806db

## Introducing JSX

It is called JSX, and it is a syntax extension to JavaScript. We recommend using it with React to describe what the UI should look like. JSX may remind you of a template language, but it comes with the full power of JavaScript.

### JSX Represents Objects
Babel compiles JSX down to `React.createElement()` calls.

These two examples are identical:
```jsx
// with JSX
const element = (
  <h1 className="greeting">
    Hello, world!
  </h1>
);

// React no JSX
const element = React.createElement(
  'h1',
  {className: 'greeting'},
  'Hello, world!'
);

// manual create
const element = {
  type: 'h1',
  props: {
    className: 'greeting',
    children: 'Hello, world!'
  }
};
```

## Rendering Elements
Unlike browser DOM elements, React elements are plain objects, and are cheap to create. React DOM takes care of updating the DOM to match the React elements.

Let’s say there is a ``<div>`` somewhere in your HTML file:</br>
We call this a “root” DOM node because everything inside it will be managed by React DOM.

To render a React element into a root DOM node, pass both to ReactDOM.render():
```jsx
const element = <h1>Hello, world</h1>
ReactDOM.render(element, document.getElementById('root'));
```

### Updating the Rendered Element
React elements are immutable. Once you create an element, you can’t change its children or attributes. An element is like a single frame in a movie: it represents the UI at a certain point in time.

With our knowledge so far, the only way to update the UI is to create a new element, and pass it to ``ReactDOM.render()``.
```jsx
function tick() {
  const element = (
    <div>
      <h1>Hello, world!</h1>
      <h2>It is {new Date().toLocaleTimeString()}.</h2>
    </div>
  );
  ReactDOM.render(element, document.getElementById('root'));
}

setInterval(tick, 1000);
```

### React Only Updates What’s Necessary
React DOM compares the element and its children to the previous one, and only applies the DOM updates necessary to bring the DOM to the desired state.

## Components and Props
Components let you split the UI into independent, reusable pieces, and think about each piece in isolation. This page provides an introduction to the idea of components. You can find a [detailed component API reference here](https://en.reactjs.org/docs/react-component.html).

### Function and Class Components
The simplest way to define a component is to write a JavaScript function:
```jsx
function Welcome(props) {
  return (
    <h1>Hello, {props.name}</h1>;
  );}
```

You can also use an [ES6 class](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes) to define a component:
```jsx
class Welcome extends React.Component {
  render() {
    return ( <h1>Hello, {this.props.name}</h1>; );
  }
}
```

### Rendering a Component
Previously, we only encountered React elements that represent DOM tags:
```jsx
const element = <div />;
```

However, elements can also represent user-defined components:
```jsx
const element = <Welcome name="Alex"/>;
```

## State and Lifecycle
This page introduces the concept of state and lifecycle in a React component. You can find a detailed component API reference here.

Consider the ticking clock example from one of the previous sections. In Rendering Elements, we have only learned one way to update the UI. We call `ReactDOM.render()` to change the rendered output.

In applications with many components, it’s very important to free up resources taken by the components when they are destroyed.

We want to set up a timer whenever the Clock is rendered to the DOM for the first time. This is called “mounting” in React.

We also want to clear that timer whenever the DOM produced by the Clock is removed. This is called “unmounting” in React.

We can declare special methods on the component class to run some code when a component mounts and unmounts:
```jsx
// Adding Lifecycle Methods to a Class
class Clock extends React.Component {
  constructor(props) {super(props); this.state = {date: new Date()};}

  componentDidMount() {
    this.timerID = setInterval( () => this.tick(), 1000 );
  }
  componentWillUnmount() {
    clearInterval(this.timerID);
  }

  tick() {
    this.setState( {date: new Date()} );
  }

  render() {
    return (
      <div>
        <h1>Hello, world!</h1>
        <h2>It is {this.state.date.toLocaleTimeString()}.</h2>
      </div> ); 
  }
}
ReactDOM.render( <Clock />, document.getElementById('root') );
```

The componentDidMount() method runs after the component output has been rendered to the DOM. This is a good place to set up a timer:
```jsx
 componentDidMount() {
    this.timerID = setInterval( () => this.tick(),1000 );
  }
```

## Handling Events
Handling events with React elements is very similar to handling events on DOM elements. There are some syntax differences:
* React events are named using camelCase, rather than lowercase.
* With JSX you pass a function as the event handler, rather than a string.

For example, the HTML:
```jsx
<button onclick="activateLasers()">
  Activate Lasers
</button>

// is slightly different in React
<button onClick={activateLasers}>
  Activate Lasers
</button>
```

## Conditional Rendering
In React, you can create distinct components that encapsulate behavior you need. Then, you can render only some of them, depending on the state of your application.

Conditional rendering in React works the same way conditions work in JavaScript. Use JavaScript operators like if or the conditional operator to create elements representing the current state, and let React update the UI to match them.

### Inline If-Else with Conditional Operator
Another method for conditionally rendering elements inline is to use the JavaScript conditional operator `condition ? true : false`.

```jsx
render() {
  const isLoggedIn = this.state.isLoggedIn;
  return (
    <div>
      The user is <b>{isLoggedIn ? 'currently' : 'not'}</b> logged in.
    </div> );}

// It can also be used for larger expressions
render() {
  const isLoggedIn = this.state.isLoggedIn;
  return (
    <div>
      {isLoggedIn
        ? <LogoutButton onClick={this.handleLogoutClick} />
        : <LoginButton onClick={this.handleLoginClick} />
      }
    </div>
  );
}
```

## List and Keys
Given the code below, we use the `map()` function to take an array of `numbers` and double their values. We assign the new array returned by `map()` to the variable `doubled` and log it:
```jsx
const numbers = [1, 2, 3, 4, 5];
const doubled = numbers.map((number) => number * 2);
console.log(doubled);
```
!!! Not Writed











