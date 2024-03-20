#pragma once
#include "includes.h"

//konteineriu skirtumo funkcijos main pasirinkimai
void darbasSuVektoriais();
void darbasSuDekais();
void darbasSuListais();

//apskaiciavimo funkcijos //ka cia daryti?? 
// double vidurkioApsk(vector<int> a, int egzaminas);
// double medianosApsk(vector<int> a, int egzaminas);
//tarpu skaiciavimas spausdinimui
string tarpai(string a, int tarpuDydis);
//rusiavimo funkcijos
bool rusiavimasVardas(const studentai &a, const studentai &b);
bool rusiavimasPavarde(const studentai &a, const studentai &b);
bool rusiavimasVidurkis(const studentai &a, const studentai &b);
bool rusiavimasMediana(const studentai &a, const studentai &b);

bool rusiavimasVardasDekas(const studentaiDekas &a, const studentaiDekas &b);
bool rusiavimasPavardeDekas(const studentaiDekas &a, const studentaiDekas &b);
bool rusiavimasVidurkisDekas(const studentaiDekas &a, const studentaiDekas &b);
bool rusiavimasMedianaDekas(const studentaiDekas &a, const studentaiDekas &b);

void rusiavimoMenu();

//laikas
void laikoSpausdinimas();

//pagrindines funkcijos
void pirmasPasirinkimas();
void antrasPasirinkimas();
void treciasPasirinkimas();

//spausdinimo funkcijos
void spausdinimasFaile();
void spausdinimasTerminale();

//nuskaitymas is failo
void NuskaitymasFailo(string fileName);
void skirstymas();
//failu generacija 
void failoGeneracija();
//0.4 versija funkciju kopijos
void rusiavimoMenuSkirstymas();
void spausdinimasFaileSkirstymas();
void spausdinimasTerminaleSkirstymas();