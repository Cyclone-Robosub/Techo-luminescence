#include <FastLED.h>
#define NUM_LEDS 16
#define LED_PIN 2
#define CYCLE_RATE 100
#define DEFAULT_COLOR CRGB::White
#define MAX_INTENSITY 20
#define PI 3.14

CRGB leds[NUM_LEDS];

void setup () {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(MAX_INTENSITY);
  delay(2000);
}

void dim_leds () {
  for (auto &i:leds) {
    i.fadeLightBy( 100 );
  }

  FastLED.show();
}

void projectile_animation (
  const char* direction = "forward",
  fl::u32 color = DEFAULT_COLOR,
  int cycle_rate = CYCLE_RATE
) { 

  int dir;
  int start;
  int end;

  if (strcmp(direction, "backward") == 0) {
    dir = -1; 
    start = NUM_LEDS - 1;
    end = 0;
  } else {
    dir = 1;
    start = 0;
    end = NUM_LEDS - 1;
  }

  for (int i = start; i != end + dir; i += dir) {
    leds[i] = color;
    FastLED.show();
    delay(cycle_rate);
    dim_leds();
  }
}

void bouncing_animation (
  fl::u32 color = DEFAULT_COLOR,
  int cycle_rate = CYCLE_RATE
) {
  projectile_animation("forward", color, cycle_rate);
  projectile_animation("backward", color, cycle_rate);
}

void twinkle_animation (
  int spacing = 4, 
  fl::u32 color = DEFAULT_COLOR, 
  int cycle_rate = CYCLE_RATE*2
) {
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

void heartbeat_animation (
  // char preset = "slow", 
  // fl::u32 color = CRGB::Red, 
  fl::u32 color = DEFAULT_COLOR, 
  int cycle_rate = CYCLE_RATE * 8
) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color; 
  }
  FastLED.show(); 
  delay(cycle_rate);

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black; 
  }
  FastLED.show(); 
  delay(cycle_rate);
}

void pulse_animation (
  bool inverted = false, 
  fl::u32 color = DEFAULT_COLOR, 
  int cycle_rate = CYCLE_RATE
) {
  
  volatile float intensity;
  volatile float cycle_index = 0;
  
  while (cycle_index < 2 * PI) {
    if (inverted) {
      intensity = (-1* abs(sin(cycle_index)) + 1) * MAX_INTENSITY;
    } else {
      intensity = abs(sin(cycle_index)) * MAX_INTENSITY;
    }
    cycle_index += PI / 32; 

    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = color; 
      FastLED.setBrightness(intensity);
    }
    FastLED.show();
    delay(cycle_rate/2);
  }
  // for (int i = 0, )
}

void progress_bar (
  float progress,
  char direction = "left", 
  bool inverted = false, 
  fl::u32 color = DEFAULT_COLOR, 
  int cycle_rate = CYCLE_RATE
) {
  fl::u32 primary_color;
  fl::u32 secondary_color;

  if (inverted) {
    primary_color = CRGB::Black;
    secondary_color = color; 
  } else {
    primary_color = color;
    secondary_color = CRGB::Black; 
  }

  int led_threshold = floor(NUM_LEDS * progress);

  for (int i = 0; i < led_threshold; i++) {
    leds[i] = primary_color; 
  }

  for (int i = led_threshold; i < NUM_LEDS; i++) {
    leds[i] = secondary_color; 
  }
  FastLED.show(); 
  delay(10);
}


void progress_bar_animation (
  char direction = "center", 
  bool inverted = false, 
  fl::u32 color = DEFAULT_COLOR, 
  int cycle_rate = CYCLE_RATE/2
) {
  for (int i = 0; i < 100; i++) {
    progress_bar(i * 0.01);
    delay(cycle_rate);
  }
  for (int i = 0; i < 100; i++) {
    progress_bar(i * 0.01, "left", true);
    delay(cycle_rate);
  }
}


void loop () {
  
  // projectile_animation("backward");
  // bouncing_animation();
  // twinkle_animation();

  // heartbeat_animation();
  // pulse_animation(true);
  // pulse_animation();
  // progress_bar(0.70);
  progress_bar_animation();

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