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

    for(;;)
    {
       LED_Red_Write( buton_Read());
    }
}

/* [] END OF FILE */
