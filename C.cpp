#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <array>
using namespace std;

const int N = 100;
int studentuSkc = 0;
struct studentai{
    string vardas;
    string pavarde;
    array<int, N> balai;
    int egzaminas;
};

bool arMediana;
array<studentai, N> duomenys;

string tarpai(string a);

void pirmasPasirinkimas(){
    //pagrindinis ciklas
    studentai dabartinisStudentas;
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        dabartinisStudentas.balai.fill(11);
        double vidurkis = 0, mediana;
        cout << "Iveskite varda\n";
        cin >> dabartinisStudentas.vardas;
        cout << "Iveskite pavarde\n";
        cin >> dabartinisStudentas.pavarde;   

        //ivedami namu darbu irasai ranka
        cout << "Iveskite namu darbu balus. Jei norite nustoti ivedineti, parasykite ( -1 )\n";
        int temporary;
        int i = 0;
        
        while (true){
            cin >> temporary;
            if (temporary == -1){
                break;
            }
            dabartinisStudentas.balai[i] = temporary;
            i++;
        }

        cout << "Iveskite egzamino rezultata\n";
        cin >> dabartinisStudentas.egzaminas;

        //issaugomi duomenys
        duomenys[studentuSkc] = dabartinisStudentas;        
        studentuSkc++;

        //paprasoma baigti ivesti
        cout << "Jeigu norite baigti ivedineti duomenys, parasykite ( stop )\n";
        string temp;
        cin >> temp;
        if (temp == "stop"){
            return;
        }
    }
}

void antrasPasirinkimas(){
    //pagrindinis ciklas
    studentai dabartinisStudentas;
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        dabartinisStudentas.balai.fill(11);
        double vidurkis = 0, mediana;
        cout << "Iveskite varda\n";
        cin >> dabartinisStudentas.vardas;
        cout << "Iveskite pavarde\n";
        cin >> dabartinisStudentas.pavarde;

        //namu darbu irasai
        cout << "Iveskite kiek norite namu darbu balu\n";
        int n;
        cin >> n;
        srand(time(NULL));
        for (int i = 0; i < n; i++){
            int temp = rand() % 10 + 1;
            dabartinisStudentas.balai[i] = temp;
        }

        dabartinisStudentas.egzaminas = rand() % 10 + 1;

        //issaugomi duomenys
        duomenys[studentuSkc] = dabartinisStudentas;        
        studentuSkc++;       


        //paprasoma baigti ivesti
        cout << "Jeigu norite baigti ivedineti duomenys, parasykite ( stop )\n";
        string temp;
        cin >> temp;
        if (temp == "stop"){
            return;
        }
    }
}

void treciasPasirinkimas(){
    //Vardu baze || vardai gali nesutapti su ne mergiotinem pavardem
    array<string, 10> bVardas = {"Povilas", "Andrius", "Marius", "Ignas", "Petras",
    "Ieva", "Liepa", "Rugile", "Onute", "Asta"};
    array<string, 10> bPavarde = {"Petrauskas", "Pavardenis", "Maliauka", "Ablamas",
    "Jonaiskis", "Grazetis", "Pavardenis", "Simpsonas", "Dundulis", "Mazetis"};


    //pagrindinis ciklas
    studentai dabartinisStudentas;
    int m;
    cout << "Pasirinkite kiek studentu bus automatiskai sugeneruota\n";
    cin >> m;
    for (int i = 0; i < m; i++){
        dabartinisStudentas.balai.fill(11);
        srand(time(NULL));
        int temp;
        temp = rand() % 10 + 1;
        dabartinisStudentas.vardas = bVardas[temp];
        temp = rand() % 10 + 1;
        dabartinisStudentas.pavarde = bPavarde[temp];

        //namu darbu irasai
        cout << "Iveskite kiek norite namu darbu balu\n";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            int temp = rand() % 10 + 1;
            dabartinisStudentas.balai[i] = temp;
        }

        dabartinisStudentas.egzaminas = rand() % 10 + 1;

        //issaugomi duomenys
        duomenys[studentuSkc] = dabartinisStudentas;        
        studentuSkc++;       

    }
}

double medianosApsk(array<int, N> a, int egzaminas){
    int n = 0;
    sort(a.begin(), a.end());
    while(a[n] != 11){
        n++;
    }
    n /= 2;
    if(n % 2 == 0){
        return a[n] * 0.4 + egzaminas * 0.6;
    }
    else {
        return (a[n] + a[n++]) / 2 * 0.4 + egzaminas * 0.6;
    }
}

double vidurkioApsk(array<int, N> a, int egzaminas){
    int n = 0;
    double vidurkis = 0;
    while(a[n] != 11){
        vidurkis += a[n];
        n++;
    }
    return vidurkis / n * 0.4 + 0.6 * egzaminas;
}





int main(){
    bool darbasBaigtas = false;
    //pasirinkimu menu
    while (darbasBaigtas == false)
    {
        cout << duomenys[0].balai.size();
        cout << "Pasirinkite, ka norite daryti\n"
        << "( 1 ) - Ivesti duomenys ranka\n"
        << "( 2 ) - Generuoti pazymius atsitiktinai\n"
        << "( 3 ) - Generuoti ir pazymius ir studentu vardus, pavardes\n"
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