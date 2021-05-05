/*
#   DURAND Boris
#
#   Fichier principal pour l'arduino (système embarqué du projet)
#
#   git remote add origin https://github.com/404-C0RPs/Projet_IoT_SE.git
#   git branch -M main
#   git push -u origin main
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
  Serial.begin(9600);
  activation_ecran_LCD();
  moduleHorloge.begin();
  moduleHorloge.setDateTime(__DATE__, __TIME__);
  delay(500);
  infoDateHeure = moduleHorloge.getDateTime();
  delay(100);
  heureSauvegarde = infoDateHeure.hour;
  activation_lecteur_sd();
  delay(200);
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
    fichierCsvExiste = verifier_fichier_csv_existe(infoDateHeure.hour);
    fichierJsonExiste = verifier_fichier_json_existe(infoDateHeure.hour);

    if(!fichierCsvExiste && !fichierJsonExiste){
      creation_fichier_csv(infoDateHeure.hour);
      creation_fichier_json(infoDateHeure.hour);
    }else if(!fichierJsonExiste && fichierCsvExiste){
      creation_fichier_json(infoDateHeure.hour);
    }else if(!fichierCsvExiste && fichierJsonExiste){
      creation_fichier_csv(infoDateHeure.hour);
    };

    ecriture_donnee_fichier_csv( infoDateHeure, lecture_capteur_temperature_TMP36(), lecture_capteur_humidite_HIH4030(lecture_capteur_temperature_TMP36()) );
    ecriture_donnee_fichier_json( infoDateHeure, lecture_capteur_temperature_TMP36(), lecture_capteur_humidite_HIH4030(lecture_capteur_temperature_TMP36()) );
    heureSauvegarde++;
    if(heureSauvegarde == 24){heureSauvegarde = 0;};
  }
}
