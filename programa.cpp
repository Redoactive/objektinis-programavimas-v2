#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int studentuSkc = 0;
bool arMediana;

// struct studentai {
//     vector<string> vardas;
//     vector<string> pavarde;
//     vector<int> egzaminas;
//     vector<int> balas;
// };

struct studentai{
    string vardas;
    string pavarde;
    vector<int> balai;
    int egzaminas;
};
vector<studentai> duomenys;
string tarpai(string a);

void pirmasPasirinkimas(){
    //pagrindinis ciklas
    studentai dabartinisStudentas;
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        double vidurkis = 0, mediana;
        cout << "Iveskite varda\n";
        cin >> dabartinisStudentas.vardas;
        cout << "Iveskite pavarde\n";
        cin >> dabartinisStudentas.pavarde;   

        //ivedami namu darbu irasai ranka
        cout << "Iveskite namu darbu balus. Jei norite nustoti ivedineti, parasykite ( -1 )\n";
        int temporary;

        while (true){
            cin >> temporary;
            if (temporary == -1){
                break;
            }
            dabartinisStudentas.balai.push_back(temporary);
        }

        cout << "Iveskite egzamino rezultata\n";
        cin >> dabartinisStudentas.egzaminas;

        //issaugomi duomenys
        duomenys.push_back(dabartinisStudentas);        


        //paprasoma baigti ivesti
        cout << "Jeigu norite baigti ivedineti duomenys, parasykite ( stop )\n";
        string temp;
        cin >> temp;
        if (temp == "stop"){
            return;
        }
    }
}

void antrasPasirinkimas(){};

void treciasPasirinkimas(){};

double medianosApsk(vector<int> a, int egzaminas){
    
    sort(a.begin(), a.end());
    int n = a.size() / 2;
    if(n % 2 == 0){
        return a[n / 2] * 0.4 + egzaminas * 0.6;
    }
    else {
        return (a[n] + a[n++]) / 2 * 0.4 + egzaminas * 0.6;
    }
}

double vidurkioApsk(vector<int> a, int egzaminas){
    double vidurkis = 0;
    for (int i : a){
        vidurkis += i;
    }
    return vidurkis / a.size() * 0.4 + 0.6 * egzaminas;
}





int main(){
    bool darbasBaigtas = false;
    //pasirinkimu menu
    while (darbasBaigtas == false)
    {
        cout << "Pasirinkite, ka norite daryti\n"
        << "( 1 ) - Ivesti duomenys ranka\n"
        << "( 2 ) - Generuoti pazymius atsitiktinai\n"
        << "( 3 ) - Generuoti ir pažymius ir studentų vardus, pavardės\n"
        << "( 4 ) - Baigti darba\n";
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

     //klausiama ar vartotojas nori vidurio, ar medianos
    darbasBaigtas = false;

    while (darbasBaigtas == false){
        cout << "Norite naudoti namu darbu balo apskaiciavimui vidurki (vid) ar mediana (med)\n";
        string pasirinkimas;
        cin >> pasirinkimas;

        if (pasirinkimas == "vid"){
            arMediana = false;
            darbasBaigtas = true;
        } 
        else if(pasirinkimas == "med"){
            arMediana = true;
            darbasBaigtas = true;
        }
        else{
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
        }
    }
    
    //surandama mediana
    // sort(namuDarbai.begin(), namuDarbai.end());
    // if(n % 2 == 0){
    //     mediana = namuDarbai[n/2];
    // }
    // else {
    //     int temp = n / 2;
    //     mediana = (namuDarbai[temp] + namuDarbai[temp++]) / 2;
    // }
    //apskaiciuojamas galutinis balas

    cout << "Pavarde        Vardas         ";
    if (arMediana == false){
        cout << "Galutinis (Vid.)\n";
    }
    else{
        cout << "Galutinis (Med.)\n";
    }    
    cout << "----------------------------------------------------\n";

    for (int i = 0; i < duomenys.size(); i++){

        cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas);
        if (arMediana){
            cout << medianosApsk(duomenys[i].balai, duomenys[i].egzaminas) << endl;
        }
        else {
            cout << vidurkioApsk(duomenys[i].balai, duomenys[i].egzaminas) << endl;
        }
    
    }
    //reiketu sutvarkyti ivedimo tvarka- pavardes pirmos



    // if (arMediana == false){
    //     duomenys.bala = 0.4 * vidurkis + 0.6 * duomenys[i].egzaminas;
    // }
    // else{
    //     duomenys[i].balas = 0.4 * mediana + 0.6 * duomenys[i].egzaminas;
    // }
    // //output

    // cout << "Pavarde        Vardas         ";
    // if (arMediana == false){
    //     cout << "Galutinis (Vid.)\n";
    // }
    // else{
    //     cout << "Galutinis (Med.)\n";
    // }    
    // cout << "------------------------------------------------------------------------\n";
    // for (int i = 0; i < m; i++){
        
    //     cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde)
    //     << duomenys[i].vardas <<  tarpai(duomenys[i].vardas) << duomenys[i].balas << endl;
    // }

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