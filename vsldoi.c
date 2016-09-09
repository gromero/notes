#include <altivec.h>

int main() { asm (
/*
                  "vxor  5, 5, 5      \n\t"
                  "lis   3,    0x5555 \n\t"
                  "ori   3, 3, 0x5555 \n\t"
                  "sldi  3, 3, 32     \n\t"
                  "oris  3, 3, 0x5555 \n\t"
                  "ori   3, 3, 0x5555 \n\t"
                  "mtvrd 4, 3         \n\t"
                  "vsldoi 6, 4, 5, 4  \n\t"
*/
//                "vsldoi 6, 5, 4, 8  \nt"    
              
                  // Load r3 with zebra bits.
"                  lis  3, 0x5555     \n\t"
"                  ori  3, 3, 0x5555  \n\t"
"                  sldi 3, 3, 32      \n\t"
"                  oris 3, 3, 0x5555  \n\t"
"                  ori  3, 3, 0x5555  \n\t"
                 
                  // Load r4 with just 1s.
"                  lis  4, 0xFFFF     \n\t"
"                  ori  4, 4, 0xFFFF  \n\t"
"                  sldi 4, 4, 32      \n\t"
"                  oris 4, 4, 0xFFFF  \n\t"
"                  ori  4, 4, 0xFFFF  \n\t"

"                  mtvsrd 3, 3       \n\t"
"                  mtvsrd 4, 4       \n\t"
                  
                  // VR0 = 0x5555555555555555555FFFFFFFFFFFFFFFF.
"                  xxmrghd 32, 3, 4  \n\t"
                   
                  // VR1 = 0x0. 
"                  vxor 1, 1, 1  \n\t"
 
                  // VR2 = ? 
"                  vsldoi 2, 1, 0, 8 \n\t"


                  /***********************/

                  // Load r3 with zebra bits.
"		  lis  3, 0x5555     \n\t"
"                  ori  3, 3, 0x5555  \n\t"
"                  sldi 3, 3, 32      \n\t"
"                  oris 3, 3, 0x5555  \n\t"
"                  ori  3, 3, 0x5555  \n\t"
                 
                  // Load r4 with just 1s.
"                  lis  4, 0xFFFF     \n\t"
"                  ori  4, 4, 0xFFFF  \n\t"
"                  sldi 4, 4, 32      \n\t"
"                  oris 4, 4, 0xFFFF  \n\t"
"                  ori  4, 4, 0xFFFF  \n\t"

"                  mtvsrd 3, 3       \n\t"
"                  mtvsrd 4, 4       \n\t"
                  
                  // VR0 = 0x5555555555555555555FFFFFFFFFFFFFFFF.
"                  xxmrghd 32, 3, 4  \n\t"
                   
                  // VR1 = 0x0. 
"                  vxor 1, 1, 1  \n\t"
 
                  // VR2 = ? 
"                  vsldoi 2, 0, 1, 4 \n\t"
                 );


}
