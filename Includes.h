#ifndef includes.h
#define includes.h
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>

#include "funkcijuBaze.h"
using namespace std;

struct studentai{
    string vardas;
    string pavarde;
    vector<int> balai;
    int egzaminas;
    double vidurkis;
    double mediana;
};
#endif