# **开源硬件实战作业** 赵子旭 18010500055
> 授课教师：damo王（张力月）
软件|版本号|日期
-|-|-
Visual Studio|15.9.3|2019.7.2
Arduino|1.8.9|2019.7.3
## 三个文件夹里分别是三次的**作业**
# ·第一天 **2019.7.2**
## 了解各种软件，与三个软件下载
#### 经过第一天的学习之后，我了解到了开源硬件实战的具体是做什么的，能做什么，我需要去做什么和了解什么，并且做好了在后三天内肝代码的准备hhhhhh,第一天还介绍了Arduino、processing、fritizing三个软件hhhhh，而且经过第一天的学习之后感觉老师真的好厉害。
##### 有两个下载的软件一直没用到（processing、fritizing）
# ·第二天 **2019.7.3**
####第二天主要讲了库函数编写形式和使用
## 作业 morse代码编写
## 代码如下
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
## 头文件与类说明
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
### tinkercad图片如图
![Image text](https://github.com/qiyinxi/morse-/blob/master/7%E6%9C%883%E6%97%A5%E6%91%A9%E5%B0%94%E6%96%AF/morse_tinkercad.JPG)
##### 写到贼晚
# ·第三天 **2019.7.4**
## 小车马达与灯
### 代码如下
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
### tinkercad图片如图
![Image text](https://github.com/qiyinxi/morse-/blob/master/7%E6%9C%884%E6%97%A5%E5%B0%8F%E8%BD%A6%E7%81%AF/car_led%26motor_tinkercad.JPG)
## 晚上作业是7段数码管
### 代码如下
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
### tinkercad图片如图
![Image text](https://github.com/qiyinxi/morse-/blob/master/7%E6%9C%884%E6%97%A57%E6%AE%B5%E6%95%B0%E7%A0%81%E7%AE%A1/7seg_led_tinkercad.png)
###### （老师上课没做出来）
# ·第四天 **2019.7.5**
## md文件编写与流程图还有答疑
# 老师真棒！报这门课收获真的多！！！