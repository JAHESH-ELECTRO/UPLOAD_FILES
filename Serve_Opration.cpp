
#include "Serve_Opration.h"
#include <Arduino.h>
#define COMMENT_C  //


Serve_Opration::Serve_Opration():server(80)
{
    COMMENT_C Serial.begin(115200);
}
 
  void Serve_Opration::Serve_Opration1()
  {
        COMMENT_C Serial.begin(115200);
        WiFi.softAP(name_wifi,pass_wifi);


        IPAddress IP = WiFi.softAPIP();
        server.on("/", [this](AsyncWebServerRequest *req1)
        {   
            pages1(req1);
        });
                                  
        server.on("/LOGIN", [this](AsyncWebServerRequest *req1){
            
           if(req1->authenticate("admin",key_for_Encryption_tag.c_str()))
           {
             flag_recive_sintaxses=1;
             Resul1.number_seting_opration=DEF_SET_ENCRYPTION_TAG;
             req1->send(200,"text/text; charset=UTF-8","ریموت رو میتونین کد کنین");
           }
           if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
            return req1->requestAuthentication(); 
            func_login(req1);
          });

         server.on("/ADMIN_PANEL",[this](AsyncWebServerRequest *req1){
          
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_admin_panel(req1);
          });
        
        
        server.on("/USER_PANEL", [this](AsyncWebServerRequest *req1){
          
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_user_panel(req1);
          });
//************************************************************************************
        server.on("/USER_PANEL_ADD_TAG", [this](AsyncWebServerRequest *req1){
          
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_user_panel_add_tag(req1);
          });
        server.on("/USER_PANEL_ACCESS_CONTROL", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_user_panel_control_access(req1);
         });
        server.on("/USER_PANEL_DELETE_TAG", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_user_panel_delete_tag(req1);
         });

        server.on("/USER_PANEL_NUMBER_SWITCH", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_user_panel_number_switch(req1);
         });
//*************************************************************

        server.on("/ADMIN_PANEL_DEVICE_SERIAL", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_admin_panel_device_serial(req1);
         });

        server.on("/ADMIN_PANEL_AUTHTIRIZED_GROUP", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_admin_panel_authorized_group(req1);
         });
         
         server.on("/ADMIN_PANEL_RELAY_TIME", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_admin_panel_relay_time(req1);
         });

        server.on("/ADMIN_PANEL_CHANGE_PASS", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          func_admin_panel_change_pass(req1);
         });
        server.on("/ADMIN_PANEL_CHANGE_PASS_WIFI", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          admin_panel_change_pass_wifi(req1);
         });
       
        server.on("/ADMIN_PANEL_DEFULT_SETING", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          admin_panel_defult_setings(req1);
         });
        server.on("/ADMIN_PANEL_DEFULT_SETING_SELECT", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          return req1->requestAuthentication(); 
          //admin_panel_defult_setings(req1);
          req1->send(200,"text/html; charset=UTF-8",Defult_setings);

         });
 server.on("/ADMIN_PANEL_SHOW_TIME", [this](AsyncWebServerRequest *req1)
         {
            if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
            return req1->requestAuthentication(); 
            short unsigned int getTimeBuff[7];
                Resul1.number_seting_opration=DEF_DELAY_;
                flag_recive_sintaxses=1;
            if(P_func_get_system_state!=nullptr)
            {
 
                String out_send=send_alarm_java_script(P_func_get_system_state()); //EDITE_8/4/2024
                req1->send(200,"text/html; charset=UTF-8",out_send);
            }
         });
           server.on("/USER_PANEL_SHOW_APP_PASS", [this](AsyncWebServerRequest *req1)
         {
          if(!req1->authenticate(admin_name.c_str(),admin_pass.c_str()))
          {return req1->requestAuthentication();}

            String active_code=req1->getParam("texbox_userpanel_app_pass",true)->value();
            String group_num=req1->getParam("texbox_userpanel_group_numbers",true)->value();
            String out_pass_number;
             Serial.println("USER_PANEL_SHOW_APP_PASS");
            if(this->P_func_created_app_pass!=nullptr)//edite::8/10/2024
            {
              out_pass_number=this->P_func_created_app_pass(active_code,group_num);
            }
               Serial.println(group_num);
               Serial.println(active_code);
              req1->send(200,"text/html; charset=UTF-8", send_alarm_java_script_v2(group_num,out_pass_number));
 
         });

          server.on("/LOGIN_PANEL_OPEN_RELAY",[this](AsyncWebServerRequest *req1)
          {
            func_login_panel_open_relay(req1);
          });
          server.on("/LOGIN_PANEL_OPEN_RELAY2",[this](AsyncWebServerRequest *req1)
          {
            func_login_panel_open_relay2(req1);
          });

    server.begin();
    Serial.print(IP);
    
  }
