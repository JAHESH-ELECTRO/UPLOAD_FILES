#include "core_esp8266_features.h"
#ifndef _Toolse_h
#define _Toolse_h
//////////////////  در  قسمت ADD TAG حافظه رو برسی قسمت نوشتن روی تگ انجام شد
extern Result_values resultt1;
#include "IRF.h"
//#include "Send_protocol.h"
unsigned char temp_data_for_write[17]={0};
String created_password(String number_group_, unsigned char &delet_counter);
String created_password(String number_group_, User &temp_user);
//extern info_data info1;
//extern Send_protocol rs485;
extern unsigned long now_time;
extern unsigned long now_time_timer_reset;
extern unsigned long previousTime ;
extern unsigned long relay_time;
String get_system_state()  //EDITE_8/4/2024
{
  String wifi_pass = WIFI_FIX_NAME + String(MEM_control.Get_wifi_pass());
  String adminpass = String(MEM_control.Get_admin_pass());
  String serial_number = String(MEM_control.Get_serial_number());
  String out_s = "رمزوای فای:" + wifi_pass + "\\n" + "رمز ادمین ::" + adminpass + "\\n" + "سریال دستگاه:" + serial_number + "\\n";
  return out_s;
}  //END_EDITE_8/4/2024







void set_data_to_bufer_block(unsigned char *out_block_data,uint16_t number_group)
{
      unsigned char temp_serial_number[5];
      unsigned char temp_group_number[5];
      unsigned long temp_serail= MEM_control.Get_serial_number();

     MEM_control.ret_ucahr(temp_serail,temp_serial_number);
     MEM_control.ret_uint16tochar(number_group,temp_group_number);
     
     out_block_data[0]=temp_serial_number[0];
     out_block_data[1]=temp_serial_number[1];
     out_block_data[2]=temp_serial_number[2];
     out_block_data[3]=temp_serial_number[3];

     out_block_data[4]=temp_group_number[0];
     out_block_data[5]=temp_group_number[1];
     User temp_us;
     MEM_control.Get_user(number_group,temp_us);
     out_block_data[6]=temp_us.delate_counter;
     out_block_data[7]=temp_us.state_access;
    
    for(int i=8;i<16;i++)
    {
    out_block_data[i]=0;
    }
}

void get_data_as_bufer_block(unsigned char *in_block_data,User &get_user1)
{
      unsigned char temp_serial_number[5];
      unsigned char temp_group_number[5];
      //unsigned long temp_serail= MEM_control.Get_serial_number();

      temp_serial_number[0]=in_block_data[0];
      temp_serial_number[1]=in_block_data[1];
      temp_serial_number[2]=in_block_data[2];
      temp_serial_number[3]=in_block_data[3];

      temp_group_number[0]=in_block_data[4];
      temp_group_number[1]=in_block_data[5];

      get_user1.delate_counter=in_block_data[6];
      get_user1.state_access=in_block_data[7];
      get_user1.group_number=MEM_control.ret_uint16(temp_group_number);
      get_user1.serial_number=MEM_control.ret_ulong(temp_serial_number);

}

char cmp_data_user(User  data_user)
{
  User temp_user={0};
  unsigned long serial_=MEM_control.Get_serial_number();
  if(data_user.serial_number==serial_)
  {
      #if TSTOP==YES
        Serial.print("\r\nOKEY_CMP_SERIAL\r\n");
      #endif
    if (data_user.group_number != 0) {
        if(data_user.group_number<MEM_control.Get_min_limit()||data_user.group_number>MEM_control.Get_max_limit())
        {
          return -1;
        }
     }
    MEM_control.Get_user(data_user.group_number,temp_user);
    if(data_user.delate_counter>=temp_user.delate_counter)
    {

        if(temp_user.state_access!=1)
        {
          Gpio.Erorr_access();
          return -2;
        }
         //Gpio.Okeyy();
         Gpio.Okeyy_recive();


          if(data_user.delate_counter>temp_user.delate_counter)
          {
          MEM_control.Set_user(data_user.group_number,SET_USER_DELETE_COUNTER,data_user.delate_counter);
          }
          

          #if TSTOP==YES
          MEM_control.print_user_data(data_user.group_number);
          #endif

//          info1.opration_code=0x21;info1.protocol=0x80;info1.data_size=1;
    //      uchar DATA;
     //     DATA=temp_user.number_switch;
         // rs485.send(&DATA,info1);
        return 0;
    }
    else
    {
     return  -1;
    }

  }  

  return  -1;
}













