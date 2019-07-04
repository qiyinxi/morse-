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