
//checkDigestAuthentication   //C:\Users\sattia\Documents\Arduino\libraries\ESPAsyncWebServer\src\WebAuthentication.cpp
//bool AsyncWebServerRequest::authenticate(const char * username, const char * password, const char * realm, bool passwordIsHash)   C:\Users\sattia\Documents\Arduino\libraries\ESPAsyncWebServer\src\WebRequest.cpp
//bool AsyncWebServerRequest::_parseReqHeader(){
 // Serial.print(_temp);                                C:\Users\sattia\Documents\Arduino\libraries\ESPAsyncWebServer\src\WebRequest.cpp
/////////7/2/2024  //تنظیمات مربوط به رمز لاگین و گرفتن صفحات انجام شده 
//اضافه کردن فلک هابرای خروجی کلاس وای فای 

/////////7/3/2024 // کلاس سرور تمام شد)(Serve_Opration) //ادامه گرفتن مقادیر از کاربر 

/////////7/4/2024//تکمیل شدن قسمت خواندن نوشتن تگ و قسمت اضافه کردن کلید به تگ //
//نوشتن توایع کاربا حافظه در کلاس حافظه 

//////////7/5/2024//قسمت افزودن تگ به قسمت مموری و و تگش کامل تموم
//////////7/6/2024//تکمیل شده حافظه وعیب یابی آن تایین حداکثر های ورودی ها نوشتن اطلاعات روی تگ /عیب یابی کاری های قبلی
//ایجاد تغییرات درسورس وب پیج
//7/7/2024->>??-_قسمت مقایسه تگ انجام شد_اضافه شدن قسمت ارسال شماره سوییچ توسط پروتکل صنعتی به بیرون 
/////////////////تغییرات مموری و تایمر 
///7/9/2024  واچ داگ و تنظیمات پیش فرض و تغییراتی در صفحات وب داده شد 

#define YES           1
#define NO            0     
#define TSTOP         YES

#define   WIFI_FIX_NAME  "MANAHOOR_"
#define   WIFI_FIX_PASS  "MANAHOOR_"

#include "Gpio_Oprations.h"
#include "Memory_Control.h"
#include "Serve_Opration.h"
#include "tools.h"
#include "IRF.h"

//#include "Rf_Id_oprations.h"
#include "WebPages.h"

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         0          // Configurable, see typical pin layout above
#define SS_PIN          4          // Configurable, see typical pin layout above


MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
MFRC522::StatusCode status; 
MFRC522::MIFARE_Key key;
unsigned long startTime_reset_key = 0;

     byte trailerBuffer[] = {
        0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,////////////////
        0XFF,0X07,0X80,0X19,
        0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf
        }; 

  /*
     byte trailerBuffer[] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff,////////////////رمز بخش اولی
        0XFF,0X07,0X80,0X19,///////////////دیتا های مربوط به .ضعیت خواند و نوشتن بلوک 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff//رمز بخش دومی  
        }; 
*/

MFRC522::MIFARE_Key key_read;
Gpio_Oprations Gpio; 
Memory_Control MEM_control;
Serve_Opration S1;
Result_values  resultt1;
unsigned long previousTime =0;
unsigned long relay_time=0;
unsigned long now_time=0;
unsigned long now_time_timer_reset=0;
//#define TIMER_RESETE     5000


