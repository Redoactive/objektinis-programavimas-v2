#pragma once
#include "includes.h"
#include <list>

// struct studentaiListai{
//     string vardas;
//     string pavarde;
//     list<int> balai;
//     int egzaminas;
//     double vidurkis;
//     double mediana;
// };

class studentai_classList{
    private:
        string vardas_;
        string pavarde_;
        list<int> balai_;
        int egzaminas_;
        double vidurkis_;
        double mediana_;
    public:
        studentai_classList() : vardas_(""), pavarde_(""), balai_(0), egzaminas_(0), vidurkis_(0), mediana_(0){};
        studentai_classList(string vardas, string pavarde, list<int> balai, int egzaminas, double vidurkis, double mediana) : 
        vardas_(vardas), pavarde_(pavarde), balai_(balai), egzaminas_(egzaminas), vidurkis_(vidurkis), mediana_(mediana){};
        ~studentai_classList(){};
        void setVardas(string a){vardas_ = a;};
        void setPavarde(string a){pavarde_ = a;};
        void setBalai(list<int> a){balai_ = a;};
        void setEgzaminas(int a){egzaminas_ = a;};
        void setVidurkis(double a){vidurkis_ = a;};
        void setMediana(double a){mediana_ = a;};

        string getVardas(){return vardas_;};
        string getPavarde(){return pavarde_;};
        list<int> getBalai(){return balai_;};
        int getEgzaminas(){return egzaminas_;};
        double getVidurkis(){return vidurkis_;};
        double getMediana(){return mediana_;};
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

bool rusiavimasVardasListai(studentai_classList &a, studentai_classList &b);
bool rusiavimasPavardeListai(studentai_classList &a, studentai_classList &b);
bool rusiavimasVidurkisListai(studentai_classList &a, studentai_classList &b);
bool rusiavimasMedianaListai(studentai_classList &a, studentai_classList &b);

void spausdinimasTerminaleListai();
void spausdinimasTerminaleSkirstymasListai();
void spausdinimasFaileListai();
void spausdinimasFaileSkirstymasListai();


void laikoSpausdinimas(duration<double> readTime, duration<double> sortTime ,duration<double> typeTime);