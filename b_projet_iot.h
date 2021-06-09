#ifndef __BIBLIOTHEQUE__
#define __BIBLIOTHEQUE__

#include <DS3231.h>

#define TMP36_PORT              A2
#define HIH4030_PORT            A1
#define CARTESD_PORT            7
#define BOUTON_PORT             6
#define BOUTON_PORT_DEUX        0

#define TMP36_TENSION           3.3
#define HIH4030_TENSION         5

#define CONVERTION_BINAIRE      1024
#define CONVERTION_MILLIVOLT    1000

#define ROUGE                   255
#define VERT                    192
#define BLEU                    0

#define LCD_ALLUME              1
#define LCD_ETEIND              0

#define LECTURE_BOUTON          digitalRead(BOUTON_PORT)
#define TEST_ENVOIE             digitalRead(BOUTON_PORT_DEUX)
#define LECTURE_PORT            analogRead               

float lecture_capteur_temperature_TMP36();
float lecture_capteur_humidite_HIH4030(float valeurTemperature);

void affichage_date(uint16_t valeurAnnee, uint8_t valeurMois, uint8_t valeurJour);
void affichage_heure(uint8_t valeurHeure, uint8_t valeurMinute);
void afficher_temperature_TMP36();
void afficher_humidite_HIH4030(float valeurTemperature);
int allumer_ecran_LCD();
int eteindre_ecran_LCD();
void ecrir_sur_premiere_ligne();
void ecrir_sur_seconde_ligne();
void activation_ecran_LCD();

void activation_lecteur_sd();
bool verifier_fichier_csv_existe(uint16_t valeurAnnee);
bool verifier_fichier_json_existe(uint16_t valeurAnnee);
void creation_fichier_csv(uint16_t valeurAnnee);
void creation_fichier_json(uint16_t valeurAnnee);
void ecriture_donnee_fichier_csv(RTCDateTime infoDateHeure, float valeurTemperature, float valeurHumidite);
void ecriture_donnee_fichier_json(RTCDateTime infoDateHeure, float valeurTemperature, float valeurHumidite);

void enregistrement_usb(RTCDateTime infoDateHeure, float valeurTemperature, float valeurHumidite);

#endif
