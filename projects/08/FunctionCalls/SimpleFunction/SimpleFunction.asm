// 
// function SimpleFunction.test 2
(SimpleFunction.test) //0
@0 //1
D=A //2
@SP //3
A=M //4
M=D //5
@SP //6
M=M+1 //7
@SP //8
M=M-1 //9
A=M //10
D=M //11
@data //12
M=D //13
@LCL //14
D=M //15
@0 //16
D=D+A //17
@address //18
M=D //19
@data //20
D=M //21
@address //22
A=M //23
M=D //24
@0 //25
D=A //26
@SP //27
A=M //28
M=D //29
@SP //30
M=M+1 //31
@SP //32
M=M-1 //33
A=M //34
D=M //35
@data //36
M=D //37
@LCL //38
D=M //39
@1 //40
D=D+A //41
@address //42
M=D //43
@data //44
D=M //45
@address //46
A=M //47
M=D //48
// push local 0
@LCL //49
D=M //50
@0 //51
A=D+A //52
D=M //53
@SP //54
A=M //55
M=D //56
@SP //57
M=M+1 //58
// push local 1
@LCL //59
D=M //60
@1 //61
A=D+A //62
D=M //63
@SP //64
A=M //65
M=D //66
@SP //67
M=M+1 //68
// add
@SP //69
M=M-1 //70
A=M //71
D=M //72
@SP //73
A=M-1 //74
D=M+D //75
@SP //76
A=M-1 //77
M=D //78
// not
@SP //79
A=M //80
A=A-1 //81
M=!M //82
// push argument 0
@ARG //83
D=M //84
@0 //85
A=D+A //86
D=M //87
@SP //88
A=M //89
M=D //90
@SP //91
M=M+1 //92
// add
@SP //93
M=M-1 //94
A=M //95
D=M //96
@SP //97
A=M-1 //98
D=M+D //99
@SP //100
A=M-1 //101
M=D //102
// push argument 1
@ARG //103
D=M //104
@1 //105
A=D+A //106
D=M //107
@SP //108
A=M //109
M=D //110
@SP //111
M=M+1 //112
// sub
@SP //113
M=M-1 //114
A=M //115
D=M //116
@SP //117
A=M-1 //118
D=M-D //119
@SP //120
A=M-1 //121
M=D //122
// return
@LCL //123
D=M //124
@FRAME //125
M=D //126
@5 //127
A=D-A //RET=*(FRAME-5) //128
D=M //129
@RET //return address 126?
M=D //130
@SP //131
M=M-1 //132
A=M //133
D=M //134
@ARG //135
A=M //136
M=D //137
@ARG //138
D=M+1 //139
@SP //140
M=D //141
@FRAME //142
D=M //143
@1 //144
A=D-A //145
D=M //146
@THAT //147
M=D //148
@FRAME //149
D=M //150
@2 //151
A=D-A //152
D=M //153
@THIS //154
M=D //155
@FRAME //156
D=M //157
@3 //158
A=D-A //159
D=M //160
@ARG //161
M=D //162
@FRAME //163
D=M //164
@4 //165
A=D-A //166
D=M //167
@LCL //168
M=D //169
@RET //170
A=M //171
0;JMP //172
