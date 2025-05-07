#include <LedControl.h>

const int DIN_PIN = 11;
const int CS_PIN = 10;
const int CLK_PIN = 13;

const char* IMAGES[][8] = {
  {
    "00011000",
    "00100100",
    "01011010",
    "01100110",
    "00111100",
    "00100100",
    "00100100",
    "00100100"
  },
  {
    "00000000",
    "00011000",
    "00100100",
    "01011010",
    "11100111",
    "00111100",
    "01000010",
    "11000011"
  },
  {
    "00000000",
    "00000000",
    "00011000",
    "00100100",
    "01011010",
    "11100111",
    "00111100",
    "11100111"
  },
  {
    "00000000",
    "00011000",
    "00100100",
    "01011010",
    "11100111",
    "00111100",
    "01000010",
    "11000011"
  }

};
const int IMAGES_LEN = sizeof(IMAGES) / sizeof(IMAGES[0]);


LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);


void setup() {
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 10);
}

void displayImage(const char* image[8]){
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, image[i][j] == '1');
    }
  }
}

int i = 0;

void loop() {
  displayImage(IMAGES[i]);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }
  delay(500);
}