void analysis_recive_sintax()
{         
    unsigned int group;
    unsigned char va;
    unsigned char va1;
    uint16_t TimeBuff[7];
    User temp_user;
    String number_group;
    String out_put_pass;
 switch (resultt1.number_seting_opration)
 {
  case DEF_USER_ADD_USER:

          Serial.print("\r\nSTART_SET_REMOTE\r\n");
          set_data_to_bufer_block(temp_data_for_write, resultt1.T_user_panel.userpanel_add_user_get_group);

          dump_byte_array(temp_data_for_write, 16);
          func_add_tag(4, temp_data_for_write, key_read);

          //MEM_control.Set_user(resultt1.T_user_panel.userpanel_add_user_get_group,SET_STATE_ACCCESS);
          //MEM_control.Set_user(resultt1.T_user_panel.userpanel_add_user_get_group,SET_USER_DELETE_COUNTER);
          //MEM_control.Set_user(resultt1.T_user_panel.userpanel_add_user_get_group,SET_USER_NUMBER_SWITCH);
      
      
      break;
      case DEF_USER_ACCESS_CONTROL:
          /////دریافت شماره گروه جهت نوشتن 
          ///نوشتن روی ایپیرام 
          MEM_control.Set_user(resultt1.T_user_panel.userpanel_acces_control_get_group,
            SET_STATE_ACCCESS,
            resultt1.T_user_panel.userpanel_acces_control_radio_get_group
          );
                    Gpio.Okeyy();

      break;
      case DEF_USER_DELETE_USER:
          User temp_get_user;
          MEM_control.Get_user(resultt1.T_user_panel.userpanel_delete_user_get_group, temp_get_user);
           Serial.print("\r\ndelete_isssss");
          Serial.print(resultt1.T_user_panel.userpanel_delete_user_get_group);
             group=resultt1.T_user_panel.userpanel_delete_user_get_group;
          MEM_control.Set_user
          (
            group,
            SET_USER_DELETE_COUNTER,
            temp_get_user.delate_counter+1//////////////////////////////
          );
          Gpio.Okeyy();
          //گرفتن شماره گروه برای افزایش یک عددی کانتر حذف
      break;
      case DEF_USER_NUMBER_SWITCH:
          //گرفتن شماره گروه برای تغییر شماره سوییچ  
          //گرفتن شماره سوییچ تغییر کرده 
          //SET_USER_NUMBER_SWITCH

          group=resultt1.T_user_panel.userpanel_number_switch_get_group;
			    va=resultt1.T_user_panel.userpanel_number_switch_number_switch;
            Serial.println("value:");
            Serial.println(va);
            Serial.println("group:");
            Serial.println(group);
          MEM_control.Set_user
          (
            group,
            SET_USER_NUMBER_SWITCH,
            va
          );

          Gpio.Okeyy();

      break;
      case DEF_ADMIN_DEVICE_SERIAL:
          ///گرفتن سریال دستگاه از کاربر برای تغییر سریال دستگاه 
          MEM_control.Set_serial_number(resultt1.T_admin_panel.admin_panel_device_serial_get_serial);
          Gpio.Okeyy();

      break;
      case DEF_ADMIN_AUTHTIRIZED_GROUP:
          //resultt1.T_admin_panel.admin_panel_athorized_group_min;//گرفتن مقدار حداقل برای در نظر گرفتن محدوده خاص از کاربر 
          //resultt1.T_admin_panel.admin_panel_athorized_group_max;/////
        

            Serial.println("group_min:");
            Serial.println(resultt1.T_admin_panel.admin_panel_athorized_group_min);
            Serial.println("group_max:");
            Serial.println(resultt1.T_admin_panel.admin_panel_athorized_group_max);
            unsigned int max,min;
                          min=resultt1.T_admin_panel.admin_panel_athorized_group_min;
                          max=resultt1.T_admin_panel.admin_panel_athorized_group_max;
          if (max > min) {      
            MEM_control.Set_min_limit(min);
            MEM_control.Set_max_limit(max);
            Gpio.Okeyy();
          } else {
          Serial.println("گروه شروع باید کوچیکتر از گروه پایان باشد");
            //Gpio.Erorr_access();
          }
      break;
      case DEF_ADMIN_RELAY_TIME:

        //گرفتن زمان رله از کاربر 
          MEM_control.Set_relay_time(resultt1.T_admin_panel.admin_panel_relay_time_gettime);
          Gpio.Okeyy();


      break;
      case DEF_ADMIN_CHANGE_PASS_ADMIN:
        
          // resultt1.T_admin_panel.admin_panel_change_pass_old_pass;//گرفتن رمز قدیمی کاربر برای مقایسه 
          //resultt1.T_admin_panel.admin_panel_change_pass_new_pass;//گرفتن رمز جدید برای مقایسه 
            unsigned long old_p;
            unsigned long new_p,get_old;

            new_p=resultt1.T_admin_panel.admin_panel_change_pass_new_pass;
            get_old=resultt1.T_admin_panel.admin_panel_change_pass_old_pass;
            old_p=MEM_control.Get_admin_pass();
            Serial.println("ADMIN_OOOOLDPASSS:");
            Serial.print(old_p);
            if (old_p==get_old)
            {
              MEM_control.Set_admin_pass(new_p);
              Gpio.Okeyy();
               ESP.restart();
            }
            else 
            {
              Gpio.Erorr();
            }
              
      break;
      case DEF_ADMIN_CHANGE_PASS_WIFI:
      
            //resultt1.T_admin_panel.admin_panel_change_pass_wifi_wifi_pass;//گرفتن رمز جدید وای فای 
            //resultt1.T_admin_panel.admin_panel_change_pass_wifi_repate_pass;//گرفتن تکرار رمز وایفای برای مقایسه 
                                            //گرفتن نام وای فای 
            Serial.println("WIFI_PAAASS:");
            Serial.println(resultt1.T_admin_panel.admin_panel_change_pass_wifi_wifi_pass);

            if (resultt1.T_admin_panel.admin_panel_change_pass_wifi_wifi_pass == resultt1.T_admin_panel.admin_panel_change_pass_wifi_repate_pass)
            {
              MEM_control.Set_wifi_name((unsigned char*)resultt1.T_admin_panel.admin_panel_change_pass_wifi_wifi_name.c_str());
              unsigned long Get_temp;
              Get_temp=resultt1.T_admin_panel.admin_panel_change_pass_wifi_wifi_pass;
              MEM_control.Set_wifi_pass(Get_temp);
              ESP.restart();
              Gpio.Okeyy();
            }
            else 
            {
              Gpio.Erorr();
            }
      break;
     case DEF_ADMIN_DEFULT_SETINGS:
      
      #if TSTOP==YES
        Serial.print("\r\nRESET_OKEEY\r\n");
      #endif
      MEM_control.flag_set_defults_on();       
      ESP.restart();
     break;
      case DEF_DELAY_:
          delay(1000);
      break;

      case DEF_LOGIN_PANEL_OPEN_RELAY:
                Serial.print("\rDEF_LOGIN_PANEL_OPEN_RELAY\r\n");
                Serial.print("\r\nNUMBER_GROUP:");
                Serial.print("\rPASS:");
                Serial.println(resultt1.login_panel_group_password);
                User temp_user;
                number_group = String(resultt1.login_panel_group_number);
                out_put_pass = created_password(number_group, temp_user);  //ساخت آی دی گروه
                if (temp_user.state_access != 1) {
                  Gpio.Erorr_access();
                  Gpio.Erorr();
                  return;  //edite::::8/6/2024
                }
                if (resultt1.login_panel_group_number != 0)  //برسی بازه
                {
                  if (resultt1.login_panel_group_number < MEM_control.Get_min_limit() || resultt1.login_panel_group_number > MEM_control.Get_max_limit()) {
                    Gpio.Erorr();
                    return;
                  }
                }

                if (out_put_pass == String(resultt1.login_panel_group_password)) {
                          Gpio.Okeyy_recive();
                          now_time=millis();
                          unsigned char relay_time_temp=MEM_control.Get_relay_time();
                          relay_time=(now_time+(relay_time_temp*1000));
                  return;
                } else {
                  Gpio.Erorr();
                  return;
                }
      break;
  }

}

