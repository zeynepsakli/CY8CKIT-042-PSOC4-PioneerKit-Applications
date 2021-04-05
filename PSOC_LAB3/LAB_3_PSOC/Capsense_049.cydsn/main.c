
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; 
     
    CapSense_Start(); //Capsense modülü başlatılır.
    CapSense_InitializeAllBaselines();
    CapSense_ScanEnabledWidgets(); //tarama özelliği başlatılır
    
    PWM_Start(); //pwm sinyali başlatılır.
   

    for(;;)
    {
        
        if( CapSense_IsBusy()==0) //tarama tamamlandığında yani cap sense busy değilse
        { 
            //slider'ın pozisyonunu alır.
             uint16 value=CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS);
             //eğer ilgili pinlere dokunulmuyorsa 0xFFFF döndürür 
            if(value != 0xFFFF) //slider işlemi yapılıyorsa
            { 
                PWM_WriteCompare(value); //pwm sliderın konumuna göre 0 ile 100 arasında değişir.
                 CyDelay(50); //Led parlaklığının azaldığını daha rahat gözlemlemek için
            }
            CapSense_UpdateEnabledBaselines(); //yeni tarama olursa druumu günceller 
            CapSense_ScanEnabledWidgets(); //yeni tarama başlatılır
            
        
        
        }
       
    }
}

/* [] END OF FILE */
