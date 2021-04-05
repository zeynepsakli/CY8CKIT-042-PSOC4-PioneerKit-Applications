
#include "project.h"

void delay ()   //gecikme fonksiyonu
{
    int a;
    for(a=0;a<1000;a++)
    { 
    }
}
// Kayan yazı için satir sütün için dizi ataması
unsigned int sutun[8]={0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE};
unsigned int satir[8]={0x00,0x7E,0x40,0x40,0x40,0x00,0x00,0x00};
int main(void)
{
    CyGlobalIntEnable; 

       int i,j;

    for(;;) //sonsuz döngü içerisinde satir ve sütünların basılması
    {
        for(j=1;j<8;j++)
        {
           for(i=0;j<8;i++)        
        {
            Pin_1_Write(satir[i]);
            Pin_2_Write(sutun[i]);
            delay();
        
        }
        }
        
    }
}


