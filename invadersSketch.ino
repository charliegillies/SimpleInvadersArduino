#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Wire.h>
#include <SPI.h>
#include <Game.h>
#include <ClickEncoder.h>
#include <TimerOne.h>
#include "StartGameMode.h"
#include <InvertedTM1638.h>
#include <TM1638.h>
#include <TM1638QYF.h>
#include <TM1640.h>
#include <TM16XX.h>
#include <TM16XXFonts.h>

// encoder values
#define WITHOUT_BUTTON 0
#define ENC_DECODER (1 << 2)
ClickEncoder* encoder;
ClickEncoder::Button buttonState;
int encoderValue;

// LCD display
#define OLED_MOSI   51 // 51 or ICSP-4
#define OLED_CLK    52 // 52 or ICSP-3
#define OLED_DC     50 // 50 or ICSP-1
#define OLED_RESET  53
#define OLED_CS     12
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// TM1638 Module handler
#define TM1638_STB 5
#define TM1638_CLK 6
#define TM1638_DIO 7
TM1638 module(TM1638_DIO, TM1638_CLK, TM1638_STB);

// The global game
Game* game;

// FPS & game loop info
const float updateTime = 1000.0f/30;

// arduino SSD1306 specific graphics device..
class ArdGraphicsDevice : public GraphicsDevice
{
  public:
    ArdGraphicsDevice() : GraphicsDevice(128, 64) { }
    
    // function to draw a rectangle of a specific size in a specific (x,y) position
    virtual void drawRect(int x, int y, int width, int height) override {
      display.drawRect(x, y, width, height, WHITE);
    }
  
    // function to draw a line from (x0,y0) to (x1,y1)
    virtual void drawLine(int x0, int y0, int x1, int y1) override {
      display.drawLine(x0, y0, x1, y1, WHITE);
    }
  
    // function to draw text in a given (x, y) position
    virtual void drawText(int x, int y, char* str) override {
      display.setCursor(x, y);
      display.print(str);
    }
  
    // function to begin the display operations
    virtual void begin() override {
      display.clearDisplay();
    }
  
    // function to end the display operations
    virtual void end() override {
      display.setCursor(0, 0);
      display.display();
    }
};

// Input processor implementation..
class ArdInputDevice : public InputReader
{
  public:
    // if the player is trying to move left
    virtual bool movedLeft() override {
      return (encoderValue == -1);
    }
    
    // if the player is trying to move right
    virtual bool movedRight() override {
      return (encoderValue == 1);
    }
  
    // if the player is trying to fire
    virtual bool fired() override {
      //todo implement this after we wire in a button
      return buttonState == ClickEncoder::Clicked;
    }
};

class UIInputDevice : public GameInterface
{
  public:
    virtual void setLivesCounter(int lives) override {
      //keep in mind, this will appear in binary
      //todo make this appear in non-binary later
      module.setLEDs(lives);
    }

    virtual void setInvaderCount(int count) override {
      module.setDisplayToDecNumber(count, 0, false);
    }
};

void timerIsr() {
  encoder->service();
}

void setup() {
  // set up the module
  module.clearDisplay();
  module.setupDisplay(true, 2);

  // set up the encoder
  encoder = new ClickEncoder(2, 3, 4);
  encoder->setAccelerationEnabled(false);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);
  encoderValue = 0;
  
  // set up the platform
  graphicsDevice = new ArdGraphicsDevice();
  inputReader = new ArdInputDevice();
  gameInterface = new UIInputDevice();

  // create the game object with the start mode
  game = new Game(new StartGameMode());
  
  // set up the display
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  display.clearDisplay();
  delay(1000);
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  // set the encoder value
  encoderValue = encoder->getValue();
  // set the button state
  buttonState = encoder->getButton();

  // update the game
  game->tick();

  // wait for 1 more frame
  delay(updateTime);
}
