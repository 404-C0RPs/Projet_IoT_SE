#include <SPI.h>
#include <SD.h>
#include <DS3231.h>

#include "b_projet_iot.h"

File fichierSauvegardeDonnee;

void activation_lecteur_sd(){
    SD.begin(CARTESD_PORT);
}

bool verifier_fichier_csv_existe(uint16_t valeurAnnee){
    bool fichierExiste;
    fichierExiste = SD.exists(String(valeurAnnee)+".csv");
    delay(100);
    return fichierExiste;    
}

bool verifier_fichier_json_existe(uint16_t valeurAnnee){
    bool fichierExiste;
    fichierExiste = SD.exists(String(valeurAnnee)+".json");
    delay(100);
    return fichierExiste;
}

void creation_fichier_csv(uint16_t valeurAnnee){
    fichierSauvegardeDonnee = SD.open(String(valeurAnnee)+".csv", FILE_WRITE);
    delay(100);
    if(fichierSauvegardeDonnee){
        fichierSauvegardeDonnee.println("Date-Heure,Temperature,Humidite");
        delay(100);
        fichierSauvegardeDonnee.close();
        delay(100);
    }
    else{
        //afficher l'erreur
    }
}

void creation_fichier_json(uint16_t valeurAnnee){
    fichierSauvegardeDonnee = SD.open(String(valeurAnnee)+".json", FILE_WRITE);
    delay(100);
    if(fichierSauvegardeDonnee){
        fichierSauvegardeDonnee.println("Date-Heure,Temperature,Humidite");
        delay(100);
        fichierSauvegardeDonnee.close();
        delay(100);
    }
    else{
        //afficher l'erreur
    }
}

void ecriture_donnee_fichier_csv(RTCDateTime infoDateHeure, float valeurTemperature, float valeurHumidite){
    fichierSauvegardeDonnee = SD.open(String(infoDateHeure.year)+".csv", FILE_WRITE);
    delay(100);
    if(fichierSauvegardeDonnee){
        fichierSauvegardeDonnee.print(infoDateHeure.year);fichierSauvegardeDonnee.print("/");
        fichierSauvegardeDonnee.print(infoDateHeure.month);fichierSauvegardeDonnee.print("/");
        fichierSauvegardeDonnee.print(infoDateHeure.day);fichierSauvegardeDonnee.print(" ");
        fichierSauvegardeDonnee.print(infoDateHeure.hour);fichierSauvegardeDonnee.print(":");
        fichierSauvegardeDonnee.print(infoDateHeure.minute);fichierSauvegardeDonnee.print(",");
        fichierSauvegardeDonnee.print(valeurTemperature);fichierSauvegardeDonnee.print(",");
        fichierSauvegardeDonnee.println(valeurHumidite);
        delay(100);
        fichierSauvegardeDonnee.close();
        delay(100);
    }
    else{
        //afficher l'erreur
    }
}

void ecriture_donnee_fichier_json(RTCDateTime infoDateHeure, float valeurTemperature, float valeurHumidite){
    fichierSauvegardeDonnee = SD.open(String(infoDateHeure.year)+".json", FILE_WRITE);
    delay(100);
    if(fichierSauvegardeDonnee){
        fichierSauvegardeDonnee.print(infoDateHeure.year);fichierSauvegardeDonnee.print("/");
        fichierSauvegardeDonnee.print(infoDateHeure.month);fichierSauvegardeDonnee.print("/");
        fichierSauvegardeDonnee.print(infoDateHeure.day);fichierSauvegardeDonnee.print(" ");
        fichierSauvegardeDonnee.print(infoDateHeure.hour);fichierSauvegardeDonnee.print(":");
        fichierSauvegardeDonnee.print(infoDateHeure.minute);fichierSauvegardeDonnee.print(",");
        fichierSauvegardeDonnee.print(valeurTemperature);fichierSauvegardeDonnee.print(",");
        fichierSauvegardeDonnee.println(valeurHumidite);
        delay(100);
        fichierSauvegardeDonnee.close();
        delay(100);
    }
    else{
        //afficher l'erreur
    }
}