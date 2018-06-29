#include<variant.h>
#include<due_can.h>
void setup() 
{
   Serial.begin(9600);

    Serial.println("---CAN Receiver---");
    
}
void loop()
{ CAN_FRAME msg;
  Can0.begin(CAN_BPS_250K);
 //Can0.watchFor(0x5A1);
  while(Can0.available()==0);
  Can0.read(msg);
  Serial.println(msg.id);
  Serial.println(msg.data.byte[0]);
  Serial.println(msg.data.byte[1]);
  Serial.println(msg.data.byte[2]);
  Serial.println(msg.data.byte[3]);
  Serial.println(msg.data.byte[4]);
  Serial.println(msg.data.byte[5]);
 Serial.println(msg.data.byte[6]);
  Serial.println(msg.data.byte[7]);
 
  delay(1000);
}

