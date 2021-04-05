/* ========================================
 *
 * zeysaklii@gmail.com , 2021
 * Open Source
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; 

    for(;;)
    {
       
        led_red_Write(!led_red_Read()); 
        CyDelay(500);
    }
}

/* [] END OF FILE */
