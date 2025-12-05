 #include <FastLED.h>
 #define NUM_LEDS 20
 #define LED_PIN 2
 #define CYCLE_RATE 200

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

 void loop () {


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

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(CYCLE_RATE);
    dim_leds();
    // leds[i] %= 192;
  //  leds[i] = CRGB::Black;
  } 

  for (int i = NUM_LEDS-1; i >= 0; i--) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(CYCLE_RATE);
  dim_leds();

  //  leds[i] = CRGB::Black;
   
  }

  // FastLED.show();
 }