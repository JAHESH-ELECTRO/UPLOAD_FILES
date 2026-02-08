
#include <Arduino.h>
#include "Gpio_Oprations.h"

Gpio_Oprations::Gpio_Oprations()
{

}

void Gpio_Oprations::Gpio_init(char red_led,char blue_led,char buzzer,char relay,char mrfc522_reset,char watch_dog)
{
  this->gpio_red=red_led;this->gpio_blue=blue_led;this->buzzer=buzzer;
  this->relay_=relay;
  this->reset_pin=mrfc522_reset;
  this->watch_dog_=watch_dog;
  //pinMode(red_led,OUTPUT);
  pinMode(blue_led,OUTPUT);
  //pinMode(buzzer,OUTPUT);
  pinMode(relay,OUTPUT);
}



void Gpio_Oprations::test_all()
{
  digitalWrite(gpio_red,!digitalRead(gpio_red));
  digitalWrite(gpio_blue,!digitalRead(gpio_blue));
  digitalWrite(buzzer,!digitalRead(buzzer));
}

void Gpio_Oprations::set_key_to_tag()
{
  digitalWrite(gpio_red,HIGH);
  digitalWrite(gpio_blue,LOW);  //ON LED BLUE 
  digitalWrite(buzzer,LOW);
  for(int i=0;i<20;i++)
  {
    digitalWrite(buzzer,!digitalRead(buzzer));
    delay(50);
  }
}

void Gpio_Oprations::blink_leds()
{
 //digitalWrite(gpio_red,!digitalRead(gpio_red));
 digitalWrite(gpio_blue,!digitalRead(gpio_blue));

}


void Gpio_Oprations::set_tag_okey()
{
  //this->red_off();
  this->blue_on();
  //this->buzzer_on();
  delay(1000);
 // this->red_off();
  this->blue_off();
//  this->buzzer_off(); 

}


void Gpio_Oprations::tag_not_autho()
{
  this->red_on();
  this->blue_off();
  this->buzzer_on();
  
  delay(1000);
  
  this->red_off();
  this->blue_off();
  this->buzzer_off(); 

}

void Gpio_Oprations::Okeyy()
{
  this->blue_off();
  delay(200);
  this->blue_on();
  delay(200);
  this->blue_off();
  delay(200);
  this->blue_on();
}


void Gpio_Oprations::Erorr()
{
  this->blue_off();
  delay(200);
  this->blue_on();
  delay(200);
  this->blue_off();
  delay(200);
  this->blue_on();
  delay(200);
  this->blue_off();
  delay(200);
  this->blue_on();
}




void Gpio_Oprations::Okeyy_recive()
{


  for(int i=0;i<2;i++)
  { 
    this->blue_on();
 //   this->red_off();
 //   this->buzzer_on();
    delay(70);
 //   this->buzzer_off();
    this->blue_off();
    delay(70);
  }
  this->blue_on();
  //this->red_off();
  //this->buzzer_off();
}


void Gpio_Oprations::Erorr_access()
{
  
  for(int i=0;i<3;i++)
  {
     this->blue_off();
     this->red_on();
    this->buzzer_on();
    delay(70);
     this->red_off();
    this->buzzer_off();
    delay(70);
  }
    this->blue_off();
    this->buzzer_off();
}








  void Gpio_Oprations::red_on()
  {
     digitalWrite(RED_LED,LOW);
  }
  void Gpio_Oprations::red_off()
  {
     digitalWrite(RED_LED,HIGH);
  }  

 void Gpio_Oprations::blue_on()
  {
     digitalWrite(BLUE_LED,HIGH);
  }

  void Gpio_Oprations::blue_off()
  {
     digitalWrite(BLUE_LED,LOW);
  }  
  void Gpio_Oprations::buzzer_on()
  {
    // digitalWrite(BUZZER,HIGH);
  }
  void Gpio_Oprations::buzzer_off()
  {
   // digitalWrite(BUZZER,LOW);
  }  

  void Gpio_Oprations::relay_on()
  {
     digitalWrite(RELAY,HIGH);
  }
  void Gpio_Oprations::relay_off()
  {
     digitalWrite(RELAY,LOW);
  }  





 void Gpio_Oprations::reset_mrfc522()
 {
   // digitalWrite(reset_pin,LOW);
    //delay(50);
    //digitalWrite(reset_pin,HIGH);
 }



void Gpio_Oprations::watch_dog_on()
{
  pinMode(watch_dog_,INPUT);
  //digitalWrite(watch_dog_,LOW);
  pinMode(watch_dog_,OUTPUT);
  digitalWrite(watch_dog_,LOW);
}





Gpio_Oprations::~Gpio_Oprations()
{
}
