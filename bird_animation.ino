#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int planeX = -20; 
int planeY = SCREEN_HEIGHT / 2; 

void setup() {

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  

  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  // Clear previous frame
  display.clearDisplay();
  
 
  updateAirplane();
  drawAirplane();

  display.display();
  delay(30);
}

void updateAirplane() {
  planeX += 2; 
  
  if (planeX > SCREEN_WIDTH) {
    planeX = -20; 
  }
}

void drawAirplane() {
  display.fillRect(planeX, planeY - 5, 20, 3, WHITE); // Body
  display.fillRect(planeX + 10, planeY - 8, 10, 11, WHITE); // Tail
  display.fillRect(planeX + 20, planeY - 3, 5, 1, WHITE); // Tail tip

  display.drawLine(planeX + 4, planeY - 2, planeX + 14, planeY - 2, WHITE); // Top wing
  display.drawLine(planeX + 2, planeY, planeX + 16, planeY, WHITE); // Middle wing
  display.drawLine(planeX + 4, planeY + 2, planeX + 14, planeY + 2, WHITE); // Bottom wing
  
  display.drawPixel(planeX + 2, planeY - 2, WHITE); // Left cockpit
  display.drawPixel(planeX + 3, planeY - 2, WHITE); // Left cockpit
  display.drawPixel(planeX + 4, planeY - 1, WHITE); // Left cockpit
  display.drawPixel(planeX + 15, planeY - 2, WHITE); // Right cockpit
  display.drawPixel(planeX + 16, planeY - 2, WHITE); // Right cockpit
  display.drawPixel(planeX + 17, planeY - 1, WHITE); // Right cockpit
}

