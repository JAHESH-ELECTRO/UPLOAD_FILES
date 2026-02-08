
#include "Memory_Control.h"

Memory_Control::Memory_Control()
{
      EEPROM.begin(10000);
}
 //EDITE__10/31/2024
void Memory_Control::writeToEEPROM(int address, unsigned char value) {
    // اطمینان از اینکه آدرس معتبر است
    if (address >= 0 && address < EEPROM.length()) {
        EEPROM.write(address, value);
        EEPROM.commit(); // ذخیره تغییرات
    }
}

unsigned char Memory_Control::readFromEEPROM(int address) {
    // اطمینان از اینکه آدرس معتبر است
    if (address >= 0 && address < EEPROM.length()) {
        return (unsigned char)EEPROM.read(address);
    }
    return 0; // در صورت آدرس نامعتبر، مقدار پیش‌فرض
}

void Memory_Control::tst_eeprom()
{
    //Serial.begin(115200);
    for(int i=0;i<10;i++)
    {
     writeToEEPROM(i, 'A');
    }
    delay(3000);
      for(int i=0;i<10;i++)
    {
      Serial.println((char)readFromEEPROM(i));
    }

}
//************************WIFI_NAME*********************************
void Memory_Control::Get_wifi_name(unsigned char* wifi_name_)
{
 for(int i=DEF_MEMORY_START_GET_NAME_WIFI;i<DEF_MEMORY_SIZE_GET_NAME_WIFI;i++)
 {
    wifi_name_[i-DEF_MEMORY_START_GET_NAME_WIFI]=readFromEEPROM(i);
 }
 writeToEEPROM(9,'\0');
}

void Memory_Control::Set_wifi_name(unsigned char* wifi_name_)
{
  delay(10);
 for(int i=DEF_MEMORY_START_GET_NAME_WIFI;i<DEF_MEMORY_SIZE_GET_NAME_WIFI;i++)
 {
  writeToEEPROM(i,0);
 }


 for(int i=DEF_MEMORY_START_GET_NAME_WIFI;i<DEF_MEMORY_SIZE_GET_NAME_WIFI;i++)
 {
  writeToEEPROM(i, wifi_name_[i-DEF_MEMORY_START_GET_NAME_WIFI]);
 }
     writeToEEPROM(9,'\0');
 delay(10);
}
//************************Get_wifi_pass***********************************************
  unsigned long  Memory_Control::Get_wifi_pass()
  {
      unsigned char temp[5]={0};
     for(int i=DEF_MEMORY_START_WIFI_PASS;i<DEF_MEMORY_SIZE_WIFI_PASS;i++)
      {
        temp[i-DEF_MEMORY_START_WIFI_PASS]=readFromEEPROM(i);
      }
   return this->ret_ulong(temp);
    
  };





 char  Memory_Control::Set_wifi_pass(unsigned long wifi_pass)
  {
    delay(50);
      unsigned char temp[5]={0};
      this->ret_ucahr(wifi_pass,temp);

     for(int i=DEF_MEMORY_START_WIFI_PASS;i<DEF_MEMORY_SIZE_WIFI_PASS;i++)
      {
        writeToEEPROM(i, temp[i-DEF_MEMORY_START_WIFI_PASS]);

      }
      delay(50);
    return 0;
  };


//***************************Get_admin_pass***************************************

 unsigned long Memory_Control::Get_admin_pass()
 {
  unsigned char temp[5]={0};
     for(int i=DEF_MEMORY_START_ADMIN_PASS;i<DEF_MEMORY_SIZE_ADMIN_PASS;i++)
      {
        temp[i-DEF_MEMORY_START_ADMIN_PASS]=readFromEEPROM(i);
      }
   return this->ret_ulong(temp);
    
 }

 char Memory_Control::Set_admin_pass(unsigned long admin_pass) 
 {
   delay(1);
  unsigned char temp[5]={0};
  
  this->ret_ucahr(admin_pass,temp);

     for(int i=DEF_MEMORY_START_ADMIN_PASS;i<DEF_MEMORY_SIZE_ADMIN_PASS;i++)
      {
        writeToEEPROM(i, temp[i-DEF_MEMORY_START_ADMIN_PASS]);

      }
      delay(1);
    return 0;
 }
 //**********************************************//////
 void Memory_Control::Get_forward_to_set_key_pass(unsigned char *buf_forward)
 {

    /////////فعلا نیازی نیست 
  
 }
