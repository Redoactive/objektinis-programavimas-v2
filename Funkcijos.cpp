#include "includes.h"
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
//funckija spausdinti tarpus
string tarpai(string a){
    string kiekis;
    int m = 15 - a.length();
    for (int i = 0; i < m; i++){
        kiekis += " ";
    }
    return kiekis;
}
//pagrindines funkcijos
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

        dabartinisStudentas.vidurkis = vidurkioApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
        dabartinisStudentas.mediana = medianosApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
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
        
        dabartinisStudentas.vidurkis = vidurkioApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
        dabartinisStudentas.mediana = medianosApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
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

        dabartinisStudentas.vidurkis = vidurkioApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
        dabartinisStudentas.mediana = medianosApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
        //issaugomi duomenys
        duomenys.push_back(dabartinisStudentas);        

    }
}