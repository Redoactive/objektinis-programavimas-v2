#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace std;


struct studentai{
    string vardas;
    string pavarde;
    vector<int> balai;
    int egzaminas;
};

// bool arMediana;
vector<studentai> duomenys;

string tarpai(string a);
void rusiavimas();
void pirmasPasirinkimas(){
    //pagrindinis ciklas
    studentai dabartinisStudentas;
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        double vidurkis = 0, mediana;
        cout << "Iveskite pavarde\n";
        cin >> dabartinisStudentas.pavarde; 
        cout << "Iveskite varda\n";
        cin >> dabartinisStudentas.vardas;
          

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

void antrasPasirinkimas(){
    //pagrindinis ciklas
    studentai dabartinisStudentas;
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        double vidurkis = 0, mediana;
        cout << "Iveskite pavarde\n";
        cin >> dabartinisStudentas.pavarde;
        cout << "Iveskite varda\n";
        cin >> dabartinisStudentas.vardas;
        

        //namu darbu irasai
        cout << "Iveskite kiek norite namu darbu balu\n";
        int n;
        cin >> n;
        srand(time(NULL));
        for (int i = 0; i < n; i++){
            int temp = rand() % 10 + 1;
            dabartinisStudentas.balai.push_back(temp);
        }

        dabartinisStudentas.egzaminas = rand() % 10 + 1;

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

void treciasPasirinkimas(){
    //Vardu baze || vardai gali nesutapti su ne mergiotinem pavardem
    vector<string> bVardas = {"Povilas", "Andrius", "Marius", "Ignas", "Petras",
    "Ieva", "Liepa", "Rugile", "Onute", "Asta", "Ugne", "Deimante"};
    vector<string> bPavarde = {"Petrauskas", "Pavardenis", "Maliauka", "Ablamas",
    "Jonaiskis", "Grazetis", "Pavardenis", "Simpsonas", "Dundulis", "Mazetis"};





    //pagrindinis ciklas
    studentai dabartinisStudentas;
    int m;
    cout << "Pasirinkite kiek studentu bus automatiskai sugeneruota\n";
    cin >> m;
    for (int i = 0; i < m; i++){
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
            dabartinisStudentas.balai.push_back(temp);
        }

        dabartinisStudentas.egzaminas = rand() % 10 + 1;

        //issaugomi duomenys
        duomenys.push_back(dabartinisStudentas);        

    }
}




void NuskaitymasFailo(string fileName){
    ifstream fin;
    fin.open(fileName);
    studentai dabartinisStudentas;

    //patikrinti kiek namu darbu yra faile
    string temp;
    fin >> temp >> temp;
    int i = 0;
    while (true){
        fin >> temp;
        if (temp == "Egz."){
            break;
        }
        i++;
    }



    while (!fin.eof()){
        fin >> dabartinisStudentas.vardas >> dabartinisStudentas.pavarde;
        for (int j = 0; j < i; j++){
            int ivestis;
            fin >> ivestis;
            dabartinisStudentas.balai.push_back(ivestis);
        }
        fin >> dabartinisStudentas.egzaminas;
        duomenys.push_back(dabartinisStudentas);
    }
    fin.close();
    

}



double medianosApsk(vector<int> a, int egzaminas){
    
    sort(a.begin(), a.end());
    int n = a.size() / 2;
    if(n % 2 == 0){
        return a[n] * 0.4 + egzaminas * 0.6;
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


void spausdinimasFaile(){
    cout << "Kaip norite pavadinti savo faila?\n";
    string pavadinimas;
    cin >> pavadinimas;

    ofstream fout;
    fout.open(pavadinimas);

    fout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    fout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < duomenys.size(); i++){

        fout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas);
        fout << medianosApsk(duomenys[i].balai, duomenys[i].egzaminas) << "             ";
        fout << vidurkioApsk(duomenys[i].balai, duomenys[i].egzaminas) << endl;
        
    }
    fout.close();
}
void spausdinimasTerminale(){
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < duomenys.size(); i++){

        cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas);
        cout << medianosApsk(duomenys[i].balai, duomenys[i].egzaminas) << "             ";
        cout << vidurkioApsk(duomenys[i].balai, duomenys[i].egzaminas) << endl;
        
    }
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
        << "( 4 ) - Baigti darba\n"
        << "( 5 ) - Nuskaityti is failo\n";
        int pasirinkimas;
        cin >> pasirinkimas;
        string failoPav;
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
        case 5:
            cout << "Iveskite failo pavadinima\n";
            cin >> failoPav;
            NuskaitymasFailo(failoPav);
            break;
        default:
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            break;
        }
    }
    //klausiama kaip vartotojas nori isrusiuoti outputa
    darbasBaigtas = false;
    while (darbasBaigtas == false){
        cout << "Kaip norite rusiuoti output?\n"
        << "( 1 ) - Pagal varda\n"
        << "( 2 ) - Pagal pavarde\n"
        << "( 3 ) - Pagal vidurki\n"
        << "( 4 ) - Pagal mediana\n";
        int pasirinkimas;
        cin >> pasirinkimas;
        
        switch (pasirinkimas)
        {
        case 1:
            rusiavimas();
            darbasBaigtas = true;
            break;
        case 2:
            
            darbasBaigtas = true;
            break;
        case 3:
            darbasBaigtas = true;
            break;
        case 4:
            darbasBaigtas = true;
            
            break;
        default:
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            break;
        }
    }
     //klausiama ar vartotojas spausdinti ekrane ar faile
    darbasBaigtas = false;
    while (darbasBaigtas == false){
        cout << "Norite spausdini terminale ( t ) ar faile ( f )?\n";
        string pasirinkimas;
        cin >> pasirinkimas;

        if (pasirinkimas == "t"){
            spausdinimasTerminale();
            darbasBaigtas = true;
        } 
        else if(pasirinkimas == "f"){
            spausdinimasFaile();
            darbasBaigtas = true;
        }
        else{
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
        }
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


void rusiavimas(){
    for (int i = 0; i < duomenys.size() - 1; i++){
        for (int j = i + 1; j < duomenys.size(); j++){
            if (duomenys[j].vardas < duomenys[i].vardas){
                studentai temp;
                temp = duomenys[j];
                duomenys[j] = duomenys[i];
                duomenys[i] = temp;
            }
        }
    }
}