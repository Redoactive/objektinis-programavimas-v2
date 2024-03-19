#ifndef include
#define include
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <chrono>
#include <random>
#include <sstream>
#include <list>

using namespace std;
using namespace std::chrono;
struct studentai{
    string vardas;
    string pavarde;
    vector<int> balai;
    int egzaminas;
    double vidurkis;
    double mediana;
};
struct studentaiDekas{
    string vardas;
    string pavarde;
    deque<int> balai;
    int egzaminas;
    double vidurkis;
    double mediana;
};
struct studentaiListai{
    string vardas;
    string pavarde;
    list<int> balai;
    int egzaminas;
    double vidurkis;
    double mediana;
};

#endif