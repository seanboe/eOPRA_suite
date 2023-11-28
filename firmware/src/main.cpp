



#include <Arduino.h>
#include "PinDefs.h"

#include <Wire.h>
#include <../lib/CommCodes.h>
#include "utilities.h"


volatile uint8_t port;

void requestEvent();
void receiveEvent(int bytes);

volatile bool read;

void setup() {
  // Wire.setSDA(MASTER_SDA0);
  // Wire.setSCL(MASTER_SCL0);
  Serial.begin(9600);
  Wire.begin(8);                // join i2c bus with address #8
  // Wire.onRequest(requestEvent); // register event



  Wire.onReceive(receiveEvent);
  read = false;
}

void loop() {

  // if (read) {
  //   Wire.print("Hello");
  //   read = false;
  // }

  // delay(100);
}

void receiveEvent(int bytes) { 
  
  uint8_t buffer[20];
  if (Wire.available()) {
    // port = Wire.read();
    Wire.readBytes(buffer, bytes);
    Serial.println("here");
  }

  // for (int x = 0; x < bytes; x++) {
  //   Serial.println(buffer[x]);
  // }

  Wire.beginTransmission(0);
  Wire.write("Hello");
  Wire.endTransmission();

}


#include <SwitcherI2C.h>

SwitcherI2C switcher = SwitcherI2C();

void setup1() {
  switcher.init(8);
}

void loop1() {

  uint8_t data[] = {10, 2, 3, 4};
  // Serial.println(sizeof(data) / sizeof(uint8_t));
  switcher.write(data, 4);

  if (Wire1.available()) {
    Serial.println("got something bcak");
    // char stuff[15];
    // Wire1.readBytes(stuff, 5);
    // Serial.println(Wire1.readString());
  }

  delay(500);
}





// WORKING EXAMPLEEERERE 
// PERIPHERAL

// void requestEvent();

// void setup() {
//   // Wire.setSDA(MASTER_SDA0);
//   // Wire.setSCL(MASTER_SCL0);
//   Wire.begin(8);                // join i2c bus with address #8
//   Wire.onRequest(requestEvent); // register event
// }

// void loop() {
//   delay(100);
// }

// // function that executes whenever data is requested by master
// // this function is registered as an event, see setup()
// void requestEvent() {
//   Wire.write("hello "); // respond with message of 6 bytes
//   // as expected by master
// }

// CONTROLLER
// void setup() {
//   // Wire.setSDA(MASTER_SDA0);
//   // Wire.setSCL(MASTER_SCL0);
//   Wire.begin();        // join i2c bus (address optional for master)
//   Serial.begin(9600);  // start serial for output
// }

// void loop() {
//   Wire.requestFrom(8, 6);    // request 6 bytes from peripheral device #8

//   while (Wire.available()) { // peripheral may send less than requested
//     char c = Wire.read(); // receive a byte as character
//     Serial.print(c);         // print the character
//   }

//   delay(500);
// }

























// // #include <Arduino.h>

// // #include <Adafruit_GFX.h>    // Core graphics library
// // #include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
// // #include <PinDefs.h>

// // #include <SPI.h>


// // // // Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
// // // // Adafruit_ST7735 tft = Adafruit_ST7735(&my_spi, (uisnt8_t)TFT_CS, (uint8_t)TFT_DC,(uint8_t)TFT_RESET);

// //   Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI0, TFT_SCK0, TFT_RESET);

// // //   // Adafruit_ST7735(SPIClass *spiClass, int8_t cs, int8_t dc, int8_t rst);



// // void testlines(uint16_t color) {
// //   tft.fillScreen(ST77XX_BLACK);
// //   for (int16_t x=0; x < tft.width(); x+=6) {
// //     tft.drawLine(0, 0, x, tft.height()-1, color);
// //   }
// //   for (int16_t y=0; y < tft.height(); y+=6) {
// //     tft.drawLine(0, 0, tft.width()-1, y, color);
// //   }

// //   tft.fillScreen(ST77XX_BLACK);
// //   for (int16_t x=0; x < tft.width(); x+=6) {
// //     tft.drawLine(tft.width()-1, 0, x, tft.height()-1, color);
// //   }
// //   for (int16_t y=0; y < tft.height(); y+=6) {
// //     tft.drawLine(tft.width()-1, 0, 0, y, color);
// //   }

// //   tft.fillScreen(ST77XX_BLACK);
// //   for (int16_t x=0; x < tft.width(); x+=6) {
// //     tft.drawLine(0, tft.height()-1, x, 0, color);
// //   }
// //   for (int16_t y=0; y < tft.height(); y+=6) {
// //     tft.drawLine(0, tft.height()-1, tft.width()-1, y, color);
// //   }

// //   tft.fillScreen(ST77XX_BLACK);
// //   for (int16_t x=0; x < tft.width(); x+=6) {
// //     tft.drawLine(tft.width()-1, tft.height()-1, x, 0, color);
// //   }
// //   for (int16_t y=0; y < tft.height(); y+=6) {
// //     tft.drawLine(tft.width()-1, tft.height()-1, 0, y, color);
// //   }
// // }

