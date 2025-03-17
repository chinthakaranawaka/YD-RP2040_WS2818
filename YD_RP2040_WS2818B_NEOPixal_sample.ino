#include <Adafruit_NeoPixel.h>

// Define the pin where the WS2812 LED is connected
#define LED_PIN    23  // YD-RP2040 built-in WS2812 is typically connected to GPIO23

// Define the number of LEDs
#define LED_COUNT  1   // Only one built-in LED

// Create an instance of the Adafruit_NeoPixel class
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialize the NeoPixel library
  strip.begin();
  strip.show();  // Initialize all pixels to 'off'
} 

void loop() {
  // Call the rainbow function with a delay to create the effect
  rainbow(10);  // 10ms delay between color changes
}

// Function to create a rainbow effect
void rainbow(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
    // For each pixel in the strip...
    for (int i = 0; i < strip.numPixels(); i++) {
      // Calculate the hue for the current pixel
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // Set the color of the pixel
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    // Update the strip with the new colors
    strip.show();
    // Wait for the specified time
    delay(wait);
  }
}