String created_password(String number_group_, unsigned char &delet_counter) {
  if (number_group_.toInt() < 10) {
    number_group_ = "00" + number_group_;
  } else if (number_group_.toInt() < 100) {
    number_group_ = "0" + number_group_;
  }
  unsigned long serial_number;
  serial_number = MEM_control.Get_serial_number();
  User temp_user;

#if TSTOP == YES
//Serial.print("serial_number::");
//Serial.println(serial_number);
#endif

  MEM_control.Get_user(number_group_.toInt(), temp_user);
  delet_counter = temp_user.delate_counter;

#if TSTOP == YES
//Serial.print("delate_counter::");
////Serial.println(temp_user.delate_counter);
//Serial.print("number_switch::");
//Serial.println(temp_user.number_switch);
#endif

  String S_delate_counter = String((temp_user.delate_counter < 41) ? temp_user.delate_counter : temp_user.delate_counter -= 40);  //برسی شرط بزرگتر از 40 بودن کانتر حذف
  String S_serial_number = String(serial_number);                                                                                 //تبدیل سریال به رشته برای راحتی جمع زدن

#if TSTOP == YES
//Serial.println("S_GUP_NUMBER::"+number_group_);
//Serial.println("S_serial_number::"+S_serial_number);
//Serial.println("S_delate_counter::"+S_delate_counter);
#endif

  String outpute_id_number = S_delate_counter + number_group_ + S_serial_number;  //جمع زدن مقادیر به صورت رشته برای خروجی ای دی نامبر

#if TSTOP == YES
//Serial.println("outpute_id_number::"+outpute_id_number);
#endif

  randomSeed(outpute_id_number.toInt());

  unsigned long get_out_pass = random(10001, 99999);

  String out_pass_string = String(get_out_pass);

#if TSTOP == YES
//Serial.println("get_out_pass::"+out_pass_string);
#endif

  return out_pass_string;
}

