#include <FastLED.h>
#define NUM_LEDS 20
#define LED_PIN 2
#define CYCLE_RATE 100
#define DEFAULT_COLOR CRGB::White

CRGB leds[NUM_LEDS];

void setup () {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(30);
  delay(2000);
}

void dim_leds () {
  for (auto &i:leds) {
    i.fadeLightBy( 100 );
  }

  FastLED.show();
}

void forward_animation (fl::u32 color = DEFAULT_COLOR, int cycle_rate = CYCLE_RATE) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
    delay(cycle_rate);
    dim_leds();
  } 
}

void backward_animation (fl::u32 color = DEFAULT_COLOR, int cycle_rate = CYCLE_RATE) {
  for (int i = NUM_LEDS-1; i >= 0; i--) {
    leds[i] = color;
    FastLED.show();
    delay(cycle_rate);
    dim_leds();
  }
}

void bouncing_animation (fl::u32 color, int cycle_rate) {
  forward_animation(color, cycle_rate);
  backward_animation(color, cycle_rate);
}

void twinkle_animation (int spacing = 4, fl::u32 color = DEFAULT_COLOR, int cycle_rate = CYCLE_RATE*2) {
  int index = 0;  
  int tracker = 0;
  int offset = 0; 

  for (int i = 0; i < NUM_LEDS; i++) {
    tracker = i * spacing;
    offset = floor(tracker / NUM_LEDS);
    index = tracker % NUM_LEDS + offset; 
    leds[index] = color;
    FastLED.show();
    delay(cycle_rate);
    dim_leds();
  } 
}

void loop () {
  
  // forward_animation();
  // backward_animation();
  // bouncing_animation(CRGB::Blue, 50);
  twinkle_animation();

  // leds[0] = CRGB::Red;
  // leds[0].maximizeBrightness();
  // FastLED.show();

  // for (int i =  0; i < 20; i++) {
  //   leds[0].fadeLightBy( 32 );
  //   FastLED.show();
  //   delay(50); 
  // } 

  // for (int i =  0; i < 20; i++) {
  //   // leds[0].LightBy( -64 );
  //   leds[0] += CRGB( 10, 0, 0);
  //   leds[0] *= 1.125;
  //   FastLED.show();
  //   delay(50); 
  // } 

  // leds[0] = CRGB::Red;
  // leds[1] = CRGB::Green;
  // leds[2] = CRGB::Blue;



  // FastLED.show();
 }