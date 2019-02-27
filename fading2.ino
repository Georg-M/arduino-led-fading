/*
 Fading
 
 This example shows how to fade an LED using the analogWrite() function.
 
 The circuit:
 * LED attached from digital pin 9 to ground.
 
 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/Fading
 
 This example code is in the public domain.
 
 */

const int incr = 1;
const int wait = 5;
const int topt = 240;

const int parab[] = {
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
    1,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   3,   3,   3,   3,   3,   3,   3,   4,
    4,   4,   4,   4,   4,   5,   5,   5,   5,   6,
    6,   6,   6,   6,   7,   7,   7,   7,   8,   8,
    8,   9,   9,   9,  10,  10,  10,  11,  11,  11,
   12,  12,  12,  13,  13,  14,  14,  14,  15,  15,
   16,  16,  17,  17,  18,  18,  19,  19,  20,  20,
   21,  21,  22,  23,  23,  24,  24,  25,  26,  26,
   27,  28,  28,  29,  30,  30,  31,  32,  33,  33,
   34,  35,  36,  37,  37,  38,  39,  40,  41,  42,
   43,  43,  44,  45,  46,  47,  48,  49,  50,  51,
   52,  53,  54,  55,  57,  58,  59,  60,  61,  62,
   63,  65,  66,  67,  68,  69,  71,  72,  73,  75,
   76,  77,  79,  80,  81,  83,  84,  86,  87,  89,
   90,  91,  93,  95,  96,  98,  99, 101, 102, 104,
  106, 107, 109, 111, 113, 114, 116, 118, 120, 121,
  123, 125, 127, 129, 131, 133, 135, 137, 139, 141,
  143, 145, 147, 149, 151, 153, 155, 157, 159, 162,
  164, 166, 168, 171, 173, 175, 178, 180, 182, 185,
  187, 190, 192, 195, 197, 200, 202, 205, 207, 210,
  213, 215, 218, 221, 223, 226, 229, 232, 235, 237,
  240, 243, 246, 249, 252, 255
};

const int led0 = 3;
const int led1 = 5;
const int led2 = 6;
const int led3 = 9;
const int led4 = 10;
const int led5 = 11;


void setup() {
}

void writePwmParabolic(int port, int value)
{
  const int shift = 1;
  int pwmValue = parab[value] + shift;
  if (pwmValue > 255)
    pwmValue = 255;
  analogWrite(port, pwmValue);
}

void loop()
{
  for (int i=0; i<256; i+=incr) {
    writePwmParabolic(led0, i);
    writePwmParabolic(led2, i);
    writePwmParabolic(led4, i);
    delay(wait);
  }
  delay(topt);

  for (int i=0; i<256; i+=incr) {
    writePwmParabolic(led0, 255-i);
    writePwmParabolic(led2, 255-i);
    writePwmParabolic(led4, 255-i);
    delay(wait);
  }

  for (int i=0; i<256; i+=incr) {
    writePwmParabolic(led1, i);
    writePwmParabolic(led3, i);
    writePwmParabolic(led5, i);
    delay(wait);
  }
  delay(topt);

  for (int i=0; i<256; i+=incr) {
    writePwmParabolic(led1, 255-i);
    writePwmParabolic(led3, 255-i);
    writePwmParabolic(led5, 255-i);
    delay(wait);
  }
}


