#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int x, minX;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
  x = display.width();
}

void loop() {
  // put your main code here, to run repeatedly:
  char text[] = "The quick brown fox jumped over the lazy dogs back";
  scrollText(text);
}

void scrollText(char message[]) {
  minX = -12 * strlen(message); //12 = 6 pixels/character * text size 2
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(x,7);
  display.print(message);
  display.display();
  x = x - 2; // scroll speed
  if (x < minX) x = display.width();
}
