#include <16f877a.h>
#device ADC = 10
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOLVP,BROWNOUT
#use delay(clock=20M)
#use standard_io(D)


#define LCD_DB4   PIN_D4         // Pines de la pantalla LCD
#define LCD_DB5   PIN_D5
#define LCD_DB6   PIN_D6
#define LCD_DB7   PIN_D7
#define LCD_RS    PIN_D2
#define LCD_E     PIN_D3
#include <LCD_16X2.c>            // Libreria para el manejo de la pantalla LCD


long valor_adc;
int valor_pwm;
int porcentaje;

void main()
{
   lcd_init();
   setup_timer_2(t2_div_by_16, 255, 1);
   setup_ccp1(ccp_pwm);
   setup_ccp2(ccp_pwm);
   setup_adc_ports(AN0);
   setup_adc(adc_clock_internal);
   set_pwm1_duty(0);                // Motor PIN_C2
   set_pwm2_duty(0);                // Led PIN_C1
   
   while(true)
   {
      set_adc_channel(0);
      delay_us(2);
      valor_adc = read_adc();
      valor_pwm = 255*valor_adc/1025;
      porcentaje = 100*valor_pwm/255
      set_pwm1_duty(valor_pwm);
      set_pwm2_duty(valor_pwm);
      
      lcd_gotoxy(1,1);
      printf(lcd_putc,"PWM: %u ",valor_pwm);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Porcentaje: %u%% "porcentaje);
      delay_ms(50);
   }
}
