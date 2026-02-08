//7/27/2024//اضافه شدن منوی نمایش رمز 

const char USER_PANEL[] PROGMEM = R"rawliteral(
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>مدیریت کاربران</title>
	<style>
		body {
	  background-color:#FFFFFF;
      font-family: Cambria, "Hoefler Text", "Liberation Serif", Times, "Times New Roman", "serif";
      line-height: 1.5;
      display: flex;
      justify-content: center;
      align-items: center;
      flex-direction: column;
      gap: 20px;	
		}
	.frame {
      background-color: #FFFFFF;
      padding: 10px;
      width: 100%;
	  margin-top: 10px;
    }
	.header {
	background-color: #373435;
	padding-bottom: 85px;
		}
	#text-header {
	padding: 10px;
	text-align: center;
	font-size: 2.5em;
	font-weight: bolder;
	color: #FDB500;
		}
	#setting {
	background-color: #FDA500;
	width: 45% ;
	color: #FFFFFF;
	font-size: 2.5em;
	font-weight: bolder;
	text-align: center;
	float: left;
	margin-left: 2%;
		}
	#user {
	background-color: #FDA500;
	width: 45% ;
	font-size: 2.5em;
	font-weight: bolder;
	color: #FFFFFF;
	text-align: center;
	float: right;
	margin-right: 2%;
	position: relative;
	border-color: #08F7D3;
		}
	.text-help {
      box-sizing: border-box;
	  font-size: 1.5em;
	  text-align: right;
	  color: #000000;
	  margin-top: 10px;
	  margin-right: 10px;
		}	
	.text-block{
	font-size: 2em;
	font-weight: bold;
	text-align: right;
	color: #000000;	
		}
	.group-num {
	background-color: #FDFFE2;
	margin-right: 1%;
	width: 19%;
	height: 50px;
	font-size: 1.5em;
		}
	.submit{
	background-color: #FDA500;
	width: 15% ;
	color: #FFFFFF;
	font-size: 1.2em;
	font-weight: bolder;
	text-align: center;
	max-height: 60px;
	float: left;
	margin-left: 2%;
		}	
	.radio-but {
	margin-right: 40px;			
		}
