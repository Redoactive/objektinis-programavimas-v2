#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Vector.cpp"
#include "C.cpp"
using namespace std;

const int N = 50;

struct studentai{
    string vardas;
    string pavarde;
    double balas;
    int egzaminas;
};

string tarpai(string a);

void pirmasPasirinkimas();

void antrasPasirinkimas();

void treciasPasirinkimas();

int main(){
    bool darbasBaigtas = false;
    //pasirinkimu menu
    while (darbasBaigtas == false)
    {
        cout << "Pasirinkite, ka norite daryti\n"
        << "( 1 ) - Ivesti duomenys ranka\n"
        << "( 2 ) - Generuoti pazymius atsitiktinai\n"
        << "( 3 ) - Generuoti ir pažymius ir studentų vardus, pavardės"
        << "( 4 ) - Baigti darba";
        int pasirinkimas;
        cin >> pasirinkimas;
        switch (pasirinkimas)
        {
        case 1:
            pirmasPasirinkimas();
            break;
        case 2:
            antrasPasirinkimas();
            break;
        case 3:
            treciasPasirinkimas();
            break;
        case 4:
            darbasBaigtas = true;
            //spausdina main
            break;
        default:
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            break;
        }
    }
    



    int m;
    bool arMediana;
    studentai duomenys[50];
    //setprecision(2);
    cout << "Iveskite studentu kieki\n";
    cin >> m;

    //klausiama ar vartotojas nori vidurio, ar medianos
    cout << "Norite naudoti namu darbu balo apskaiciavimui vidurki (vid) ar mediana (med)\n";
    string pasirinkimas;
    cin >> pasirinkimas;
    if (pasirinkimas == "vid"){
        arMediana = false;
    } 
    else if(pasirinkimas == "med"){
        arMediana = true;
    }
    else{
        cout << "err";
    }

    //namu darbu kiekis
    int n;
    cout << "Iveskite namu darbu balu kieki\n";
    cin >> n;

    //pagrindinis ciklas
    for (int i = 0; i < m; i++){
        double vidurkis = 0, mediana;
        
        cout << "Iveskite varda\n";
        cin >> duomenys[i].vardas;
        cout << "Iveskite pavarde\n";
        cin >> duomenys[i].pavarde;
        

        //ivedami namu darbu irasai ranka
        cout << "Iveskite " << n << " namu darbu balus\n";
        vector<int> namuDarbai;
        int temp;
        for (int j = 0; j < n; j++){
            cin >> temp;
            namuDarbai.push_back(temp);
            vidurkis += temp;
        }//surandama mediana
        sort(namuDarbai.begin(), namuDarbai.end());
        if(n % 2 == 0){
            mediana = namuDarbai[n/2];
        }
        else {
            int temp = n / 2;
            mediana = (namuDarbai[temp] + namuDarbai[temp++]) / 2;
        }

        cout << "Iveskite egzamino rezultata\n";
        cin >> duomenys[i].egzaminas;
        vidurkis /= n;
        //apskaiciuojamas galutinis balas
        if (arMediana == false){
            duomenys[i].balas = 0.4 * vidurkis + 0.6 * duomenys[i].egzaminas;
        }
        else{
            duomenys[i].balas = 0.4 * mediana + 0.6 * duomenys[i].egzaminas;
        }
        
    }

    
    //output

    cout << "Pavarde        Vardas         ";
    if (arMediana == false){
        cout << "Galutinis (Vid.)\n";
    }
    else{
        cout << "Galutinis (Med.)\n";
    }    
    cout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < m; i++){
        
        cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas) << duomenys[i].balas << endl;
    }

}
//funckija spausdinti tarpus
string tarpai(string a){
    string kiekis;
    int m = 15 - a.length();
    for (int i = 0; i < m; i++){
        kiekis += " ";
    }
    return kiekis;
}