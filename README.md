# **��ԴӲ��ʵս��ҵ** ������ 18010500055
> �ڿν�ʦ��damo���������£�
���|�汾��|����
-|-|-
Visual Studio|15.9.3|2019.7.2
Arduino|1.8.9|2019.7.3
## �����ļ�����ֱ������ε�**��ҵ**
# ����һ�� **2019.7.2**
## �˽����������������������
#### ������һ���ѧϰ֮�����˽⵽�˿�ԴӲ��ʵս�ľ�������ʲô�ģ�����ʲô������Ҫȥ��ʲô���˽�ʲô�������������ں������ڸδ����׼��hhhhhh,��һ�컹������Arduino��processing��fritizing�������hhhhh�����Ҿ�����һ���ѧϰ֮��о���ʦ��ĺ�������
##### ���������ص����һֱû�õ���processing��fritizing��
# ���ڶ��� **2019.7.3**
####�ڶ�����Ҫ���˿⺯����д��ʽ��ʹ��
## ��ҵ morse�����д
## ��������
'''morse.ino
#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_dottime=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*4);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*3);
}

void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*7);
}

'''
## ͷ�ļ�����˵��
'''Morse.h
#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};
#endif /*_MORSE_H*/
'''
'''Morse.cpp
#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_dottime=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*4);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*3);
}

void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*7);
}

'''
'''keywords.txt
Morse	KEYWORD1
dash	KEYWORD2
dot		KEYWORD2
'''
### tinkercadͼƬ��ͼ
![Image text](https://github.com/qiyinxi/morse-/blob/master/7%E6%9C%883%E6%97%A5%E6%91%A9%E5%B0%94%E6%96%AF/morse_tinkercad.JPG)
##### д������
# �������� **2019.7.4**
## С��������
### ��������
'''car_led&motor.ino
#define left_led 7
#define right_led 8
#define dit digitalWrite
#define for_led 11
#define sto_led 12
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(left_led,OUTPUT);
  pinMode(right_led,OUTPUT);
  pinMode(for_led,OUTPUT);
  pinMode(sto_led,OUTPUT);
  Serial.begin(9600);
}

int income=0;

void loop()
{
  while(1)
  {
    income=Serial.read();
    switch(income)
    {
      case 'f':
      forward();break;
      case 'b':
      backword();break;
      case 'r':
      right();break;
      case 's':
      stop();break;
      case 'l':
      left();break;
      default:break;
    }
  }
}
void forward()
{
  dit(5,HIGH);
  dit(10,HIGH);
  dit(6,LOW);
  dit(9,LOW);
  dit(sto_led,LOW);
  dit(right_led,LOW);
  dit(for_led,HIGH);
  dit(left_led,LOW);
}
void backword()
{
  dit(6,HIGH);
  dit(9,HIGH);
  dit(5,LOW);
  dit(10,LOW);
  dit(sto_led,HIGH);
  dit(right_led,LOW);
  dit(for_led,LOW);
  dit(left_led,LOW);
}
void right()
{
  dit(5,HIGH);
  dit(10,HIGH);
  dit(6,LOW);
  dit(9,LOW);
  dit(sto_led,LOW);
  dit(right_led,HIGH);
  dit(for_led,LOW);
  dit(left_led,LOW);
}
void left()
{
  dit(6,HIGH);
  dit(10,HIGH);
  dit(5,LOW);
  dit(9,LOW);
  dit(sto_led,LOW);
  dit(right_led,LOW);
  dit(for_led,LOW);
  dit(left_led,HIGH);
}
void stop()
{
  dit(5,LOW);
  dit(10,LOW);
  dit(6,LOW);
  dit(9,LOW);  
  dit(sto_led,HIGH);
  dit(right_led,LOW);
  dit(for_led,LOW);
  dit(left_led,LOW);
}
'''
### tinkercadͼƬ��ͼ
![Image text](https://github.com/qiyinxi/morse-/blob/master/7%E6%9C%884%E6%97%A5%E5%B0%8F%E8%BD%A6%E7%81%AF/car_led%26motor_tinkercad.JPG)
## ������ҵ��7�������
### ��������
'''7seg_led.ino
#define pin pinMode
#define out OUTPUT
#define READ Serial.read
#define wri digitalWrite
#define A1 2
#define A2 3
#define A3 4
#define A4 5
#define LT 10
#define LE 8
#define BI 9
void setup()
{
  pin(A1,out);
  pin(A2,out);
  pin(A3,out);
  pin(A4,out);
  pin(LT,out);
  pin(LE,out);
  pin(BI,out);
  Serial.begin(9600);
  wri(LE,LOW);
wri(LT,HIGH);
wri(BI,HIGH);
}

  int git;
void loop()
{
  delay(50);
  wri(LE,HIGH);
if(Serial.available()>0)
{
  git=READ();
  Serial.write(git);
}
  git=git-'0';
  show(git);
  delay(50);
  wri(LE,LOW);
}

char show(char g)
{
  if(g&1)
  wri(A1,HIGH);
  else
  wri(A1,LOW);
  if(g&1<<1)
  wri(A2,HIGH);
  else
  wri(A2,LOW);
  if(g&1<<2)
  wri(A3,HIGH);
  else
  wri(A3,LOW);
  if(g&1<<3)
  wri(A4,HIGH);
  else
  wri(A4,LOW);
  return 0;
}
'''
### tinkercadͼƬ��ͼ
![Image text](https://github.com/qiyinxi/morse-/blob/master/7%E6%9C%884%E6%97%A57%E6%AE%B5%E6%95%B0%E7%A0%81%E7%AE%A1/7seg_led_tinkercad.png)
###### ����ʦ�Ͽ�û��������
# �������� **2019.7.5**
## md�ļ���д������ͼ���д���
# ��ʦ����������ſ��ջ���Ķ࣡����