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
# Original file: Z:/home/tinke/FER-stvari/arh1r/arm/zbirka_arm_2_4_9.a
#
#
<1,0>	                      ;main
<2,0>	00000000  40 1D A0 E3 ;        mov     r1, #0x1000     ; pokazivač adresa
<3,0>	                      ;; adresa bloka za upisati uvijek će biti za točno 0x1000 viša nego adresa bloka za pročitati,
<4,0>	                      ;; adresa količie brojeva bit će veća za 0x2000, a adresa za količinu nula za 0x3000
<5,0>	                      ;
<6,0>	00000004  05 50 A0 E3 ;        mov     r5, #5          ; brojač petlje
<7,0>	00000008  40 DB A0 E3 ;        mov     sp, #0x10000    ; stog
<8,0>	                      ;
<9,0>	                      ;loop
<10,0>	0000000C  00 20 91 E5 ;        ldr     r2, [r1]        ; adresa bloka podataka za pročitati
<11,0>	                      ;
<12,0>	00000010  00 00 55 E3 ;        cmp     r5, #0
<13,0>	00000014  0C 00 00 0A ;        beq     end
<14,0>	                      ;
<15,0>	00000018  40 1D 81 E2 ;        add     r1, r1, #0x1000         
<16,0>	0000001C  00 30 91 E5 ;        ldr     r3, [r1]                ; početna adresa bloka za upisati
<17,0>	00000020  40 1D 81 E2 ;        add     r1, r1, #0x1000         
<18,0>	00000024  00 40 91 E5 ;        ldr     r4, [r1]                ; količina brojeva u bloku za pročitati
<19,0>	                      ;
<20,0>	00000028  1C 00 2D E9 ;        stmfd   sp!, {r2, r3, r4}       ; potprogram izbaci upisuje novi blok podataka i preko r0 vraća količinu izbrisanih nula
<21,0>	0000002C  07 00 00 EB ;        bl      izbaci
<22,0>	00000030  0C D0 8D E2 ;        add     sp, sp, #12
<23,0>	                      ;
<24,0>	00000034  40 1D 81 E2 ;        add     r1, r1, #0x1000         
<25,0>	00000038  00 00 81 E5 ;        str     r0, [r1]                ; spremi količinu izbrisanih nula
<26,0>	                      ;
<27,0>	0000003C  04 10 81 E2 ;        add     r1, r1, #4
<28,0>	00000040  C0 1D 41 E2 ;        sub     r1, r1, #0x3000
<29,0>	00000044  01 50 45 E2 ;        sub     r5, r5, #1
<30,0>	00000048  EF FF FF EA ;        b       loop
<31,0>	                      ;
<32,0>	                      ;
<33,0>	                      ;end
<34,0>	0000004C  56 34 12 EF ;        swi     0x123456
<35,0>	                      ;
<36,0>	                      ;
<37,0>	                      ;izbaci
<38,0>	                      ;
<39,0>	                      ;; r0 - količina izbačenih nula (ovo se vraća)
<40,0>	                      ;; r1 - pokazivač na elemente u bloku za pročitati
<41,0>	                      ;; r2 - pokazivač na elemente u bloku za upisati
<42,0>	                      ;; r3 - brojač petlje
<43,0>	                      ;; r4 - trenutni element bloka za pročitati
<44,0>	                      ;
<45,0>	00000050  1E 40 2D E9 ;        stmfd   sp!, {r1, r2, r3, r4, lr}
<46,0>	00000054  14 10 9D E5 ;        ldr     r1, [sp, #20]
<47,0>	00000058  18 20 9D E5 ;        ldr     r2, [sp, #24]
<48,0>	0000005C  1C 30 9D E5 ;        ldr     r3, [sp, #28]
<49,0>	00000060  00 00 A0 E3 ;        mov     r0, #0
<50,0>	                      ;
<51,0>	                      ;loop2
<52,0>	00000064  00 00 53 E3 ;        cmp     r3, #0          ; početna vrijednost brojača je količina brojeva u bloku za pročitati, po svakom prolazu petlje smanjuje se za 1 i, kada postane 0, petlja se završava
<53,0>	00000068  05 00 00 0A ;        beq     end_izb
<54,0>	                      ;        
<55,0>	0000006C  B2 40 D1 E0 ;        ldrh    r4, [r1], #2
<56,0>	                      ;
<57,0>	00000070  00 00 54 E3 ;        cmp     r4, #0          
<58,0>	00000074  01 00 80 02 ;        addeq   r0, r0, #1
<59,0>	00000078  B2 40 C2 10 ;        strneh  r4, [r2], #2
<60,0>	                      ;
<61,0>	0000007C  01 30 43 E2 ;        sub     r3, r3, #1
<62,0>	00000080  F7 FF FF EA ;        b       loop2
<63,0>	                      ;
<64,0>	                      ;
<65,0>	                      ;end_izb
<66,0>	00000084  1E 40 BD E8 ;        ldmfd   sp!, {r1, r2, r3, r4, lr}
<67,0>	00000088  0E F0 A0 E1 ;        mov     pc, lr
<68,0>	                      ;
<69,0>	                      ;
<70,0>	                      ;
<71,0>	                      ;        org     0x1000
<72,0>	00001000! 00 11 00 00 ;izv     dw      0x1100, 0x1200, 0x1300, 0x1400, 0x1500
|         00 12 00 00
|         00 13 00 00
|         00 14 00 00
|         00 15 00 00
<73,0>	                      ;
<74,0>	                      ;        org     0x1100
<75,0>	00001100! 00 00 01 00 ;izv1    dh      0, 1, 0, 1
|         00 00 01 00
<76,0>	                      ;
<77,0>	                      ;        org     0x1200
<78,0>	00001200! FB FF 03 00 ;izv2    dh      -5, 3, 0, 0, 40
|         00 00 00 00
|         28 00
<79,0>	                      ;
<80,0>	                      ;        org     0x1300
<81,0>	00001300! FF FF 00 00 ;izv3    dh      -1, 0, 0, 0, -1, -1
|         00 00 00 00
|         FF FF FF FF
<82,0>	                      ;
<83,0>	                      ;        org     0x1400
<84,0>	00001400! 63 00 00 00 ;izv4    dh      99, 0, 100
|         64 00
<85,0>	                      ;
<86,0>	                      ;        org     0x1500
<87,0>	00001500! 00 00 00 00 ;izv5    dh      0, 0, 0, 0
|         00 00 00 00
<88,0>	                      ;
<89,0>	                      ;
<90,0>	                      ;        org     0x2000
<91,0>	00002000! 00 21 00 00 ;odr     dw      0x2100, 0x2200, 0x2300, 0x2400, 0x2500
|         00 22 00 00
|         00 23 00 00
|         00 24 00 00
|         00 25 00 00
<92,0>	                      ;
<93,0>	                      ;        org     0x2100
<94,0>	00002100! 00 00 00 00 ;odr1    dh      0, 0, 0, 0
|         00 00 00 00
<95,0>	                      ;
<96,0>	                      ;        org     0x2200
<97,0>	00002200! 00 00 00 00 ;odr2    dh      0, 0, 0, 0, 0
|         00 00 00 00
|         00 00
<98,0>	                      ;
<99,0>	                      ;        org     0x2300
<100,0>	00002300! 00 00 00 00 ;odr3    dh      0, 0, 0, 0, 0, 0
|         00 00 00 00
|         00 00 00 00
<101,0>	                      ;
<102,0>	                      ;        org     0x2400
<103,0>	00002400! 00 00 00 00 ;odr4    dh      0, 0, 0
|         00 00
<104,0>	                      ;
<105,0>	                      ;        org     0x2500
<106,0>	00002500! 00 00 00 00 ;odr5    dh      0, 0, 0, 0
|         00 00 00 00
<107,0>	                      ;
<108,0>	                      ;
<109,0>	                      ;        org     0x3000
<110,0>	00003000! 04 00 00 00 ;        dw      4, 5, 6, 3, 4
|         05 00 00 00
|         06 00 00 00
|         03 00 00 00
|         04 00 00 00
<111,0>	                      ;
<112,0>	                      ;        org     0x4000
<113,0>	00004000! 00 00 00 00 ;nule    dw      0, 0, 0, 0, 0
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
|         00 00 00 00
#
# Debug Data
#
.debug:
<!h72,0> <!h75,0> <!h78,0> <!h81,0> <!h84,0> <!h87,0> <!h91,0> <!h94,0> <!h97,0> <!h100,0> <!h103,0> <!h106,0> <!h113,0> 
#
#
# Assembling: OK