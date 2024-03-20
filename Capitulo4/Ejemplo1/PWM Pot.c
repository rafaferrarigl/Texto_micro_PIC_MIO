#include <16f877a.h>
#device ADC = 10
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOLVP,BROWNOUT
#use delay(clock=20M)


long valor_adc;
int valor_pwm;

void main()
{
   setup_timer_2(t2_div_by_16, 255, 1);         // Configura timer 2
   setup_ccp1(ccp_pwm);                         // Configura modulo CCP1 como pwm
   setup_adc_ports(AN0);                        // ADC canal 0
   setup_adc(adc_clock_internal);               // Reloj interno para conversion del ADC
   set_pwm1_duty(0);                            // Inicia el pwm 1 en 0
   
   while(true)
   {
      set_adc_channel(0);
      delay_us(2);
      valor_adc = read_adc();
      valor_pwm = 255*valor_adc/1025;
      set_pwm1_duty(valor_pwm);
   }
}
