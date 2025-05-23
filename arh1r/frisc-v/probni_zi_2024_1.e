# DO NOT EDIT THIS FILE !!!!!!!!!!!!
#
# CONAS v3.0 output file
#
# Processor name: RV32I
#
8 ; memory word width
#
32 ; address width
#
#
# Original file: Z:/home/tk/FER-stvari/arh1r/frisc-v/probni_zi_2024_1.a
#
#
<1,0>	                      ;; jebeno katastrofalan kod lmao
<2,0>	                      ;
<3,0>	00000000  6F 00 00 02 ;reset   jal     x0, main
<4,0>	                      ;
<5,0>	                      ;
<6,0>	                      ;        org     0x20
<7,0>	                      ;
<8,0>	                      ;main
<9,0>	                      ;; s0 - adresa sklopa gpio0
<10,0>	                      ;; s1 - adresa sklopa gpio1
<11,0>	                      ;; s2 - adresa kraja bloka sa mjerenjima
<12,0>	                      ;; s3 - hoće li potprogram check utjecati na registar a2
<13,0>	                      ;; s4 - adresa 0x1000
<14,0>	                      ;; a0 - prosjecna vrijednost mjerenja
<15,0>	                      ;; a1 - kolicina mjerenja
<16,0>	                      ;; a2 - stanje gpio1A (prekidač)
<17,0>	                      ;; a3 - stanje gpio0A (temperaturni uređaj)
<18,0>	                      ;; a4 - adresa za zapisati mjerenje
<19,0>	                      ;
<20,0>	                      ;        ; lui     s0, %hi(0xffff1000)
<21,0>	                      ;        ; addi    s0, s0, %lo(0xffff1000)
<22,0>	00000020  37 14 FF FF ;        lui     s0, %hi(0xffff0f00)
<23,0>	00000024  13 04 04 F0 ;        addi    s0, s0, %lo(0xffff0f00)
<24,0>	                      ;
<25,0>	00000028  93 02 00 08 ;        addi    t0, x0, 0b10000000
<26,0>	0000002C  23 24 54 00 ;        sw      t0, 8(s0)
<27,0>	                      ;
<28,0>	                      ;        ; lui     s1, %hi(0xffff2000)
<29,0>	                      ;        ; addi    s1, s1, %lo(0xffff2000)
<30,0>	00000030  B7 14 FF FF ;        lui     s1, %hi(0xffff0b00)
<31,0>	00000034  93 84 04 B0 ;        addi    s1, s1, %lo(0xffff0b00)
<32,0>	                      ;
<33,0>	00000038  13 09 00 50 ;        addi    s2, x0, 0x500
<34,0>	                      ;
<35,0>	0000003C  13 05 00 00 ;        addi    a0, x0, 0
<36,0>	00000040  93 05 00 00 ;        addi    a1, x0, 0
<37,0>	00000044  13 07 00 50 ;        addi    a4, x0, 0x500
<38,0>	                      ;
<39,0>	00000048  37 1A 00 00 ;        lui     s4, %hi(0x1000)
<40,0>	0000004C  13 0A 0A 00 ;        addi    s4, s4, %lo(0x1000)
<41,0>	                      ;
<42,0>	                      ;p1
<43,0>	00000050  93 09 10 00 ;        addi    s3, x0, 1
<44,0>	00000054  13 06 00 00 ;        addi    a2, x0, 0
<45,0>	                      ;
<46,0>	                      ;wait1
<47,0>	00000058  EF 00 80 10 ;        jal     ra, check
<48,0>	0000005C  13 76 16 00 ;        andi    a2, a2, 1
<49,0>	00000060  63 12 06 0A ;        bne     a2, x0, p0
<50,0>	                      ;
<51,0>	00000064  93 02 00 08 ;        addi    t0, x0, 0b10000000
<52,0>	00000068  23 20 54 00 ;        sw      t0, 0(s0)
<53,0>	                      ;
<54,0>	                      ;waitrdy1                        ; čekanje signala rdy=1
<55,0>	0000006C  83 26 04 00 ;        lw      a3, 0(s0)
<56,0>	                      ;
<57,0>	00000070  93 02 00 04 ;        addi    t0, x0, 0b01000000
<58,0>	00000074  B3 F2 D2 00 ;        and     t0, t0, a3
<59,0>	                      ;
<60,0>	00000078  EF 00 80 0E ;        jal     ra, check
<61,0>	                      ;
<62,0>	0000007C  E3 88 02 FE ;        beq     t0, x0, waitrdy1
<63,0>	                      ;
<64,0>	                      ;readtemp
<65,0>	                      ;
<66,0>	00000080  83 26 04 00 ;        lw      a3, 0(s0)       ; učitavanje stanja na temperaturnom uređaju
<67,0>	                      ;
<68,0>	00000084  B3 02 D0 00 ;        add     t0, x0, a3              ; slanje impulsa na ack
<69,0>	00000088  93 62 00 08 ;        ori     t0, x0, 0b10000000
<70,0>	0000008C  23 20 54 00 ;        sw      t0, 0(s0)
<71,0>	00000090  93 F2 F2 07 ;        andi    t0, t0, 0b01111111
<72,0>	00000094  23 20 54 00 ;        sw      t0, 0(s0)
<73,0>	                      ;
<74,0>	00000098  EF 00 80 0C ;        jal     ra, check
<75,0>	                      ;
<76,0>	0000009C  93 F6 F6 03 ;        andi    a3, a3, 0b00111111      ; čitanje i upisivanje temperature
<77,0>	000000A0  23 24 D7 00 ;        sw      a3, 8(a4)
<78,0>	                      ;
<79,0>	000000A4  EF 00 C0 0B ;        jal     ra, check
<80,0>	                      ;
<81,0>	                      ;
<82,0>	                      ;waitrdy0                        ; čekanje signala rdy=0
<83,0>	000000A8  83 26 04 00 ;        lw      a3, 0(s0)
<84,0>	000000AC  93 F2 06 04 ;        andi    t0, a3, 0b01000000
<85,0>	                      ;
<86,0>	000000B0  EF 00 00 0B ;        jal     ra, check
<87,0>	000000B4  E3 9A 02 FE ;        bne     t0, x0, waitrdy0
<88,0>	                      ;
<89,0>	000000B8  93 85 05 FE ;        addi    a1, a1, -32     ; namještanje brojača količine mjerenja
<90,0>	000000BC  63 C4 05 00 ;        blt     a1, x0, aaa
<91,0>	000000C0  93 05 F0 FF ;        addi    a1, x0, -1
<92,0>	000000C4  93 85 15 02 ;aaa     addi    a1, a1, 33
<93,0>	                      ;
<94,0>	000000C8  23 20 B9 00 ;        sw      a1, 0(s2)
<95,0>	                      ;
<96,0>	000000CC  EF 00 00 01 ;        jal     ra, next
<97,0>	000000D0  EF 00 00 09 ;        jal     ra, check
<98,0>	                      ;
<99,0>	000000D4  93 09 00 00 ;        addi    s3, x0, 0
<100,0>	000000D8  6F F0 1F F8 ;        jal     x0, wait1
<101,0>	                      ;
<102,0>	                      ;next
<103,0>	000000DC  13 07 07 B0 ;        addi    a4, a4, -0x500
<104,0>	000000E0  13 57 27 00 ;        srli    a4, a4, 2       ; namještanje adrese za upisivanje mjerenja
<105,0>	000000E4  13 07 17 FE ;        addi    a4, a4, -31
<106,0>	000000E8  63 14 07 00 ;        bne     a4, x0, aba
<107,0>	000000EC  13 07 00 FE ;        addi    a4, x0, -32
<108,0>	000000F0  13 07 07 02 ;aba     addi    a4, a4, 32
<109,0>	000000F4  13 17 27 00 ;        slli    a4, a4, 2
<110,0>	000000F8  13 07 07 50 ;        addi    a4, a4, 0x500
<111,0>	                      ;        
<112,0>	000000FC  23 22 E9 00 ;        sw      a4, 4(s2)
<113,0>	                      ;
<114,0>	00000100  67 80 00 00 ;        jalr    x0, 0(ra)
<115,0>	                      ;
<116,0>	                      ;p0
<117,0>	00000104  93 09 10 00 ;        addi    s3, x0, 1
<118,0>	00000108  13 05 00 00 ;        addi    a0, x0, 0
<119,0>	0000010C  13 06 00 00 ;        addi    a2, x0, 0
<120,0>	00000110  93 02 00 00 ;        addi    t0, x0, 0
<121,0>	                      ;
<122,0>	                      ;izrpr
<123,0>	00000114  03 23 07 00 ;        lw      t1, 0(a4)       ; akumulacija rezultata mjerenja u a0
<124,0>	00000118  EF F0 5F FC ;        jal     ra, next
<125,0>	0000011C  33 05 65 00 ;        add     a0, a0, t1
<126,0>	00000120  93 82 12 00 ;        addi    t0, t0, 1
<127,0>	00000124  E3 98 B2 FE ;        bne     t0, a1, izrpr
<128,0>	                      ;        
<129,0>	00000128  EF 00 00 02 ;        jal     ra, dijeli    ; izračunavanje prosjeka
<130,0>	0000012C  23 20 AA 00 ;        sw      a0, 0(s4)
<131,0>	00000130  93 09 00 00 ;        addi    s3, x0, 0
<132,0>	                      ;
<133,0>	                      ;wait0
<134,0>	00000134  EF 00 C0 02 ;        jal     ra, check
<135,0>	00000138  13 76 16 00 ;        andi    a2, a2, 1
<136,0>	0000013C  E3 1A 06 F0 ;        bne     a2, x0, p1
<137,0>	00000140  6F F0 5F FF ;        jal     x0, wait0
<138,0>	                      ;
<139,0>	                      ;
<140,0>	                      ;        
<141,0>	                      ;        
<142,0>	                      ;
<143,0>	                      ;
<144,0>	                      ;kraj
<145,0>	00000144  6F F0 D0 6B ;        halt
<146,0>	                      ;
<147,0>	                      ;dijeli
<148,0>	00000148  B3 02 A0 00 ;        add     t0, x0, a0
<149,0>	0000014C  33 05 00 00 ;        add     a0, x0, x0
<150,0>	                      ;
<151,0>	                      ;djloop
<152,0>	00000150  B3 82 B2 40 ;        sub     t0, t0, a1
<153,0>	00000154  13 05 15 00 ;        addi    a0, a0, 1
<154,0>	00000158  E3 DC 02 FE ;        bge     t0, x0, djloop
<155,0>	                      ;
<156,0>	0000015C  67 80 00 00 ;        jalr    x0, 0(ra)
<157,0>	                      ;
<158,0>	                      ;check
<159,0>	00000160  63 96 09 00 ;        bne     s3, x0, check_e
<160,0>	00000164  03 A6 04 00 ;        lw      a2, 0(s1)
<161,0>	00000168  93 79 16 00 ;        andi    s3, a2, 1
<162,0>	0000016C  23 20 30 21 ;check_e sw      s3, bruh(x0)
<163,0>	00000170  67 80 00 00 ;        jalr    x0, 0(ra)
<164,0>	                      ;
<165,0>	                      ;
<166,0>	                      ;
<167,0>	                      ;     
<168,0>	                      ;
<169,0>	                      ;        org     0x200
<170,0>	00000200! 01 00 00 00 ;bruh    dw      1
<171,0>	                      ;
<172,0>	                      ;
<173,0>	                      ;        org     0x500
<174,0>	00000500! 00 00 00 00 ;brojac  dw      0
<175,0>	00000504! 00 00 00 00 ;adresa  dw      0
<176,0>	00000508! 00 00 00 00 ;podatci dw      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
<177,0>	                      ;
<178,0>	                      ;        org     0x1000
<179,0>	00001000! 00 00 00 00 ;prosjek dw      0
<180,0>	                      ;        
#
# Debug Data
#
.debug:
<!h170,0> <!h174,0> <!h175,0> <!h176,0> <!h179,0> 
#
#
# Assembling: OK