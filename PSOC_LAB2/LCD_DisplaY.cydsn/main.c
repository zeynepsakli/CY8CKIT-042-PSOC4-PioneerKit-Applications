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
    CyGlobalIntEnable;
       LCD_A_Write(0); // Arka ışıklar için LCD  A pini low'da bırakılmıştır.
       LCD_K_Write(1); // Arka ışıklar için LCD K pini High'a çekilmiştir.
       LCD_Start();    // Eklenen LCD modülü başlatma komutu
       LCD_DisplayOn(); // Eklenen LCD modülünü açma komutu
    
    int j=2;            // LCD ekranda yazı gözükmesi için konum ayarları yapılmalıdır.
    for(;;)             
    {
        for(j=2; j<8; j++) //konum aralığı belirtilmiştir.
{

       LCD_Position(0,j); //döngüde j'ye göre soldan sağa kayan yazı konumu  belirleme
       LCD_PrintString("Zeynep"); //LCD'ye yazdırma fonksiyonu
       CyDelay(500); //500 ms bekleme fonksiyonu
       LCD_ClearDisplay(); // İşlem bitince LCD ekranı temizlenir.
       
}     j=6;        //Sağdan sola kayan yazının başladığı yer için tekrar konum ataması 
        for(j=6; j>1; j--) // döngüde sağdan sola kayan yazı için for döngüsü
{

       LCD_Position(0,j);   //Döngüde j'ye göre sağdan sola kayan yazı konumu belirleme
       LCD_PrintString("Zeynep"); //Kayan yazı LCD yazdırma komutu.
       CyDelay(500);
       LCD_ClearDisplay(); //Ekran, döngü bitince temizlenir.
       
} 
               /*************** COUNTER *****************************/

  /*  int i=0;             //for döngüsü için değişken tanımlanır.
       for(i=0;i<100;i++)  //0-99 değerleri için for döngüsü oluşturulur.
    {
       
        LCD_Position(1,0); //Yazı konumu belirlenir.
        LCD_PrintNumber(i); //LCD ekrana değişkenin değeri yazdırılır.
        
        
        CyDelay(1000); //Gecikme fonksiyonu ile ekrana geliş hızları düzenlenir.
    }
       */
       
       
    }
    
    }

