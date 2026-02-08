/*
 * IRF.h
 *
 *  Created on: Jul 3, 2024
 *      Author: sattia
 */

#ifndef IRF_H_
#define IRF_H_
#include <SPI.h>
#include <MFRC522.h>
#define DEF_BLOCK_FOR_WRITE_DATA    4
extern MFRC522::MIFARE_Key key;
extern MFRC522 mfrc522;  // Create MFRC522 instance.
extern MFRC522::StatusCode status; 
extern Memory_Control MEM_control;
extern unsigned long previousTime;
extern Result_values  resultt1;
extern Gpio_Oprations Gpio; 
extern byte trailerBuffer[];
extern MFRC522::MIFARE_Key key_read;

byte knownKeys[10][6] =  { 
    {0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5},
    {0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5},
    {0x4d, 0x3a, 0x99, 0xc3, 0x51, 0xdd}, 
    {0x1a, 0x98, 0x2c, 0x7e, 0x45, 0x9a},
    {0xaa, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5},
    {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff},
    {0xab, 0xac, 0xad, 0xae, 0xaf, 0xa5},
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
    {0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf},
    {0xaa, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5}
};



void ret_ucahr(unsigned long D_OUT,unsigned char *data)
{
	data[0] = D_OUT & 255;
	data[1] = (D_OUT>>8) & 255;
	data[2] = (D_OUT >> 16) & 255;
	data[3] = (D_OUT >> 32) & 255;
}

unsigned long ret_ulong(unsigned char *data)
{
	unsigned long D_OUT = data[0] + data[1] * 256 + data[2] * 65536 + data[3] * 16777216;
	return D_OUT;
} 





void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}



char read_block_tag(unsigned char number_block,byte* buffer_block,MFRC522::MIFARE_Key *key)
{
       byte sizeread=64;
       bool state_flag=0;
        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A,number_block,key,&(mfrc522.uid));
        if (status != MFRC522::STATUS_OK) 
        {
             
         mfrc522.PICC_HaltA();       // Halt PICC
         mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD    
         return -1;
        }
     #if TSTOP==YES
        Serial.println("OKKKEEET_HOVIAAT");
     #endif

      status=mfrc522.MIFARE_Read(number_block,buffer_block,&sizeread);
      if (status != MFRC522::STATUS_OK) {
          mfrc522.PICC_HaltA();       // Halt PICC
          mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
          return -1;
      }
      else{
         //mfrc522.PICC_HaltA();       // Halt PICC
         //mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
          return 0;
      }

  
}



char write_block_tag(unsigned char number_block,byte* buffer_block,MFRC522::MIFARE_Key key)
{
     
       byte sizeread=16;
       bool state_flag=0;
        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A,number_block,&key,&(mfrc522.uid));
        if (status == MFRC522::STATUS_OK) 
        {
          state_flag=1;
        }


      if(state_flag!=1)
      {
        return -1;
        mfrc522.PICC_HaltA();       // Halt PICC
        mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
      }
        Serial.println("OKKKEEET_HOVIAAT");

      status=mfrc522.MIFARE_Write(number_block,buffer_block,sizeread);
      if (status != MFRC522::STATUS_OK) {
          mfrc522.PICC_HaltA();       // Halt PICC
          mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
          return -1;
      }
      else{
           
      mfrc522.PICC_HaltA();       // Halt PICC
      mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
          return 0;
      }

  
}


char set_key_rfid_tag(unsigned char *key_for_write)
{

      bool state_flag=0;
      for (byte k = 0; k < 10; k++) 
      {
          // Copy the known key into the MIFARE_Key structure
          for (byte i = 0; i < 6; i++) {
              key.keyByte[i] = knownKeys[k][i];
          }
        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B,7, &key, &(mfrc522.uid));
        if (status == MFRC522::STATUS_OK) 
        {
          state_flag=1;
          break;
        }
        if ( ! mfrc522.PICC_IsNewCardPresent())
            break;
        if ( ! mfrc522.PICC_ReadCardSerial())
            break;
      }


      if(state_flag!=1)
      {
        return -1;
        mfrc522.PICC_HaltA();       // Halt PICC
        mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
      }
        Serial.println("OKKKEEET_HOVIAAT");

      status=mfrc522.MIFARE_Write(7,key_for_write, 16);
      if (status != MFRC522::STATUS_OK) {
          mfrc522.PICC_HaltA();       // Halt PICC
          mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
  
          return -1;
      }
      else{
           
      mfrc522.PICC_HaltA();       // Halt PICC
      mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
          return 0;
      }

  
}


void func_add_tag(unsigned char block_number,unsigned char* block_data,MFRC522::MIFARE_Key key)
{
   unsigned long led_time=0;
   if(resultt1.number_seting_opration==DEF_USER_ADD_USER){previousTime=millis();led_time=millis();}
   while(resultt1.number_seting_opration==DEF_USER_ADD_USER)
   {
     mfrc522.PCD_Init();
      Gpio.watch_dog_on();
     if(millis()>(led_time+1000))
        {
          led_time=millis();
          Gpio.blink_leds();
        }
        if(millis()>(previousTime+8000))
        {
          Gpio.buzzer_off();
          Gpio.red_off();
          Gpio.blue_off();
          resultt1.number_seting_opration=0;
          break;
        }
          
        if (mfrc522.PICC_IsNewCardPresent())
        {
            if (mfrc522.PICC_ReadCardSerial())
            {
              if(write_block_tag(block_number,block_data,key)==0)
              {
                Gpio.set_tag_okey();
                previousTime=millis();
                led_time=millis();
              }
              else{
                  Gpio.tag_not_autho();
              }
            }
        }
      }
   
}






























void setkey_start()
   {
   unsigned long led_time=0;
   if(resultt1.number_seting_opration==DEF_SET_ENCRYPTION_TAG){previousTime=millis();led_time=millis();}
   while(resultt1.number_seting_opration==DEF_SET_ENCRYPTION_TAG)
   {
     Gpio.watch_dog_on();

     mfrc522.PCD_Init();

     if(millis()>(led_time+1000))
        {
          led_time=millis();
          Gpio.test_all();
        }
        if(millis()>(previousTime+10000))
        {
          Gpio.buzzer_off();
          resultt1.number_seting_opration=0;
          break;
        }
          
        if (mfrc522.PICC_IsNewCardPresent())
        {
              if (mfrc522.PICC_ReadCardSerial())
              {
                if(set_key_rfid_tag(trailerBuffer)==0)
                {
                  Gpio.set_key_to_tag();
                  previousTime=millis();
                  led_time=millis();
                }
                else{
                Serial.println("ERORRRE_write_okeeey");
                }
              }
        }

  }
   
}











































#endif /* IRF_H_ */


