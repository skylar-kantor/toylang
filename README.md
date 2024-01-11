# toylang

This is an interpreter for the toy language (that I suppose is similar-ish to an assembly language) defined in [this Stack Overflow answer](https://stackoverflow.com/a/6888074). I'll continue to add functionality to it as time goes on, with the goal of getting to something like [FORTH](https://en.wikipedia.org/wiki/Forth_(programming_language))

# The Language As of Now
Currently, I've defined everything exactly as the SO answer specifies (I think, tests to come!)

## Words/Commands 
- push: Pushes the argument given to the stack
- pop: Pops the top value off the stack
- add: Adds the top two values of the stack
- ifeq: Jumps to the specified line if the top of the stack is 0, otherwise does nothing
- jump: Jumps to the specified line in the input file
- print: Prints the top of the stack to STDOUT, without removing it
- and: Bitwise AND the top 2 values of the stack
- nand: Bitwise NAND the top 2 values of the stack
- or: Bitwise OR the top 2 values of the stack
- nor: Bitwise NOR the top 2 values of the stack
- xor: Bitwise XOR the top 2 values of the stack
- ls: Top of the stack shifted left by the second number in the stack
- rs: Top of the stack shifted right by the second number in the stack
## Behavior
Each command is specified in two parts, separated by a space. The command, and its argument, with the exception of pop and print.
Each command/argument pair is separated by a newline.

## To Do
- ~~Jump and ifeq should probably be able to go backwards~~ (Done 1/10/2024)
- add an "if" word that pushes 1 to the stack if top == arg and 0 otherwise