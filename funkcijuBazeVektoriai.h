#pragma once
#include "includes.h"

// struct studentai{
//     string vardas;
//     string pavarde;
//     vector<int> balai;
//     int egzaminas;
//     double vidurkis;
//     double mediana;
// };
string tarpai(string a, int tarpuDydis);// turi buti pirmiau uz klase del perdengto operatoriaus <<
double vidurkioApsk(vector<int> a, int egzaminas);
double medianosApsk(vector<int> a, int egzaminas);


class studentai_base{
    protected:
        string vardas_;
        string pavarde_;
        vector<int> balai_;
        int egzaminas_;
        double vidurkis_;
        double mediana_;
        int* rodykle_;
        int dydis_;
    public:
        virtual void setMasyvas(int a, int b){rodykle_[a] = b;};
        virtual void testav() = 0;
        studentai_base(){};//default konstruktorius
        virtual ~studentai_base(){};
};




class studentai_class : public studentai_base{
    public:
        studentai_class();
        studentai_class(string vardas, string pavarde, vector<int> balai, int egzaminas, double vidurkis, double mediana);
        ~studentai_class(){delete[] rodykle_;}; 
        //testavimui
        studentai_class(int dydis);
        
        void testav();
        void setVardas(string a){vardas_ = a;};
        void setPavarde(string a){pavarde_ = a;};
        void setBalai(vector<int> a){balai_ = a;};
        void setEgzaminas(int a){egzaminas_ = a;};
        void setVidurkis(double a){vidurkis_ = a;};
        void setMediana(double a){mediana_ = a;};

        string getVardas(){return vardas_;};
        string getPavarde(){return pavarde_;};
        vector<int> getBalai(){return balai_;};
        int getEgzaminas(){return egzaminas_;};
        double getVidurkis(){return vidurkis_;};
        double getMediana(){return mediana_;};
        friend ostream& operator<<(ostream& out, studentai_class a);//output overloading
        friend istream& operator>>(istream& in, studentai_class &a);//input

        studentai_class(const studentai_class& a);  // kopiviavimo konstruktorius
        studentai_class operator=(const studentai_class& a); // kopiviavimo operatorius / priskirimas
        studentai_class (studentai_class&& a); // move konstruktorius
        studentai_class operator=(studentai_class&& a); // move operatorius
};
string extraSpace (string a, int b);


void klasiuTestavimas();
//Vektorius
void pirmasPasirinkimas();
void antrasPasirinkimas();
void treciasPasirinkimas();

void NuskaitymasFailo(string fileName);
void failoGeneracija();

void skirstymas();

void rusiavimoMenu();
void rusiavimoMenuSkirstymas();

bool rusiavimasVardas(studentai_class &a, studentai_class &b);
bool rusiavimasPavarde(studentai_class &a, studentai_class &b);
bool rusiavimasVidurkis(studentai_class &a, studentai_class &b);
bool rusiavimasMediana(studentai_class &a, studentai_class &b);

void spausdinimasFaile();
void spausdinimasTerminale();
void spausdinimasFaileSkirstymas();
void spausdinimasTerminaleSkirstymas();

void laikoSpausdinimas(duration<double> readTime, duration<double> sortTime ,duration<double> typeTime);

