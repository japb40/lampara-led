#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include <String.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

SoftwareSerial BT(10, 11);  // RX, TX CONNECTADO AL MODULO BLUETOOTH 

 #define PIXEL_PIN      6    // Data Pin de la tira de led 
#define PIXEL_COUNT    12   // numero de led de la tira
#define BRIGHTNESS   255   // usar  96 para brillo medio
#define SPEED          50    //Velocidad de cada transición de color (en ms)
#define IMMEDIATELY    0    // Transición sucede al instante
#define RAINBOW_SPEED  50    // Rainbow velocidad de transicion

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool offOld = LOW;
bool WhiteOld = LOW;
bool RedOld = LOW;
bool GreenOld = LOW;
bool BlueOld = LOW;
bool TopazOld = LOW;
bool LilacOld = LOW;
bool Yellowold = LOW;
bool RainbowOld = LOW;
bool rgbOld = LOW;
bool OrangeOld = LOW;
bool CyanOld = LOW;
int  showType = 0;


void setup() {
  startShow (EEPROM.read (0));// empezar color
   BT.begin(9600);
   
   BT.println("Connected to Arduino");
    

  strip.setBrightness(BRIGHTNESS);  
   

  strip.begin();
  strip.show();
}

char a;

void loop() {

  bool off = LOW;
  bool White = LOW;
  bool Blue = LOW;
  bool Red = LOW;
  bool Green = LOW;
  bool Topaz = LOW;
  bool Lilac = LOW;
  bool Yellow = LOW;
  bool Rainbow = LOW;
  bool rgb = LOW;
  bool Orange = LOW;
  bool Cyan = LOW;  
  bool ende;
   if (BT.available())
   {
    a= (char)BT.read();
 
  

 



    if(a=='n')
    {
      off = HIGH;
          BT.println("APAGAR LEDs..");

    }else{
          off = LOW;
    }
    
// ===========================================================================================

    if(a=='w')
    {
      White = HIGH;
          BT.println("ENCENDIENDO LEDS BLANCO");

    }else{
          White = LOW;
    }
    
// ===========================================================================================

    if(a=='b')
    {
      Blue = HIGH;
          BT.println("CAMBIANDO A AZUL");      
          
    }else{
          Blue = LOW;  
    }

// ===========================================================================================

if(a=='r')
    {
      Red = HIGH;
          BT.println("CAMBIANDO A ROJO");            
    }else{
          Red = LOW;  
    }

// ===========================================================================================

if(a=='g')
    {
      Green = HIGH;
          BT.println("CAMBIANDO A VERDE");      
          
    }else{
          Green = LOW;
    }

// ===========================================================================================

if(a=='t')
    {
      Topaz = HIGH;
          BT.println("CAMBIANDO A TOPAZ");      
          
    }else{
          Topaz = LOW;
    }

// ===========================================================================================

if(a=='v')
    {
      Lilac = HIGH;
          BT.println("CAMBIANDO A LILA");      
          
    }else{
          Lilac = LOW;
    }

// ===========================================================================================


if(a=='y')
    {
      Yellow = HIGH;
          BT.println("CAMBIANDO A AMARILLO");      
          
    }else{
          Yellow = LOW;
    }

// ===========================================================================================    
    if(a=='o')
    {
      Orange = HIGH;
          BT.println("CAMBIANDO A NARANJA");      
          
    }else{
          Orange = LOW;
    }

// ===========================================================================================    
    if(a=='c')
    {
      Cyan = HIGH;
          BT.println("CAMBIANDO A CYAN");      
          
    }else{
          Cyan = LOW;
    }

// ===========================================================================================    
    if(a=='a')
    {
      Rainbow = HIGH;
          BT.println("RAINBOW ANIMACION");      
          
    }else{
          Rainbow = LOW;  
    }
    
// ===========================================================================================

     if(a=='m')
    {
      rgb = HIGH;
          BT.println("MIX COLORES");      
          
    }else{
          rgb = LOW;  
    }
}
if (off == LOW && offOld == HIGH) {
    delay(20);
   
    
    if (off == LOW) {
       showType = 0  ;                            // Off animation Type 0
     
      startShow(showType);
    }
  }

// ===========================================================================================

if (White == LOW && WhiteOld == HIGH) {
    delay(20);
   
    
    if (White == LOW) {
       showType = 1  ;                            // White animation Type 1
     
      startShow(showType);
    }
  }

  
// ===========================================================================================  
  
  if (Red == LOW && RedOld == HIGH) {
    delay(20);
   
    
    if (Red == LOW) {
       showType = 2  ;                            // Red animation Type 2
     
      startShow(showType);
    }
  }

// ===========================================================================================

if (Green == LOW && GreenOld == HIGH) {
    delay(20);
   
    
    if (Green == LOW) {
       showType = 3  ;                            // Green animation Type 3
     
      startShow(showType);
    }
  }
  
// ===========================================================================================

if (Blue == LOW && BlueOld == HIGH) {
    delay(20);
   
    
    if (Blue == LOW) {
       showType = 4  ;                            // Blue animation Type 4
     
      startShow(showType);
    }
  }

// ===========================================================================================

if (Topaz == LOW && TopazOld == HIGH) {
    delay(20);
   
    
    if (Topaz == LOW) {
       showType = 5  ;                            // Topaz animation Type 5
     
      startShow(showType);
    }
  }

// ===========================================================================================

if (Lilac == LOW && LilacOld == HIGH) {
    delay(20);
   
    
    if (Lilac == LOW) {
       showType = 6  ;                            // Topaz animation Type 6
     
      startShow(showType);
    }
  }
    
// ===========================================================================================
if (Yellow == LOW && Yellowold == HIGH) {
    delay(20);
   
    
    if (Yellow == LOW) {
       showType = 9  ;                            // Yellow animation Type 9
     
      startShow(showType);
    }
  }
    
// ===========================================================================================
if (Orange == LOW && OrangeOld == HIGH) {
    delay(20);
   
    
    if (Yellow == LOW) {
       showType = 10  ;                            // Orange animation Type 10
     
      startShow(showType);
    }
  }
    
// ===========================================================================================
   if (Cyan == LOW && CyanOld == HIGH) {
    delay(20);
   
    
    if (Cyan == LOW) {
       showType = 11  ;                            // Cyan animation Type 11
     
      startShow(showType);
    }
  }
    
// ===========================================================================================
    if (Rainbow == LOW && RainbowOld == HIGH) {
    delay(20);

    if (Rainbow == LOW) {
showType = 8;                            // Rainbow animation Type 8
      startShow(showType);
    }
  }

// ===========================================================================================

      if (rgb == LOW && rgbOld == HIGH) {
    delay(20);

    if (rgb == LOW) {
   showType = 7;                            // Mix animation Type 7
     rgb = HIGH;

      startShow(showType);
    }
  }

WhiteOld = White;
RedOld = Red;
BlueOld = Blue;
GreenOld = Green;
TopazOld = Topaz;
LilacOld = Lilac;
offOld = off;
RainbowOld = Rainbow;
rgbOld = rgb;
Yellowold = Yellow;
OrangeOld = Orange;
CyanOld = Cyan;
}


