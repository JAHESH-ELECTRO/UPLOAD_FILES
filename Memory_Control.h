//#include <AT24Cxx.h>
#define i2c_address 0x50
//////////////////
#define DEF_MEMORY_START_GET_NAME_WIFI        0
#define DEF_MEMORY_SIZE_GET_NAME_WIFI         9
//
#define DEF_MEMORY_START_WIFI_PASS              10
#define DEF_MEMORY_SIZE_WIFI_PASS               14 

#define DEF_MEMORY_START_ADMIN_PASS             14
#define DEF_MEMORY_SIZE_ADMIN_PASS              18 
/////////////////////////////////////////////////////////
#define DEF_MEMORY_START_RELAY_TIME             18
#define DEF_MEMORY_SIZE_RELAY_TIME              19 

#define DEF_MEMORY_START_MIN_LIMIT              19
#define DEF_MEMORY_SIZE_MIN_LIMIT               23 
//
#define DEF_MEMORY_START_MAX_LIMIT              23
#define DEF_MEMORY_SIZE_MAX_LIMIT               27 

#define DEF_MEMORY_START_DEVICE_SERIAL         27//از 27 تا 31
#define DEF_MEMORY_SIZE_DEVICE_SERIAL          31
//////////////////OP_USERS//////////////////////////////////////////
//#define SET_USER_DELETE_COUNTER                 1
//#define SET_USER_NUMBER_SWITCH                  2
//#define SET_STATE_ACCCESS                       3  
////////////////////////////////////////////////////////////
#include <EEPROM.h>
#include <Arduino.h>

#pragma once

typedef struct User
{
unsigned long serial_number;
unsigned int  group_number;
unsigned char number_switch;
unsigned char delate_counter;
unsigned char state_access;
}User;
enum ENUM_OP_USER
{
  NULLL=-1,
  SET_USER_NUMBER_SWITCH=0,
  SET_USER_DELETE_COUNTER=1,
  SET_STATE_ACCCESS=2
};



class Memory_Control
{

public:
  //AT24Cxx eep; 
  Memory_Control();
/////////////////////////////////////////////////////////////////////////
  void writeToEEPROM(int address, unsigned char value);
  unsigned char readFromEEPROM(int address);
  void           Get_wifi_name(unsigned char* wifi_name_);
  void           Get_forward_to_set_key_pass(unsigned char *buf_forward);
  unsigned long  Get_wifi_pass();
  unsigned long  Get_admin_pass();
  unsigned long  Get_max_limit();
  unsigned long  Get_min_limit();
  unsigned char  Get_relay_time();
  unsigned long  Get_serial_number();
/////////////////////////////////////////////////////////////////
  void  Set_wifi_name(unsigned char* wifi_name_);
  void  Set_forward_to_set_key_pass(unsigned char *buf_forward);  
  char  Set_wifi_pass(unsigned long wifi_pass);
  char  Set_admin_pass(unsigned long admin_pass);
  char  Set_max_limit(unsigned long max_limit);
  char  Set_min_limit(unsigned long min_limit);
  char  Set_relay_time(unsigned char relay_time);
  char  Set_serial_number(unsigned long serial_number);
//////////////////////////////////////////////////////////////////
  char Get_user(unsigned int group_number,User &out_user_data);
  char Set_user(unsigned int group_number,ENUM_OP_USER  OP_USER,unsigned char valu_set=1);
 

void print_saved_data();
char print_user_data(unsigned int group_number);
char clear_recorded(unsigned int group_number);


void tst_eeprom();
unsigned long ret_ulong(unsigned char *data);
void ret_ucahr(unsigned long D_OUT,unsigned char *data);

unsigned short int ret_uint16(unsigned char *data);
void ret_uint16tochar(unsigned short int inpute,unsigned char *data);
void set_defults();
void flag_set_defults_on();



  ~Memory_Control();

};

