#pragma once
#include "includes.h"

//apskaiciavimo funkcijos
double vidurkioApsk(vector<int> a, int egzaminas);
double medianosApsk(vector<int> a, int egzaminas);
//tarpu skaiciavimas spausdinimui
string tarpai(string a);
//rusiavimo funkcijos
bool rusiavimasVardas(const studentai &a, const studentai &b);
bool rusiavimasPavarde(const studentai &a, const studentai &b);
bool rusiavimasVidurkis(const studentai &a, const studentai &b);
bool rusiavimasMediana(const studentai &a, const studentai &b);

void rusiavimoMenu();

//pagrindines funkcijos
void pirmasPasirinkimas();
void antrasPasirinkimas();
void treciasPasirinkimas();

//spausdinimo funkcijos
void spausdinimasFaile();
void spausdinimasTerminale();

//nuskaitymas is failo
void NuskaitymasFailo(string fileName);

//failu generacija 
void failoGeneracija();