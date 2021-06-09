#include <DS3231.h>

#include "Arduino.h"
#include "b_projet_iot.h"

void enregistrement_usb(RTCDateTime infoDateHeure, float valeurTemperature, float valeurHumidite){

  const int idSe = 2 ;
  Serial.println(idSe);delay(1000);
  Serial.println(infoDateHeure.year);delay(100);
  Serial.println(infoDateHeure.month);delay(100);
  Serial.println(infoDateHeure.day);delay(100);
  Serial.println(infoDateHeure.hour);delay(100);
  Serial.println(infoDateHeure.minute);delay(100);
  Serial.println(valeurTemperature);delay(100);
  Serial.println(valeurHumidite);delay(100);
}
