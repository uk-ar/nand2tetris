

push constant 17
_________________
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 17
_________________
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
eq
___
@result
M=-1
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
@true0
D;JEQ
@result
M=0
(true0)
@result
D=M
@SP
A=M
A=A-1
M=D
push constant 17
_________________
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 16
_________________
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
eq
___
@result
M=-1
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
@true1
D;JEQ
@result
M=0
(true1)
@result
D=M
@SP
A=M
A=A-1
M=D
push constant 16
_________________
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 17
_________________
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
eq
___
@result
M=-1
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
@true2
D;JEQ
@result
M=0
(true2)
@result
D=M
@SP
A=M
A=A-1
M=D
push constant 892
__________________
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 891
__________________
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
lt
___
@result
M=-1
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
@true3
D;JLT
@result
M=0
(true3)
@result
D=M
@SP
A=M
A=A-1
M=D
push constant 891
__________________
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 892
__________________
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
lt
___
@result
M=-1
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
@true4
D;JLT
@result
M=0
(true4)
@result
D=M
@SP
A=M
A=A-1
M=D
push constant 891
__________________
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 891
__________________
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
lt
___
@result
M=-1
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
@true5
D;JLT
@result
M=0
(true5)
@result
D=M
@SP
A=M
A=A-1
M=D
push constant 32767
____________________
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 32766
____________________
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
gt
___
@result
M=-1
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
@true6
D;JGT
@result
M=0
(true6)
@result
D=M
@SP
A=M
A=A-1
M=D
push constant 32766
____________________
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 32767
____________________
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
gt
___
@result
M=-1
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
@true7
D;JGT
@result
M=0
(true7)
@result
D=M
@SP
A=M
A=A-1
M=D
push constant 32766
____________________
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 32766
____________________
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
gt
___
@result
M=-1
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
@true8
D;JGT
@result
M=0
(true8)
@result
D=M
@SP
A=M
A=A-1
M=D
push constant 57
_________________
@57
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 31
_________________
@31
D=A
@SP
A=M
M=D
@SP
M=M+1
push constant 53
_________________
@53
D=A
@SP
A=M
M=D
@SP
M=M+1
add
____
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M+D
@SP
A=M-1
M=D
push constant 112
__________________
@112
D=A
@SP
A=M
M=D
@SP
M=M+1
sub
____
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=M-D
@SP
A=M-1
M=D
neg
____
@SP
A=M
A=A-1
M=-M
and
____
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=D&M
@SP
A=M-1
M=D
push constant 82
_________________
@82
D=A
@SP
A=M
M=D
@SP
M=M+1
or
___
@SP
M=M-1
@SP
A=M
D=M
@SP
A=M-1
D=D|M
@SP
A=M-1
M=D
not
____
@SP
A=M
A=A-1
M=!M
