/* ========================================
 *
 * zeysaklii@gmail.com , 2021
 * Open Source
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        if (! sw_Read())
       {
        RED_Write(0u); /* set low */
       CyDelay(100);
       RED_Write(1u); /*set high */
       CyDelay(100);
       
       GREEN_Write(0u);
       CyDelay(100);
       GREEN_Write(1u);
       CyDelay(100);
    
       BLUE_Write(0u);
       CyDelay(100);
       BLUE_Write(1u);
       CyDelay(100);
    
       
     }
    }
}

/* [] END OF FILE */
