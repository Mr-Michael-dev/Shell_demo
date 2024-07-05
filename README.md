# A demo on Simple Shell development

### Curriculum Notes

#### 1. Introduction to TypeScript
- **Objective:** Understand what TypeScript is, its benefits, and how it differs from JavaScript.
  - **Overview of TypeScript:** TypeScript is a superset of JavaScript that adds static typing and other features to enhance code quality and development speed.
  - **TypeScript vs. JavaScript:** TypeScript offers type safety, early bug detection, and enhanced IDE support.
  - **Benefits of using TypeScript:** Helps catch errors at compile time, improves code readability, and makes refactoring easier.

  *Example:*
  ```javascript
  // JavaScript
  let message = "Hello, world!";
  message = 123; // No error in JavaScript

  // TypeScript
  let message: string = "Hello, world!";
  message = 123; // Error: Type 'number' is not assignable to type 'string'.
  ```

#### 2. Setting Up the TypeScript Environment
- **Objective:** Set up a development environment for TypeScript.
  - **Installing Node.js and npm:** Necessary for managing packages and running TypeScript.
  - **Installing TypeScript globally:** Use `npm install -g typescript` to install TypeScript.
  - **Setting up a TypeScript project:** Initialize with `tsc --init` to create a `tsconfig.json` file.
  - **Configuring `tsconfig.json`:** Customize the TypeScript compiler options.

  *Example:*
  ```sh
  npm install -g typescript
  tsc --init
  ```

#### 3. Basic Types and Type Annotations
- **Objective:** Learn and use basic types and annotations in TypeScript.
  - **Primitive types:** `number`, `string`, `boolean`
  - **Special types:** `any`, `unknown`, `void`, `never`
  - **Arrays and Tuples:** Define types for arrays and fixed-length tuples.
  - **Type annotations:** Explicitly declare variable types.

  *Example:*
  ```typescript
  let age: number = 30;
  let name: string = "John";
  let isStudent: boolean = true;

  let list: number[] = [1, 2, 3];
  let tuple: [string, number] = ["hello", 10];
  ```

#### 4. Interfaces and Type Aliases
- **Objective:** Define and use interfaces and type aliases to describe object shapes.
  - **Interfaces:** Define the structure of an object.
  - **Type aliases:** Create a new name for an existing type.
  - **Differences and use cases:** Interfaces are extendable, while type aliases are more flexible with complex types.

  *Example:*
  ```typescript
  interface Person {
    name: string;
    age: number;
  }

  function greet(person: Person) {
    console.log(`Hello, ${person.name}`);
  }

  type ID = number | string;
  ```

#### 5. Functions and Typing Functions
- **Objective:** Understand function types, optional parameters, and default parameters.
  - **Function types:** Specify the types for function parameters and return values.
  - **Optional and default parameters:** Define parameters that are optional or have default values.
  - **Arrow functions:** Use concise syntax for functions.

  *Example:*
  ```typescript
  function add(a: number, b: number): number {
    return a + b;
  }

  function log(message: string, userId?: number): void {
    console.log(message);
    if (userId !== undefined) {
      console.log(`User ID: ${userId}`);
    }
  }

  const greet = (name: string = "Guest"): void => {
    console.log(`Hello, ${name}`);
  };
  ```

#### 6. Classes and Object-Oriented Programming
- **Objective:** Utilize TypeScript’s class syntax to implement OOP principles.
  - **Class syntax and properties:** Define classes with properties and methods.
  - **Inheritance:** Extend classes to create a hierarchy.
  - **Access modifiers:** Control the visibility of class members using `public`, `private`, and `protected`.

  *Example:*
  ```typescript
  class Animal {
    public name: string;
    
    constructor(name: string) {
      this.name = name;
    }

    public move(distance: number): void {
      console.log(`${this.name} moved ${distance} meters.`);
    }
  }

  class Dog extends Animal {
    public bark(): void {
      console.log("Woof! Woof!");
    }
  }

  const dog = new Dog("Rex");
  dog.bark();
  dog.move(10);
  ```

#### 7. Generics
- **Objective:** Use generics to create reusable components.
  - **Generic functions:** Define functions that work with any type.
  - **Generic interfaces and classes:** Create reusable and flexible components.
  - **Constraints:** Restrict the types that can be used with generics.

  *Example:*
  ```typescript
  function identity<T>(arg: T): T {
    return arg;
  }

  let result = identity<number>(42);

  interface Container<T> {
    value: T;
  }

  class Box<T> {
    contents: T;
    constructor(value: T) {
      this.contents = value;
    }
  }
  ```

#### 8. Advanced Types
- **Objective:** Master advanced types for more complex type handling.
  - **Union and intersection types:** Combine multiple types.
  - **Type guards:** Narrow down types using conditional checks.
  - **Conditional types:** Create types based on conditions.
  - **Mapped types:** Transform types.

  *Example:*
  ```typescript
  function printId(id: number | string) {
    if (typeof id === "string") {
      console.log(`ID: ${id.toUpperCase()}`);
    } else {
      console.log(`ID: ${id}`);
    }
  }

  type ReadOnly<T> = {
    readonly [P in keyof T]: T[P];
  };

  type Person = { name: string; age: number };
  const readonlyPerson: ReadOnly<Person> = { name: "Alice", age: 30 };
  ```

