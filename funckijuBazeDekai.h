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
string tarpai(string a, int tarpuDydis);
string extraSpace (string a, int b);

void darbasSuDekais();

void pirmasPasirinkimasDekai();
void antrasPasirinkimasDekai();
void treciasPasirinkimasDekai();

void NuskaitymasFailoDekai(string fileName);
void failoGeneracija();
void skirstymasDekai();

void rusiavimoMenuSkirstymasDekai();
void rusiavimoMenuDekai();

bool rusiavimasVardasDekas(const studentaiDekas &a, const studentaiDekas &b);
bool rusiavimasPavardeDekas(const studentaiDekas &a, const studentaiDekas &b);
bool rusiavimasVidurkisDekas(const studentaiDekas &a, const studentaiDekas &b);
bool rusiavimasMedianaDekas(const studentaiDekas &a, const studentaiDekas &b);

void spausdinimasTerminaleDekai();
void spausdinimasTerminaleSkirstymasDekai();
void spausdinimasFaileDekai();
void spausdinimasFaileSkirstymasDekai();


void laikoSpausdinimas(duration<double> readTime, duration<double> sortTime ,duration<double> typeTime);