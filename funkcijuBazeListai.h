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

string tarpai(string a, int tarpuDydis);
string extraSpace (string a, int b);

void pirmasPasirinkimasListai();
void antrasPasirinkimasListai();
void treciasPasirinkimasListai();

void NuskaitymasFailoListai(string fileName);
void failoGeneracija();

void skirstymasListai();

void rusiavimoMenuSkirstymasListai();
void rusiavimoMenuListai();

bool rusiavimasVardasListai(const studentaiListai &a, const studentaiListai &b);
bool rusiavimasPavardeListai(const studentaiListai &a, const studentaiListai &b);
bool rusiavimasVidurkisListai(const studentaiListai &a, const studentaiListai &b);
bool rusiavimasMedianaListai(const studentaiListai &a, const studentaiListai &b);

void spausdinimasTerminaleListai();
void spausdinimasTerminaleSkirstymasListai();
void spausdinimasFaileListai();
void spausdinimasFaileSkirstymasListai();


void laikoSpausdinimas(duration<double> readTime, duration<double> sortTime ,duration<double> typeTime);