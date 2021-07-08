#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define BUTTON 7


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


String message = "henlo world! :>";
String sender = "ASomeone: ";
int messageLength;
int touch_count = 0;
unsigned long timePressLimit;

void setup() {
  Serial.begin(19200);
  
  pinMode(BUTTON, INPUT);
  timePressLimit = 0;
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

}

void loop() {

  if(digitalRead(BUTTON)){
    Serial.println("touched");
    
    while(digitalRead(BUTTON)){
      delay(200);
    }

    if (touch_count == 0) {

      timePressLimit = millis() + 500;    
      touch_count = 1;

      while(millis() < timePressLimit){
        
        if(digitalRead(BUTTON)){
          delay(200);
          touch_count = touch_count + 1;
        }
        
      }

      Serial.print("times touched: ");
      Serial.println(touch_count);
    }


    if(touch_count == 1){
      sender = "Lara: ";
    }
    else if(touch_count == 2){
      sender = "Michel: ";
    }
    else if(touch_count == 3){
      sender = "Alissa: ";
    }
    
    
    display.clearDisplay();
    
    display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
    display.setTextWrap(false);
    display.setTextSize(2);
    
    display.setCursor(4, 4);
    display.print(sender);
    
    display.setTextSize(3);
    
    messageLength = message.length() * 18;
    
    for(int i = SCREEN_WIDTH; i > -messageLength; i-= 2){
      display.setCursor(i, 32);
      display.print(message);
      display.display();
    }
    


    
    delay(1000);

    Serial.println("scrolling message finished!");
    
    display.clearDisplay();
    display.display();

    touch_count = 0;
  }

}
