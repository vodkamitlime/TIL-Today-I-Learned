# TS-for-JS

## Inferred types
- TS "infers" types of variables in many cases. 
- For a variable without a type declared, TS uses the value as its type.
- However, some types are complex so that it is difficult for the engine to infer the types automatically. This is when the developer has to define the types.

## Defining types 
- Interfaces are used to explicitly desribe some objects' shape 
```ts
interface User {
  name: string;
  id: number;
}

const user: User = {
  name: "Hayes",
  id: 0,
};
```
- Interfaces are also used to annotate parameters and return values 
```ts
function getAdminUser(): User {
  //...
}
 
function deleteUser(user: User) {
  // ...
}
```
- TS also provides OOP classes, so interface declaration can be used with classes
```ts
interface User {
  name: string;
  id: number;
}
 
class UserAccount {
  name: string; // To use class properties, declaration comes first 
  id: number;
 
  constructor(name: string, id: number) {
    this.name = name;
    this.id = id;
  }
}
 
const user: User = new UserAccount("Murphy", 1);
```
- Two syntaxes for building types: Interfaces vs Types
	- prefer interface, use type when specific features are needed 

## TS types
- All of JS primitive types can be used as interfaces: boolean, bigint, null, number, string, symbol, and undefined
- TS extensions: any, unknown, never, void (function that returns undefined or doesn't have return value)

## Composing types
- Create complex types by combining simple ones 
- Unions vs Generics
- Unions
	- Type can be declared as one of many options
	```ts
		type WindowStates = "open" | "closed" | "minimized";
		type LockStates = "locked" | "unlocked";
		type PositiveOddNumbersUnderTen = 1 | 3 | 5 | 7 | 9;
		function getLength(obj: string | string[]) {
		  return obj.length;
		}
	```
- Generics	
	- Provide variables to types (ex declare type of object inside array)
	```ts
		type StringArray = Array<string>;
		type NumberArray = Array<number>;
		type ObjectWithNameArray = Array<{ name: string }>;
	```

## Structural Typing
- type checking focuses on the shape that values have 
- If 2 objects have the same shape (or same subset), they are considered to be of the same type 
