#define FASTLED_INTERNAL
#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    26
#define BRIGHTNESS  150
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

const int BUTTON_PIN = 9;
int lastState = HIGH;
int currentState;
int stateOptions = 7;
int count = 0;

#define UPDATES_PER_SECOND 100

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  //FastLED.setBrightness(  BRIGHTNESS );
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}


void loop()
{
  currentState = digitalRead(BUTTON_PIN);
  if(lastState == LOW && currentState == HIGH) {
    count++;
  }
  lastState = currentState;
  if(count == 0) {
    static_purple_turquoise();
  }
  if(count == 1) {
    static_purple_red();
  }
  if(count == 7) {
    offLights();
  }
  if(count > stateOptions) {
    count = 0;
  }
  
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}




//Func for colours

void offLights() {
  FastLED.clear();
}

void static_purple_turquoise() {
  for(int i=0; i<NUM_LEDS; i++) {
    leds[i]=CRGB::Purple;
  }
  
//  leds[14]=CRGB::HotPink;
//  leds[15]=CRGB::HotPink;
//  
//  for(int i=16; i<30; i++) {
//    leds[i].setRGB( 4, 255, 247);
//  }
}

void static_purple_red() {
  for(int i=0; i<NUM_LEDS; i++) {
    leds[i]=CRGB::Red;
  }
  
//  leds[14]=CRGB::HotPink;
//  leds[15]=CRGB::HotPink;
//  
//  for(int i=16; i<30; i++) {
//    leds[i]=CRGB::Red;
//  }
}
