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
# Original file: Z:/home/tk/FER-stvari/arh1r/arm/lab1arh.a
#
#
<1,0>	                      ;  ; dosad iskoristeni registri: 
<2,0>	                      ;  ; r1 - operacija, u potprogramu DIJELI predznak rezultata
<3,0>	                      ;  ; r2 - prvi operand
<4,0>	                      ;  ; r3 - drugi operand
<5,0>	                      ;  ; r4 - niz podataka
<6,0>	                      ;  ; r5 - niz rezultata
<7,0>	                      ;  ; r6 - broj koji oznacava kraj niza podataka
<8,0>	                      ;  ; r7 - zaključni rezutat
<9,0>	                      ;  ; r10 - rezultat operacije
<10,0>	                      ;
<11,0>	00000000  70 4E A0 E3 ;        mov     r4, #0x700       ; pocetak niza podataka
<12,0>	00000004  80 5D A0 E3 ;        mov     r5, #0x2000      ; pocetak niza rezultata   
<13,0>	                      ;
<14,0>	00000008  F0 64 9F E5 ;        ldr     r6, 0x500    ; kraj niza podataka
<15,0>	0000000C  F0 74 9F E5 ;        ldr     r7, 0x504       ; kraj niza rezultata
<16,0>	                      ;        
<17,0>	00000010  40 DB A0 E3 ;        mov     sp, #0x10000    ; inicijalizacija stoga
<18,0>	                      ;
<19,0>	00000014  04 10 94 E4 ;gpetlja ldr     r1, [r4], #4    ; gpetlja - glavna petlja
<20,0>	                      ;        
<21,0>	00000018  06 00 51 E1 ;        cmp     r1, r6  ; program se prekida kada se na r1 ucita 0x88888888
<22,0>	0000001C  35 00 00 0A ;        beq     kraj            
<23,0>	                      ;
<24,0>	00000020  04 20 94 E4 ;        ldr     r2, [r4], #4    
<25,0>	00000024  04 30 94 E4 ;        ldr     r3, [r4], #4    
<26,0>	                      ;
<27,0>	00000028  00 00 51 E3 ;        cmp     r1, #0  ; ako je r1 == 0, obavi zbrajanje
<28,0>	0000002C  0A 00 00 0A ;        beq     zbr
<29,0>	                      ;
<30,0>	00000030  01 00 51 E3 ;        cmp     r1, #1  ; ako je r1 == 1, obavi oduzimanje
<31,0>	00000034  06 00 00 0A ;        beq     odu
<32,0>	                      ;
<33,0>	00000038  02 00 51 E3 ;        cmp     r1, #2  ; ako je r1 == 2, obavi mnozenje
<34,0>	0000003C  08 00 00 0A ;        beq     umn
<35,0>	                      ;
<36,0>	00000040  03 00 51 E3 ;        cmp     r1, #3  ; ako je r1 == 3, obavi dijeljenje korištenjem potprograma DIJELI
<37,0>	00000044  0E 00 2D E9 ;        stmfd   SP!, {r1, r2, r3}
<38,0>	00000048  07 00 00 0B ;        bleq    DIJELI
<39,0>	0000004C  0C D0 8D E2 ;        add     sp, sp, #12
<40,0>	00000050  26 00 00 EA ;        b       slj
<41,0>	                      ;
<42,0>	00000054  03 A0 42 E0 ;odu     sub     r10, r2, r3     ; oduzimanje
<43,0>	00000058  24 00 00 EA ;        b       slj
<44,0>	                      ;
<45,0>	0000005C  03 A0 82 E0 ;zbr     add     r10, r2, r3     ; zbrajanje
<46,0>	00000060  22 00 00 EA ;        b       slj
<47,0>	                      ;
<48,0>	00000064  92 03 0A E0 ;umn     mul     r10, r2, r3     ; mnozenje
<49,0>	00000068  20 00 00 EA ;        b       slj
<50,0>	                      ;
<51,0>	0000006C  0E 00 2D E9 ;DIJELI  stmfd   sp!, {r1, r2, r3}       ; spremanje konteksta
<52,0>	                      ;        
<53,0>	00000070  0C 10 9D E5 ;        ldr     r1, [sp, #12]   ; uvođenje argumenata na registre
<54,0>	00000074  10 20 9D E5 ;        ldr     r2, [sp, #16]   ; r1 - predznak, r2 - djeljenik, r3 - djelitelj
<55,0>	00000078  14 30 9D E5 ;        ldr     r3, [sp, #20]
<56,0>	                      ;
<57,0>	0000007C  01 10 A0 E3 ;        mov     r1, #1
<58,0>	00000080  00 A0 A0 E3 ;        mov     r10, #0
<59,0>	                      ;
<60,0>	00000084  00 00 53 E3 ;        cmp     r3, #0  ; ako je r3 == 0, potprogram se odmah završava
<61,0>	00000088  16 00 00 0A ;        beq     dj_kraj ; i r10 je namješten na 0
<62,0>	                      ;
<63,0>	0000008C  00 00 52 E3 ;prvi    cmp     r2, #0
<64,0>	00000090  00 00 00 4A ;        bmi     neg1
<65,0>	00000094  04 00 00 EA ;        b       drugi
<66,0>	                      ;
<67,0>	00000098  02 20 E0 E1 ;neg1    mvn     r2, r2  ; ako je prvi operand negativan, promijeni njegov predznak i predznak rezultata
<68,0>	0000009C  01 20 82 E2 ;        add     r2, r2, #1
<69,0>	000000A0  01 10 E0 E1 ;        mvn     r1, r1
<70,0>	000000A4  01 10 81 E2 ;        add     r1, r1, #1
<71,0>	000000A8  FF FF FF EA ;        b       drugi
<72,0>	                      ;
<73,0>	000000AC  00 00 53 E3 ;drugi   cmp     r3, #0
<74,0>	000000B0  00 00 00 4A ;        bmi     neg2
<75,0>	000000B4  04 00 00 EA ;        b       dj
<76,0>	                      ;
<77,0>	000000B8  03 30 E0 E1 ;neg2    mvn     r3, r3  ; ako je drugi operand negativan, promijeni njegov predznak i predznak rezultata
<78,0>	000000BC  01 30 83 E2 ;        add     r3, r3, #1
<79,0>	000000C0  01 10 E0 E1 ;        mvn     r1, r1
<80,0>	000000C4  01 10 81 E2 ;        add     r1, r1, #1
<81,0>	000000C8  FF FF FF EA ;        b       dj
<82,0>	                      ;
<83,0>	000000CC  03 20 42 E0 ;dj      sub     r2, r2, r3      ; od r2 se oduzima r3 dok je r2 veći od nule, a
<84,0>	000000D0  01 A0 8A E2 ;        add     r10, r10, #1    ; u r10 se broji koliko puta je r3 oduzet od r2
<85,0>	000000D4  00 00 52 E3 ;        cmp     r2, #0
<86,0>	000000D8  FB FF FF 5A ;        bpl     dj
<87,0>	                      ;
<88,0>	000000DC  00 00 52 E3 ;        cmp     r2, #0          ; ako je r2 manji od nule, konačni rezultat je r10 - 1
<89,0>	000000E0  01 A0 4A 42 ;        submi   r10, r10, #1
<90,0>	000000E4  91 0A 0A E0 ;        mul     r10, r1, r10    ; postavljanje predznaka r10
<91,0>	                      ;
<92,0>	000000E8  0E 00 BD E8 ;dj_kraj ldmfd   sp!, {r1, r2, r3}       ; obnavljanje konteksta
<93,0>	000000EC  0E F0 A0 E1 ;        mov     pc, lr
<94,0>	                      ;        
<95,0>	                      ;
<96,0>	                      ;
<97,0>	000000F0  04 A0 85 E4 ;slj     str     r10, [r5], #4
<98,0>	000000F4  C6 FF FF EA ;        b       gpetlja
<99,0>	                      ;
<100,0>	                      ;
<101,0>	000000F8  04 70 85 E4 ;kraj    str     r7, [r5], #4
<102,0>	000000FC  56 34 12 EF ;        swi     0x123456
<103,0>	                      ;
<104,0>	                      ;        org     0x500
<105,0>	00000500! 88 88 88 88 ;stvari  dw      0x88888888, 0xFFFFFFFF
|         FF FF FF FF
<106,0>	                      ;
<107,0>	                      ;        org     0x700
<108,0>	00000700! 00 00 00 00 ;podaci  dw      0x0, 0x00001000, 0x0001FEDC, 0x0, 0xFFFFFED4, 0x00001000, 0x0, 0x00110000, 0xFFFFFF6A, 0x0, 0xFFFFFF38, 0xFFFFFE0C, 0x1, 0x00001000, 0x0001FEDC, 0x1, 0xFFFFFED4, 0x00001000, 0x1, 0x00110000, 0xFFFFFF6A, 0x1, 0xFFFFFF38, 0xFFFFFE0C, 0x2, 0x00001000, 0x0001FEDC, 0x2, 0xFFFFFED4, 0x00001000, 0x2, 0x00110000, 0xFFFFFF6A, 0x2, 0xFFFFFF38, 0xFFFFFE0C, 0x3, 0x00001000, 0x0001FEDC, 0x3, 0xFFFFFED4, 0x00001000, 0x3, 0x00110000, 0xFFFFFF6A, 0x3, 0xFFFFFF38, 0xFFFFFE0C, 0x88888888
|         00 10 00 00
|         DC FE 01 00
|         00 00 00 00
|         D4 FE FF FF
|         00 10 00 00
|         00 00 00 00
|         00 00 11 00
|         6A FF FF FF
|         00 00 00 00
|         38 FF FF FF
|         0C FE FF FF
|         01 00 00 00
|         00 10 00 00
|         DC FE 01 00
|         01 00 00 00
|         D4 FE FF FF
|         00 10 00 00
|         01 00 00 00
|         00 00 11 00
|         6A FF FF FF
|         01 00 00 00
|         38 FF FF FF
|         0C FE FF FF
|         02 00 00 00
|         00 10 00 00
|         DC FE 01 00
|         02 00 00 00
|         D4 FE FF FF
|         00 10 00 00
|         02 00 00 00
|         00 00 11 00
|         6A FF FF FF
|         02 00 00 00
|         38 FF FF FF
|         0C FE FF FF
|         03 00 00 00
|         00 10 00 00
|         DC FE 01 00
|         03 00 00 00
|         D4 FE FF FF
|         00 10 00 00
|         03 00 00 00
|         00 00 11 00
|         6A FF FF FF
|         03 00 00 00
|         38 FF FF FF
|         0C FE FF FF
|         88 88 88 88
<109,0>	                      ;
<110,0>	                      ;
<111,0>	                      ;        org     0x2000
<112,0>	00002000! 00 00 00 00 ;rj      dw      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0     ; rjesenja
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
<113,0>	                      ; 
<114,0>	                      ;
#
# Debug Data
#
.debug:
<!h105,0> <!h108,0> <!h112,0> 
#
#
# Assembling: OK