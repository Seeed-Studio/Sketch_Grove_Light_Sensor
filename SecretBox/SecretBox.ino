// demo of Grove Starter kit for LinkIt ONE
// Secret box
 
#include <LGSM.h>
 
char num[20] = "13425171053";           // your number write here
char text[100] = "Warning: Your box had been opened!!";    // what do you want to send
 
 
const int pinLight = A0;                // light sensor connect to A0
 
bool isLightInBox()
{
    return (analogRead(pinLight)<50);   // when get data less than 50, means light sensor was in box
}
 
void setup()
{
    Serial.begin(115200);
 
    while(!isLightInBox());             // until put in box
    delay(2000);
}
 
 
void loop()
{
    if(!isLightInBox())                 // box is open
    {
        Serial.println("box had been opened");
 
        while(!LSMS.ready())
        {
            delay(1000);
        }
 
        Serial.println("SIM ready for work!");
        LSMS.beginSMS(num);
        LSMS.print(text);
 
        if(LSMS.endSMS())
        {
            Serial.println("SMS is sent");
        }
        else
        {
            Serial.println("SMS send fail");
        }
 
        while(!isLightInBox());             // until put in box
        delay(2000);
    }
 
    delay(10);
}