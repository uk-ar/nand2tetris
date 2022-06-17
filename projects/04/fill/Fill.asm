// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed.
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

(WHITE)
@0//color
M=0
@FILL_INIT
0;JMP

(BLACK)
@0//color
M=-1
@FILL_INIT
0;JMP

(FILL_INIT)
@SCREEN
D=A
//@KBD
//D=A-1
//D=D-1
@1//pos
M=D

(FILL)
@0
D=M
@1
A=M
M=D

@1
M=M+1

@1
D=M
@KBD
D=A-D//until pos==KBD
@FILL
D;JGT

(KBDCKECK)
@KBD
D=M
@BLACK
D;JGT
@WHITE
D;JEQ
@KBDCHECK
0;JMP
