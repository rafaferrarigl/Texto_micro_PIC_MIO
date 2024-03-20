#include <16f877a.h>
#fuses HS,NOWDT
#use delay(clock=2M)
#use standard_io(D)
#BYTE OPTION_REG = 0x81

int Veces;


#INT_EXT

void ext_isr() {
   Veces++;
   
   
   if (Veces == 1){
      output_high(PIN_B1);
      output_low(PIN_B5);
   }
   else if(Veces == 2){
      output_high(PIN_B2);
      output_low(PIN_B1);
   }
   else if(Veces == 3){
      output_high(PIN_B3);
      output_low(PIN_B2);
   }
   else if(Veces == 4){
      output_high(PIN_B4);
      output_low(PIN_B3);
   }
   else if(Veces == 5){
      output_high(PIN_B5);
      output_low(PIN_B4);
      Veces = 0;
   }
   
   

}


void main()
{
   bit_clear(OPTION_REG, 7);  //Habilitacion PULL-UP
   enable_interrupts(int_ext);  //Habilitacio interrupciones externas 
   ext_int_edge(H_to_L);       //Interrupcion externa en RB0
   enable_interrupts(GLOBAL); //Habilitacio interrupciones Globales 

   while(TRUE)
   {
      
   }

}
