@256 //0
D=A //1
@SP //2
M=D //3
@return-address0 //4
D=A //5
@SP //6
A=M //7
M=D //8
@SP //9
M=M+1 //10
@LCL //11
D=M //12
@SP //13
A=M //14
M=D //15
@SP //16
M=M+1 //17
@ARG //18
D=M //19
@SP //20
A=M //21
M=D //22
@SP //23
M=M+1 //24
@THIS //25
D=M //26
@SP //27
A=M //28
M=D //29
@SP //30
M=M+1 //31
@THAT //32
D=M //33
@SP //34
A=M //35
M=D //36
@SP //37
M=M+1 //38
@SP //39
D=M //40
@0 //41
D=D-A //42
@5 //43
D=D-A //ARG=SP-n-5 //44
@ARG //45
M=D //46
@SP //47
D=M //48
@LCL //49
M=D //50
@Sys.init //51
0;JMP //52
(return-address0)
// 
// function Main.fibonacci 0
(Main.fibonacci)
// push argument 0
@ARG //53
D=M //54
@0 //55
A=D+A //56
D=M //57
@SP //58
A=M //59
M=D //60
@SP //61
M=M+1 //62
// push constant 2
@2 //63
D=A //64
@SP //65
A=M //66
M=D //67
@SP //68
M=M+1 //69
// lt                     // checks if n<2
@result //70
M=-1 //71
@SP //72
M=M-1 //73
A=M //74
D=M //75
@SP //76
A=M-1 //77
D=M-D //78
@SP //79
A=M-1 //80
M=D //81
@true0 //82
D;JLT //83
@result //84
M=0 //85
(true0) //86
@result //87
D=M //88
@SP //89
A=M //90
A=A-1 //91
M=D //92
// if-goto IF_TRUE
@SP //93
M=M-1 //94
A=M //95
D=M //96
@IF_TRUE //97
D;JNE //98
// goto IF_FALSE
@IF_FALSE //99
0;JMP //100
// label IF_TRUE          // if n<2, return n
(IF_TRUE)
// push argument 0        
@ARG //101
D=M //102
@0 //103
A=D+A //104
D=M //105
@SP //106
A=M //107
M=D //108
@SP //109
M=M+1 //110
// return
@LCL //111
D=M //112
@FRAME //113
M=D //114
@5 //115
A=D-A //RET=*(FRAME-5) //116
D=M //117
@RET //return address  //118
M=D //119
@SP //120
M=M-1 //121
A=M //122
D=M //123
@ARG //124
A=M //125
M=D //126
@ARG //127
D=M+1 //128
@SP //129
M=D //130
@FRAME //131
D=M //132
@1 //133
A=D-A //134
D=M //135
@THAT //136
M=D //137
@FRAME //138
D=M //139
@2 //140
A=D-A //141
D=M //142
@THIS //143
M=D //144
@FRAME //145
D=M //146
@3 //147
A=D-A //148
D=M //149
@ARG //150
M=D //151
@FRAME //152
D=M //153
@4 //154
A=D-A //155
D=M //156
@LCL //157
M=D //158
@RET //159
A=M //160
0;JMP //161
// label IF_FALSE         // if n>=2, returns fib(n-2)+fib(n-1)
(IF_FALSE)
// push argument 0
@ARG //162
D=M //163
@0 //164
A=D+A //165
D=M //166
@SP //167
A=M //168
M=D //169
@SP //170
M=M+1 //171
// push constant 2
@2 //172
D=A //173
@SP //174
A=M //175
M=D //176
@SP //177
M=M+1 //178
// sub
@SP //179
M=M-1 //180
A=M //181
D=M //182
@SP //183
A=M-1 //184
D=M-D //185
@SP //186
A=M-1 //187
M=D //188
// call Main.fibonacci 1  // computes fib(n-2)
@return-address1 //189
D=A //190
@SP //191
A=M //192
M=D //193
@SP //194
M=M+1 //195
@LCL //196
D=M //197
@SP //198
A=M //199
M=D //200
@SP //201
M=M+1 //202
@ARG //203
D=M //204
@SP //205
A=M //206
M=D //207
@SP //208
M=M+1 //209
@THIS //210
D=M //211
@SP //212
A=M //213
M=D //214
@SP //215
M=M+1 //216
@THAT //217
D=M //218
@SP //219
A=M //220
M=D //221
@SP //222
M=M+1 //223
@SP //224
D=M //225
@1 //226
D=D-A //227
@5 //228
D=D-A //ARG=SP-n-5 //229
@ARG //230
M=D //231
@SP //232
D=M //233
@LCL //234
M=D //235
@Main.fibonacci //236
0;JMP //237
(return-address1)
// push argument 0
@ARG //238
D=M //239
@0 //240
A=D+A //241
D=M //242
@SP //243
A=M //244
M=D //245
@SP //246
M=M+1 //247
// push constant 1
@1 //248
D=A //249
@SP //250
A=M //251
M=D //252
@SP //253
M=M+1 //254
// sub
@SP //255
M=M-1 //256
A=M //257
D=M //258
@SP //259
A=M-1 //260
D=M-D //261
@SP //262
A=M-1 //263
M=D //264
// call Main.fibonacci 1  // computes fib(n-1)
@return-address2 //265
D=A //266
@SP //267
A=M //268
M=D //269
@SP //270
M=M+1 //271
@LCL //272
D=M //273
@SP //274
A=M //275
M=D //276
@SP //277
M=M+1 //278
@ARG //279
D=M //280
@SP //281
A=M //282
M=D //283
@SP //284
M=M+1 //285
@THIS //286
D=M //287
@SP //288
A=M //289
M=D //290
@SP //291
M=M+1 //292
@THAT //293
D=M //294
@SP //295
A=M //296
M=D //297
@SP //298
M=M+1 //299
@SP //300
D=M //301
@1 //302
D=D-A //303
@5 //304
D=D-A //ARG=SP-n-5 //305
@ARG //306
M=D //307
@SP //308
D=M //309
@LCL //310
M=D //311
@Main.fibonacci //312
0;JMP //313
(return-address2)
// add                    // returns fib(n-1) + fib(n-2)
@SP //314
M=M-1 //315
A=M //316
D=M //317
@SP //318
A=M-1 //319
D=M+D //320
@SP //321
A=M-1 //322
M=D //323
// return
@LCL //324
D=M //325
@FRAME //326
M=D //327
@5 //328
A=D-A //RET=*(FRAME-5) //329
D=M //330
@RET //return address  //331
M=D //332
@SP //333
M=M-1 //334
A=M //335
D=M //336
@ARG //337
A=M //338
M=D //339
@ARG //340
D=M+1 //341
@SP //342
M=D //343
@FRAME //344
D=M //345
@1 //346
A=D-A //347
D=M //348
@THAT //349
M=D //350
@FRAME //351
D=M //352
@2 //353
A=D-A //354
D=M //355
@THIS //356
M=D //357
@FRAME //358
D=M //359
@3 //360
A=D-A //361
D=M //362
@ARG //363
M=D //364
@FRAME //365
D=M //366
@4 //367
A=D-A //368
D=M //369
@LCL //370
M=D //371
@RET //372
A=M //373
0;JMP //374
// 
// function Sys.init 0
(Sys.init)
// push constant 4
@4 //375
D=A //376
@SP //377
A=M //378
M=D //379
@SP //380
M=M+1 //381
// call Main.fibonacci 1   // computes the 4'th fibonacci element
@return-address3 //382
D=A //383
@SP //384
A=M //385
M=D //386
@SP //387
M=M+1 //388
@LCL //389
D=M //390
@SP //391
A=M //392
M=D //393
@SP //394
M=M+1 //395
@ARG //396
D=M //397
@SP //398
A=M //399
M=D //400
@SP //401
M=M+1 //402
@THIS //403
D=M //404
@SP //405
A=M //406
M=D //407
@SP //408
M=M+1 //409
@THAT //410
D=M //411
@SP //412
A=M //413
M=D //414
@SP //415
M=M+1 //416
@SP //417
D=M //418
@1 //419
D=D-A //420
@5 //421
D=D-A //ARG=SP-n-5 //422
@ARG //423
M=D //424
@SP //425
D=M //426
@LCL //427
M=D //428
@Main.fibonacci //429
0;JMP //430
(return-address3)
// label WHILE
(WHILE)
// goto WHILE              // loops infinitely
@WHILE //431
0;JMP //432