//******************************Get_max_limit*****************************
  unsigned long Memory_Control::Get_max_limit()
  {
    unsigned char temp[5]={0};
     for(int i=DEF_MEMORY_START_MAX_LIMIT;i<DEF_MEMORY_SIZE_MAX_LIMIT;i++)
      {
          temp[i-DEF_MEMORY_START_MAX_LIMIT]=readFromEEPROM(i);
      }
     return this->ret_ulong(temp);
    
  }

 char Memory_Control::Set_max_limit( unsigned long max_limit)
  {
    delay(1);
     unsigned char temp[5]={0};
     this->ret_ucahr(max_limit,temp);
     for(int i=DEF_MEMORY_START_MAX_LIMIT;i<DEF_MEMORY_SIZE_MAX_LIMIT;i++)
      {
        writeToEEPROM(i, temp[i-DEF_MEMORY_START_MAX_LIMIT]);
      }
      delay(1);
          return 0;
  }

  //************************Get_min_limit***************************************
  unsigned long Memory_Control::Get_min_limit()
  {
    unsigned char temp[5]={0};
     for(int i=DEF_MEMORY_START_MIN_LIMIT;i<DEF_MEMORY_SIZE_MIN_LIMIT;i++)
      {
          temp[i-DEF_MEMORY_START_MIN_LIMIT]=readFromEEPROM(i);
      }
     return this->ret_ulong(temp);
  }


 char Memory_Control::Set_min_limit(unsigned long min_limit)
  {
    delay(1);
     unsigned char temp[5]={0};
     this->ret_ucahr(min_limit,temp);
     for(int i=DEF_MEMORY_START_MIN_LIMIT;i<DEF_MEMORY_SIZE_MIN_LIMIT;i++)
      {
        writeToEEPROM(i, temp[i-DEF_MEMORY_START_MIN_LIMIT]);
      }
      delay(1);
          return 0;
  }

//***********************Get_relay_time***********************************

 unsigned char  Memory_Control::Get_relay_time()
 {

    return readFromEEPROM(DEF_MEMORY_START_RELAY_TIME);

 }

 char  Memory_Control::Set_relay_time(unsigned char relay_time)
 {
      delay(1);
     writeToEEPROM(DEF_MEMORY_START_RELAY_TIME,relay_time);     
      delay(1);
      return 0;
 }

//******************************************
unsigned long  Memory_Control::Get_serial_number()
{
   unsigned char temp[5]={0};
     for(int i=DEF_MEMORY_START_DEVICE_SERIAL;i<DEF_MEMORY_SIZE_DEVICE_SERIAL;i++)
      {
          temp[i-DEF_MEMORY_START_DEVICE_SERIAL]=readFromEEPROM(i);
      }
     return this->ret_ulong(temp);
}

char Memory_Control::Set_serial_number(unsigned long serial_number)
{ delay(1);
   unsigned char temp[5]={0};
   this->ret_ucahr(serial_number,temp);//تبدیل لانگ به بایت 
     for(int i=DEF_MEMORY_START_DEVICE_SERIAL;i<DEF_MEMORY_SIZE_DEVICE_SERIAL;i++)
       {
        writeToEEPROM(i, temp[i-DEF_MEMORY_START_DEVICE_SERIAL]);      
        }
  delay(1);
     return 0;
}
//*************************USERS_OPRTION*****************************************************************


  char Memory_Control::Get_user(unsigned int group_number,User &out_user_data)
  {
  out_user_data.number_switch= readFromEEPROM((100+(group_number*3))+SET_USER_NUMBER_SWITCH);
  out_user_data.delate_counter=readFromEEPROM((100+(group_number*3))+SET_USER_DELETE_COUNTER);
  out_user_data.state_access=readFromEEPROM((100+(group_number*3))+SET_STATE_ACCCESS);
      return 0;
  }
  char Memory_Control::Set_user(unsigned int group_number,ENUM_OP_USER  OP_USER,unsigned char valu_set)
  {  
    delay(1);
     writeToEEPROM((100+(group_number*3))+OP_USER,valu_set);
    delay(1);
    return 0;
  }






