# More on functions

## Function type expressions
- Similar to arrow functions (syntactically)
```ts
function greeter(fn: (a: string) => void) {
  fn("Hello, World");
}
 
function printToConsole(s: string) {
  console.log(s);
}
 
greeter(printToConsole);
```

## Construct Signatures
- JS functions can also be invoked with the `new` operator. 
- They are called constructors, add it in front of a call signature to make it a construct signature 
```ts
type SomeConstructor = {
  new (s: string): SomeObject;
};
function fn(ctor: SomeConstructor) {
  return new ctor("hello");
}
```

## Generics 
- Used to describe correspondence between two or more values 
- Done by declaring a type parameter in the function signature 
- Ex : without type parameter 
```ts
function firstElement(arr: any[]) {
  return arr[0];
}
```
- With type parameter, this will return a specific type by creating a link between input and output 
```ts
function firstElement<Type>(arr: Type[]): Type | undefined {
  return arr[0];
}

// or 
function map<Input, Output>(arr: Input[], func: (arg: Input) => Output): Output[] {
  return arr.map(func);
}
 
// Parameter 'n' is of type 'string'
// 'parsed' is of type 'number[]'
const parsed = map(["1", "2", "3"], (n) => parseInt(n));
```
- Rule: If a type parameter only appears in one location, strongly reconsider if you actually need it

## Constraint
- Used to relate two values that have relativity, limit kinds of types that a type parameter can accept
```ts
function longest<Type extends { length: number }>(a: Type, b: Type) { // only accepts types with "length" property
  if (a.length >= b.length) {
    return a;
  } else {
    return b;
  }
}
```
- Rule: When possible, use the type parameter itself rather than constraining it