nav {
  width : 100%; 
  background: #d9d9d9;
  margin : 10px auto; 
}
span {
  padding : 20px;
  background : #08F7D3;
  text-align: center;
  color : F000000;
  font-size : 2.5em;
  font-weight: bolder;
  font-variant : small-caps;
  cursor : pointer;
  display: block;
}
span::after {
  float: right;
  right: 10%;
	margin-top: -15px;
	font-size: 1.5em;
  content: "+";
}
.slide {
  clear:both;
  width:95%;
  height:0px;
  overflow: hidden;
  text-align: center;
  transition: height .4s ease;
}
.slide li {padding : 5px;}
#touch1 {position: absolute; opacity: 0; height: 0px;}    
#touch1:checked + .slide {height: 150px;}
#touch2 {position: absolute; opacity: 0; height: 0px;}    
#touch2:checked + .slide {height: 150px;}
#touch3 {position: absolute; opacity: 0; height: 0px;}    
#touch3:checked + .slide {height: 150px;}
#touch4 {position: absolute; opacity: 0; height: 0px;}    
#touch4:checked + .slide {height: 180px;}
#touch5 {position: absolute; opacity: 0; height: 0px;}    
#touch5:checked + .slide {height: 150px;}
#touch6 {position: absolute; opacity: 0; height: 0px;}    
#touch6:checked + .slide {height: 150px;}		
#touch7 {position: absolute; opacity: 0; height: 0px;}    
#touch7:checked + .slide {height: 180px;}
#touch8 {position: absolute; opacity: 0; height: 0px;}    
#touch8:checked + .slide {height: 150px;}
#touch9 {position: absolute; opacity: 0; height: 0px;}    
#touch9:checked + .slide {height: 150px;}
	@media(max-width: 768px) {
      .frame {
        width: 100%;
      }
	</style>
</head>
<body>
	<div class="frame">
<div class="header">
		<div id="text-header"><strong>MANAHOOR-PRO</strong></div>
	<!-- Form for Admin Panel -->
		 <form method="post" action="ADMIN_PANEL">
      <input type="submit" id="setting" value="تنظیمات">
    </form>
	<!-- Form for User Panel -->
     <form method="post" action="USER_PANEL">
      <input type="submit" id="user"  value="مدیریت کاربران">
  </form>
</div>
	<!-- Form for Adding User Tag -->
<nav>
  <label for="touch1"><span>صدور تگ</span></label>               
  <input type="checkbox" id="touch1"> 
  <ul class="slide">
    <li>	
		<form method="post" action="USER_PANEL_ADD_TAG">
      <div class="text-block">
		<input type="submit" class="submit" value="تایید">
		<input name="texbox_userpanel_add_user_get_group" type="number"  required class="group-num" max="999" min="0">شماره واحد
		</div> 
      </form>
		<div class="text-help">شماره واحد را وارد کرده، دکمه تایید را بزنید و تگ را مقابل کارتخوان قرار دهید</div>
	</li> 
  </ul>
</nav> 
		<!-- Form for Access Control -->
<nav>
  <label for="touch2"><span>کنترل دسترسی</span></label>               
  <input type="checkbox" id="touch2"> 

  <ul class="slide">
    <li>		
    <form method="post" action="USER_PANEL_ACCESS_CONTROL">
      <div class="text-block">
	<input type="submit" class="submit" value="تایید">
	شماره واحد
	<input name="texbox_userpanel_acces_control_get_group" type="number" required class="group-num" max="999" min="1">
	<label><input name="radio_userpanel_acces_control_get_group" type="radio" class="radio-but" value="1"> فعال</label>
	<label><input name="radio_userpanel_acces_control_get_group" type="radio" required class="radio-but" value="0">غیرفعال</label>
</div>
    </form>
<div class="text-help">شماره واحد را وارد کرده، نوع دسترسی (فعال/غیرفعال) را انتخاب و دکمه تایید را بزنید</div>
		</li> 
  </ul>
</nav> 
  <!-- Form for Showing Password -->
<nav>

  <label for="touch3"><span>دریافت رمز ثابت</span></label>               
  <input type="checkbox" id="touch3"> 
  <ul class="slide">
    <li>
	 <form method="post" action="USER_PANEL_SHOW_PASS">
      <div class="text-block">
      <input name="texbox_userpanel_add_user_show_pass" type="number" required class="group-num" max="999" min="0">
      <input type="submit" class="submit" value="تایید">
		  شماره واحد
       </div>
    </form>
<div class="text-help">برای مشاهده رمز ثابت، شماره واحد را وارد کرده و دکمه تایید را بزنید</div>
	</li> 
  </ul>
</nav>
 <!-- Form for active dynamic Password -->
<nav>
  <label for="touch4"><span>رمز پویا</span></label>               
  <input type="checkbox" id="touch4"> 
  <ul class="slide">
    <li>	
		  <form method="post" action="USER_PANEL_STATE_GET_PASS">
    <div class="text-block">فعالسازی رمز پویا
	<input type="submit" class="submit" value="تایید">
    <label><input name="user_panel_state_pass" type="radio" value="1" required>فعال</label>
    <label><input name="user_panel_state_pass" type="radio" value="0">غیرفعال</label>
		</div>
	  </form>
<div class="text-help">با فعال شدن رمز پویا، رمز ثابت تمام واحدها غیر از واحد صفر غیرفعال می شود و با غیرفعال کردن رمزپویا، رمز ثابت فعال می شود</div>	
	  </li> 
  </ul>
</nav>
 <!-- Form for App Activator -->	
<nav>
  <label for="touch5"><span>فعال ساز اپلیکیشن کاربر</span></label>               
  <input type="checkbox" id="touch5"> 
  <ul class="slide">
    <li>		
	  <form method="post" action="USER_PANEL_SHOW_APP_PASS">
	    <div class="text-block">
		      <input type="submit" class="submit" value="تایید">
	<input name="texbox_userpanel_app_pass" type="number" required class="group-num" max="99999" min="10001">شماره واحد
	<input name="texbox_userpanel_group_numbers" type="number" required class="group-num" max="999" min="0"> &nbsp سریال موبایل
	    </div>
 	 </form>
<div class="text-help">برای دریافت کد فعالسازی اپلیکیشن، شماره واحد و سریال موبایل کاربر را وارد و دکمه تایید را بزنید</div>
	</li> 
  </ul>
</nav>
<!-- Form for Deleting User Tag -->
<nav>
  <label for="touch6"><span>حذف اطلاعات واحد</span></label>               
  <input type="checkbox" id="touch6"> 
  <ul class="slide">
    <li>	
	<form method="post" action="USER_PANEL_DELETE_TAG">
      <div class="text-block">
	  <input type="submit" class="submit" value="تایید">
      <input name="texbox_userpanel_delete_user_get_group" type="number"  required class="group-num" max="999" min="0">
	  شماره واحد
	  </div>
     </form>	
<div class="text-help">برای حذف اطلاعات واحد (شامل تگها، رمز و اپلیکیشن)، شماره واحد را وارد و دکمه تایید را بزنید</div>
	</li> 
  </ul>
</nav>
	  <!-- Button for Getting All Passwords -->
<nav>
  <label for="touch7"><span>دریافت اطلاعات واحدها</span></label>               
  <input type="checkbox" id="touch7"> 
  <ul class="slide">
    <li>	
	<form method="post" action="USER_PANEL_GET_ALL_PASS">
     <div class="text-block">
	   <input type="submit" class="submit" value="تایید">
		دریافت رمز تمام واحدهای مجاز
  		 </div>
	  </form>
<div class="text-help">با زدن دکمه تایید می توانید لیست رمز ثابت تمام واحدها را دریافت نمایید </div>
	</li> 
  </ul>
</nav>
	  <!-- Button for Generating Logs block -->
<nav>
  <label for="touch8"><span>لیست واحدهای غیرفعال</span></label>               
  <input type="checkbox" id="touch8"> 
  <ul class="slide">
    <li>
		    <form method="post" action="ADMIN_PANEL_BLOCKED_LIST">
	  <div class="text-block">
      <input type="submit" class="submit" value="تایید" >
	  دریافت لیست واحد های مسدود شده
			  </div>
    </form>
		<div class="text-help">برای دریافت لیست واحدهای مسدود شده، دکمه تایید را بزنید </div>
	</li> 
  </ul>
</nav>	
	  <!-- Button for Generating Logs -->
<nav>
  <label for="touch9"><span>گزارش تردد</span></label>               
  <input type="checkbox" id="touch9"> 
  <ul class="slide">
    <li>
		    <form method="post" action="USER_PANEL_SHOW_LOG">
	  <div class="text-block">
      <input type="submit" class="submit" value="تایید" >
	  دریافت گزارش تردد
			  </div>
    </form>
		<div class="text-help">برای دریافت گزارش تردد دکمه تایید را بزنید </div>
	</li> 
  </ul>
</nav>	
  </div>
</body>
</html>

 )rawliteral";

 
