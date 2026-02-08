const char USER_PANEL[] PROGMEM =
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
	border-color: #00FFFF;
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
  background : #00FFFF;
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
#touch6 {position: absolute; opacity: 0; height: 0px;}    
#touch6:checked + .slide {height: 150px;}
	@media(max-width: 768px) {
      .frame {
        width: 100%;
      }
	</style>
</head>
<body>
	<div class="frame">
<div class="header">
		<div id="text-header"><strong>MANAHOOR_TAG_Reader</strong></div>
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
		<div class="text-help">شماره واحد را وارد نمایید و دکمه تایید را بزنید، دستگاه شروع به بوق زدن کرده و می توانید تگ های واحد را برای صدور مقابل کارتخوان قرار دهید</div>
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
 
<!-- Form for Deleting User Tag -->
<nav>
  <label for="touch3"><span>حذف تگ های واحد</span></label>               
  <input type="checkbox" id="touch3"> 
  <ul class="slide">
    <li>	
	<form method="post" action="USER_PANEL_DELETE_TAG">
      <div class="text-block">
	  <input type="submit" class="submit" value="تایید">
      <input name="texbox_userpanel_delete_user_get_group" type="number"  required class="group-num" max="999" min="0">
	  شماره واحد
	  </div>
     </form>	
<div class="text-help">برای حذف تگ های یک واحد، شماره واحد را وارد و دکمه تایید را بزنید</div>
	</li> 
  </ul>
</nav>
  </div>

<div class="text-help">با فعال شدن رمز پویا، رمز ثابت تمام واحدها غیر از واحد صفر غیرفعال می شود و با غیرفعال کردن رمزپویا، رمز ثابت فعال می شود</div></li></ul></nav>
<nav><label for="touch6"><span>فعال ساز اپلیکیشن کاربر</span></label><input type="checkbox" id="touch6"><ul class="slide"><li><form method="post" action="USER_PANEL_SHOW_APP_PASS"><div class="text-block">
<input type="submit" class="submit" value="تایید">
<input name="texbox_userpanel_app_pass" type="number" required class="group-num" max="99999" >شماره واحد
<input name="texbox_userpanel_group_numbers" type="number" required class="group-num" max="999" min="0"> &nbsp سریال موبایل
</div></form>

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
			border-color: #00FFFF;
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
  background : #00FFFF;
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
	@media(max-width: 768px) {
      .frame {
        width: 100%;
      }
	</style>
</head>
<body>
	<div class="frame">
<div class="header">
		<div id="text-header"><strong>MANAHOOR_TAG_Reader</strong></div>
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
 <!-- Form for Change manager password -->	
<nav>
  <label for="touch4"><span>تغییر رمز مدیریت</span></label>               
  <input type="checkbox" id="touch4"> 
  <ul class="slide">
    <li>		
    <form method="post" action="ADMIN_PANEL_CHANGE_PASS">
	   <div class="text-block">     
	    <input type="submit" class="submit" value="تایید">
      <input name="text_box_admin_panel_change_pass_old_pass" class="numbers" type="number" value="olde" min="100000" max="999999" spellcheck="false" placeholder="OLD" required >رمز جدید
      <input name="tex_box_admin_panel_change_pass_new_pass"  class="numbers" type="number" value="new" min="100000" max="999999" spellcheck="false" placeholder="NEW" required> &nbsp رمز قدیم
	   </div>
 	 </form>
<div class="text-help">برای تغییر رمز مدیریت ابتدا رمز قدیم و بعد رمز جدید را وارد کرده و دکمه تایید را بزنید</div>
	</li> 
  </ul>
</nav>
<!-- Form for Change WiFi INFO -->
<nav>
  <label for="touch5"><span>تغییر نام و رمز وای فای</span></label>               
  <input type="checkbox" id="touch5"> 
  <ul class="slide">
    <li>	
    <form method="post" action="ADMIN_PANEL_CHANGE_PASS_WIFI">
    <div class="text-block">
	<input type="submit" class="submit" value="تایید">
	<input name="texy_box_admin_panel_change_pass_wifi_repate_pass" type="number" required class="numbers" value=""  max="9999999" spellcheck="false" placeholder="تکرار رمز">
	<input name="text_box_admin_panel_change_pass_wifi_wifi_pass" type="number" required class="numbers" value=""  max="9999999" spellcheck="false" placeholder="رمز جدید">
	<input name="text_box_admin_panel_change_pass_wifi_wifi_name" type="text" value=""  spellcheck="false"  required class="name" placeholder="نام وای فای">
		</div>
     </form>	
<div class="text-help">نام و رمز جدید را وارد کرده و دکمه تایید را بزنید. قبل از تایید حتما رمز را یادداشت کنید</div>
	</li> 
  </ul>
</nav>
			<!-- Form for Device info -->
<nav>

  <label for="touch6"><span>اطلاعات دستگاه</span></label>               
  <input type="checkbox" id="touch6"> 

  <ul class="slide">
    <li>	
    <form method="post" action="ADMIN_PANEL_SHOW_TIME">
      <div class="text-block">
		<input type="submit" class="submit2" value="دریافت اطلاعات دستگاه"><strong>&nbsp</strong>
		</div> 
      </form>
		<div class="text-help">اطلاعات دستگاه شامل سریال دستگاه، رمز مدیر، نام و رمز وای فای است</div>
	</li> 
  </ul>
</nav> 
				<!-- Form for Defult setting -->
<nav>

  <label for="touch7"><span>بازگردانی به تنظیمات کارخانه</span></label>               
  <input type="checkbox" id="touch7"> 

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
</body>
</html>

  )rawliteral";

const char SELECT_OP[] PROGMEM =
R"rawliteral(


<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Select Page</title>
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
<strong>MANAHOOR_TAG_Reader</strong>
	<form method="post" action="USER_PANEL">
      <input type="submit" id="user"  value="مدیریت کاربران">
  </form>
	<form method="post" action="ADMIN_PANEL">
      <input type="submit" id="setting" value="تنظیمات">
   </form>
</body>
</html>
  )rawliteral";

