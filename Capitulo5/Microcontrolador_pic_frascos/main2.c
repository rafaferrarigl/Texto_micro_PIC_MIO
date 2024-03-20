#include <16f877.h>

#FUSES XT, NOWDT
#use delay(clock=2M)
#use standard_io(B)
#BYTE OPTION_REG = 0x81 //Declaracion PULL-UP

int Tiempo = 0;
float valor_adc;

#INT_EXT
void ext_isr(){
    output_low(PIN_B2);
    output_high(PIN_B3);
    Setup_timer_1 (T1_INTERNAL | T1_DIV_BY_8);   //Configuraci�n timer1
    set_timer1 (59286);                           //Carga del timer1 para 0,1 s
    enable_interrupts(INT_TIMER1);    // Enable timer1 interrupt
}

#INT_TIMER1
void TIMER1_isr(){
    set_timer1(59286);
    if Tiempo < 3{
        Tiempo++;
    }
    else{
        Tiempo = 0;
        valor_adc = read_adc();
        if(valor_adc = 1000){
            output_low(PIN_B3);
            output_high(PIN_B2);
            Setup_timer_1 (T1_DISABLED);

        }

    }
}



int main(){

    bit_clear(OPTION_REG, 7);  //Habilitacion PULL-UP
	enable_interrupts(int_ext);  //Habilitacio interrupciones externas 
	ext_int_edge(H_to_L);       //Interrupcion externa en RB0
	enable_interrupts(GLOBAL); //Habilitacio interrupciones Globales 

    output_low(PIN_B3);
    output_high(PIN_B2);
    	while(TRUE)
	{
		//TODO: User Code
	}

}