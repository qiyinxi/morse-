# **开源硬件实战总结**  
> 撰写：赵子旭 18010500055
> 授课教师：damo王  
*******************************
|     软件    |版本号|   日期|
|-------------|------|-------- | 
|Visual Studio|15.9.3|2019.7.2|
|Arduino      |1.8.9 |2019.7.3|
*******************************
## 三个文件夹里分别是三次的**作业**
# ·第一天 **2019.7.2**
## 了解各种软件，与三个软件下载
#### 经过第一天的学习之后，我了解到了开源硬件实战的具体是做什么的，能做什么，我需要去做什么和了解什么，并且做好了在后三天内肝代码的准备hhhhhh,第一天还介绍了Arduino、processing、fritizing三个软件hhhhh，而且经过第一天的学习之后感觉老师真的好厉害。
##### 有两个下载的软件一直没用到（processing、fritizing）
# ·第二天 **2019.7.3**
#### 第二天主要讲了库函数编写形式和使用
在第二天的学习中，在做morse的过程中学到了头文件和库函数的使用方法和编写，还初步了解了c++/java中类的概念。  
知晓了morse码的转译方法和用tinkercad做简单的模拟，还有部分中文morse码，除了学会Arduino中基础库的操作之外，还了解了uno中串口的部分函数以及使用方式。  
## 作业 morse代码编写  
代码如下：  
morse.ino  
```
#include <Morse.h>
#define b break
#define do_t morse.dot
#define da   morse.dash
  Morse morse(13);
  String str = "";
  
  void trans(int n)
  {
    switch(n)
    {
    case 97:str="*-  ";b;//a
    case 98:str="-***";b;//b
    case 99:str="-*-*";b;//c
    case 100:str="-** ";b;//d
    case 101:str="*   ";b;//e
    case 102:str="**-*";b;//f
    case 103:str="--* ";b;//g
    case 104:str="****";b;//h
    case 105:str="**  ";b;//i
    case 106:str="*---";b;//j
    case 107:str="-*- ";b;//k
    case 108:str="*-**";b;//l
    case 109:str="--  ";b;//m
    case 110:str="-*  ";b;//n
    case 111:str="--- ";b;//o
    case 112:str="*--*";b;//p
    case 113:str="--*-";b;//q
    case 114:str="*-* ";b;//r
    case 115:str="*** ";b;//s
    case 116:str="-   ";b;//t
    case 117:str="**- ";b;//u
    case 118:str="***-";b;//v
    case 119:str="*-- ";b;//w
    case 120:str="-**-";b;//x
    case 121:str="-*--";b;//y
    case 122:str="--**";b;//z
    case 32:str="*-*-";b;//空格
    case 10:str="----";b;//回车
    default:b;
    }
  }
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int getread;
  while(Serial.available()>0)
  {
  getread = Serial.read();
  // put your main code here, to run repeatedly:
  trans(getread);
  int i;
  for(i=0;i<4;i++)
  {
    if(str[i]=='*')
   do_t();
    if(str[i]=='-')
   da();
    delay(50);
  }
  delay(300);
  str="";
}
}


```
## 头文件与类说明
Morse.h
```
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
```
Morse.cpp
```
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

```
keywords.txt
```
Morse	KEYWORD1
dash	KEYWORD2
dot		KEYWORD2
```
### tinkercad图片如图
![Image text](https://github.com/qiyinxi/morse-/blob/master/7%E6%9C%883%E6%97%A5%E6%91%A9%E5%B0%94%E6%96%AF/morse_tinkercad.JPG)
>	当天晚上写作业写到了十二点多快一点，morse输出的判断条件总是写成  
>   >	while(Serial.read()>0);  
>	然而实际上应该是  
>   >	while(Serial.available()>0);  
>	找了半天没找到就很难受，第三天的7seg_led作业判断也是忘记了没找到，找了两个小时，非常难受。  
# ·第三天 **2019.7.4**
## 课上 小车马达与灯
了解了直流电机的模拟方法，且课上老师说现实生活中电机并不能仅仅使用uno板子所提供的电流做驱动，经了解后我知晓了继电器的存在。  
在小车电路搭建完成之后，老师让我们自己去在往上面加led灯，我选择加直行左转右转后退一共四个灯，每一种状态下都有不同的灯会亮，后退和刹车时一个灯，与现实生活相符。  
而后老师讲起了7seg_led和cd4511的使用方法，首先是使用芯片会节约io口，然后还让我们知道了如果想使用一个芯片，首先要去网上等其他途径去找到芯片的使用说明，然后根据说明搭建电路，由于时间过短老师并没有在搭建完成成功写代码模拟出来，于是便成为了我们的作业。  
经过这节课，我了解了如何去搭建一个较为复杂的电路和其他芯片的使用方法。  
代码如下：  
car_led&motor.ino  
```
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
```
### tinkercad图片如图
![Image text](https://github.com/qiyinxi/morse-/blob/master/7%E6%9C%884%E6%97%A5%E5%B0%8F%E8%BD%A6%E7%81%AF/car_led%26motor_tinkercad.JPG)
## 晚上作业是7段数码管
代码如下：  
7seg_led.ino  
```
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
```
### tinkercad图片如图
![Image text](https://github.com/qiyinxi/morse-/blob/master/7%E6%9C%884%E6%97%A57%E6%AE%B5%E6%95%B0%E7%A0%81%E7%AE%A1/7seg_led_tinkercad.png)
###### （老师上课没做出来）
# ·第四天 **2019.7.5**
## md文件编写与流程图还有答疑
老师上课讲了.md文件以及流程图的制作，github的更多操作，包括git的使用方法。
> 程序员就应该专心写代码没有其他纷扰hhh
# 老师真棒！报这门课收获真的多！！！
在这四天内学到了好多将来才会学到的知识点比如部分c++中的语法，还有电子电路的搭建、电子芯片的使用、数字信号的编码和转码，而且还对上学期微处理器原理中的一些概念比如IO口、串口等进行了回顾，让以前学过的知识也变得更加牢固，上了老师的课之后让我更下决心打算在假期买一个单片机开发板然后自己学习，然后完成自己心中所想的事情，去学习电路、硬件等知识，在将来的学习途中变得更加游刃有余，而且希望能让单片机取代游戏，老师说过：“这玩意可比游戏啥的好玩多了”，我希望我以后也能做到这样，大学还有三年时间，足够我好好玩一玩这些东西啦，感谢老师这四天以来的教导，虽说时间很短、但是收获颇丰！