void setup()
 {
      key_read.keyByte[0]=0xaa;
      key_read.keyByte[1]=0xab;
      key_read.keyByte[2]=0xac;
      key_read.keyByte[3]=0xad;
      key_read.keyByte[4]=0xae;
      key_read.keyByte[5]=0xaf;
      Gpio.Gpio_init(RED_LED,BLUE_LED,BUZZER,RELAY,RST_PIN,WATCH_DOG);
      SPI.begin(); 
      mfrc522.PCD_Init();
      unsigned char tempp[50];
      //MEM_control.flag_set_defults_on();
      MEM_control.set_defults();
      MEM_control.Get_wifi_name(tempp);
////////////////////////////////////////////////////////////////////////////////////////
      //MEM_control.Set_admin_pass(543210);
      String  wifi_name=WIFI_FIX_NAME;
      wifi_name.concat((const char *)tempp);
      String  wifi_pass=WIFI_FIX_PASS+String(MEM_control.Get_wifi_pass());  //اول نام وای فای حروف ثابت دارد                 /////
      String  admin_name="admin";                                        /////  تعیین اسم و رمز وای فای
      String  admin_pass=String(MEM_control.Get_admin_pass());
//////////////////////////////////////////////////////////////////////////////////
      String  key_for_Encryption_tag="12345678910";
      MEM_control.print_saved_data();
      Serial.println();
      /////////////////test
      S1.set_wifi_setings(wifi_name,wifi_pass);
      S1.set_admin_setings(admin_name,admin_pass);
      S1.key_for_Encryption_tag=key_for_Encryption_tag;
      //////////////////test
        S1.web_server_init(LOGIN,USER_PANEL,ADMIN_PANEL,LOGIN,DEFULT_SETING);
        S1.Serve_Opration1();
        Gpio.blue_on();
        Gpio.buzzer_on();
        delay(500);
        Gpio.buzzer_off();
        ESP.wdtEnable(1000); 
        S1.P_func_get_system_state=get_system_state;
        S1.P_func_created_app_pass=created_app_pass;
}


void loop() {
  // put your main code here, to run repeatedly:
mfrc522.PCD_Init();
Gpio.blue_on();
ESP.wdtFeed();
if(S1.state_recive_sintaxes_from_client()==1) ///وقفه دریافت دستور از کاربر
{
  S1.reset_recive_sintaxes_from_client();     //بازنشانی فلگ وقفه 
  resultt1=S1.Get_Result_values();
  #if TSTOP==YES                              //برای نمایش عملیات های تستی
   Serial.println("NUMBER_OPTATIN IS=="+String(resultt1.number_seting_opration));
  #endif
  analysis_recive_sintax();////تحلیل دستورات کاربر و نوشتن روی مموری
  ///تذکر :::: برای تغییر نام و رمز وای فای و ادمین دستگاه باید خاموش روشن شود 
}
//////////////////////////////////////////////////////////////////////////////////////////////
int adcValue = analogRead(A0);   // خواندن از پایه ADC0 (0 تا 1023)

    if (adcValue > 800) {  // شرط مثلا نگه داشتن بالاتر از 800
      startTime_reset_key = millis();
    } else {
      Serial.print("PRESED RESTE_KEY");
      
        if(millis()-startTime_reset_key>5000){
           MEM_control.flag_set_defults_on();    
           ESP.restart();       
        }
    }
///////////////////////////////////////////////////////////////////////////////////////////////
  now_time=millis();
  if (relay_time>now_time)
  {
  Gpio.relay_on();
  }
  else
  {
  Gpio.relay_off();
  }
///////////////////////////////////////////////////////////////////////////////////////////////
setkey_start();//////////برای ذخیره کلید در تگ بعد از دستور کاربر تا ده ثانیه اجرا بعد متوقف میشود
//////////////////////////////////خواندن و تحلیل تگ//////////////////////////////////////   
if ( ! mfrc522.PICC_IsNewCardPresent())
    return;

if ( ! mfrc522.PICC_ReadCardSerial())
    return;

   byte buffer_block[64];
 if(resultt1.number_seting_opration!=DEF_SET_ENCRYPTION_TAG)
 {
    if (read_block_tag(4,buffer_block,&key_read)==0)
    {
      User get_user1;
      get_data_as_bufer_block(buffer_block,get_user1);
      //////////////////////////////////////////////////////////////////
      #if TSTOP==YES
      dump_byte_array(buffer_block, 16);
      Serial.print("\r\n(INFO_TAGIS) SERIAL:");
      Serial.print(get_user1.serial_number);
      Serial.print("__group:");
      Serial.print(get_user1.group_number);
      Serial.print("__delete_counter:");
      Serial.print(get_user1.delate_counter);
      Serial.print("__state_access:");
      Serial.println(get_user1.state_access);
      MEM_control.print_user_data(get_user1.group_number);
      #endif
      //////////////////////////////////////////////////////////////////
      if(cmp_data_user(get_user1)==0)
      {
        now_time=millis();
        unsigned char relay_time_temp=MEM_control.Get_relay_time();
        relay_time=(now_time+(relay_time_temp*1000));
      }
      else
      {
        Gpio.Erorr();
      }
    }
    else
    {
      Gpio.Erorr();
    }
 }

///////////////////end///////////////////////////////  
}