#### 9. Modules and Namespaces
- **Objective:** Organize code using modules and namespaces.
  - **ES6 modules:** Use `import` and `export` to organize code.
  - **Namespaces:** Group related code under a single name.
  - **Module resolution:** Understand how TypeScript resolves module imports.

  *Example:*
  ```typescript
  // math.ts
  export function add(a: number, b: number): number {
    return a + b;
  }

  // main.ts
  import { add } from './math';
  console.log(add(2, 3));
  ```

#### 10. TypeScript with React
- **Objective:** Integrate TypeScript with React for building robust applications.
  - **Setting up a React project with TypeScript:** Use Create React App with TypeScript template.
  - **Typing React components:** Define types for props and state in components.
  - **Props and state types:** Ensure components receive the correct types for props and state.

  *Example:*
  ```typescript
  import React from 'react';

  interface GreetingProps {
    name: string;
  }

  const Greeting: React.FC<GreetingProps> = ({ name }) => {
    return <h1>Hello, {name}!</h1>;
  }

  export default Greeting;
  ```

#### 11. Tooling and Best Practices
- **Objective:** Use tools and follow best practices for efficient TypeScript development.
  - **Linters and formatters:** Use ESLint and Prettier to enforce coding standards.
  - **Type checking and debugging:** Utilize tools and techniques for debugging TypeScript code.
  - **Best practices for TypeScript code:** Follow guidelines to write clean and maintainable code.

  *Example:* Configure ESLint for a TypeScript project:
  ```sh
  npm install eslint @typescript-eslint/parser @typescript-eslint/eslint-plugin --save-dev
  ```

#### 12. Project: Building a Simple Application (Continued)
- **Objective:** Apply learned concepts in a real-world project.
  - **Planning the project:** Outline the application’s features and structure.
    - Create a feature list (e.g., adding tasks, marking tasks as complete, deleting tasks).
    - Design the UI components and interactions.
  - **Setting up the project structure:** Organize the project files and directories.
    - Create directories for components, services, and models.
  - **Implementing features using TypeScript:** Develop the application using TypeScript to handle different aspects like components, services, and state management.
    - Implement components using TypeScript and React.
    - Use TypeScript interfaces to define the shape of data.
    - Manage state using a state management library like Redux or React's built-in hooks.

  *Example:* Extend the to-do list application with more functionality:

  ```typescript
  interface Todo {
    id: number;
    task: string;
    completed: boolean;
  }

  class TodoApp {
    private todos: Todo[] = [];

    addTask(task: string) {
      const newTodo: Todo = { id: Date.now(), task, completed: false };
      this.todos.push(newTodo);
    }

    completeTask(id: number) {
      const todo = this.todos.find(todo => todo.id === id);
      if (todo) {
        todo.completed = true;
      }
    }

    deleteTask(id: number) {
      this.todos = this.todos.filter(todo => todo.id !== id);
    }

    getTasks(): Todo[] {
      return this.todos;
    }
  }

  // Using the class in a React component
  import React, { useState } from 'react';

  const TodoAppComponent: React.FC = () => {
    const [task, setTask] = useState("");
    const [app] = useState(new TodoApp());

    const handleAddTask = () => {
      app.addTask(task);
      setTask("");
    };

    return (
      <div>
        <input
          type="text"
          value={task}
          onChange={(e) => setTask(e.target.value)}
        />
        <button onClick={handleAddTask}>Add Task</button>
        <ul>
          {app.getTasks().map(todo => (
            <li key={todo.id}>
              <span style={{ textDecoration: todo.completed ? 'line-through' : 'none' }}>
                {todo.task}
              </span>
              <button onClick={() => app.completeTask(todo.id)}>Complete</button>
              <button onClick={() => app.deleteTask(todo.id)}>Delete</button>
            </li>
          ))}
        </ul>
      </div>
    );
  };

  export default TodoAppComponent;
  ```

- **Objective:** Solidify understanding through practical application.
  - **Iterate on feedback:** Continuously improve the project based on feedback.
  - **Implement additional features:** Add new features like task filtering, sorting, and persistent storage (e.g., using localStorage or a backend API).
  - **Refactor and optimize:** Refactor the code for better readability and performance.

*Example:*
```typescript
// Adding local storage for persistence
class TodoApp {
  private todos: Todo[] = JSON.parse(localStorage.getItem('todos') || '[]');

  private saveToLocalStorage() {
    localStorage.setItem('todos', JSON.stringify(this.todos));
  }

  addTask(task: string) {
    const newTodo: Todo = { id: Date.now(), task, completed: false };
    this.todos.push(newTodo);
    this.saveToLocalStorage();
  }

  completeTask(id: number) {
    const todo = this.todos.find(todo => todo.id === id);
    if (todo) {
      todo.completed = true;
      this.saveToLocalStorage();
    }
  }

  deleteTask(id: number) {
    this.todos = this.todos.filter(todo => todo.id !== id);
    this.saveToLocalStorage();
  }

  getTasks(): Todo[] {
    return this.todos;
  }
}
```