////////////////////////////////////////////////////////////////////
void Serve_Opration::web_server_init(const char *login_page,const char *user_panel_page,const char *admin_panel_page,const char* select_op_page,const char* defult_setings_page)
 {
  Login=login_page;
  User_panel=user_panel_page;
  Admin_panel=admin_panel_page;
  Select_op=select_op_page;
  Defult_setings=defult_setings_page;
 }
void Serve_Opration::set_admin_setings(String name,String pass)
{
  admin_name=name;
  admin_pass=pass;
}
void Serve_Opration::set_wifi_setings(String name,String pass)
{
  name_wifi=name;
  pass_wifi=pass;
}
//////////////////////////////////////////////////////////////////////
char Serve_Opration::func_start_defult_setings(AsyncWebServerRequest *req1)
{  
            return 0;
}
//////////////////////////////////////////////////////////////////////
  char Serve_Opration::pages1(AsyncWebServerRequest *req1)
  {  
            req1->send(200,"text/html; charset=UTF-8",Login);
            return 0;
  }
////////////////////////////////////////////////////////////////////
  char Serve_Opration::func_login(AsyncWebServerRequest *req1)
  {
    COMMENT_C Serial.begin(115200);
    req1->send(200,"text/html; charset=UTF-8",Select_op);
    return 0;
  }
///////////////////////////////////////////////////////////////////////////
  char Serve_Opration::func_user_panel(AsyncWebServerRequest *req1)
  {
    req1->send(200,  "text/html; charset=UTF-8",User_panel);
    return 0;
  }
/////////////////////////////////// /////////////////////////////
  char Serve_Opration::func_admin_panel(AsyncWebServerRequest *req1)
  {
    req1->send(200,  "text/html; charset=UTF-8",Admin_panel);
    return 0;
  }
////////////////////////////////////////////////////////////////// 
  char Serve_Opration::func_select_op(AsyncWebServerRequest *req1)
  {
    return 0;
  }
//////////////////////USER_PANEL_FUNC/////////////////////////////////

 char Serve_Opration::func_user_panel_add_tag(AsyncWebServerRequest *req1)
 {
  
    String  S1=req1->getParam("texbox_userpanel_add_user_get_group",true)->value();
    Resul1.T_user_panel.userpanel_add_user_get_group=S1.toInt();
    Resul1.number_seting_opration=DEF_USER_ADD_USER;
    flag_recive_sintaxses=1;
    #if TSTOP==YES
    Serial.println(S1);
    #endif
          String okey_get=send_alarm_java_script("تا ده ثانیه هر تگی مقابل دستگاه قرار بدید ثبت میشود ");
      req1->send(200,  "text/html; charset=UTF-8",okey_get);
    return 0;
 }
