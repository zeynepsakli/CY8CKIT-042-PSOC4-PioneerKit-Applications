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
   

    // 0'dan 9'a kadar sayması için pinleri yakacak dizi oluşturuldu.
    const char dizi[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};
int main(void)
{
    CyGlobalIntEnable; //Genel Kesme
   int i;     //for döngüsü için değişken atandı
    for(;;)   
    {   for(i=0;i<10;i++)  // i değişkeni 10dan küçük olana kadar dönecek
    {
        Segment_disp_Write(dizi[i]);   // Seven segmentte ledleri yakacak komut
        CyDelay(500);             //Akışı görmek adına 500 ms bekleme komutu
         
    }
}
}
/* [] END OF FILE */