String created_app_pass(String serial_app,String group_number){
    
    unsigned char delat;
    String  fixed_pass=created_password(group_number,delat);
    if(group_number.toInt()<10){
      group_number="00"+group_number;
    }else if(group_number.toInt()<100){
      group_number="0"+group_number;
    }
    String sum=fixed_pass+group_number;
    sum+="7";
    Serial.print("SUM_IS:"+sum+":");
    uint32_t get=3*(serial_app.toInt()+sum.toInt());
    String  app_active_pass=String(get);
    return app_active_pass;

}

String created_password(String number_group_, User &temp_user) {

  if (number_group_.toInt() < 10) {
    number_group_ = "00" + number_group_;
  } else if (number_group_.toInt() < 100) {
    number_group_ = "0" + number_group_;
  }

  unsigned long serial_number;
  serial_number = MEM_control.Get_serial_number();
#if TSTOP == YES
  Serial.print("serial_number::");
  Serial.println(serial_number);
#endif

  MEM_control.Get_user(number_group_.toInt(), temp_user);

#if TSTOP == YES
  Serial.print("delate_counter::");
  Serial.println(temp_user.delate_counter);
  Serial.print("number_switch::");
  Serial.println(temp_user.number_switch);
#endif

  String S_delate_counter = String((temp_user.delate_counter < 41) ? temp_user.delate_counter : temp_user.delate_counter - 40);  //برسی شرط بزرگتر از 40 بودن کانتر حذف
  String S_serial_number = String(serial_number);                                                                                //تبدیل سریال به رشته برای راحتی جمع زدن

#if TSTOP == YES
  Serial.println("S_GUP_NUMBER::" + number_group_);
  Serial.println("S_serial_number::" + S_serial_number);
  Serial.println("S_delate_counter::" + S_delate_counter);
#endif

  String outpute_id_number = S_delate_counter + number_group_ + S_serial_number;  //جمع زدن مقادیر به صورت رشته برای خروجی ای دی نامبر

#if TSTOP == YES
  Serial.println("outpute_id_number::" + outpute_id_number);
#endif

  randomSeed(outpute_id_number.toInt());

  unsigned long get_out_pass = random(10001, 99999);

  String out_pass_string = String(get_out_pass);

#if TSTOP == YES
  Serial.println("get_out_pass::" + out_pass_string);
#endif

  return out_pass_string;
}






#endif