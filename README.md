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
- and: Pops from the stack and then pushes top bitwise AND arg
- nand: Pops from the stack and then pushes top bitwise NAND arg
- or: Pops from the stack and then pushes top bitwise OR arg
- nor: Pops from the stack and then pushes top bitwise NOR arg
- xor: Pops from the stack and then pushes top bitwise XOR arg
- ls: Pops from the stack and then pushes top shifted left arg bits
- rs: Pops from the stack and then pushes top shifted right arg bits
## Behavior
Each command is specified in two parts, separated by a space. The command, and its argument, with the exception of pop and print.
Each command/argument pair is separated by a newline.
