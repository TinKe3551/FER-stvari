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
# Original file: Z:/home/tk/FER-stvari/arh1r/arm/test.a
#
#
<1,0>	                      ;main
<2,0>	00000000  F8 10 9F E5 ;        ldr     r1, stvar
<3,0>	00000004  F4 11 8F E5 ;        str     r1, stvar2
<4,0>	                      ;end
<5,0>	00000008  56 34 12 EF ;        swi     0x123456
<6,0>	                      ;
<7,0>	                      ;
<8,0>	                      ;        org     0x100
<9,0>	00000100! 50          ;stvar   db      0x50
<10,0>	                      ;
<11,0>	                      ;
<12,0>	                      ;        org     0x200
<13,0>	00000200! 00 00 00 00 ;stvar2  dw      0
#
# Debug Data
#
.debug:
<!h9,0> <!h13,0> 
#
#
# Assembling: OK