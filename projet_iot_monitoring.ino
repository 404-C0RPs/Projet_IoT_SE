/*
#   DURAND Boris
#
#   Fichier principal pour l'arduino (système embarqué du projet)
#
*/
#include <DS3231.h>

#include "b_projet_iot.h"

DS3231 moduleHorloge;
RTCDateTime infoDateHeure;

unsigned int etatDuLCD = 0;
unsigned int heureSauvegarde = 0;
bool fichierCsvExiste = false;
bool fichierJsonExiste = false;

void setup(){
  pinMode(BOUTON_PORT, INPUT);
  pinMode(BOUTON_PORT_DEUX, INPUT);
  Serial.begin(9600);
  activation_ecran_LCD();
  moduleHorloge.begin();
  moduleHorloge.setDateTime(__DATE__, __TIME__);
  infoDateHeure = moduleHorloge.getDateTime();
  delay(100);
  heureSauvegarde = infoDateHeure.hour;
  activation_lecteur_sd();
}

void loop(){
  infoDateHeure = moduleHorloge.getDateTime();
  if( LECTURE_BOUTON && (etatDuLCD==0) ){
    etatDuLCD = allumer_ecran_LCD();
    ecrir_sur_premiere_ligne();
    affichage_date(infoDateHeure.year, infoDateHeure.month, infoDateHeure.day);
    affichage_heure(infoDateHeure.hour, infoDateHeure.minute);
    ecrir_sur_seconde_ligne();
    afficher_temperature_TMP36();
    afficher_humidite_HIH4030(lecture_capteur_temperature_TMP36());
    while(LECTURE_BOUTON);
  }else if( LECTURE_BOUTON && (etatDuLCD==1) ){etatDuLCD = eteindre_ecran_LCD();while(LECTURE_BOUTON);};

  if(infoDateHeure.hour == heureSauvegarde){

    if(!verifier_fichier_csv_existe(infoDateHeure.hour) && !verifier_fichier_json_existe(infoDateHeure.hour)){
      creation_fichier_csv(infoDateHeure.year);
      delay(100);
      creation_fichier_json(infoDateHeure.year);
    }else if(!verifier_fichier_json_existe(infoDateHeure.hour) && verifier_fichier_csv_existe(infoDateHeure.hour)){
      creation_fichier_json(infoDateHeure.year);
    }else if(!verifier_fichier_csv_existe(infoDateHeure.hour) && verifier_fichier_json_existe(infoDateHeure.hour)){
      creation_fichier_csv(infoDateHeure.year);
    }
    ecriture_donnee_fichier_csv( infoDateHeure, lecture_capteur_temperature_TMP36(), lecture_capteur_humidite_HIH4030(lecture_capteur_temperature_TMP36()) );
    ecriture_donnee_fichier_json( infoDateHeure, lecture_capteur_temperature_TMP36(), lecture_capteur_humidite_HIH4030(lecture_capteur_temperature_TMP36()) );
    heureSauvegarde++;
    //enregistrement_usb( infoDateHeure, lecture_capteur_temperature_TMP36(), lecture_capteur_humidite_HIH4030(lecture_capteur_temperature_TMP36()) );
    if(heureSauvegarde == 24){heureSauvegarde = 0;};
  }

  if(TEST_ENVOIE){
    enregistrement_usb( infoDateHeure, lecture_capteur_temperature_TMP36(), lecture_capteur_humidite_HIH4030(lecture_capteur_temperature_TMP36()) );
  }
}
