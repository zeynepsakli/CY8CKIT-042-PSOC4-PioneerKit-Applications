/* ========================================
 *
 * Copyleft by Shahariar,2015
 * All Rights Released
 * OPEN SOFTWARE, NO WARRENTY 
 *
 * DODGY BROTHERS C CODING Inc.  
 * Programmed With No Style, BUG may appear in Future !!!
 * Non-Precision Soft-Only Clock, will Lose around 12 sec a day, ( may vary for other PSoC chips)
 * ========================================
*/

// flag variable is a volatile global variable to check interrupt

#include <project.h>
volatile int flag=0; 
volatile int press_detect=1;

// Initial time ,set  here
int sec =05;
int minu =26;
int hr = 8;
int am_pm_flag=1; //  1 for PM , 0 for AM
void update_time(void);

int main()

{
// Start Timer
    TCPWM_1_Start();
// Enable Global Interrupt and start ISR  
    CyGlobalIntEnable; 
    ISR_Start();
    SetTime_ISR_Start();
// ISR code is in the ISR.c file
    
//  Supply 5 Vdd to LCD display from MCU and Power Up Back Light  
    Power_Up_LCD_Pin_1_Write(1); // PSoC Pin 2.0 to LCD Vdd
    Back_Light_On_N_Write(0);    // PSoC Pin 3.6 to LDC K (BackLight -Ve)
    Back_Light_On_P_Write(1);    // PSoC Pin 3.5 to LDC A (BackLight +Ve)
    
    // Vss to PSoC Gnd

// Start LCD display    
    LCD_Char_Start();
    LCD_Char_DisplayOn();
    LCD_Char_Position(0,0);
    LCD_Char_PrintString(" PSoC  Software ");
    LCD_Char_Position(1,0);
    LCD_Char_PrintString("Clock");
    LCD_Char_Position(1,14);
    LCD_Char_PrintString("PM");
             
        for(;;)
        {
            // turns off the CPU, saves about 30% (from 10.6 mA to 7.6 mA)
            // wakes up on next timer interrupt
            CySysPmSleep();    
         
// On-kit Switch (Pin 0.7 SW1-Interrupt driven) to increment time 5 minutes        
            if(press_detect==0)
        {
            minu=minu+5;
            update_time();
            CyDelay(50);
            press_detect=1;
        }
            //  clock update code section, executes after interrupt 
            if (flag==1)
            {
                flag=0;
                sec++;
                
        
            
                if (sec>=60)
                {
                sec=0;
                minu++;
                update_time();
                }
                
                //LCD_Char_ClearDisplay();
                
                
            }
            
        
                LED_Write(1);            
         
                LCD_Char_Position(1,6);
                LCD_Char_PrintString("        ");
                LCD_Char_Position(1,6);
                LCD_Char_PrintNumber(hr);
                LCD_Char_PrintString(":");
                LCD_Char_PrintNumber(minu);
                LCD_Char_PrintString(":");
                LCD_Char_PrintNumber(sec);
        
                CyDelay(10);
                
                LED_Write(0);
            
                
                
        
                // turns off the CPU, saves about 30% (from 10.6 mA to 7.6 mA)
                // wakes up on next timer interrupt
            
            
            }
        
       // return 0;
}
          
void update_time(void)
{
     if (minu>=60)
                {
                    minu=0;
                    hr++;
                    if (hr>12)
                       {hr=1;}
                    if (hr==12 && minu==0)
                       {am_pm_flag=am_pm_flag^1;
                                
        if(am_pm_flag==0)
        {
            LCD_Char_Position(1,14);
           LCD_Char_PrintString("AM");
        }
        else
        {
            LCD_Char_Position(1,14);
           LCD_Char_PrintString("PM");
        
        }
                    
                    
                        }
}
}
/* [] END OF FILE */