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
# Original file: Z:/home/tk/FER-stvari/arh1r/arm/paritet.a
#
#
<1,0>	                      ;        org     300
<2,0>	0000012C! F0 F0 F0 F0 ;stvari  dw      0xf0f0f0f0, 0x1000, 0x100000
|         00 10 00 00
|         00 00 10 00
<3,0>	                      ;
<4,0>	                      ;
<5,0>	                      ;start
<6,0>	00000138  10 10 1F E5 ;        ldr     r1, 304
<7,0>	0000013C  10 D0 1F E5 ;        ldr     sp, 308
<8,0>	00000140  02 00 2D E9 ;        stmfd   sp!, {r1}
<9,0>	00000144  01 00 00 EB ;        bl      obradi
<10,0>	00000148  04 D0 8D E2 ;        add     sp, sp, #4
<11,0>	                      ;
<12,0>	0000014C  56 34 12 EF ;kraj    swi     0x123456
<13,0>	                      ;        
<14,0>	                      ;
<15,0>	                      ;
<16,0>	                      ;obradi
<17,0>	00000150  07 00 2D E9 ;        stmfd   sp!, {r0, r1, r2}       ; spremanje konteksta
<18,0>	                      ;        
<19,0>	00000154  0C 10 9D E5 ;        ldr     r1, [sp, #12]   ; r1 - trenutni podatak
<20,0>	00000158  40 2F 81 E2 ;        add     r2, r1, #0x100  ; r2 - zadnji podatak
<21,0>	                      ;
<22,0>	                      ;ptlj_obr
<23,0>	                      ;
<24,0>	0000015C  04 20 91 E4 ;        ldr     r2, [r1], #4
<25,0>	                      ;
<26,0>	                      ;        
<27,0>	00000160  00 00 8F E5 ;        str     r0, podatak
<28,0>	00000164  07 00 00 EB ;        bl      paritet
<29,0>	00000168! 00 00 00 00 ;podatak dw      0
<30,0>	                      ;
<31,0>	0000016C  01 00 50 E3 ;        cmp     r0, #1
<32,0>	00000170  4C 00 1F 05 ;        ldreq   r0, 300
<33,0>	00000174  00 00 81 05 ;        streq   r0, [r1]
<34,0>	                      ;
<35,0>	00000178  02 00 51 E1 ;        cmp     r1, r2
<36,0>	0000017C  F6 FF FF 1A ;        bne     ptlj_obr
<37,0>	                      ;
<38,0>	                      ;
<39,0>	                      ;kraj_obr
<40,0>	00000180  07 00 BD E8 ;        ldmfd   sp!, {r0, r1, r2}
<41,0>	00000184  0E F0 A0 E1 ;        mov     pc, lr
<42,0>	                      ;
<43,0>	                      ;
<44,0>	                      ;paritet
<45,0>	00000188  06 00 2D E9 ;        stmfd   sp!, {r1, r2}   ; spremanje konteksta
<46,0>	0000018C  04 10 9E E4 ;        ldr     r1, [lr], #4    ; r1 - podatak kojem se provjeava paritet
<47,0>	00000190  00 00 A0 E3 ;        mov     r0, #0          ; r0 - paritet
<48,0>	                      ;
<49,0>	                      ;ptlj_par        ; registru r0 pribrajaju se jedinice iz r1, parnost zbroja također je i paritet r1
<50,0>	00000194  A1 10 B0 E1 ;        movs    r1, r1, lsr #1
<51,0>	00000198  00 00 A0 E2 ;        adc     r0, r0, #0
<52,0>	0000019C  00 00 51 E3 ;        cmp     r1, #0
<53,0>	000001A0  FB FF FF 1A ;        bne     ptlj_par
<54,0>	                      ;
<55,0>	                      ;kraj_par
<56,0>	000001A4  01 00 00 E2 ;        and     r0, r0, #1      ; n & 1 == n % 2
<57,0>	000001A8  06 00 BD E8 ;        ldmfd   sp!, {r1, r2}   ; obnova konteksta
<58,0>	                      ;        
<59,0>	                      ;
<60,0>	                      ;
<61,0>	                      ;
<62,0>	                      ;
#
# Debug Data
#
.debug:

#
#
# Assembling: OK