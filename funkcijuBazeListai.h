#pragma once
#include "includes.h"
#include <list>

struct studentaiListai{
    string vardas;
    string pavarde;
    list<int> balai;
    int egzaminas;
    double vidurkis;
    double mediana;
};

void darbasSuListais();
bool rusiavimasVardasListai(const studentaiListai &a, const studentaiListai &b);
bool rusiavimasPavardeListai(const studentaiListai &a, const studentaiListai &b);
bool rusiavimasVidurkisListai(const studentaiListai &a, const studentaiListai &b);
bool rusiavimasMedianaListai(const studentaiListai &a, const studentaiListai &b);
string tarpai(string a, int tarpuDydis);
void laikoSpausdinimas();
void pirmasPasirinkimas();
void antrasPasirinkimas();
void treciasPasirinkimas();
void spausdinimasFaile();
void spausdinimasTerminale();
void failoGeneracija();

//nuskaitymas is failo
void NuskaitymasFailo(string fileName);

void skirstymas();
void rusiavimoMenuSkirstymas();
void spausdinimasFaileSkirstymas();
void spausdinimasTerminaleSkirstymas();