const char ADMIN_PANEL[] PROGMEM =
R"rawliteral(
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>مدیریت کاربران</title>
	<style>
		body {
	  background-color:#FFFFFF;
      font-family: Cambria, "Hoefler Text", "Liberation Serif", Times, "Times New Roman", "serif";
	  line-height: 1.5;
      display: flex;
      justify-content: center;
      align-items: center;
      flex-direction: column;
      gap: 20px;	
		}
	.frame {
      background-color: #FFFFFF;
      padding: 10px;
      width: 100%;
    }
	.header {
	background-color: #373435;
	padding-bottom: 85px;
		}
		#text-header {
			padding: 10px;
			text-align: center;
			font-size: 2.5em;
			font-weight: bolder;
			color: #FDB500;
		}
		#setting {
			background-color: #FDA500;
			width: 45% ;
			color: #FFFFFF;
			font-size: 2.5em;
			font-weight: bolder;
			border-color: #08F7D3;
			text-align: center;
			float: left;
			margin-left: 2%;
		}
		#user {
			background-color: #FDA500;
			width: 45% ;
			font-size: 2.5em;
			font-weight: bolder;
			color: #FFFFFF;
			text-align: center;
			float: right;
			margin-right: 2%;
			position: relative;
		}
	.text-help {
	font-size: 1.2em;
	text-align: right;
	color: #000000;
	margin-top: 10px;
	margin-right: 10px;
		}
	.text-block{
	font-size: 2em;
	font-weight: bold;
	text-align: right;
	color: #000000;	
		}
	.group-num {
	background-color: #FDFFE2;
	margin-right: 1%;
	width: 19%;
	height: 50px;
	font-size: 1.5em;
	text-align: center;
		}
	.numbers {
	background-color: #FDFFE2;
	margin-right: 1%;
	width: 21%;
	height: 50px;
	text-align: center;
	font-size: 1.2em;
		}
	.name {
	background-color: #FDFFE2;
	margin-right: 1%;
	font-size: 1.2em;
	text-align: center;
	width: 30%;
	height: 50px;
		}
	.submit{
	background-color: #FDA500;
	width: 15% ;
	color: #FFFFFF;
	font-size: 1.2em;
	font-weight: bolder;
	text-align: center;
	max-height: 60px;
	float: left;
	margin-left: 2%;
		}
	.submit2{
	background-color: #FDA500;
	width: 50% ;
	color: #FFFFFF;
	font-size: 1.2em;
	font-weight: bolder;
	text-align: center;
	max-height: 60px;
	float: left;
		margin-left: 25%;
		}
		.radio-but {
			margin-right: 40px;		
		}