// // void testdrawtext(char *text, uint16_t color) {
// //   tft.setCursor(0, 0);
// //   tft.setTextColor(color);
// //   tft.setTextWrap(true);
// //   tft.print(text);
// // }

// // void testfastlines(uint16_t color1, uint16_t color2) {
// //   tft.fillScreen(ST77XX_BLACK);
// //   for (int16_t y=0; y < tft.height(); y+=5) {
// //     tft.drawFastHLine(0, y, tft.width(), color1);
// //   }
// //   for (int16_t x=0; x < tft.width(); x+=5) {
// //     tft.drawFastVLine(x, 0, tft.height(), color2);
// //   }
// // }

// // void testdrawrects(uint16_t color) {
// //   tft.fillScreen(ST77XX_BLACK);
// //   for (int16_t x=0; x < tft.height(); x+=6) {
// //     tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color);
// //   }
// // }

// // void testfillrects(uint16_t color1, uint16_t color2) {
// //   tft.fillScreen(ST77XX_BLACK);
// //   for (int16_t x=tft.height()-1; x > 6; x-=6) {
// //     tft.fillRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color1);
// //     tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color2);
// //   }
// // }

// // void testfillcircles(uint8_t radius, uint16_t color) {
// //   for (int16_t x=radius; x < tft.width(); x+=radius*2) {
// //     for (int16_t y=radius; y < tft.height(); y+=radius*2) {
// //       tft.fillCircle(x, y, radius, color);
// //     }
// //   }
// // }

// // void testdrawcircles(uint8_t radius, uint16_t color) {
// //   for (int16_t x=0; x < tft.width()+radius; x+=radius*2) {
// //     for (int16_t y=0; y < tft.height()+radius; y+=radius*2) {
// //       tft.drawCircle(x, y, radius, color);
// //     }
// //   }
// // }

// // void testtriangles() {
// //   tft.fillScreen(ST77XX_BLACK);
// //   uint16_t color = 0xF800;
// //   int t;
// //   int w = tft.width()/2;
// //   int x = tft.height()-1;
// //   int y = 0;
// //   int z = tft.width();
// //   for(t = 0 ; t <= 15; t++) {
// //     tft.drawTriangle(w, y, y, x, z, x, color);
// //     x-=4;
// //     y+=4;
// //     z-=4;
// //     color+=100;
// //   }
// // }

// // void testroundrects() {
// //   tft.fillScreen(ST77XX_BLACK);
// //   uint16_t color = 100;
// //   int x = 0;
// //   int y = 0;
// //   int w = tft.width()-2;
// //   int h = tft.height()-2;
// //   while ((w > 10) && (h > 10)) {
// //     tft.drawRoundRect(x, y, w, h, 5, color);
// //     x+=2;
// //     y+=3;
// //     w-=4;
// //     h-=6;
// //     color+=1100;
// //   }
// // }

// // void tftPrintTest() {
// //   tft.setTextWrap(false);
// //   tft.fillScreen(ST77XX_BLACK);
// //   tft.setCursor(0, 0);
// //   tft.setTextColor(ST77XX_RED);
// //   tft.setTextSize(1);
// //   tft.println("Hello World!");
// //   tft.setTextColor(ST77XX_YELLOW);
// //   tft.setTextSize(2);
// //   tft.println("Hello World!");
// //   tft.setTextColor(ST77XX_GREEN);
// //   tft.setTextSize(3);
// //   tft.println("Hello World!");
// //   tft.setTextColor(ST77XX_BLUE);
// //   tft.setTextSize(4);
// //   tft.print(1234.567);
// //   delay(1500);
// //   tft.setCursor(0, 0);
// //   tft.fillScreen(ST77XX_BLACK);
// //   tft.setTextColor(ST77XX_WHITE);
// //   tft.setTextSize(0);
// //   tft.println("Hello World!");
// //   tft.setTextSize(1);
// //   tft.setTextColor(ST77XX_GREEN);
// //   // tft.print(p, 6);
// //   tft.println(" Want pi?");
// //   tft.println(" ");
// //   tft.print(8675309, HEX); // print 8,675,309 out in HEX!
// //   tft.println(" Print HEX!");
// //   tft.println(" ");
// //   tft.setTextColor(ST77XX_WHITE);
// //   tft.println("Sketch has been");
// //   tft.println("running for: ");
// //   tft.setTextColor(ST77XX_MAGENTA);
// //   tft.print(millis() / 1000);
// //   tft.setTextColor(ST77XX_WHITE);
// //   tft.print(" seconds.");
// // }

