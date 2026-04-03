// If you like this project, consider starring on GitHub! ⭐

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true); // stop here
  }

  display.clearDisplay();

  // Show welcome text
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);
  display.println("Hello!");
  display.display();

  delay(2000);
}

void loop() {
  showText();
  drawShapes();
}

// Function: Display text
void showText() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("OLED Demo");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.println("Welcome");

  display.display();
  delay(2000);
}

// Function: Draw basic shapes
void drawShapes() {
  display.clearDisplay();

  // Draw rectangle
  display.drawRect(0, 0, 127, 63, SSD1306_WHITE);

  // Draw line
  display.drawLine(0, 0, 127, 63, SSD1306_WHITE);

  // Draw circle
  display.drawCircle(64, 32, 10, SSD1306_WHITE);

  display.display();
  delay(2000);
}
