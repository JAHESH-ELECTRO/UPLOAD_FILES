#pragma once

#define RED_LED    7
#define BLUE_LED   2
#define BUZZER     3
#define RELAY      5
#define WATCH_DOG  45
class Gpio_Oprations
{
  char gpio_red,gpio_blue,buzzer,relay_,reset_pin;
  char watch_dog_;
public:
	Gpio_Oprations();

  void blink_leds();
  void Gpio_init(char red_led,char blue_led,char buzzer,char relay,char mrfc522_reset,char watch_dog);
  void test_all();
  void set_key_to_tag();



void Okeyy();
void Erorr();

void Okeyy_recive();
void Erorr_access();

void buzzer_on();
void buzzer_off();
void blue_on();
void blue_off();
void red_on();
void red_off();
void relay_on();
void relay_off();
void reset_mrfc522();

void tag_not_autho();
void set_tag_okey();

void watch_dog_on();

	~Gpio_Oprations();
};