//***
char Serve_Opration::func_user_panel_control_access(AsyncWebServerRequest *req1)
{

    String  S1=req1->getParam("texbox_userpanel_acces_control_get_group",true)->value();
    Resul1.T_user_panel.userpanel_acces_control_get_group=S1.toInt();
    
    String S2=req1->getParam("radio_userpanel_acces_control_get_group",true)->value();
    Resul1.T_user_panel.userpanel_acces_control_radio_get_group=S2.toInt();
    
    Resul1.number_seting_opration=DEF_USER_ACCESS_CONTROL;
    flag_recive_sintaxses=1;
  #if TSTOP==YES
    Serial.println(S1);
    Serial.println(S2);
  #endif
      String okey_get=send_alarm_java_script("تنظیمات ارسال شد ");
      req1->send(200,  "text/html; charset=UTF-8",okey_get);

    return 0;
}
//***
char Serve_Opration::func_user_panel_delete_tag(AsyncWebServerRequest *req1)
{
    String  S1=req1->getParam("texbox_userpanel_delete_user_get_group",true)->value();
    Resul1.T_user_panel.userpanel_delete_user_get_group=S1.toInt();
    Resul1.number_seting_opration=DEF_USER_DELETE_USER;
    flag_recive_sintaxses=1;
#if TSTOP==YES
    Serial.println("delet_numberis:"+S1);
#endif
      String okey_get=send_alarm_java_script("تنظیمات ارسال شد ");
      req1->send(200,  "text/html; charset=UTF-8",okey_get);
    return 0;
}
//***
 char Serve_Opration::func_user_panel_number_switch(AsyncWebServerRequest *req1)
 {
    String  S1=req1->getParam("texbox_userpanel_number_switch_get_group",true)->value();
    Resul1.T_user_panel.userpanel_number_switch_get_group=S1.toInt();
    String S2=req1->getParam("texbox_userpanel_number_switch_number_switch",true)->value();
    Resul1.T_user_panel.userpanel_number_switch_number_switch=S2.toInt();
    
    
    Resul1.number_seting_opration=DEF_USER_NUMBER_SWITCH;
    flag_recive_sintaxses=1;
#if TSTOP==YES
    Serial.println("group_number is:"+S1);
    Serial.println("number_seitch is:"+S2);
#endif
          String okey_get=send_alarm_java_script("تنظیمات ارسال شد ");
      req1->send(200,  "text/html; charset=UTF-8",okey_get);
    return 0;
 }
