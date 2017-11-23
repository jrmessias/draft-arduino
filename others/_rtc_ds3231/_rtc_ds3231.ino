#include <Wire.h>
#include <DS3231.h>

/*
   GND ==> GND
   VCC ==> 5V
   SDA ==> A4
   SCL ==> A5
*/

DS3231 rtc;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);
  rtc.begin();

  //rtc.setDateTime(__DATE__, __TIME__);   // Config initial values of RTC DS3231
  // Comment line above after first execution

  // Set from UNIX timestamp
  // rtc.setDateTime(1397408400);

  // Manual set (YYYY, MM, DD, HH, II, SS)
  // rtc.setDateTime(2014, 4, 13, 19, 21, 00);
}

void loop()
{
  dt = rtc.getDateTime();

  // Show date and time in one line
  Serial.print("Data/Hora (BR): ");
  Serial.print(dt.day);
  Serial.print("/");
  Serial.print(dt.month);
  Serial.print("/");
  Serial.print(dt.year);
  Serial.print(" ");
  Serial.print(dt.hour);
  Serial.print(":");
  Serial.print(dt.minute);
  Serial.print(":");
  Serial.println(dt.second);
  Serial.print("Date/Time (US): ");
  Serial.print(dt.year);
  Serial.print("-");
  Serial.print(dt.month);
  Serial.print("-");
  Serial.print(dt.day);
  Serial.print(" ");
  Serial.print(dt.hour);
  Serial.print(":");
  Serial.print(dt.minute);
  Serial.print(":");
  Serial.println(dt.second);

  // Datailed date and time
  // Calculate rest of days in year
  int daysInYear = 365;
  if(rtc.dateFormat("L", dt) == 1){
    daysInYear++;
}
  int daysToEndYear = daysInYear - atoi(rtc.dateFormat("z", dt));
  
  Serial.print("Long number format:          ");
  Serial.println(rtc.dateFormat("d-m-Y H:i:s", dt));

  Serial.print("Long format with month name: ");
  Serial.println(rtc.dateFormat("d F Y H:i:s",  dt));

  Serial.print("Short format witch 12h mode: ");
  Serial.println(rtc.dateFormat("jS M y, h:iA", dt));

  Serial.print("Today is:                    ");
  Serial.print(rtc.dateFormat("l, z", dt));
  Serial.println(" days of the year.");

  Serial.print("Days to end for year:        ");
  Serial.print(daysToEndYear);
  Serial.println(" day(s).");

  Serial.print("Actual month has:            ");
  Serial.print(rtc.dateFormat("t", dt));
  Serial.println(" day(s).");

  Serial.print("Unixtime:                    ");
  Serial.println(rtc.dateFormat("U", dt));

  Serial.print("Leap year:                   ");
  Serial.println(rtc.dateFormat("L", dt));

  Serial.print("Temperature:                 ");
  Serial.print(rtc.readTemperature());
  Serial.println("C");

  Serial.println();

  delay(1000); // Time to send to serial
}
