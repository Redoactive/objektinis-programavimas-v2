#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <array>
using namespace std;

int studentuSkc = 0;
struct studentai{
    string vardas;
    string pavarde;
    int *balai;
    int egzaminas;
    int baluKiekis;
};

bool arMediana;
studentai *duomenys;

string tarpai(string a);

int *newArr(int size){
    int *a = new int[size+1];
    return a;
}

int *copyArr(int *a, int size, int val, int *b){
    
    for (int i = 0; i < size; i++)
    {
        a[i] = b[i];
    }
    a[size] = val;
    delete[] b;
    return a;
}


void pirmasPasirinkimas(){
    //pagrindinis ciklas
    studentai dabartinisStudentas;
    
    while (true){
        double vidurkis = 0, mediana;
        cout << "Iveskite varda\n";
        cin >> dabartinisStudentas.vardas;
        cout << "Iveskite pavarde\n";
        cin >> dabartinisStudentas.pavarde;   

        //ivedami namu darbu irasai ranka
        cout << "Iveskite namu darbu balus. Jei norite nustoti ivedineti, parasykite ( -1 )\n";
        int temporary;
        int i = 0;
        int *naujas;
        int *senas = new int;
        while (true){
            
            cin >> temporary;
            if (temporary == -1){
                break;
            }
            naujas = newArr(i);
            senas = copyArr(naujas, i, temporary, senas);
            
            i++;
        }
        dabartinisStudentas.balai = naujas;
        dabartinisStudentas.baluKiekis = i;
        cout << "Iveskite egzamino rezultata\n";
        cin >> dabartinisStudentas.egzaminas;
        
        //issaugomi duomenys
        
        studentai *a = new studentai[studentuSkc + 1];
        for(int i = 0; i < studentuSkc; i++){
            a[i] = duomenys[i];
        }
        a[studentuSkc] = dabartinisStudentas;
        delete[] duomenys;
        duomenys = a;
        studentuSkc++;

        //paprasoma baigti ivesti
        cout << "Jeigu norite baigti ivedineti duomenys, parasykite ( s )\n";
        string temp;
        cin >> temp;
        if (temp == "s"){
            return;
        }
    }
}

void antrasPasirinkimas(){
    //pagrindinis ciklas
    studentai dabartinisStudentas;

    while (true){
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
        int i = 0;
        int *naujas;
        naujas = newArr(n - 1);
        for (i = 0; i < n; i++){
            int temp = rand() % 10 + 1;
            
            naujas[i] = temp;
        }
        dabartinisStudentas.balai = naujas;
        dabartinisStudentas.baluKiekis = i;
        dabartinisStudentas.egzaminas = rand() % 10 + 1;

        //issaugomi duomenys
        studentai *a = new studentai[studentuSkc + 1];
        for(int i = 0; i < studentuSkc; i++){
            a[i] = duomenys[i];
        }
        a[studentuSkc] = dabartinisStudentas;
        delete[] duomenys;
        duomenys = a;
        studentuSkc++;

        //paprasoma baigti ivesti
        cout << "Jeigu norite baigti ivedineti duomenys, parasykite ( s )\n";
        string temp;
        cin >> temp;
        if (temp == "s"){
            return;
        }
    }
}

void treciasPasirinkimas(){
    //Vardu baze || vardai gali nesutapti su ne mergiotinem pavardem
    array<string, 11> bVardas = {"Povilas", "Andrius", "Marius", "Ignas", "Petras",
    "Ieva", "Liepa", "Rugile", "Onute", "Asta", "Medis"};
    array<string, 11> bPavarde = {"Petrauskas", "Pavardenis", "Maliauka", "Ablamas",
    "Jonaiskis", "Grazetis", "Pavardenis", "Simpsonas", "Dundulis", "Mazetis", "Sabonis"};


    //pagrindinis ciklas
    studentai dabartinisStudentas;
    int m;
    cout << "Pasirinkite kiek studentu bus automatiskai sugeneruota\n";
    cin >> m;
    cout << "Iveskite kiek norite namu darbu balu\n";
    int n;
    cin >> n;
    srand(time(NULL));
    for (int j = 0; j < m; j++){
        
        
        int temp;
        temp = rand() % 10 + 1;
        dabartinisStudentas.vardas = bVardas[temp];
        temp = rand() % 10 + 1;
        dabartinisStudentas.pavarde = bPavarde[temp];

        //namu darbu irasai
        
        int i = 0;
        int *naujas;
        naujas = newArr(n - 1);
        for (i = 0; i < n; i++){
            int temp = rand() % 10 + 1;
            
            naujas[i] = temp;
        }
        dabartinisStudentas.balai = naujas;
        dabartinisStudentas.baluKiekis = i;
        
        dabartinisStudentas.egzaminas = rand() % 10 + 1;

        //issaugomi duomenys
        studentai *a = new studentai[studentuSkc + 1];
        for(int i = 0; i < studentuSkc; i++){
            a[i] = duomenys[i];
        }
        a[studentuSkc] = dabartinisStudentas;
        delete[] duomenys;
        duomenys = a;
        studentuSkc++;      

    }
}

double medianosApsk(int* a, int egzaminas, int kiekis){

    
    sort(a, a + kiekis);
    kiekis /= 2;
    if(kiekis % 2 == 0){
        return a[kiekis] * 0.4 + egzaminas * 0.6;
    }
    else {
        return (a[kiekis] + a[kiekis++]) / 2 * 0.4 + egzaminas * 0.6;
    }
}

double vidurkioApsk(int *a, int egzaminas, int kiekis){
    double vidurkis = 0;
    int i;
    for (i = 0; i < kiekis; i++){
        vidurkis += a[i];
    }
    return vidurkis / i * 0.4 + 0.6 * egzaminas;
}





int main(){
    bool darbasBaigtas = false;
    //pasirinkimu menu
    while (darbasBaigtas == false)
    {
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
        cout << "Norite naudoti namu darbu balo apskaiciavimui vidurki (v) ar mediana (m)\n";
        string pasirinkimas;
        cin >> pasirinkimas;

        if (pasirinkimas == "v"){
            arMediana = false;
            darbasBaigtas = true;
        } 
        else if(pasirinkimas == "m"){
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

    for (int i = 0; i < studentuSkc; i++){
        cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas);

        if (arMediana){
            cout << medianosApsk(duomenys[i].balai, duomenys[i].egzaminas, duomenys[i].baluKiekis) << endl;
        }
        else {
            cout << vidurkioApsk(duomenys[i].balai, duomenys[i].egzaminas, duomenys[i].baluKiekis) << endl;
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