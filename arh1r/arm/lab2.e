# DO NOT EDIT THIS FILE !!!!!!!!!!!!
#
# CONAS v3.0 output file
#
# Processor name: ARM 7
#
8 ; memory word width
#
32 ; address width
#
#
# Original file: Z:/home/tk/FER-stvari/arh1r/arm/lab2.a
#
#
<1,0>	                      ;; r1 - adresa gpio1 - lcd na vratima B
<2,0>	                      ;; r2 - adresa gpio2 - tipka i LED diode na vratima A
<3,0>	                      ;; r3 - adresa rtc
<4,0>	                      ;; r0 - razne namjene
<5,0>	                      ;
<6,0>	                      ;
<7,0>	                      ;        org     0
<8,0>	00000000  3E 00 00 EA ;        b       reset
<9,0>	                      ;
<10,0>	                      ;
<11,0>	                      ;        org     0x18
<12,0>	00000018  94 00 00 EA ;        b       irq
<13,0>	                      ;
<14,0>	                      ;
<15,0>	                      ;        org     0x100
<16,0>	                      ;
<17,0>	                      ;reset
<18,0>	00000100  D3 F0 29 E3 ;        msr     cpsr, #0b11010011
<19,0>	00000104  40 DB A0 E3 ;        mov     sp, #0x10000
<20,0>	                      ;
<21,0>	00000108  D2 F0 29 E3 ;        msr     cpsr, #0b11010010
<22,0>	0000010C  F0 DC A0 E3 ;        mov     sp, #0xf000
<23,0>	                      ;
<24,0>	                      ;
<25,0>	                      ;main
<26,0>	                      ;
<27,0>	00000110  D3 F0 29 E3 ;        msr     cpsr, #0b11010011
<28,0>	                      ;
<29,0>	00000114  E4 11 9F E5 ;        ldr     r1, gpio1
<30,0>	                      ;
<31,0>	00000118  E4 21 9F E5 ;        ldr     r2, gpio2
<32,0>	0000011C  E0 00 A0 E3 ;        mov     r0, #0b11100000
<33,0>	00000120  08 00 82 E5 ;        str     r0, [r2, #8]
<34,0>	                      ;
<35,0>	00000124  DC 31 9F E5 ;        ldr     r3, rtc
<36,0>	                      ;
<37,0>	                      ;
<38,0>	                      ;st1
<39,0>	00000128  D3 F0 29 E3 ;        msr     cpsr, #0b11010011       ; način rada svc za zabranjenim irq
<40,0>	                      ;
<41,0>	0000012C  00 00 A0 E3 ;        mov     r0, #0b00000000
<42,0>	00000130  00 00 82 E5 ;        str     r0, [r2]
<43,0>	                      ;
<44,0>	00000134  C3 0F A0 E3 ;        mov     r0, #txt1
<45,0>	00000138  01 00 2D E9 ;        stmfd   sp!, {r0}
<46,0>	0000013C  35 00 00 EB ;        bl      prnstr
<47,0>	00000140  04 D0 8D E2 ;        add     sp, sp, #4
<48,0>	                      ;
<49,0>	                      ;st1_lp
<50,0>	00000144  00 00 92 E5 ;        ldr     r0, [r2]
<51,0>	                      ;
<52,0>	00000148  EC 01 8F E5 ;        str     r0, debug
<53,0>	                      ;
<54,0>	0000014C  01 00 10 E3 ;        tst     r0, #1
<55,0>	00000150  FB FF FF 0A ;        beq     st1_lp
<56,0>	                      ;
<57,0>	00000154  02 00 A0 E3 ;        mov     r0, #2
<58,0>	00000158  D8 01 8F E5 ;        str     r0, tr_st
<59,0>	0000015C  FF FF FF EA ;        b       st2
<60,0>	                      ;
<61,0>	                      ;st2
<62,0>	00000160  52 F0 29 E3 ;        msr     cpsr, #0b01010010
<63,0>	                      ;
<64,0>	00000164  20 00 A0 E3 ;        mov     r0, #0b00100000         ; LED diode
<65,0>	00000168  00 00 82 E5 ;        str     r0, [r2]
<66,0>	                      ;        
<67,0>	0000016C  C5 0F A0 E3 ;        mov     r0, #txt2
<68,0>	00000170  01 00 2D E9 ;        stmfd   sp!, {r0}
<69,0>	00000174  27 00 00 EB ;        bl      prnstr
<70,0>	00000178  04 D0 8D E2 ;        add     sp, sp, #4
<71,0>	                      ;
<72,0>	0000017C  2F 00 00 EB ;        bl      setrtc
<73,0>	                      ;
<74,0>	00000180  1A 00 00 EA ;        b       wait
<75,0>	                      ;
<76,0>	                      ;st3
<77,0>	00000184  52 F0 29 E3 ;        msr     cpsr, #0b01010010
<78,0>	                      ;
<79,0>	00000188  40 00 A0 E3 ;        mov     r0, #0b01000000
<80,0>	0000018C  00 00 82 E5 ;        str     r0, [r2]
<81,0>	                      ;
<82,0>	00000190  C7 0F A0 E3 ;        mov     r0, #txt3
<83,0>	00000194  01 00 2D E9 ;        stmfd   sp!, {r0}
<84,0>	00000198  1E 00 00 EB ;        bl      prnstr
<85,0>	0000019C  04 D0 8D E2 ;        add     sp, sp, #4
<86,0>	                      ;
<87,0>	000001A0  26 00 00 EB ;        bl      setrtc
<88,0>	                      ;
<89,0>	000001A4  11 00 00 EA ;        b       wait
<90,0>	                      ;
<91,0>	                      ;st4
<92,0>	000001A8  52 F0 29 E3 ;        msr     cpsr, #0b01010010
<93,0>	                      ;
<94,0>	000001AC  80 00 A0 E3 ;        mov     r0, #0b10000000
<95,0>	000001B0  00 00 82 E5 ;        str     r0, [r2]
<96,0>	                      ;
<97,0>	000001B4  C9 0F A0 E3 ;        mov     r0, #txt4
<98,0>	000001B8  01 00 2D E9 ;        stmfd   sp!, {r0}
<99,0>	000001BC  15 00 00 EB ;        bl      prnstr
<100,0>	000001C0  04 D0 8D E2 ;        add     sp, sp, #4
<101,0>	                      ;
<102,0>	000001C4  1D 00 00 EB ;        bl      setrtc
<103,0>	                      ;
<104,0>	000001C8  08 00 00 EA ;        b       wait
<105,0>	                      ;
<106,0>	                      ;st5
<107,0>	000001CC  52 F0 29 E3 ;        msr     cpsr, #0b01010010
<108,0>	                      ;
<109,0>	000001D0  E0 00 A0 E3 ;        mov     r0, #0b11100000
<110,0>	000001D4  00 00 82 E5 ;        str     r0, [r2]
<111,0>	                      ;
<112,0>	000001D8  CB 0F A0 E3 ;        mov     r0, #txt5
<113,0>	000001DC  01 00 2D E9 ;        stmfd   sp!, {r0}
<114,0>	000001E0  0C 00 00 EB ;        bl      prnstr
<115,0>	000001E4  04 D0 8D E2 ;        add     sp, sp, #4
<116,0>	                      ;
<117,0>	000001E8  14 00 00 EB ;        bl      setrtc
<118,0>	                      ;
<119,0>	000001EC  FF FF FF EA ;        b wait
<120,0>	                      ;
<121,0>	                      ;
<122,0>	000001F0  FE FF FF EA ;wait    b       wait
<123,0>	                      ;        
<124,0>	                      ;
<125,0>	                      ;
<126,0>	                      ;
<127,0>	                      ;
<128,0>	                      ;lcdwr
<129,0>	                      ;; r0 i r4 kao i u potprogramu prnstr
<130,0>	                      ;; r4 - heksadekadski prikaz znaka
<131,0>	                      ;
<132,0>	000001F4  00 40 2D E9 ;        stmfd   sp!, {lr}
<133,0>	                      ;        
<134,0>	000001F8  7F 40 04 E2 ;        and     r4, r4, #0b01111111
<135,0>	                      ;
<136,0>	000001FC  04 40 C1 E5 ;        strb    r4, [r1, #4]
<137,0>	                      ;
<138,0>	00000200  80 40 84 E2 ;        add     r4, r4, #128    ; rastući brid
<139,0>	00000204  04 40 C1 E5 ;        strb    r4, [r1, #4]
<140,0>	                      ;
<141,0>	00000208  80 40 44 E2 ;        sub     r4, r4, #128    ; padajući brid
<142,0>	0000020C  04 40 C1 E5 ;        strb    r4, [r1, #4]
<143,0>	                      ;
<144,0>	00000210  00 40 BD E8 ;        ldmfd   sp!, {lr}
<145,0>	00000214  0E F0 A0 E1 ;        mov     pc, lr
<146,0>	                      ;        
<147,0>	                      ;        
<148,0>	                      ;        
<149,0>	                      ;
<150,0>	                      ;prnstr
<151,0>	                      ;; r0 - pokazivač na znak
<152,0>	                      ;; r1 - heksadekadski zapis znaka
<153,0>	                      ;
<154,0>	00000218  11 40 2D E9 ;        stmfd   sp!, {r0, r4, lr}
<155,0>	0000021C  0C 00 9D E5 ;        ldr     r0, [sp, #12]
<156,0>	00000220  0D 40 A0 E3 ;        mov     r4, #0x0d
<157,0>	                      ;
<158,0>	00000224  F2 FF FF EB ;        bl      lcdwr
<159,0>	                      ;
<160,0>	                      ;prst_lp 
<161,0>	00000228  01 40 D0 E4 ;        ldrb    r4, [r0], #1
<162,0>	0000022C  00 00 54 E3 ;        cmp     r4, #0
<163,0>	00000230  EF FF FF 1B ;        blne    lcdwr
<164,0>	00000234  FB FF FF 1A ;        bne     prst_lp
<165,0>	                      ;
<166,0>	00000238  11 40 BD E8 ;        ldmfd   sp!, {r0, r4, lr}
<167,0>	0000023C  0E F0 A0 E1 ;        mov     pc, lr
<168,0>	                      ;        
<169,0>	                      ;
<170,0>	                      ;setrtc
<171,0>	00000240  01 00 2D E9 ;        stmfd   sp!, {r0}
<172,0>	                      ;
<173,0>	00000244  00 00 A0 E3 ;        mov     r0, #0
<174,0>	00000248  10 00 83 E5 ;        str     r0, [r3, #16]
<175,0>	                      ;
<176,0>	0000024C  00 00 A0 E3 ;        mov     r0, #0          ; resetiranje timera
<177,0>	00000250  0C 00 83 E5 ;        str     r0, [r3, #12]
<178,0>	                      ;
<179,0>	00000254  08 00 83 E5 ;        str     r0, [r3, #8]
<180,0>	                      ;
<181,0>	00000258  D4 00 9F E5 ;        ldr     r0, vr        
<182,0>	0000025C  04 00 83 E5 ;        str     r0, [r3, #4]
<183,0>	                      ;
<184,0>	00000260  01 00 A0 E3 ;        mov     r0, #1          ; omogućavanje slanja zahtjeva za prekid
<185,0>	00000264  10 00 83 E5 ;        str     r0, [r3, #16]
<186,0>	                      ;
<187,0>	00000268  01 00 BD E8 ;        ldmfd   sp!, {r0}
<188,0>	0000026C  0E F0 A0 E1 ;        mov     pc, lr
<189,0>	                      ;
<190,0>	                      ;
<191,0>	                      ;
<192,0>	                      ;irq
<193,0>	                      ;; todo onaj dio sa rtcom
<194,0>	00000270  D2 F0 29 E3 ;        msr     cpsr, #0b11010010       ; onemogućavanje dodatnih prekida
<195,0>	00000274  01 00 2D E9 ;        stmfd   sp!, {r0}
<196,0>	                      ;
<197,0>	00000278  00 00 A0 E3 ;        mov     r0, #0
<198,0>	0000027C  10 00 83 E5 ;        str     r0, [r3, #16]
<199,0>	                      ;
<200,0>	00000280  B0 00 9F E5 ;        ldr     r0, tr_st
<201,0>	00000284  01 00 80 E2 ;        add     r0, r0, #1
<202,0>	                      ;
<203,0>	00000288  06 00 50 E3 ;        cmp     r0, #6
<204,0>	0000028C  01 00 A0 03 ;        moveq   r0, #1
<205,0>	                      ;
<206,0>	00000290  A0 00 8F E5 ;        str     r0, tr_st
<207,0>	                      ;
<208,0>	00000294  01 00 50 E3 ;        cmp     r0, #1
<209,0>	00000298  4A EF A0 03 ;        moveq   lr, #st1
<210,0>	0000029C  08 00 00 0A ;        beq     end_irq
<211,0>	                      ;
<212,0>	000002A0  03 00 50 E3 ;        cmp     r0, #3
<213,0>	000002A4  61 EF A0 03 ;        moveq   lr, #st3
<214,0>	000002A8  05 00 00 0A ;        beq     end_irq
<215,0>	                      ;
<216,0>	000002AC  04 00 50 E3 ;        cmp     r0, #4
<217,0>	000002B0  6A EF A0 03 ;        moveq   lr, #st4
<218,0>	000002B4  02 00 00 0A ;        beq     end_irq
<219,0>	                      ;
<220,0>	000002B8  05 00 50 E3 ;        cmp     r0, #5
<221,0>	000002BC  73 EF A0 03 ;        moveq   lr, #st5
<222,0>	000002C0  FF FF FF 0A ;        beq     end_irq
<223,0>	                      ;
<224,0>	                      ;end_irq
<225,0>	000002C4  01 00 BD E8 ;        ldmfd   sp!, {r0}
<226,0>	                      ;        ; mov     pc, lr
<227,0>	000002C8  04 E0 8E E2 ;        add     lr, lr, #4
<228,0>	000002CC  04 F0 5E E2 ;        subs    pc, lr, #4
<229,0>	                      ;        
<230,0>	                      ;
<231,0>	                      ;        org     0x300
<232,0>	                      ;
<233,0>	00000300! 00 0F FF FF ;gpio1   dw      0xffff0f00
<234,0>	00000304! 00 0B FF FF ;gpio2   dw      0xffff0b00
<235,0>	00000308! 00 0E FF FF ;rtc     dw      0xffff0e00
<236,0>	                      ;
<237,0>	                      ;
<238,0>	                      ;; "WELCOME"
<239,0>	0000030C! 57 45 4C 43 ;txt1    db      0x57, 0x45, 0x4c, 0x43, 0x4f, 0x4d, 0x45, 0x00
|         4F 4D 45 00
<240,0>	                      ;; "HEATING"
<241,0>	00000314! 48 45 41 54 ;txt2    db      0x48, 0x45, 0x41, 0x54, 0x49, 0x4e, 0x47, 0x00
|         49 4E 47 00
<242,0>	                      ;; "COFFEE"
<243,0>	0000031C! 43 4F 46 46 ;txt3    db      0x43, 0x4f, 0x46, 0x46, 0x45, 0x45, 0x00
|         45 45 00
<244,0>	                      ;; "MILK"
<245,0>	                      ;        org     0x324
<246,0>	00000324! 4D 49 4C 4B ;txt4    db      0x4d, 0x49, 0x4c, 0x4b, 0x00
|         00
<247,0>	                      ;; "DONE"
<248,0>	                      ;        org     0x32c
<249,0>	0000032C! 44 4F 4E 45 ;txt5    db      0x44, 0x4f, 0x4e, 0x45, 0x00
|         00
<250,0>	                      ;
<251,0>	00000334! 5A 0A 00 00 ;vr      dw      2650
<252,0>	                      ;
<253,0>	00000338! 01 00 00 00 ;tr_st   dw      1
<254,0>	                      ;
<255,0>	0000033C! 00 00 00 00 ;debug   dw      0
#
# Debug Data
#
.debug:
<!h253,0> <!h255,0> 
#
#
# Assembling: OK