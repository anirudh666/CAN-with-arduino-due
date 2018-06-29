#include<due_can.h>
#include"variant.h"
CAN_FRAME msg;
void setup() 
{
  
  Serial.begin(9600);
  Serial.println("---- CAN Sender ----");
}

void sender()
{
  msg.id=0x5A1;
  msg.extended=LOW;
  msg.priority=LOW;
  msg.length=8;
  msg.rtr=LOW; 
  msg.data.byte[0]=0x0;
  msg.data.byte[1]=0x1;
  msg.data.byte[2]=0x2;
  msg.data.byte[3]=0x3;
  msg.data.byte[4]=0x4;
  msg.data.byte[5]=0x5;
  msg.data.byte[6]=0x6;
  msg.data.byte[7]=0x7;
}
void loop() 
{  
  Can0.begin(CAN_BPS_250K);
  sender();
  if(CAN.sendFrame(msg))
  Serial.println("Sent...........");
  else Serial.println("CAN Failed!!!!");
}

