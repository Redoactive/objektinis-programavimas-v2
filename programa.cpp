#include "headerFile.h"
#include "vector.cpp"
using namespace std;

int studentuSkc = 0;
bool arMediana;


string tarpai(string a);

void pirmasPasirinkimas(){
    //pagrindinis ciklas
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        double vidurkis = 0, mediana;
        string temp;
        cout << "Iveskite varda\n";
        cin >> temp;
        duomenys[studentuSkc].vardas = temp;

        cout << "Iveskite pavarde\n";
        cin >> temp;
        duomenys[studentuSkc].pavarde = temp;
        
        

        //ivedami namu darbu irasai ranka
        cout << "Iveskite namu darbu balus\n";        
        while (true){
            int temporary;
            cin >> temporary;
            duomenys[studentuSkc].balai.push_back(temporary);
        }

        cout << "Iveskite egzamino rezultata\n";
        cin >> duomenys[studentuSkc].egzaminas;

        // 
        
    }
}

void antrasPasirinkimas(){};

void treciasPasirinkimas(){};

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
   



    // int m;
    // studentai duomenys[50];
    // cout << "Iveskite studentu kieki\n";
    // cin >> m;
    // //namu darbu kiekis
    // int n;
    // cout << "Iveskite namu darbu balu kieki\n";
    // cin >> n;

    
// //surandama mediana
        // sort(namuDarbai.begin(), namuDarbai.end());
        // if(n % 2 == 0){
        //     mediana = namuDarbai[n/2];
        // }
        // else {
        //     int temp = n / 2;
        //     mediana = (namuDarbai[temp] + namuDarbai[temp++]) / 2;
        // }
    //apskaiciuojamas galutinis balas
        // if (arMediana == false){
        //     duomenys[i].balas = 0.4 * vidurkis + 0.6 * duomenys[i].egzaminas;
        // }
        // else{
        //     duomenys[i].balas = 0.4 * mediana + 0.6 * duomenys[i].egzaminas;
        // }
    //output

    cout << "Pavarde        Vardas         ";
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