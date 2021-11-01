# TS intro

## JS problems
- In a nutshell: JS doesn't throw errors in many situations where most languages will, mostly because of the unexpected behavior of JS (such as argument coercion, lenient property assertion, etc.). 
- Makes it difficult for developers to expect errors in their code before runtime, thus making debugging a time consuming task. Whereas many languages allow static checking (which means they detect errors in code without running it)
- "Static type checking" : Determining what's an error and what's not based on the kinds of values being operated on 

## TS solution
- TS solves JS' problems mentioned above by static type checking. 
- TS is a superset of JS, so all of JS syntax is still relevant in TS context. 

## How the compiler works
1. TS compiler checks code's types
2. Compiles code (transforms it to JS) and erases the types along
3. Runs JS code 
- TypeScript is JavaScript’s runtime with a compile-time type checker