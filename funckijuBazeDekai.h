#pragma once
#include "includes.h"
#include <deque>
// struct studentaiDekas{
//     string vardas;
//     string pavarde;
//     deque<int> balai;
//     int egzaminas;
//     double vidurkis;
//     double mediana;
// };

class studentai_classDeque{
    private:
        string vardas_;
        string pavarde_;
        deque<int> balai_;
        int egzaminas_;
        double vidurkis_;
        double mediana_;
    public:
        studentai_classDeque() : vardas_(""), pavarde_(""), balai_(0), egzaminas_(0), vidurkis_(0), mediana_(0){};
        studentai_classDeque(string vardas, string pavarde, deque<int> balai, int egzaminas, double vidurkis, double mediana) : 
        vardas_(vardas), pavarde_(pavarde), balai_(balai), egzaminas_(egzaminas), vidurkis_(vidurkis), mediana_(mediana){};
        ~studentai_classDeque(){};
        void setVardas(string a){vardas_ = a;};
        void setPavarde(string a){pavarde_ = a;};
        void setBalai(deque<int> a){balai_ = a;};
        void setEgzaminas(int a){egzaminas_ = a;};
        void setVidurkis(double a){vidurkis_ = a;};
        void setMediana(double a){mediana_ = a;};

        string getVardas(){return vardas_;};
        string getPavarde(){return pavarde_;};
        deque<int> getBalai(){return balai_;};
        int getEgzaminas(){return egzaminas_;};
        double getVidurkis(){return vidurkis_;};
        double getMediana(){return mediana_;};
};
string tarpai(string a, int tarpuDydis);
string extraSpace (string a, int b);

void pirmasPasirinkimasDekai();
void antrasPasirinkimasDekai();
void treciasPasirinkimasDekai();

void NuskaitymasFailoDekai(string fileName);
void failoGeneracija();

void skirstymasDekai();

void rusiavimoMenuSkirstymasDekai();
void rusiavimoMenuDekai();

bool rusiavimasVardasDekas( studentai_classDeque &a,  studentai_classDeque &b);
bool rusiavimasPavardeDekas( studentai_classDeque &a,  studentai_classDeque &b);
bool rusiavimasVidurkisDekas( studentai_classDeque &a,  studentai_classDeque &b);
bool rusiavimasMedianaDekas( studentai_classDeque &a,  studentai_classDeque &b);

void spausdinimasTerminaleDekai();
void spausdinimasTerminaleSkirstymasDekai();
void spausdinimasFaileDekai();
void spausdinimasFaileSkirstymasDekai();


void laikoSpausdinimas(duration<double> readTime, duration<double> sortTime ,duration<double> typeTime);