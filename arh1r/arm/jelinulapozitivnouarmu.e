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
# Original file: Z:/home/tk/FER-stvari/arh1r/arm/jelinulapozitivnouarmu.a
#
#
<1,0>	                      ;start
<2,0>	00000000  01 10 A0 E3 ;        mov     r1, #1
<3,0>	00000004  01 10 51 E2 ;        subs    r1, r1, #1
<4,0>	00000008  01 20 A0 E3 ;        mov     r2, #1
<5,0>	0000000C  EC 2F 8F 55 ;        strpl   r2, 0x1000
<6,0>	                      ;
<7,0>	                      ;        org     0x1000
<8,0>	00001000! 00 00 00 00 ;jeli    dw      0
#
# Debug Data
#
.debug:
<!h8,0> 
#
#
# Assembling: OK