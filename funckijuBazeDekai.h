#pragma once
#include "includes.h"
#include <deque>
struct studentaiDekas{
    string vardas;
    string pavarde;
    deque<int> balai;
    int egzaminas;
    double vidurkis;
    double mediana;
};
void failoGeneracija();

void darbasSuDekais();
string tarpai(string a, int tarpuDydis);
bool rusiavimasVardasDekas(const studentaiDekas &a, const studentaiDekas &b);
bool rusiavimasPavardeDekas(const studentaiDekas &a, const studentaiDekas &b);
bool rusiavimasVidurkisDekas(const studentaiDekas &a, const studentaiDekas &b);
bool rusiavimasMedianaDekas(const studentaiDekas &a, const studentaiDekas &b);
void pirmasPasirinkimasDekai();
void antrasPasirinkimasDekai();
void treciasPasirinkimasDekai();
void NuskaitymasFailoDekai(string fileName);
