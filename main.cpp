#include "mbed.h"
#include "LM75B.h"
#include "C12832.h"


LM75B temp_sensor(p28,p27);
C12832 lcd(p5, p7, p6, p8, p11);
DigitalIn motionsensor(p21); //internal pull up 
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main (){

  
    

    lcd.cls();
    lcd.locate(0,3);
     while(1) 
    {   lcd.locate(0,15);
        lcd.printf("Temperature: %.2f Degrees",temp_sensor.read());
        if(motionsensor == 1) {        
            led4=1;
        
         }
        else if(motionsensor == 0) {
            led4=0;  
                      
         }       
        
        float temperature = temp_sensor.read();
        
        if (led4=1 && temperature <= 18.0)        
         {
            led1 = 1; 
            wait(0.5);
            led1 = 0; 
            wait(0.5);
            lcd.printf("\nHeating system on");
          }
        // turns LED1 on air conditioning heating system on
        
        else if (led4=1 && temperature > 18 && temperature <= 24) 
         {
            led2 = 1;
            wait(0.5); 
            led2 = 0;
            wait(0.5);
            lcd.printf("\nsystem off");            
        }
        // turns LED2 on air conditioning system off           
        else if (motionsensor == 1 && temperature > 24.0)         
        {            
            led3 = 1;;
            wait(0.5);
            led3 = 0;;
            wait(0.5);
            lcd.printf("\nCooling system on");           
        }         
        else if(motionsensor == 0){
            lcd.printf("\nSystem off");
            } 
        }
        
    }
        



 
 
 
    

       
    
   
 