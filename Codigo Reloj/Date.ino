
// DS3231:  SDA pin   -> Arduino UNO: A4 pin / Ardunino MEGA: SDA pin
//          SCL pin   -> Arduino UNO: A5 pin / Ardunino MEGA: SCL pin
#include <DS3231.h>     //Downlaod library here: https://www.electronoobs.com/eng_arduino_ds3231.php
DS3231  rtc(SDA, SCL);

void setup()
{
  // Setup Serial connection
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  
  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(MONDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(11, 47, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(28, 8, 2018);   // Set the date to January 1st, 2014
}

void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating :)
  delay (1000);
}