nav {
  width : 100%; 
  background: #d9d9d9;
  margin : 10px auto; 
}
span {
  padding : 20px;
  background : #08F7D3;
  text-align: center;
  color : #000000;
  font-size : 2.5em;
  font-weight: bolder;
  font-variant : small-caps;
  cursor : pointer;
  display: block;
}
span::after {
  float: right;
  right: 10%;
	margin-top: -15px;
	font-size: 1.5em;
  content: "+";
}
.slide {
  clear:both;
  width:95%;
  height:0px;
  overflow: hidden;
  text-align: center;
  transition: height .4s ease;
}
.slide li {padding : 5px;}
#touch1 {position: absolute; opacity: 0; height: 0px;}    
#touch1:checked + .slide {height: 150px;}		
#touch2 {position: absolute; opacity: 0; height: 0px;}    
#touch2:checked + .slide {height: 150px;}		
#touch3 {position: absolute; opacity: 0; height: 0px;}    
#touch3:checked + .slide {height: 150px;}
#touch4 {position: absolute; opacity: 0; height: 0px;}    
#touch4:checked + .slide {height: 180px;}		
#touch5 {position: absolute; opacity: 0; height: 0px;}    
#touch5:checked + .slide {height: 150px;}		
#touch6 {position: absolute; opacity: 0; height: 0px;}    
#touch6:checked + .slide {height: 150px;}		
#touch7 {position: absolute; opacity: 0; height: 0px;}    
#touch7:checked + .slide {height: 180px;}		
#touch8 {position: absolute; opacity: 0; height: 0px;}    
#touch8:checked + .slide {height: 150px;}
#touch9 {position: absolute; opacity: 0; height: 0px;}    
#touch9:checked + .slide {height: 180px;}		
#touch10 {position: absolute; opacity: 0; height: 0px;}    
#touch10:checked + .slide {height: 150px;}		
#touch11 {position: absolute; opacity: 0; height: 0px;}    
#touch11:checked + .slide {height: 150px;}
#touch13 {position: absolute; opacity: 0; height: 0px;}    
#touch13:checked + .slide {height: 150px;}

	@media(max-width: 768px) {
      .frame {
        width: 100%;
      }
	</style>
</head>
<body>
	<div class="frame">
<div class="header">
		<div id="text-header"><strong>MANAHOOR-PRO</strong></div>
	<!-- Form for Admin Panel -->
		 <form method="post" action="ADMIN_PANEL">
      <input type="submit" id="setting" value="تنظیمات">
    </form>
	<!-- Form for User Panel -->
     <form method="post" action="USER_PANEL">
      <input type="submit" id="user"  value="مدیریت کاربران">
  </form>
</div>
	<!-- Form for Adding serial number -->
<nav>
  <label for="touch1"><span>فعالسازی دستگاه</span></label>               
  <input type="checkbox" id="touch1"> 
  <ul class="slide">
    <li>	
    <form method="post" action="ADMIN_PANEL_DEVICE_SERIAL">
      <div class="text-block">
		<input type="submit" class="submit" value="تایید">
        <input name="texbox_admin_panel_device_serial_get_serial" type="number" required class="numbers">سریال دستگاه
		</div> 
      </form>
		<div class="text-help">سریال 5 رقمی دستگاه را وارد و دکمه تایید را بزنید</div>
	</li> 
  </ul>
</nav> 
		<!-- Form for Access Group -->
<nav>
  <label for="touch2"><span>تعداد واحدهای مجاز</span></label>               
  <input type="checkbox" id="touch2"> 
  <ul class="slide">
    <li>		
    <form method="post" action="ADMIN_PANEL_AUTHTIRIZED_GROUP">
      <div class="text-block">
	<input type="submit" class="submit" value="تایید">
    <input name="text_box_admin_panel_athorized_group_max" type="number" required class="numbers" placeholder="تا">
    <input name="text_box_admin_panel_athorized_group_min" type="number" required class="numbers" placeholder="از">
		  شماره واحدها
</div>
    </form>
<div class="text-help">بازه واحدهای مجاز برای دستگاه به صورت پیشفرض 0 تا 999 واحد است. میتوانید بازه شماره واحدها را به دلخواه تغییر دهید</div>
		</li> 
  </ul>
</nav> 
  <!-- Form for relay time -->
<nav>
  <label for="touch3"><span>تنظیم زمان رله خروجی</span></label>               
  <input type="checkbox" id="touch3"> 
  <ul class="slide">
    <li>
	 <form method="post" action="ADMIN_PANEL_RELAY_TIME">
      <div class="text-block">
       <input type="number" class="numbers"  name="text_box_admin_panel_relay_time_gettime" value="" max="99" spellcheck="false"  required>
       <input type="submit" class="submit" value="تایید">
		   زمان رله - ثانیه
       </div>
    </form>
<div class="text-help">زمان مورد نظر خود را بین 1 تا 99 ثانیه وارد و دکمه تایید را بزنید</div>
	</li> 
  </ul>
</nav>
		 <!-- Form for active switch panel -->
<nav>
  <label for="touch4"><span>سوئیچ طبقات آسانسور</span></label>               
  <input type="checkbox" id="touch4"> 
  <ul class="slide">
    <li>	
	 	<form method="post" action="USER_PANEL_NUMBER_SWITCH">
	    <div class="text-block">     
	     <input type="submit" class="submit" value="تایید">
	     <input name="texbox_userpanel_number_switch_number_switch" type="number" spellcheck="false" required class="group-num" max="32" min="0">شماره واحد 
	     <input name="texbox_userpanel_number_switch_get_group" type="number" spellcheck="false" required class="group-num" max="999" min="0">&nbsp شماره طبقه
	    </div>
 	 </form>
<div class="text-help">در صورت نصب سوئیچ طبقات آسانسور، در این قسمت شماره طبقه را برای هر واحد تعیین کنید</div>
	  </li> 
  </ul>
</nav>
 <!-- Form for Change manager password -->	
<nav>
  <label for="touch5"><span>تغییر رمز مدیریت</span></label>               
  <input type="checkbox" id="touch5"> 
  <ul class="slide">
    <li>		
    <form method="post" action="ADMIN_PANEL_CHANGE_PASS">
	   <div class="text-block">     
	    <input type="submit" class="submit" value="تایید">
      <input name="text_box_admin_panel_change_pass_old_pass" class="numbers" type="number" value="" min="100000" max="999999" spellcheck="false" placeholder="OLD" required>رمز جدید
      <input name="tex_box_admin_panel_change_pass_new_pass"  class="numbers" type="number"value="" min="100000" max="999999" spellcheck="false" placeholder="NEW" required> &nbsp رمز قدیم
	   </div>
 	 </form>
     <div class="text-help">برای تغییر رمز مدیریت رمز قدیم و جدید را وارد کرده و دکمه تایید را بزنید</div>
    <div class="text-help">توجه! بعد از تغییر رمز، ارتباط قطع می شود و می بایست مجدد با رمز جدید وارد شوید</div>
	</li> 
  </ul>
</nav>
<!-- Form for Change WiFi INFO -->
<nav>
  <label for="touch6"><span>تغییر نام و رمز وای فای</span></label>               
  <input type="checkbox" id="touch6"> 
  <ul class="slide">
    <li>	
      <form method="post" action="ADMIN_PANEL_CHANGE_PASS_WIFI">
         <div class="text-block">
	         <input type="submit" class="submit" value="تایید">
	           <input name="texy_box_admin_panel_change_pass_wifi_repate_pass" type="number" required class="numbers" value=""  max="9999999" spellcheck="false" placeholder="تکرار رمز">
	           <input name="text_box_admin_panel_change_pass_wifi_wifi_pass" type="number" required class="numbers" value=""  max="9999999" spellcheck="false" placeholder="رمز جدید">
	           <input name="text_box_admin_panel_change_pass_wifi_wifi_name" type="text" value=""  spellcheck="false"  required required class="name" placeholder="نام وای فای">
		       </div>
       </form>	
<div class="text-help">نام و رمز جدید را وارد کرده و دکمه تایید را بزنید. قبل از تایید حتما رمز را یادداشت کنید</div>
<div class="text-help">توجه! بعد از تغییر رمز، ارتباط قطع می شود و می بایست مجدد با رمز جدید وارد شوید</div>
	</li> 
  </ul>
</nav>
	  <!-- Form for set time -->
<nav>
  <label for="touch7"><span>تنظیم ساعت</span></label>               
  <input type="checkbox" id="touch7"> 
  <ul class="slide">
    <li>	
    <form method="post" action="ADMIN_PANEL_SET_TIME">
     <div class="text-block">
	   <input type="submit" class="submit" value="تایید">
        <input name="text_admin_panel_set_time_hour" type="number" required class="numbers" max="23" placeholder="0-23"><strong>دقیقه</strong>
		 <input name="text_admin_panel_set_time_minute" type="number" required class="numbers" max="59" placeholder="0-59"><strong>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp ساعت</strong>
  		 </div>
	  </form>
<div class="text-help">برای تنظیم ساعت، ساعت و دقیقه را به صورت 24 ساعتی وارد و دکمه تایید را بزنید </div>
	</li> 
  </ul>
</nav>
	  <!-- Form For date -->
<nav>
  <label for="touch8"><span>تنظیم تاریخ</span></label>               
  <input type="checkbox" id="touch8"> 
  <ul class="slide">
    <li>
    <form method="post" action="ADMIN_PANEL_SET_DATE">
	  <div class="text-block">
      <input type="submit" class="submit" value="تایید" >
	  <input name="text_admin_panel_set_date_year" type="number" required class="numbers" min="2024" placeholder="سال میلادی">
	  <input name="text_admin_panel_set_date_month" type="number" required class="numbers" placeholder="ماه">
	  <input name="text_admin_panel_set_date_day" type="number" required class="numbers" placeholder="روز">
			  </div>
    </form>
		<div class="text-help">تاریخ را به میلادی وارد کرده و دکمه تایید را بزنید </div>
	</li> 
  </ul>
</nav>	


<nav>

  <label for="touch9"><span>اطلاعات دستگاه</span></label>               
  <input type="checkbox" id="touch9"> 

  <ul class="slide">
    <li>	
    <form method="post" action="ADMIN_PANEL_SHOW_TIME">
      <div class="text-block">
		<input type="submit" class="submit2" value="دریافت اطلاعات دستگاه"><strong>&nbsp</strong>
		</div> 
      </form>
		<div class="text-help">اطلاعات دستگاه شامل سریال، زمان، رمز مدیر، نام و رمز وای فای است</div>
	</li> 
  </ul>
</nav> 
				<!-- Form for Conect to Server -->
<nav>

  <label for="touch10"><span>تنظیمات شبکه</span></label>               
  <input type="checkbox" id="touch10"> 

  <ul class="slide">
    <li>	
    <form method="post" action="ADMIN_PANEL_MODEM_SETING">
      <div class="text-block">
		<input type="submit" class="submit2" value="ورود"><strong>&nbsp</strong>
		</div> 
      </form>
		<div class="text-help">برای تنظیم مودم اینترنت و ارتباط با سرور نرم افزار حسابداری وارد شوید</div>
	</li> 
  </ul>
</nav> 
				<!-- Form for Defult setting -->
<nav>

  <label for="touch11"><span>بازگردانی به تنظیمات کارخانه</span></label>               
  <input type="checkbox" id="touch11"> 

  <ul class="slide">
    <li>	
    <form method="post" action="ADMIN_PANEL_DEFULT_SETING_SELECT">
      <div class="text-block">
		<input type="submit" class="submit2" value="ورود"><strong>&nbsp</strong>
		</div> 
      </form>
		<div class="text-help">برای حذف تمام اطلاعات دستگاه و بازگردانی به تنظیمات پیش فرض کارخانه وارد شوید</div>
	</li> 
  </ul>
</nav> 
  </div>
 
<nav><label for="touch13"><span>آپلود اطلاعات گروه</span></label><input type="checkbox" id="touch13"><ul class="slide"><li><form method="post" action="ADMIN_PANEL_UPLOAD_FILE_0"><div class="text-block">
<input type="submit" class="submit2" value="آپلود اطلاعات دستگاه"><strong>&nbsp</strong>
</div></form><div class="text-help"><p>فایل اطلاعات را از بخش مدیریت کاربران و بخش دریافت اطلاعات واحدها دریافت کنید و در این قسمت بار

</body>
</html>

  )rawliteral";

