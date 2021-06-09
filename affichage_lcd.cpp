#include "Arduino.h"
#include <Wire.h>

#include "b_projet_iot.h"
#include "rgb_lcd.h"

rgb_lcd moduleLCD;

void affichage_date(uint16_t valeurAnnee, uint8_t valeurMois, uint8_t valeurJour){
    moduleLCD.print(valeurJour);
    moduleLCD.print("/");
    moduleLCD.print(valeurMois);
    moduleLCD.print("/");
    moduleLCD.print(valeurAnnee);
    moduleLCD.print(" ");
}
void affichage_heure(uint8_t valeurHeure, uint8_t valeurMinute){
    moduleLCD.print(valeurHeure);
    moduleLCD.print(":");
    if(valeurMinute < 10){
        moduleLCD.print("0");
        moduleLCD.print(valeurMinute);
    }else{
        moduleLCD.print(valeurMinute);
    }
    moduleLCD.print("        ");
}
void afficher_temperature_TMP36(){
    moduleLCD.print("T:");
    moduleLCD.print(lecture_capteur_temperature_TMP36(),1);
    moduleLCD.print("C ");
}
void afficher_humidite_HIH4030(float valeurTemperature){
    moduleLCD.print("H:");
    moduleLCD.print(lecture_capteur_humidite_HIH4030(valeurTemperature),1);
    moduleLCD.print("% ");
}
int allumer_ecran_LCD(){
    moduleLCD.setRGB(ROUGE, VERT, BLEU);
    moduleLCD.display();
    return LCD_ALLUME;
}
int eteindre_ecran_LCD(){
    moduleLCD.setRGB(0,0,0);
    moduleLCD.noDisplay();
    return LCD_ETEIND;
}
void ecrir_sur_premiere_ligne(){
    moduleLCD.setCursor(0,0);
}
void ecrir_sur_seconde_ligne(){
    moduleLCD.setCursor(0,1);
}
void activation_ecran_LCD(){
    moduleLCD.begin(16,2);
    moduleLCD.setRGB(0, 0, 0);
    moduleLCD.noDisplay();
}
