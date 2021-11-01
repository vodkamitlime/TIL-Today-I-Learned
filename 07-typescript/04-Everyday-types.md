# Everyday types

## Primitives
- String
- Number
- Boolean

## Arrays 
- [1,2,3] === number[] or Array<number>

## Any
- Used to avoid typechecking errors 
- When type not specified and TS can't infer it from context, compiler will default to `any`

## Annotations on variables
- optionally added to specify type of variable
- otherwise initalizer becomes the type of variable (inferred)

## Functions & parameter annotations
- typing after parameter name
- can also add return type annotations 
- anonymous functions: contextual typing also applies 

## Objects 
- properties are separated by `,` or `;`
- if property type not specified type assumed to any 
- optional properties have `?` added at the end of variable name 
```ts
function printName(obj: { first: string; last?: string }) {
  // ...
}
// Both OK
printName({ first: "Bob" });
printName({ first: "Alice", last: "Alisson" });
```

## union types
- combination of more than one types 
```ts
function printId(id: number | string) {
  console.log("Your ID is: " + id);
}
```
- but methods or properties have to be valid for every member fo the union
```ts
function printId(id: number | string) {
  console.log(id.toUpperCase());
// Property 'toUpperCase' does not exist on type 'string | number'.
//   Property 'toUpperCase' does not exist on type 'number'.
}
```
- solution: narrowing
```ts
function printId(id: number | string) {
  if (typeof id === "string") {
    // In this branch, id is of type 'string'
    console.log(id.toUpperCase());
  } else {
    // Here, id is of type 'number'
    console.log(id);
  }
}
```

## Type aliases 
- a name for a specific type 
```ts
type Point = {
  x: number;
  y: number;

type ID = number | string;
};
```

## Interfaces
- Another way to name an object te - only concerned with the structure of the value of properties 
```ts
interface Point {
  x: number;
  y: number;
}
```
- can be extended by `extends` keyword or simply restating class, but type cannot be changed after created 

## Literal types 
- when specific lieterals are assigned to variable as a type
```ts
let x : hello = "hello";
x = "howdy" // error
```
- used mostly for unions 

## Null and undefined 
- When `strictNullchecks` off: null/undefined accessed normally, can be assigned to a property of any type 
- When `strictNullchecks` on: have to test for null/undefined values before using methods/properties on them -> narrowing 
```ts
function doSomething(x: string | null) {
  if (x === null) {
    // do nothing
  } else {
    console.log("Hello, " + x.toUpperCase());
  }
}
```