/////****************************************************************************************
char Serve_Opration::func_admin_panel_device_serial(AsyncWebServerRequest *req1)
{
    String  S1=req1->getParam("texbox_admin_panel_device_serial_get_serial",true)->value();
    Resul1.T_admin_panel.admin_panel_device_serial_get_serial=S1.toInt();

    Resul1.number_seting_opration=DEF_ADMIN_DEVICE_SERIAL;
    flag_recive_sintaxses=1;
#if TSTOP==YES
    Serial.println("SERIAL_DEVICE IS:"+S1);
#endif
          String okey_get=send_alarm_java_script("تنظیمات ارسال شد ");
      req1->send(200,  "text/html; charset=UTF-8",okey_get);
    return 0;
}
//********************
char Serve_Opration::func_admin_panel_authorized_group(AsyncWebServerRequest *req1)
{
    
    String  S1=req1->getParam("text_box_admin_panel_athorized_group_min",true)->value();
    Resul1.T_admin_panel.admin_panel_athorized_group_min=S1.toInt();
    
    String  S2=req1->getParam("text_box_admin_panel_athorized_group_max",true)->value();
    Resul1.T_admin_panel.admin_panel_athorized_group_max=S2.toInt();

    Resul1.number_seting_opration=DEF_ADMIN_AUTHTIRIZED_GROUP;
    flag_recive_sintaxses=1;
#if TSTOP==YES
    Serial.println("MIN GROUP IS:"+S1);
    Serial.println("MAX GROUP IS:"+S2);
#endif
          String okey_get=send_alarm_java_script("تنظیمات ارسال شد ");
      req1->send(200,  "text/html; charset=UTF-8",okey_get);
    return 0;
}
//********************
char Serve_Opration::func_admin_panel_relay_time(AsyncWebServerRequest *req1)
{
    String  S1=req1->getParam("text_box_admin_panel_relay_time_gettime",true)->value();
    Resul1.T_admin_panel.admin_panel_relay_time_gettime=S1.toInt();

    Resul1.number_seting_opration=DEF_ADMIN_RELAY_TIME;
    flag_recive_sintaxses=1;
#if TSTOP==YES
    Serial.println("RELAY_TIME_IS IS:"+S1);
#endif
          String okey_get=send_alarm_java_script("تنظیمات ارسال شد ");
      req1->send(200,  "text/html; charset=UTF-8",okey_get);
    return 0;
}
//******************
char Serve_Opration::func_admin_panel_change_pass(AsyncWebServerRequest *req1)
{
    
    String  S1=req1->getParam("tex_box_admin_panel_change_pass_new_pass",true)->value();
    Resul1.T_admin_panel.admin_panel_change_pass_new_pass=S1.toInt();
    
    String  S2=req1->getParam("text_box_admin_panel_change_pass_old_pass",true)->value();
    Resul1.T_admin_panel.admin_panel_change_pass_old_pass=S2.toInt();

    Resul1.number_seting_opration=DEF_ADMIN_CHANGE_PASS_ADMIN;
    flag_recive_sintaxses=1;
#if TSTOP==YES
    Serial.println("NEW_PASS_IS:"+S1);
    Serial.println("OLD_PASS_IS:"+S2);
#endif
          String okey_get=send_alarm_java_script("تنظیمات ارسال شد ");
      req1->send(200,  "text/html; charset=UTF-8",okey_get);
    return 0;
}
//**********
char Serve_Opration::admin_panel_change_pass_wifi(AsyncWebServerRequest *req1)
{
    
    String  S1=req1->getParam("text_box_admin_panel_change_pass_wifi_wifi_pass",true)->value();
    Resul1.T_admin_panel.admin_panel_change_pass_wifi_wifi_pass=S1.toInt();
    
    String  S2=req1->getParam("texy_box_admin_panel_change_pass_wifi_repate_pass",true)->value();
    Resul1.T_admin_panel.admin_panel_change_pass_wifi_repate_pass=S2.toInt();

    String  S3=req1->getParam("text_box_admin_panel_change_pass_wifi_wifi_name",true)->value();
    Resul1.T_admin_panel.admin_panel_change_pass_wifi_wifi_name=S3;

    Resul1.number_seting_opration=DEF_ADMIN_CHANGE_PASS_WIFI;
    flag_recive_sintaxses=1;
    #if TSTOP==YES
    Serial.println("رمز وایفای:"+S1);
    Serial.println("تکرار رمز:"+S2);
    Serial.println("نام وای فای:"+Resul1.T_admin_panel.admin_panel_change_pass_wifi_wifi_name);
    #endif
          String okey_get=send_alarm_java_script("تنظیمات ارسال شد ");
      req1->send(200,  "text/html; charset=UTF-8",okey_get);
    return 0;
}
//********************************************

char Serve_Opration::admin_panel_defult_setings(AsyncWebServerRequest *req1)
{
  req1->send(200,"text/html; charset=UTF-8",Login);
  Resul1.number_seting_opration=DEF_ADMIN_DEFULT_SETINGS;
  flag_recive_sintaxses=1;
  return 0;
}


String Serve_Opration::send_alarm_java_script(String inpute)
{

              String send_for_user="<script>alert(\"";
              send_for_user+=inpute;
              send_for_user+="\");history.back();</script>";
              
              return send_for_user;
          
              //req1->send(200,"text/html; charset=UTF-8",send_for_user);

}







////////////////////////////////////////
 bool Serve_Opration::state_recive_sintaxes_from_client()
 {
   return flag_recive_sintaxses;
 }

  void Serve_Opration::reset_recive_sintaxes_from_client()
 {
   flag_recive_sintaxses=0;
 }
///////////////////////////////////////
Result_values Serve_Opration::Get_Result_values()
{
	return Resul1;
}
///////////////////////////////////////
char Serve_Opration::client_handler()
{
 
 // server.handleClient();
  return 0;
}

