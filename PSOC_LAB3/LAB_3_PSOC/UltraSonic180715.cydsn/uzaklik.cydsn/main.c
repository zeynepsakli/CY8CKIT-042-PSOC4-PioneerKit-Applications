/* ========================================
 * HC-SR04 test program for CY8CKIT-044
 * For this appliation, VDD must be set to 5V
 * Set J9 Jumper to 3+2.
 * ========================================
*/
#include "project.h"
#include <stdio.h>

/* https://keisan.casio.jp/exec/system/1231998943 */
#define MACH    346.513     /* Mach 1.0 at 25.0 */

char str[128] ; /* print buffer */

void init_hardware(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Clock_12MHz_Start() ;
    UART_Start() ;
    Timer_Start() ;
}

/**
 * pulse_trigger
 * Generate 10us high pulse from trigger pin
 */
void pulse_trigger(void)
{
    Trigger_Write(1) ;
    CyDelayUs(10) ;
    Trigger_Write(0) ;
}

/**
 * measure_echo
 * Measure high pulse width of echo pin
 */
uint32_t measure_echo(void)
{
    uint32_t length ;
#if 0
    while(Echo_Read() == 0) ;
    Timer_WriteCounter(0) ;
    while(Echo_Read() != 0) ;
    length = Timer_ReadCounter() ;
    return( length ) ;    
#else
    Timer_Stop() ;
    Timer_WriteCounter(0) ;
    while(Echo_Read() == 0) ;
    Timer_Start() ;
    while(Echo_Read() != 0) ;
    Timer_Stop() ;
    length = Timer_ReadCounter() ;
    return( length ) ; 
#endif
}

/**
 * print_value
 * Calculate distance from the duration
 * Since the duration include both way of the trip
 * to get the distance, the real duration is the half 
 * of the duration.
 *
 * distance = duration * MACH(m/s) * 100(cm) / (2 * 12000000(Hz)) ;
 *
 */
void print_value(uint32_t duration)
{
    double distance = 0.0 ;
    
    distance = (double)(duration) * MACH / 240000.0 ;
    sprintf(str, "%d.%02dcm\n", (int)distance, (int)(100 * distance)%100) ;
    UART_UartPutString(str) ;
}

int main(void)
{
    uint32_t duration ;
    
    init_hardware() ;

    for(;;) {
        pulse_trigger() ;
        duration = measure_echo() ;
        print_value(duration) ;
        CyDelay(1000) ;
    }
}

/* [] END OF FILE */
