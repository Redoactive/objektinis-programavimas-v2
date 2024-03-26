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

class studentai_class{
    private:
        string vardas_;
        string pavarde_;
        vector<int> balai_;
        int egzaminas_;
        double vidurkis_;
        double mediana_;
    public:
        studentai_class();
        void setVardas(string);
        string getVardas();
};


string tarpai(string a, int tarpuDydis);
string extraSpace (string a, int b);



//Vektorius
void pirmasPasirinkimas();
void antrasPasirinkimas();
void treciasPasirinkimas();

void NuskaitymasFailo(string fileName);
void failoGeneracija();

void skirstymas();

void rusiavimoMenu();
void rusiavimoMenuSkirstymas();

bool rusiavimasVardas(const studentai &a, const studentai &b);
bool rusiavimasPavarde(const studentai &a, const studentai &b);
bool rusiavimasVidurkis(const studentai &a, const studentai &b);
bool rusiavimasMediana(const studentai &a, const studentai &b);

void spausdinimasFaile();
void spausdinimasTerminale();
void spausdinimasFaileSkirstymas();
void spausdinimasTerminaleSkirstymas();

void laikoSpausdinimas(duration<double> readTime, duration<double> sortTime ,duration<double> typeTime);