void Memory_Control::ret_ucahr(unsigned long D_OUT,unsigned char *data)
{
	data[0] = D_OUT & 255;
	data[1] = (D_OUT>>8) & 255;
	data[2] = (D_OUT >> 16) & 255;
	data[3] = (D_OUT >> 32) & 255;
}

unsigned long Memory_Control::ret_ulong(unsigned char *data)
{
	unsigned long D_OUT = data[0] + data[1] * 256 + data[2] * 65536 + data[3] * 16777216;
	return D_OUT;
} 

unsigned short int Memory_Control::ret_uint16(unsigned char *data)
{
  return data[0] + data[1] * 256;
}

 void Memory_Control::ret_uint16tochar(unsigned short int inpute,unsigned char *data)
{
	data[0] = inpute & 255;
	data[1] = (inpute>>8) & 255;
}


///////////LSB__MSB//بایت کوچیکترLSB

void Memory_Control::print_saved_data()
{
   Serial.println();
   Serial.print("ADMIN_PASS::");
   Serial.println(this->Get_admin_pass()); 


   Serial.println();
   Serial.print("WIFI_NAME::");
   unsigned char temp[15];
   Get_wifi_name(temp);
   
   Serial.println((char*)temp); 

   Serial.println();
   Serial.print("WIFI_PASS::");
   Serial.println(this->Get_wifi_pass());

   Serial.println();
   Serial.print("MIN_LIMIT::");
   Serial.println(this->Get_min_limit());
   
   Serial.println();
   Serial.print("MAX_LIMIT::");
   Serial.println(this->Get_max_limit());

   Serial.println();
   Serial.print("RELAY_TIME::");
   Serial.println(this->Get_relay_time());
//////////
   
   Serial.println();
   Serial.print("SERIAL_NUMBER::");
   Serial.println(this->Get_serial_number());

//////////////

   Serial.println();
   Serial.print("SERIAL_NUMBER::");
   User T_U1;
   Get_user(20,T_U1);
   Serial.printf("GROUP_NUMBBER:20___NUMBER_SWITCH:%d___DELETE_COUNTER::%d____STATE_ACCESS:%d",T_U1.number_switch,T_U1.delate_counter,T_U1.state_access);



}

char Memory_Control::print_user_data(unsigned int group_number)
{
User T_U1;
this->Get_user(group_number,T_U1);
Serial.printf("(EEPROM)  GROUP_NUMBBER:%d_NUMBER_SWITCH:%d_DELETE_COUNTER::%d_STATE_ACCESS:%d\r\n",group_number,T_U1.number_switch,T_U1.delate_counter,T_U1.state_access);
return 0;
}

char Memory_Control::clear_recorded(unsigned int group_number)
{
User T_U1;
//this->Get_user(group_number,T_U1);
this->Set_user(group_number,SET_STATE_ACCCESS,1);
this->Set_user(group_number,SET_USER_DELETE_COUNTER,1);
this->Set_user(group_number,SET_USER_NUMBER_SWITCH,0);

return 0;
}

void Memory_Control::set_defults()
{
    Serial.print("WHITE_FOR_RESET_OKEEEY");
    if(readFromEEPROM(60)>0)
    {
      for(int i=62;i<110;i++)
      {


        writeToEEPROM(i,0);
         Serial.println(i);
      }
      for(int i=0;i<1000;i++)//اصلاح شد 
      {
        clear_recorded(i);
        Serial.println(i);
      }
      this->Set_wifi_name((unsigned char *)"12345");
      this->Set_wifi_pass(12345);
      this->Set_admin_pass(123456);
      this->Set_serial_number(12345);
      this->Set_max_limit(999);
      this->Set_min_limit(0);
      this->Set_relay_time(1);

    writeToEEPROM(60,0);
 }
  Serial.print("SET_DEFULT_OKEEEY");

}
void Memory_Control::flag_set_defults_on()
{
 writeToEEPROM(60,200);
}


Memory_Control::~Memory_Control()
{
  
}
