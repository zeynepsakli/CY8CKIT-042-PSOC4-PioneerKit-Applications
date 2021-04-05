/* ========================================
 *
 * zeysaklii@gmail.com, 2021
 * Open Source
 * 
 *
 * 
 * 
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_modul_Start();      // UART modülü başlatılır.
    UART_modul_UartPutString("Zeynep SAKLI");  //string ifade yazılır.
    
    for(;;)
    {
    
    }
    
}

/* [] END OF FILE */
