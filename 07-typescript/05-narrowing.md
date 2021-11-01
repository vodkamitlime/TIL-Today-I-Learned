# Narrowing

## Type guard 
```ts
function doSomething(x: string | null) {
  if (x === null) {
    // do nothing
  } else {
    console.log("Hello, " + x.toUpperCase());
  }
}
```
- When TS seeds `typeof`, it understands it as a form of code called type guard.  (value returned by typeof is a type guard)
- ex) "string", "number", etc...

## Control flow analysis
- analysis of code based on reachability (determines & eliminates type based on if & else statements)
- the variable can have a different type at each moment of analysis

## Type predicates
- define a user-defined type guard : define a function whose return type is a type predicate
- takes the form of `parameterName is Type` --> parameterName is the name of parameter from current functino signature 
```ts
function isFish(pet: Fish | Bird): pet is Fish {
  return (pet as Fish).swim !== undefined;
}
```
- type predicate: pet is Fish 

## Non-null assertions
- `!` symbol used to assert that some value is definitely present in some circumstance 
```ts
function getArea(shape: Shape) {
  if (shape.kind === "circle") {
    return Math.PI * shape.radius! ** 2;
  }
}
```

### Never 
- assignable to every type, however no type is assignable to never 
- used as a return type for function, and when it is used, it always returns an error or nothing