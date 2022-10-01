# toylang

This is an interpreter for the toy language (that I suppose is similar-ish to an assembly language) defined in [this Stack Overflow answer](https://stackoverflow.com/a/6888074). I'll continue to add functionality to it as time goes on, with the goal of getting to something like [FORTH](https://en.wikipedia.org/wiki/Forth_(programming_language))

# The Language As of Now
Currently, I've defined everything exactly as the SO answer specifies (I think, tests to come!)

## Words/Commands 
- push: Pushes the argument given to the stack
- pop: pops... the top value off the stack
- add: adds the top two values of the stack
- ifeq: jumps to the specified line if the top of the stack is 0, otherwise does nothing
- jump: jumps to the specified line in the input file
- print: prints the top of the stack, without removing it
- and: bitwise AND the top 2 values of the stack
- nand: bitwise AND the top 2 values of the stack
- or: bitwise AND the top 2 values of the stack
- nor: bitwise AND the top 2 values of the stack
- xor: bitwise AND the top 2 values of the stack
- ls: top of the stack shifted left by the second number in the stack
- rs: Pops from the stack and then pushes top shifted right by the second number in the stack
## Behavior
Each command is specified in two parts, separated by a space. The command, and its argument, with the exception of pop and print.
Each command/argument pair is separated by a newline.

## To Do
- Jump and ifeq should probably be able to go backwards
- add an "if" word that pushes 1 to the stack if top == arg and 0 otherwise