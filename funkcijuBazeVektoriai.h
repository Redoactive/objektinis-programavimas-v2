#pragma once
#include "includes.h"

struct studentai{
    string vardas;
    string pavarde;
    vector<int> balai;
    int egzaminas;
    double vidurkis;
    double mediana;
};

bool rusiavimasVardas(const studentai &a, const studentai &b);
bool rusiavimasPavarde(const studentai &a, const studentai &b);
bool rusiavimasVidurkis(const studentai &a, const studentai &b);
bool rusiavimasMediana(const studentai &a, const studentai &b);


//Vektorius
void pirmasPasirinkimas();
void antrasPasirinkimas();
void treciasPasirinkimas();
void NuskaitymasFailo(string fileName);
void failoGeneracija();
void skirstymas();
void rusiavimoMenu();
void rusiavimoMenuSkirstymas();
void spausdinimasFaile();
void spausdinimasTerminale();
void spausdinimasFaileSkirstymas();
void spausdinimasTerminaleSkirstymas();
void laikoSpausdinimas();


string tarpai(string a, int tarpuDydis);
string extraSpace (string a, int b);