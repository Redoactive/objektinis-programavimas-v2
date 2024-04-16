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
class studentai_class{
    private:
        string vardas_;
        string pavarde_;
        vector<int> balai_;
        int egzaminas_;
        double vidurkis_;
        double mediana_;
    public:
        studentai_class() : vardas_(""), pavarde_(""), balai_(0), egzaminas_(0), vidurkis_(0), mediana_(0){};
        studentai_class(string vardas, string pavarde, vector<int> balai, int egzaminas, double vidurkis, double mediana) : 
        vardas_(vardas), pavarde_(pavarde), balai_(balai), egzaminas_(egzaminas), vidurkis_(vidurkis), mediana_(mediana){};
        ~studentai_class(){};


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
        friend ostream& operator<<(ostream& out, studentai_class a) // output overloading
        {
            out << setprecision(2) << fixed << a.pavarde_ << tarpai(a.pavarde_, 15) << a.vardas_ <<
            tarpai(a.vardas_, 15) << a.vidurkis_ << "             " << a.mediana_ << endl;
            return out;
        };
        friend istream& operator>>(istream& in, studentai_class a) // input oveloading
        {
            in >> a.vardas_ >> a.pavarde_ >> a.egzaminas_ >> a.vidurkis_ >> a.mediana_;
            return in;
        };

        studentai_class(const studentai_class& a)  // kopiviavimo konstruktorius
        : vardas_(a.vardas_), pavarde_(a.pavarde_), balai_(a.balai_), egzaminas_(a.egzaminas_), vidurkis_(a.vidurkis_), mediana_(a.mediana_) {
            for (int i = 0; i < a.balai_.size(); i++){
                balai_[i] = a.balai_[i];
            }
        }
        studentai_class operator=(const studentai_class& a){ // kopiviavimo operatorius / priskirimas
            if (&a == this){
                return *this;
            }
            vardas_ = a.vardas_;
            pavarde_ = pavarde_;
            for (int i = 0; i < a.balai_.size(); i++){
                balai_[i] = a.balai_[i];
            }
            egzaminas_ = a.egzaminas_;
            vidurkis_ = a.vidurkis_;
            mediana_ = a.mediana_;
            return *this;
        }
        studentai_class (studentai_class&& a)
        : vardas_(a.vardas_), pavarde_(a.pavarde_), balai_(a.balai_), egzaminas_(a.egzaminas_), vidurkis_(a.vidurkis_), mediana_(a.mediana_) {
            for (int i = 0; i < a.balai_.size(); i++){
                balai_[i] = a.balai_[i];
            }
        }
        studentai_class operator=(studentai_class&& a){
            if (&a == this){
                return *this;
            }
            vardas_ = a.vardas_;
            pavarde_ = pavarde_;
            for (int i = 0; i < a.balai_.size(); i++){
                balai_[i] = a.balai_[i];
            }
            egzaminas_ = a.egzaminas_;
            vidurkis_ = a.vidurkis_;
            mediana_ = a.mediana_;
            return *this;
        }
};



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

bool rusiavimasVardas(studentai_class &a, studentai_class &b);
bool rusiavimasPavarde(studentai_class &a, studentai_class &b);
bool rusiavimasVidurkis(studentai_class &a, studentai_class &b);
bool rusiavimasMediana(studentai_class &a, studentai_class &b);

void spausdinimasFaile();
void spausdinimasTerminale();
void spausdinimasFaileSkirstymas();
void spausdinimasTerminaleSkirstymas();

void laikoSpausdinimas(duration<double> readTime, duration<double> sortTime ,duration<double> typeTime);

