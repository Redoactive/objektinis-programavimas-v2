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
string tarpai(string a, int tarpuDydis);
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
        int* rodykle_ = nullptr; /// Rodykle ir dydis yra naudojami testavimo tikslams
        int dydis_= 0;
    public:
        /// Pakeicia rodykleje skaiciu, kad pamatyti ar gerai kopijavimas/movinimas vyksta
        virtual void setMasyvas(int a, int b){rodykle_[a] = b;}; 
        /// Isspausdina rodykles turini, jei tuscia, sako kad yra null, siuo atveju tai yra pilnai virtuali funkcija
        virtual void testav() = 0;
        /// Brief description - Tai yra konstruktorius
        /** Detailed description - Cia vyksta konstruktoriaus dalykai
         *  Pvz jis sukuria kintamus
         *  Tada executina tai kas tarp siu skliaustu {}
         *  Po to konstruktorius uzsidaro
         */
        studentai_base(){};
        virtual ~studentai_base(){};
};




class studentai_class : public studentai_base{
    public:
        studentai_class();
        studentai_class(string vardas, string pavarde, vector<int> balai, int egzaminas, double vidurkis, double mediana);
        /// Dekonstruktorius istryna rodykles turini
        ~studentai_class(){delete[] rodykle_;}; 
        //testavimui
        /// Konstruktorius, kuris naudojamas darant testavima
        studentai_class(int dydis);
        /// Si funkcija yra overwritinama is bazines klases
        void testav();
        /// Setteris
        void setVardas(string a){vardas_ = a;};
        /// Setteris
        void setPavarde(string a){pavarde_ = a;};
        /// Setteris
        void setBalai(vector<int> a){balai_ = a;};
        /// Setteris
        void setEgzaminas(int a){egzaminas_ = a;};
        /// Setteris
        void setVidurkis(double a){vidurkis_ = a;};
        /// Setteris
        void setMediana(double a){mediana_ = a;};

        /// Getteris
        string getVardas(){return vardas_;};
        /// Getteris
        string getPavarde(){return pavarde_;};
        /// Getteris
        vector<int> getBalai(){return balai_;};
        /// Getteris
        int getEgzaminas(){return egzaminas_;};
        /// Getteris
        double getVidurkis(){return vidurkis_;};
        /// Getteris
        double getMediana(){return mediana_;};


        friend ostream& operator<<(ostream& out, studentai_class a);///< output overloading
        friend istream& operator>>(istream& in, studentai_class &a);///< input overloading

        studentai_class(const studentai_class& a);  ///< kopiviavimo konstruktorius
        studentai_class operator=(const studentai_class& a); ///< kopiviavimo operatorius / priskirimas
        studentai_class (studentai_class&& a); ///< move konstruktorius
        studentai_class operator=(studentai_class&& a); ///< move operatorius
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