const char SELECT_OP[] PROGMEM =
R"rawliteral(


<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>select menu</title>
<style>
	body {
	  background-color:#000000;
		font-size: 2.5em;
		color: #FDA500;
		text-align: center;
		margin-top: 200px;
		line-height: 3;
		}
	#setting {
	background-color: #FDA500;
	width: 60% ;
	color: #FFFFFF;
	font-size: 1.5em;
	text-align: center;
		}
	#user {
	background-color: #FDA500;
	width: 60% ;
	font-size: 1.5em;
	color: #FFFFFF;
	text-align: center;
		margin-bottom: 40px;
		}
</style>
</head>
<body>
<strong>MANAHOOR-PRO</strong></div>
	     <form method="post" action="USER_PANEL">
      <input type="submit" id="user"  value="مدیریت کاربران">
  </form>
		 <form method="post" action="ADMIN_PANEL">
      <input type="submit" id="setting" value="تنظیمات">
    </form>
</div>
</body>
</html>

  )rawliteral";

  const char LOGIN[] PROGMEM =
R"rawliteral(
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Select Page</title>
<style>
	body {
	background-color:#000000;
	font-size: 2em;
	color: #FDA500;
	text-align: center;
	margin-top: 200px;
				}
	#setting {
	background-color: #FDA500;
	width: 60% ;
	color: #FFFFFF;
	font-size: 1.2em;
	text-align: center;
		}
	#user {
	background-color: #FDA500;
	width: 80% ;
	font-size: 1.5em;
	color: #FFFFFF;
	text-align: center;
		margin-bottom: 50px;
		}
	.frame {
	background-color: #FFFFFF;
	color: #000000;
	text-align: center;
	font-family: Cambria, "Hoefler Text", "Liberation Serif", Times, "Times New Roman", "serif";
	font-size: 1.2em;
	width: 80%;
	padding: 10px 0px 20px 0px;
	align-items: center;
	margin: 10% 10% 10% 10%;
	}
		.group-num {
	background-color: #FDFFE2;
	width: 40%;
	height: 70px;
	font-size: 1.5em;
	text-align: center;
	margin: 10px 4% 5% 4%;
		}
