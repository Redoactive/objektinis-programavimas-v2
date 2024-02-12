#include <iostream>
#include <iomanip>
using namespace std;

const int N = 50;

struct studentai{
    string vardas;
    string pavarde;
    double balas;
    int egzaminas;
};

string tarpai(string a);

int main(){
    int m;
    studentai duomenys[50];
    //setprecision(2);
    cout << "Iveskite studentu kieki\n";
    cin >> m;

    for (int i = 0; i < m; i++){
        double vidurkis = 0;
        cout << "Iveskite varda\n";
        cin >> duomenys[i].vardas;
        cout << "Iveskite pavarde\n";
        cin >> duomenys[i].pavarde;
        cout << "Iveskite namu darbu balu kieki ir iveskite siuos balus\n";
        int n;
        cin >> n;
        int namuDarbai;
        for (int j = 0; j < n; j++){
            cin >> namuDarbai;
            vidurkis += namuDarbai;
        }
        cout << "Iveskite egzamino rezultata\n";
        cin >> duomenys[i].egzaminas;
        vidurkis /= n;
        duomenys[i].balas = 0.4 * vidurkis + 0.6 * duomenys[i].egzaminas;
        
    }

    //output
    cout << "Pavarde        Vardas         Galutinis (Vid.)\n"
    << "-----------------------------------------------\n";
    for (int i = 0; i < m; i++){
        
        cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas) << duomenys[i].balas << endl;
    }

    
    

}
string tarpai(string a){
    string kiekis;
    int m = 15 - a.length();
    for (int i = 0; i < m; i++){
        kiekis += " ";
    }
    return kiekis;
}