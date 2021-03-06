/*
 IReflowv01.ino
*/

#include "Wire.h"
#include <SPI.h>

#include "LandBoards_IReflow.h"
#include "LandBoards_MyMenu.h"

#include "U8glib.h"
#include "Adafruit_MAX31855.h"
#include <Time.h>  
#include <TimeLib.h>

#define CS   9
Adafruit_MAX31855 thermocouple(CS);

//////////////////////////////////////////////////////////////////////////////
// enums follow
//////////////////////////////////////////////////////////////////////////////

enum MENUITEMS
{
  FIRST_LINE_MENU,
  SECOND_LINE_MENU,
  THIRD_LINE_MENU,
  FOURTH_LINE_MENU,
  FIRST_SUB_MENU,
  SECOND_SUB_MENU,
  FSTL_TESTS_MENU,
  SCND_TESTS_MENU
};

typedef enum PROFILES
{
  NO_PROFILE,
  LEAD_FREE,
  LEADED
} myRprfiles;


//////////////////////////////////////////////////////////////////////////////
// Global variables follow
//////////////////////////////////////////////////////////////////////////////

uint8_t menuState;              // Menu State variable

LandBoards_IReflow myIReflow;

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NO_ACK);

LandBoards_MyMenu menuCard;

myRprfiles profileSelected;

void setup(void) 
{
  profileSelected = NO_PROFILE;
  menuState = FIRST_LINE_MENU;  // Set up the init menu state
  myIReflow.redLED(LOW);
  delay(250);
  myIReflow.redLED(HIGH);
  myIReflow.greenLED(LED_ON);
  delay(100);
  myIReflow.greenLED(LED_OFF);
  displayInit();                // Hardware specific function to set up the display
  menuCard.begin();
  TWBR = 12;
  Serial.begin(9600);
  time_t t = now();
  delay(100);
  Serial.println("Hey");

}

void loop(void) 
{
  u8g.firstPage();  
  do 
  {
    menuRefresh();
  } 
  while( u8g.nextPage() );

  menuNav();
}