// // void mediabuttons() {
// //   // play
// //   tft.fillScreen(ST77XX_BLACK);
// //   tft.fillRoundRect(0, 10, 78, 60, 8, ST77XX_WHITE);
// //   tft.fillTriangle(17, 20, 17, 60, 65, 40, ST77XX_RED);
// //   delay(500);
// //   // pause
// //   tft.fillRoundRect(82, 10, 78, 60, 8, ST77XX_WHITE);
// //   tft.fillRoundRect(96, 18, 20, 45, 5, ST77XX_GREEN);
// //   tft.fillRoundRect(127, 18, 20, 45, 5, ST77XX_GREEN);
// //   delay(500);
// //   // play color
// //   tft.fillTriangle(17, 20, 17, 60, 65, 40, ST77XX_BLUE);
// //   delay(50);
// //   // pause color
// //   tft.fillRoundRect(39, 98, 20, 45, 5, ST77XX_RED);
// //   tft.fillRoundRect(69, 98, 20, 45, 5, ST77XX_RED);
// //   // play color
// //   tft.fillTriangle(17, 20, 17, 60, 65, 40, ST77XX_GREEN);
// // }


// // // void dial(uint16_t color) {
// // //   // tft.fillScreen(ST77XX_BLACK);
// // //   tft.fillCircle(50, 50, 10, color);
// // //   tft.setCursor(50, 50);
// // //   tft.setTextColor(ST77XX_WHITE);
// // //   tft.setTextSize(0);
// // //   tft.println("1");
// // // }

// // #define BACKGROUND    14856
// // #define AUX_1       49931
// // #define AUX_2       44890


// // void drawDial(int8_t originX, int8_t originY, int8_t radius, uint8_t tokens, bool individual=false, uint8_t selection=0) { 
// //   double arc_offset = PI / 2;
// //   double spacing = (2*PI - arc_offset) / (tokens - 1);
// //   tft.fillCircle(originX, originY, 3, ST7735_BLUE);
// //   for (int x = 0; x < tokens; x++) {
// //     uint8_t posX = (uint8_t)(cos(spacing * x - (PI / 2 - arc_offset / 2)) * radius + originX);
// //     uint8_t posY = (uint8_t)(-sin(spacing * x - (PI / 2 - arc_offset / 2)) * radius + originY);
// //     Serial.println(String(posX) + ", " + String(posY));
// //     int8_t newRadius = radius / 5;
// //     tft.fillCircle(posX, posY, newRadius, 10825);
// //     tft.drawCircle(posX, posY, newRadius + 1, ST7735_WHITE);
// //   }
// // }

// // void setup(void) {
// //   Serial.begin(115200);
// //   while(!Serial) {
// //     ;
// //   }
  
// //   Serial.print("Hello! ST77xx TFT Test");
  
// //   // if (!ss.begin()) {
// //   //   Serial.println("seesaw init error!");
// //   //   while(1);
// //   // }
// //   // else Serial.println("seesaw started");

// //   // ss.tftReset();
// //   // ss.setBacklight(0x0); //set the backlight fully on

// //   // Use this initializer (uncomment) if you're using a 0.96" 180x60 TFT
// //   tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, mini display
// //   // tft.initSPI();

// //   tft.setRotation(3);

// //   tft.fillScreen(ST77XX_BLACK);

    
// //   Serial.println("Initialized");

// //   drawDial(100, 50, 30, 8);

// //   delay(10000000);
// //   Serial.println("not here...");


// //   uint16_t time = millis();
// //   tft.fillScreen(ST77XX_BLACK);
// //   time = millis() - time;

// //   // for (int x= 0 ; x < 10; x++) {
// //   //   if (x % 2 == 0) {
// //   //     dial(ST77XX_BLUE);
// //   //   }
// //   //   else {
// //   //     dial(ST77XX_GREEN);
// //   //   }
// //   //   delay(1000);
// //   // }

// //   delay(10000000);

// //   Serial.println(time, DEC);
// //   delay(500);

// //   // large block of text
// //   tft.fillScreen(ST77XX_BLACK);
// //   testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST77XX_WHITE);
// //   delay(1000);

// //   // tft print function!
// //   tftPrintTest();
// //   delay(1000);

// //   // a single pixel
// //   tft.drawPixel(tft.width()/2, tft.height()/2, ST77XX_GREEN);
// //   delay(500);

// //   // line draw test
// //   testlines(ST77XX_YELLOW);
// //   delay(500);

// //   // optimized lines
// //   testfastlines(ST77XX_RED, ST77XX_BLUE);
// //   delay(500);

// //   testdrawrects(ST77XX_GREEN);
// //   delay(500);

// //   testfillrects(ST77XX_YELLOW, ST77XX_MAGENTA);
// //   delay(500);

// //   tft.fillScreen(ST77XX_BLACK);
// //   testfillcircles(10, ST77XX_BLUE);
// //   testdrawcircles(10, ST77XX_WHITE);
// //   delay(500);

// //   testroundrects();
// //   delay(500);

// //   testtriangles();
// //   delay(500);

// //   mediabuttons();
// //   delay(500);

// //   Serial.println("done");
// //   delay(1000);
// // }

// // void loop() {
// //   tft.invertDisplay(true);
// //   delay(500);
// //   tft.invertDisplay(false);
// //   delay(500);
// // }