String Serve_Opration::upadata_alarm_javascript()
{

  String text="سیستم در حال دریافت اطلاعات از سرور است لطفا چند لحظه بعد مجدد تلاش کنید.";
  return send_alarm_java_script(text);
}
String Serve_Opration::send_alarm_java_script_v2(String group_num, String pass_val)
{
    String html =
    "<div style='padding:25px; font-size:2.5em; align-items: center; text-align: center;"
    "font-family:tahoma; line-height:2;'>";

    // شماره گروه
    html += "<div>شماره گروه = " + group_num + "</div>";

    // پسورد + اسپن مخصوص
    html += "<div style='margin-top:15px;'>کد فعالساز = "
            "<span id='pass_val' style='font-weight:bold; color:#333;'>" 
            + pass_val +
            "</span></div>";

    // دکمه کپی
    html += "<button onclick='copyPass()' "
            "style='margin-top:20px; padding:12px 25px; font-size:1.5em;"
            "background:#4CAF50; color:white; border:none; border-radius:8px;"
            "cursor:pointer;'>"
            "کپی کد فعالساز"
            "</button>";

    // دکمه بازگشت
    html += "<br><br><button onclick='history.back();' "
            "style='padding:12px 25px; font-size:1.5em; background:#2196F3; "
            "color:white; border:none; border-radius:8px; cursor:pointer;'>"
            "🔙 بازگشت"
            "</button>";

    // نسخه تضمینی برای کپی در ESP
    html +=
        "<script>"
        "function copyPass(){"
        "  var txt=document.getElementById('pass_val').innerText;"
        "  var ta=document.createElement('textarea');"
        "  ta.value=txt;"
        "  document.body.appendChild(ta);"
        "  ta.select();"
        "  document.execCommand('copy');"
        "  document.body.removeChild(ta);"
        "  alert('پسورد کپی شد');"
        "}"
        "</script>";

    html += "</div>";

    return html;
}
 char Serve_Opration::func_login_panel_open_relay(AsyncWebServerRequest *req1)
  {

    String  S1=req1->getParam("text_login_panel_group_number",true)->value();
    Resul1.login_panel_group_number=S1.toInt();
    String S2=req1->getParam("text_login_panel_group_password",true)->value();
    Resul1.login_panel_group_password=S2.toInt();

      //Serial .print("S1:");Serial .println(S1);
     // Serial .print("S2:");Serial.println(S2);


    String result = "";
    randomSeed(millis());   
    for(int i = 0; i < 8; i++) {
        result += char('0' + random(0, 10)); // اعداد ۰ تا ۹
    }
    this->TKEN_VALUE=0;
    //
    //  result="12345678";

    //
   // flag_recive_sintaxses=1;
    for(int i=0;i<result.length();i++){
      this->TKEN_VALUE+=result[i]-48;
    }
      this->TKEN_VALUE*=S2.toInt();


      String send_back=send_alarm_java_script(result); 
     // Serial .print("result:");Serial.println(result);
     // Serial .print("TKEN_VALUE:");Serial.println(TKEN_VALUE);

      req1->send(200,"text/html; charset=UTF-8",send_back);   
      return 0;
  }
 char Serve_Opration::func_login_panel_open_relay2(AsyncWebServerRequest *req1)
  {
   String S2=req1->getParam("TOKEN",true)->value();
   Serial.print("RECIVE_CODE:");Serial.println(S2);//SHOW_CODE
   String send_back;
    if( this->TKEN_VALUE==S2.toInt()){
         flag_recive_sintaxses=1;
         Resul1.number_seting_opration=DEF_LOGIN_PANEL_OPEN_RELAY;   
         send_back=send_alarm_java_script("انجام شد"); 
         req1->send(200,"text/html; charset=UTF-8",send_back);   

    }else{
         send_back=send_alarm_java_script("مشکل در اهرازهویت "); 
          req1->send(400,"text/html; charset=UTF-8",send_back);   
    }
    return 0;
  }
Serve_Opration::~Serve_Opration()
{
}
