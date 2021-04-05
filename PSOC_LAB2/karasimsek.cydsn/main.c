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
    CyGlobalIntEnable; //Genel Kesme

int led_deger = 0; //Başlangıçta lede değer atanır.
        while(1)   //sonsuz döngü
        {
 
      
if(led_deger>13)      //led 13ten büyük olunca ledi sıfırlar.
led_deger = 0;

  switch(led_deger)
  {
  case 0:             //led degeri sıfır ise ilk ledi yakar söndürür.
	  A1_Write(1u);   //logic high ledi yakar (initial state lowda baslangicta)
    CyDelay(1000);   //500 ms aralık bekleme
	  A1_Write(0u);  //low'a çeker söndürür
	  break;
  case 1:       //led değeri bir ise ikinci ledi yakar söndürür.
       A2_Write(1u);
        CyDelay(200);
       A2_Write(0u);
	  break;
  case 2:       //led değeri iki ise üçüncü ledi yakar söndürür.
       A3_Write(1u);
       CyDelay(200);
       A3_Write(0u);
	  break;
  case 3:
       A4_Write(1u); 
         CyDelay(200);
       A4_Write(0u);
	  break;
  case 4:
       A5_Write(1u);
         CyDelay(200);
       A5_Write(0u);
	  break;
  case 5:
       A6_Write(1u);
        CyDelay(200);
       A6_Write(0u);
	  break;
  case 6:
     A7_Write(1u);
        CyDelay(200);
       A7_Write(0u);
	  break;
  case 7:
      A8_Write(1u);  //led değeri yedi ise sekizinci ledi yakar söndürür.
       CyDelay(200);
       A8_Write(0u);
	  break;
     case 8:
	  A7_Write(1u);  // Tersten yakma işlemine geçer 7. ledi yakar söndürür.
    CyDelay(200);
	  A7_Write(0u);
	  break;
  case 9:
       A6_Write(1u);  // LEd değeri 9 ise 6. ledi yakar söndürür
        CyDelay(200);
       A6_Write(0u);
	  break;
  case 10:
       A5_Write(1u);
       CyDelay(200);
       A5_Write(0u);
	  break;
  case 11:
       A4_Write(1u);
         CyDelay(200);
       A4_Write(0u);
	  break;
  case 12:
       A3_Write(1u);
         CyDelay(200);
       A3_Write(0u);
	  break;
  case 13: 
//Led koşul ifadesini geçmeden en son 1. led yanar söner ve led değeri 14 olmadan döngüde sıfırlanır.
       A2_Write(1u);  
        CyDelay(200);
       A2_Write(0u);
	  break;
    
    
    
  }
   led_deger++;  //döngüde led değeri bir arttırılır.
 }
}
      
        

