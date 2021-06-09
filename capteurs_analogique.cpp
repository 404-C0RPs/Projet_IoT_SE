#include "Arduino.h"

#include "b_projet_iot.h"

float lecture_capteur_temperature_TMP36(){
    float valeurTemperature;

    valeurTemperature = ( LECTURE_PORT(TMP36_PORT) * ( (TMP36_TENSION * CONVERTION_MILLIVOLT) / CONVERTION_BINAIRE ) - 500 ) /10;

    return valeurTemperature;
}

float lecture_capteur_humidite_HIH4030(float valeurTemperature){
    float valeurHumidite;

    valeurHumidite = ( LECTURE_PORT(HIH4030_PORT) * HIH4030_TENSION ) / CONVERTION_BINAIRE;
    valeurHumidite /= ( 0.0062 * HIH4030_TENSION );
    valeurHumidite -= 25.81;
    valeurHumidite /= (1.0546 - (0.00216 * valeurTemperature));

    return valeurHumidite;
}
