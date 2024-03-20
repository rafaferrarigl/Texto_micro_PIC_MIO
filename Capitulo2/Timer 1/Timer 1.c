#include <16f877a.h>
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOLVP,BROWNOUT
#use delay(clock=20M)
#use standard_io(B)

#INT_TIMER1
void timer1_interrupcion()
{
   output_toggle(PIN_B0);
   set_timer1(3036);
}

void main()
{
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   set_timer1(3036);
   output_high(PIN_B0);
   
   while(true)
   {
      
   }
}
