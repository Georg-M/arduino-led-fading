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

const int wait = 20;

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

const int sensor = A0;
const int led0 = 3;
const int led1 = 5;
const int led2 = 6;
const int led3 = 9;
const int led4 = 10;
const int led5 = 11;

const int sensor_max = 1024;
const int led_max    = 256;

const int ind_len = 6;
const int indicator[ind_len] = {led0, led1, led2, led3, led4, led5};
const int ind_step = 256;
const int ind_overlap = ind_step + ind_step/2;



void setup() {
}

void writePwmParabolic(int port, int value)
{
  const int shift = 1;
  int value2 = (value > 255) ? 255 : ((value < 0) ? 0 : value);
  int pwmValue = parab[value2] + shift;
  if (pwmValue > 255)
    pwmValue = 255;
  analogWrite(port, pwmValue);
}


void loop()
{
  long sensorValue_1;
  int sensorValue_2;
  sensorValue_1 = analogRead(sensor);
  sensorValue_1 = sensorValue_1 * ind_step * (ind_len - 1);
  sensorValue_2 = sensorValue_1 / sensor_max;
  
  for (int i=0; i<ind_len; i++) {
    int led_value = i * ind_step;
    int ind_value;
    ind_value = (led_value < sensorValue_2) ?
        ind_overlap + (led_value - sensorValue_2) :
        ind_overlap - (led_value - sensorValue_2);
    ind_value = (ind_value < 0) ? 0 : ind_value;
    writePwmParabolic(indicator[i], ind_value);
//  ind_value = (long)ind_value * (long)led_max / (led_max + ind_overlap - ind_step);
//  ind_value = (ind_value < 0  ) ? 0   : ind_value;
//  ind_value = (ind_value > 255) ? 255 : ind_value;
//  analogWrite      (indicator[i], ind_value);
  }
  delay(wait);
}