const char LOGIN[] PROGMEM =
R"rawliteral(
<!doctype html><html><head><meta charset="utf-8"><title>Select Page</title><style>body{background-color:#000000;font-size:2em;color:#FDA500;text-align:center;margin-top:200px;}
#setting{background-color:#FDA500;width:60%;color:#FFFFFF;font-size:1.2em;text-align:center;}#user{background-color:#FDA500;width:80%;font-size:1.5em;color:#FFFFFF;text-align:center;margin-bottom:50px;}
.frame{background-color:#FFFFFF;color:#000000;text-align:center;font-family:Cambria,"Hoefler Text", "Liberation Serif", Times, "Times New Roman", "serif";font-size: 1.2em;width:80%;padding: 10px 0px 20px 0px;align-items:center;margin: 10% 10% 10% 10%;}
.group-num{background-color:#FDFFE2;width:40%;height:70px;font-size:1.5em;text-align:center;margin: 10px 4% 5% 4%;}</style></head><body>
<strong>MANAHOOR-SMART</strong><form name="form_management" method="post" action="USER_PANEL" enctype="multipart/form-data" ><input type="submit" id="user"  value="ورود به پنل مدیریت"></form><div class="frame"><p>باز کردن درب و آسانسور با اپلیکیشن</p> <form name="form_logn" method="post" action="LOGIN_PANEL_OPEN_RELAY" enctype="multipart/form-data" ><input name="text_login_panel_group_password" type="number" required class="group-num" placeholder="رمز واحد" max="99999" min="10001"><input name="text_login_panel_group_number" type="number" required class="group-num" placeholder="شماره واحد" max="999" min="0"><input name="sub_login" type="submit" id="setting" value="کلید ورود"></form></div></body></html>
  )rawliteral";

  





const char DEFULT_SETING[] PROGMEM=
R"rawliteral(
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Back to Defult</title>
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
</html>
    )rawliteral";