void startShow(int i) {
  EEPROM.write(0,i);
  switch(i){

    case 0: colorWipe(strip.Color(0, 0, 0), SPEED);    // Black/off
            break;

    case 1: strip.setBrightness(255);                            // CAMBIA BRILLO AL MAXIMO
            colorWipe(strip.Color(255, 255, 255), IMMEDIATELY);  // BLANCO
            strip.setBrightness(BRIGHTNESS);                     // Resetea le Brillo a valores por defecto
            break;  

    case 2: colorWipe(strip.Color(255, 0, 0), SPEED);  // rojo
            break;

    case 3: colorWipe(strip.Color(0, 255, 0), SPEED);  // verde
            break;

    case 4: colorWipe(strip.Color(0, 0, 255), SPEED);  // azul
            break;

    case 5: colorWipe(strip.Color(0, 250, 255), SPEED);  // Topaz
            break;            

    case 6: colorWipe(strip.Color(221, 130, 255), SPEED);  // Lila
            break;            
    
    case 7: colorWipe(strip.Color(255, 0, 0), SPEED);  // rojo
            colorWipe(strip.Color(0, 255, 0), SPEED);  // verde
            colorWipe(strip.Color(0, 0, 255), SPEED);  // azul
            theaterChase(strip.Color(  0,   0, 127), SPEED); // azul
            theaterChase(strip.Color(127,   0,   0), SPEED); // rojo
            theaterChase(strip.Color(0,   127,   0), SPEED); // verde
            break;

    case 8: colorWipe(strip.Color(255, 255, 255), IMMEDIATELY);  // blanco
            delay(10000);
            colorWipe(strip.Color(255, 0, 0), SPEED);  // rojo
            delay(10000);
           colorWipe(strip.Color(0, 255, 0), SPEED);  // verde
            delay(10000);
            colorWipe(strip.Color(0, 0, 255), SPEED);  // azul
            delay(10000);
            colorWipe(strip.Color(0, 250, 255), SPEED);  // Topaz
            delay(10000);
            colorWipe(strip.Color(221, 130, 255), SPEED);  // Lila
            delay(10000);
            colorWipe(strip.Color(243, 255, 51), SPEED);  // amarillo
            delay(10000);
            colorWipe(strip.Color(254, 133, 59), SPEED);  // naranja
            delay(10000);
            colorWipe(strip.Color(89, 238, 252), SPEED);  //Cyan
            delay(10000);
            
            colorWipe(strip.Color(255, 255, 255), IMMEDIATELY);  // blanco
            delay(10000);
            break;
    case 9: colorWipe(strip.Color(243, 255, 51), SPEED);  // amarillo
            break;  
    case 10: colorWipe(strip.Color(254, 133, 59), SPEED);  // naranja
            break;            
    case 11: colorWipe(strip.Color(89, 238, 252), SPEED);  //Cyan
            break;                                     
  }
}
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*10; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
