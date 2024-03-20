#include <16f877.h>

#FUSES XT, NOWDT
#use delay(clock=2M)
#use standard_io(B)
#BYTE OPTION_REG = 0x81 //Declaracion PULL-UP



#INT_EXT
void ext_isr() {
	while(TRUE){
		output_low(PIN_B1);
		output_high(PIN_B2);
	}
}

void main()
{   
	bit_clear(OPTION_REG, 7);  //Habilitacion PULL-UP
	enable_interrupts(int_ext);  //Habilitacio interrupciones externas 
	ext_int_edge(H_to_L);       //Interrupcion externa en RB0
	enable_interrupts(GLOBAL); //Habilitacio interrupciones Globales 

	output_low(PIN_B2); //Que este apagado el led en RB2
	
	while(TRUE)
	{
		
		output_high(PIN_B1); //Que este encendido el led en RB1 siempre
	}

}  