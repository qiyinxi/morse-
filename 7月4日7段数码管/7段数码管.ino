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
