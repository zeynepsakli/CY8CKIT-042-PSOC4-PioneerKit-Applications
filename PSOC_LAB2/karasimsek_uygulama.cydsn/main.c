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

const int dizi[16]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
//Her bir ledi tanımlamak için binary olarak sayı dizisi oluşturuldu. 

int main(void)
{
    CyGlobalIntEnable; //Genel Kesme
    
    int i;   //Degisken Tanımlandı
    
    for(;;)
    {
        for(i=0;i<16;i++) //LEdleri sırayla yakmak için for döngüsü
        {
          Ledler_Write(dizi[i]);  //Dizi elemanları sırayla çağırılarak Ledler yanar
          CyDelay(200);    // 200 ms aralıklarla bekleme fonksiyonu
        }
    }
}
