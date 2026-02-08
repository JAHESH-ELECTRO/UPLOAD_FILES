//دیفاین ها ایراد عددی داشت حل شد خروجی وقفه ها اومده بیرون //7/3/2024

#include <ESP8266WiFi.h>
#include <WiFiServer.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include "Memory_Control.h"
#include <FS.h>

#define DEF_USER_ADD_USER                 1
#define DEF_USER_DELETE_USER              2
#define DEF_USER_ACCESS_CONTROL           3
#define DEF_USER_NUMBER_SWITCH            4
#define DEF_ADMIN_DEVICE_SERIAL           5
#define DEF_ADMIN_AUTHTIRIZED_GROUP       6
#define DEF_ADMIN_RELAY_TIME              7
#define DEF_ADMIN_CHANGE_PASS_ADMIN       8
#define DEF_ADMIN_CHANGE_PASS_WIFI        9
#define DEF_SET_ENCRYPTION_TAG            10
#define DEF_ADMIN_DEFULT_SETINGS          11
#define DEF_LOGIN_PANEL_OPEN_RELAY        17
#define DEF_DELAY_                        12






typedef struct T_user_panel
{
	unsigned int  userpanel_add_user_get_group;
	/////////
	unsigned int  userpanel_acces_control_get_group;
	bool          userpanel_acces_control_radio_get_group;
	/////////
	unsigned int  userpanel_delete_user_get_group;
	/////////
	unsigned int  userpanel_number_switch_get_group;
	unsigned char  userpanel_number_switch_number_switch;

}T_user_Panel;


typedef struct T_admin_panel
{
	unsigned long admin_panel_device_serial_get_serial;//6رقمی
	////////////////////////////////
	unsigned int   admin_panel_athorized_group_min;//3 رقمی 
	unsigned int   admin_panel_athorized_group_max;//3رقمی 
	////////////////////////////////
	unsigned int   admin_panel_relay_time_gettime;//3رقمی 
	////////////////////////////////
	unsigned long  admin_panel_change_pass_new_pass;//6رقمی
	unsigned long  admin_panel_change_pass_old_pass;//6رقمی
	////////////////////////////////
	unsigned long  admin_panel_change_pass_wifi_wifi_pass;
	unsigned long  admin_panel_change_pass_wifi_repate_pass;
	////////////////////////////
  String         admin_panel_change_pass_wifi_wifi_name;

  ////////////////////////////
}T_admin_Panel;

typedef struct Result_values
{
	T_admin_Panel T_admin_panel;
	T_user_Panel  T_user_panel;
unsigned long login_panel_group_password;
unsigned int  login_panel_group_number;	
unsigned char number_seting_opration=0;
}Result_values;

class Serve_Opration
{
  bool            flag_recive_sintaxses;
	Result_values   Resul1;
  const char*     Login=nullptr;
  const char*     User_panel=nullptr;
  const char*     Admin_panel=nullptr;
  const char*     Select_op=nullptr;
  const char*     Defult_setings=nullptr;

  String          name_wifi="access_point";
  String          pass_wifi="55255363000";
  String          admin_name="admin";
  String          admin_pass="123456";
public: 
  uint64_t TKEN_VALUE=0;
String key_for_Encryption_tag;
AsyncWebServer server;
Serve_Opration();
void Serve_Opration1();
char client_handler(); 
void web_server_init(const char *login_page,const char *user_panel_page,const char *admin_panel_page,const char* select_op_page,const char* defult_setings_page);
///
String(*P_func_get_system_state)(void)=nullptr;
String(*P_func_created_app_pass)(String,String)=nullptr;
//tools/////////////////////////////////////////////////////////
Result_values Get_Result_values();                  //دریافت اطلاعات دریافت شده از کاربر
bool state_recive_sintaxes_from_client(); //برسی فلگ دریافت اطلاعات از کاربر مقدار 1 اطلاعات جدید و 0 بدون اطلاعات
void reset_recive_sintaxes_from_client();

void set_admin_setings(String name,String pass);     ////اسم و رمز ادمین 
void set_wifi_setings(String name,String pass);       //تعیین اسم و رمز وای فای
//**************توابع صفات وب ************************************************
char pages1(AsyncWebServerRequest *req1);
char func_start_defult_setings(AsyncWebServerRequest *req1);
char func_login(AsyncWebServerRequest *req1);         //تابع لوگین
char func_user_panel(AsyncWebServerRequest *req1);   
char func_admin_panel(AsyncWebServerRequest *req1);
char func_select_op(AsyncWebServerRequest *req1);
////////////////////درخواست ای باتن//////////////////////
char func_user_panel_add_tag(AsyncWebServerRequest *req1);
char func_user_panel_control_access(AsyncWebServerRequest *req1);
char func_user_panel_delete_tag(AsyncWebServerRequest *req1);
char func_user_panel_number_switch(AsyncWebServerRequest *req1);
//*********ADMIN_PANEL*******
char func_admin_panel_device_serial(AsyncWebServerRequest *req1);
char func_admin_panel_authorized_group(AsyncWebServerRequest *req1);
char func_admin_panel_relay_time(AsyncWebServerRequest *req1);
char func_admin_panel_change_pass(AsyncWebServerRequest *req1);
char admin_panel_change_pass_wifi(AsyncWebServerRequest *req1);
char admin_panel_defult_setings(AsyncWebServerRequest *req1);
char func_login_panel_open_relay(AsyncWebServerRequest *req1);
char func_login_panel_open_relay2(AsyncWebServerRequest *req1);
///////////////////////////////////////////////////////////////
String send_alarm_java_script(String inpute);
String send_alarm_java_script_v2(String group_num, String pass_val);
///////////////////////////////////////////////////////////////////////
String upadata_alarm_javascript();
~Serve_Opration();


};

