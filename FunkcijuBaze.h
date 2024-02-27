#include "includes.h"
#include "funkcijos.cpp"
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

//pagrindines funkcijos
void pirmasPasirinkimas();
void antrasPasirinkimas();
void treciasPasirinkimas();