</style>
</head>
<body>
<strong>MANAHOOR-PRO</strong>
        <form name="form_management" method="post" action="LOGIN" enctype="multipart/form-data" >
       <input type="submit" id="user"  value="ورود به پنل مدیریت">
       </form>
<div class="frame"><p>کلید ورود</p> 
<form name="form_logn" method="post" action="LOGIN_PANEL_OPEN_RELAY" enctype="multipart/form-data" >
<input name="text_login_panel_group_password" type="number" required class="group-num" placeholder="رمز واحد" max="99999" min="10001">
<input name="text_login_panel_group_number" type="number" required class="group-num" placeholder="شماره واحد" max="999" min="0">
<input name="sub_login" type="submit" id="setting" value="ورود">
        </form>
</div>
</body>
</html>

  )rawliteral";

const char DEFULT_SETING[] PROGMEM=
R"rawliteral(

<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Select Page</title>
<style>
	body {
	background-color:#FFFFFF;
	font-size: 1em;
	color: #000000;
	text-align: center;
	margin-top: 200px;
		}
	#add {
	background-color: #FDA500;
	width: 50% ;
	color: #FFFFFF;
	font-size: 1.5em;
	text-align: center;
	margin-top: 30px;
		}
.frame {
		background-color: #E2FFFC;
		color: #000000;
		text-align: center;
		font-family: Cambria, "Hoefler Text", "Liberation Serif", Times, "Times New Roman", "serif";
		font-size: 1.5em;
		width: 90%;
		padding: 10px 10px 20px 10px;
		align-items: center;
		margin: 10% 5% 10% 5%;
	}
