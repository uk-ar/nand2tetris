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
// function Class1.set 0
(Class1.set)
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
// pop static 0
@SP //63
M=M-1 //64
A=M //65
D=M //66
@data //67
M=D //68
@Class1.0 //69
D=A //70
@address //71
M=D //72
@data //73
D=M //74
@address //75
A=M //76
M=D //77
// push argument 1
@ARG //78
D=M //79
@1 //80
A=D+A //81
D=M //82
@SP //83
A=M //84
M=D //85
@SP //86
M=M+1 //87
// pop static 1
@SP //88
M=M-1 //89
A=M //90
D=M //91
@data //92
M=D //93
@Class1.1 //94
D=A //95
@address //96
M=D //97
@data //98
D=M //99
@address //100
A=M //101
M=D //102
// push constant 0
@0 //103
D=A //104
@SP //105
A=M //106
M=D //107
@SP //108
M=M+1 //109
// return
@LCL //110
D=M //111
@FRAME //112
M=D //113
@5 //114
A=D-A //RET=*(FRAME-5) //115
D=M //116
@RET //return address  //117
M=D //118
@SP //119
M=M-1 //120
A=M //121
D=M //122
@ARG //123
A=M //124
M=D //125
@ARG //126
D=M+1 //127
@SP //128
M=D //129
@FRAME //130
D=M //131
@1 //132
A=D-A //133
D=M //134
@THAT //135
M=D //136
@FRAME //137
D=M //138
@2 //139
A=D-A //140
D=M //141
@THIS //142
M=D //143
@FRAME //144
D=M //145
@3 //146
A=D-A //147
D=M //148
@ARG //149
M=D //150
@FRAME //151
D=M //152
@4 //153
A=D-A //154
D=M //155
@LCL //156
M=D //157
@RET //158
A=M //159
0;JMP //160
// function Class1.get 0
(Class1.get)
// push static 0
@Class1.0 //161
D=M //162
@SP //163
A=M //164
M=D //165
@SP //166
M=M+1 //167
// push static 1
@Class1.1 //168
D=M //169
@SP //170
A=M //171
M=D //172
@SP //173
M=M+1 //174
// sub
@SP //175
M=M-1 //176
A=M //177
D=M //178
@SP //179
A=M-1 //180
D=M-D //181
@SP //182
A=M-1 //183
M=D //184
// return
@LCL //185
D=M //186
@FRAME //187
M=D //188
@5 //189
A=D-A //RET=*(FRAME-5) //190
D=M //191
@RET //return address  //192
M=D //193
@SP //194
M=M-1 //195
A=M //196
D=M //197
@ARG //198
A=M //199
M=D //200
@ARG //201
D=M+1 //202
@SP //203
M=D //204
@FRAME //205
D=M //206
@1 //207
A=D-A //208
D=M //209
@THAT //210
M=D //211
@FRAME //212
D=M //213
@2 //214
A=D-A //215
D=M //216
@THIS //217
M=D //218
@FRAME //219
D=M //220
@3 //221
A=D-A //222
D=M //223
@ARG //224
M=D //225
@FRAME //226
D=M //227
@4 //228
A=D-A //229
D=M //230
@LCL //231
M=D //232
@RET //233
A=M //234
0;JMP //235
// 
// function Sys.init 0
(Sys.init)
// push constant 6
@6 //236
D=A //237
@SP //238
A=M //239
M=D //240
@SP //241
M=M+1 //242
// push constant 8
@8 //243
D=A //244
@SP //245
A=M //246
M=D //247
@SP //248
M=M+1 //249
// call Class1.set 2
@return-address1 //250
D=A //251
@SP //252
A=M //253
M=D //254
@SP //255
M=M+1 //256
@LCL //257
D=M //258
@SP //259
A=M //260
M=D //261
@SP //262
M=M+1 //263
@ARG //264
D=M //265
@SP //266
A=M //267
M=D //268
@SP //269
M=M+1 //270
@THIS //271
D=M //272
@SP //273
A=M //274
M=D //275
@SP //276
M=M+1 //277
@THAT //278
D=M //279
@SP //280
A=M //281
M=D //282
@SP //283
M=M+1 //284
@SP //285
D=M //286
@2 //287
D=D-A //288
@5 //289
D=D-A //ARG=SP-n-5 //290
@ARG //291
M=D //292
@SP //293
D=M //294
@LCL //295
M=D //296
@Class1.set //297
0;JMP //298
(return-address1)
// pop temp 0 // Dumps the return value
@SP //299
M=M-1 //300
A=M //301
D=M //302
@data //303
M=D //304
@R5 //305
D=A //306
@0 //307
D=D+A //308
@address //309
M=D //310
@data //311
D=M //312
@address //313
A=M //314
M=D //315
// push constant 23
@23 //316
D=A //317
@SP //318
A=M //319
M=D //320
@SP //321
M=M+1 //322
// push constant 15
@15 //323
D=A //324
@SP //325
A=M //326
M=D //327
@SP //328
M=M+1 //329
// call Class2.set 2
@return-address2 //330
D=A //331
@SP //332
A=M //333
M=D //334
@SP //335
M=M+1 //336
@LCL //337
D=M //338
@SP //339
A=M //340
M=D //341
@SP //342
M=M+1 //343
@ARG //344
D=M //345
@SP //346
A=M //347
M=D //348
@SP //349
M=M+1 //350
@THIS //351
D=M //352
@SP //353
A=M //354
M=D //355
@SP //356
M=M+1 //357
@THAT //358
D=M //359
@SP //360
A=M //361
M=D //362
@SP //363
M=M+1 //364
@SP //365
D=M //366
@2 //367
D=D-A //368
@5 //369
D=D-A //ARG=SP-n-5 //370
@ARG //371
M=D //372
@SP //373
D=M //374
@LCL //375
M=D //376
@Class2.set //377
0;JMP //378
(return-address2)
// pop temp 0 // Dumps the return value
@SP //379
M=M-1 //380
A=M //381
D=M //382
@data //383
M=D //384
@R5 //385
D=A //386
@0 //387
D=D+A //388
@address //389
M=D //390
@data //391
D=M //392
@address //393
A=M //394
M=D //395
// call Class1.get 0
@return-address3 //396
D=A //397
@SP //398
A=M //399
M=D //400
@SP //401
M=M+1 //402
@LCL //403
D=M //404
@SP //405
A=M //406
M=D //407
@SP //408
M=M+1 //409
@ARG //410
D=M //411
@SP //412
A=M //413
M=D //414
@SP //415
M=M+1 //416
@THIS //417
D=M //418
@SP //419
A=M //420
M=D //421
@SP //422
M=M+1 //423
@THAT //424
D=M //425
@SP //426
A=M //427
M=D //428
@SP //429
M=M+1 //430
@SP //431
D=M //432
@0 //433
D=D-A //434
@5 //435
D=D-A //ARG=SP-n-5 //436
@ARG //437
M=D //438
@SP //439
D=M //440
@LCL //441
M=D //442
@Class1.get //443
0;JMP //444
(return-address3)
// call Class2.get 0
@return-address4 //445
D=A //446
@SP //447
A=M //448
M=D //449
@SP //450
M=M+1 //451
@LCL //452
D=M //453
@SP //454
A=M //455
M=D //456
@SP //457
M=M+1 //458
@ARG //459
D=M //460
@SP //461
A=M //462
M=D //463
@SP //464
M=M+1 //465
@THIS //466
D=M //467
@SP //468
A=M //469
M=D //470
@SP //471
M=M+1 //472
@THAT //473
D=M //474
@SP //475
A=M //476
M=D //477
@SP //478
M=M+1 //479
@SP //480
D=M //481
@0 //482
D=D-A //483
@5 //484
D=D-A //ARG=SP-n-5 //485
@ARG //486
M=D //487
@SP //488
D=M //489
@LCL //490
M=D //491
@Class2.get //492
0;JMP //493
(return-address4)
// label WHILE
(WHILE)
// goto WHILE
@WHILE //494
0;JMP //495
// 
// function Class2.set 0
(Class2.set)
// push argument 0
@ARG //496
D=M //497
@0 //498
A=D+A //499
D=M //500
@SP //501
A=M //502
M=D //503
@SP //504
M=M+1 //505
// pop static 0
@SP //506
M=M-1 //507
A=M //508
D=M //509
@data //510
M=D //511
@Class2.0 //512
D=A //513
@address //514
M=D //515
@data //516
D=M //517
@address //518
A=M //519
M=D //520
// push argument 1
@ARG //521
D=M //522
@1 //523
A=D+A //524
D=M //525
@SP //526
A=M //527
M=D //528
@SP //529
M=M+1 //530
// pop static 1
@SP //531
M=M-1 //532
A=M //533
D=M //534
@data //535
M=D //536
@Class2.1 //537
D=A //538
@address //539
M=D //540
@data //541
D=M //542
@address //543
A=M //544
M=D //545
// push constant 0
@0 //546
D=A //547
@SP //548
A=M //549
M=D //550
@SP //551
M=M+1 //552
// return
@LCL //553
D=M //554
@FRAME //555
M=D //556
@5 //557
A=D-A //RET=*(FRAME-5) //558
D=M //559
@RET //return address  //560
M=D //561
@SP //562
M=M-1 //563
A=M //564
D=M //565
@ARG //566
A=M //567
M=D //568
@ARG //569
D=M+1 //570
@SP //571
M=D //572
@FRAME //573
D=M //574
@1 //575
A=D-A //576
D=M //577
@THAT //578
M=D //579
@FRAME //580
D=M //581
@2 //582
A=D-A //583
D=M //584
@THIS //585
M=D //586
@FRAME //587
D=M //588
@3 //589
A=D-A //590
D=M //591
@ARG //592
M=D //593
@FRAME //594
D=M //595
@4 //596
A=D-A //597
D=M //598
@LCL //599
M=D //600
@RET //601
A=M //602
0;JMP //603
// function Class2.get 0
(Class2.get)
// push static 0
@Class2.0 //604
D=M //605
@SP //606
A=M //607
M=D //608
@SP //609
M=M+1 //610
// push static 1
@Class2.1 //611
D=M //612
@SP //613
A=M //614
M=D //615
@SP //616
M=M+1 //617
// sub
@SP //618
M=M-1 //619
A=M //620
D=M //621
@SP //622
A=M-1 //623
D=M-D //624
@SP //625
A=M-1 //626
M=D //627
// return
@LCL //628
D=M //629
@FRAME //630
M=D //631
@5 //632
A=D-A //RET=*(FRAME-5) //633
D=M //634
@RET //return address  //635
M=D //636
@SP //637
M=M-1 //638
A=M //639
D=M //640
@ARG //641
A=M //642
M=D //643
@ARG //644
D=M+1 //645
@SP //646
M=D //647
@FRAME //648
D=M //649
@1 //650
A=D-A //651
D=M //652
@THAT //653
M=D //654
@FRAME //655
D=M //656
@2 //657
A=D-A //658
D=M //659
@THIS //660
M=D //661
@FRAME //662
D=M //663
@3 //664
A=D-A //665
D=M //666
@ARG //667
M=D //668
@FRAME //669
D=M //670
@4 //671
A=D-A //672
D=M //673
@LCL //674
M=D //675
@RET //676
A=M //677
0;JMP //678