</style>
	<script>
function submitadmin_panel_defult_setings()
{
   var regexp;
   var RadioButton1 = document.getElementsByName('Name');
   if (!(RadioButton1[0].disabled ||
         RadioButton1[0].style.display === 'none' ||
         RadioButton1[0].style.visibility === 'hidden'))
   {
      var selected = false;
      for (i=0;i<RadioButton1.length;i++)
      {
         if (RadioButton1[i].checked)
            selected = true;
      }
      if (!selected)
      {
          alert("لطفا بعد از خواندن تذکر، تیک مطالعه شد را بزنید");
         return false;
      }
   }
   return true;
}
</script>
</head>
<body>
	<div class="frame">
	        <h1 style="color: red;">تذکر</h1>
		     <p>بعد از بازگردانی به تنظیمات کارخانه، تمامی اطلاعات ذخیره شده روی دستگاه شامل اطلاعات کاربران و تنظیمات دستگاه پاک شده و به حالت پیش فرض باز می گردد</p>
		
         <form method="post" action="ADMIN_PANEL_DEFULT_SETING" onsubmit="return submitadmin_panel_defult_setings()">
             <label>
                <input type="radio" name="Name" value="1" > <strong>مطالعه شد</strong>
             </label>
             <br>
             <input type="submit" id="add" value="تایید">
         </form>
</div>
</body>

    )rawliteral";

    const char WITE_WEB_PAGES[] PROGMEM=
R"rawliteral(
 
 <!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
  <title>Countdown and Form Submission</title>
  <style>
    body {
      font-family: Cambria, "Hoefler Text", "Liberation Serif", Times, "Times New Roman", "serif";
      text-align: center;
      background-color: #f0f0f0;
      padding: 20px;
    }
    
   .title {
      color: #333;
		font-size: 2em;
		text-align: center;
    }
    
    #countdown {
      font-size: 3em;
      font-weight: bold;
		text-align: center;
      margin: 20px 0;
    }
  </style>
</head>
<body>
	<div class="title"> :) لطفا صبر کنید در حال آماده سازی داده ها هستم </div>
  <p id="countdown">6</p>
  <form id="myForm" action="/USER_PANEL_DOWNLOAD_DATA" method="POST" style="display: none;">
  </form>
  <script>
    function countdown() {
      let counter = 6;
      const counterElement = document.getElementById('countdown');
      const form = document.getElementById('myForm');
      const interval = setInterval(() => {
        counterElement.textContent = counter;
        counter--;
        if (counter < 0) {
          clearInterval(interval);
          form.submit();
        }
      }, 1000);
    }
    countdown();
  </script>
</body>
</html>
 )rawliteral";



    const char UPDATE_WEB_PAGES[] PROGMEM=
R"rawliteral(
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Simple Forms</title>
<style>
body {
    background-color: #E6E6FA;
    text-align: center;
    margin: 0;
    padding: 20px;
}
form {
    background-color: #F0F0F0;
    border: 1px solid #CCCCCC;
    border-radius: 8px;
    padding: 20px;
    margin: 10px auto;
    display: inline-block;
    max-width: 600px;
    width: 100%;
               display: flex;
            flex-direction: column;
            gap: 10px; /* فاصله بین عناصر */
}

.radio-group input {
  margin-right: 10px; /* فاصله بیشتر بین گزینه‌های رادیویی و برچسب‌ها */
}
.radio-group label {
  margin-right: 60px; /* فاصله بیشتر بین برچسب‌ها */
  font-weight: bold;
}

</style>
</head>
<body>

<form name="Form11" method="post" action="UPDATE_PAGE_SET_STATUS_SERVER_CONCTED">
<h2>وضعیت اتصال به شبکه</h2>
<label for="text_state_conected">وضعیت اتصال فعال / غیرفعال</label><br>
<div class="radio-group">
<input type="radio" id="RadioButton1" name="text_state_conected" value="0" required>
<label for="RadioButton1">فعال</label>
<input type="radio" id="RadioButton2" name="text_state_conected" value="1" required>
<label for="RadioButton2">غیرفعال</label>
</div>
<input type="submit" id="Button8" name="SUB_STATE_CONECTED" value="ارسال">
</form>

<form name="Form1" method="post" action="UPDATE_PAGE_CHANGE_MODEM">
    <h2>تنظیمات اتصال به مودم</h2>
    <label for="text_setings_change_modem_wifi_wifi_name">نام وای فای</label>
    <input type="text" id="text_setings_change_modem_wifi_wifi_name" name="text_update_setings_change_modem_wifi_wifi_name" placeholder="نام وای فای" maxlength="32" required>

    <label for="text_setings_change_modem_wifi_wifi_pass">رمز وای فای</label>
    <input type="text" id="text_setings_change_modem_wifi_wifi_pass" name="text_update_setings_modem_output_wifi_wifi_pass" placeholder="رمز وای فای" maxlength="62" required>

    <input type="submit" id="Button2" name="SUB_SETINGS_CHANGE_WIFI_MODEM" value="ارسال">
</form>

<form name="ServerSettingsForm" method="post" action="UPDATE_PAGE_CHANGE_SERVER_INFO">
    <h2>تنظیمات سرور</h2>
    <label for="server_address">آدرس سرور</label>
    <input type="text" id="server_address" name="text_update_setings_conected_server_address" placeholder="آدرس سرور" required>

    <label for="server_password">رمز سرور</label>
    <input type="text" id="server_password" name="text_update_setings_conected_server_password" placeholder="رمز سرور" minlength="1" required>

    <input type="submit" id="Button3" name="SUB_SETINGS_CHANGE_SERVER_OUTPUT" value="ارسال">
</form>
<form name="UpdateIntervalForm" method="post" action="UPDATE_PAGE_SET_UPDATE_INTERVAL">
    <h2>زمان‌بندی آپدیت</h2>
    <label for="update_interval">دقیقه (۲ تا ۶۰)</label>
    <input type="number" id="update_interval" name="update_interval_minutes" placeholder="مثال: 30" min="2" max="60" required>
    <input type="submit" id="ButtonUpdateInterval" name="SUB_UPDATE_INTERVAL" value="تایید">
</form>
<form name="ReportForm" method="post" action="UPDATE_PAGE_REPORT_LAST_UPDATE">
    <input type="submit" id="Button5" name="REPORT_LAST_UPDATE" value="گزارش آخرین آپدیت">
</form>

<form name="TestServerForm" method="post" action="WITE_UPDATE_WEB_PAGES">
    <input type="submit" id="Button6" name="TEST_SERVER" value="تست سرور">
</form>
</body>
</html>

 )rawliteral";

const char WITE_UPDATE_WEB_PAGES[] PROGMEM=
R"rawliteral(

<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
</head>
<body>
<h1 align="center"> :) لطفا صبر کنید در حال آماده سازی داده ها هستم </h1>
<h1 align="center" id="countdown">15</h1>
<form id="myForm" action="/UPDATE_PAGE_TEST_SERVER" method="POST" style="display: none;">
</form>
<script>
function countdown() {let counter = 15;const counterElement = document.getElementById('countdown');const form = document.getElementById('myForm');
const interval = setInterval(() => {counterElement.textContent = counter;counter--;
if (counter < 0) {clearInterval(interval);form.submit();}}, 1000);}
countdown();
</script>
</body>
</html>
 )rawliteral";


 const char WITE_GET_PASS_WEB_PAGES[] PROGMEM=
R"rawliteral(

<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
</style>
</head>
<body>
<h1 align="center"> :) لطفا صبر کنید در حال آماده سازی داده ها هستم </h1>
<h1 align="center" id="countdown">20</h1>
<form id="myForm" action="/USER_PANEL_SEND_ALL_PASS" method="POST" style="display: none;">
</form>
<script>
function countdown() {let counter = 20;const counterElement = document.getElementById('countdown');const form = document.getElementById('myForm');
const interval = setInterval(() => {counterElement.textContent = counter;counter--;
if (counter < 0) {clearInterval(interval);form.submit();}}, 1000);}
countdown();
</script>
</body>
</html>
 )rawliteral";





