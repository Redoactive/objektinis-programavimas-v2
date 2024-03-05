#include "includes.h"
#include "FunkcijuBaze.h"
vector<studentai> duomenys;
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
string tarpai(string a, int tarpuDydis){
    string kiekis;
    int m = tarpuDydis - a.length();
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
        try{
            cout << "Iveskite pavarde\n";
            cin >> dabartinisStudentas.pavarde; 
            if(dabartinisStudentas.pavarde.length() > 15){
                throw "Jusu ivesta pavarde yra per ilga (limitas yra 15 simboliu)";
            }
            cout << "Iveskite varda\n";
            cin >> dabartinisStudentas.vardas;
            if(dabartinisStudentas.vardas.length() > 15){
                throw "Jusu ivestas vardas yra per ilgas (limitas yra 15 simboliu)";
            }
        }
        catch(char const *msg){
            cerr << msg << endl;
            terminate();
        }

        //ivedami namu darbu irasai ranka
        cout << "Iveskite namu darbu balus. Jei norite nustoti ivedineti, parasykite ( -1 )\n";
        int temporary;

        while (true){
            //tikrinama ar desimtbaleje sistemoje
            try{
                cin >> temporary;
                if (temporary == -1){
                    break;
                }
                if (!isdigit(temporary + 48) && temporary != 10){
                    throw "Ivestas balas nera skaicius";
                }
                else if(temporary > 10 || temporary < 1){
                    throw "Ivestas balas nera desimtbaleje sistemoje";
                }
            }
            catch(char const *msg){
                cerr << msg << endl;
                terminate();
                continue;
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
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        double vidurkis = 0, mediana;
        try{
            cout << "Iveskite pavarde\n";
            cin >> dabartinisStudentas.pavarde; 
            if(dabartinisStudentas.pavarde.length() > 15){
                throw "Jusu ivesta pavarde yra per ilga (limitas yra 15 simboliu)";
            }
            cout << "Iveskite varda\n";
            cin >> dabartinisStudentas.vardas;
            if(dabartinisStudentas.vardas.length() > 15){
                throw "Jusu ivestas vardas yra per ilgas (limitas yra 15 simboliu)";
            }
        }
        catch(char const *msg){
            cerr << msg << endl;
            terminate();
        }
        

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
    vector<string> bVardas = {"Povilas", "Andrius", "Marius", "Ignas", "Petras",
    "Ieva", "Liepa", "Rugile", "Onute", "Asta", "Ugne", "Deimante"};
    vector<string> bPavarde = {"Petrauskas", "Pavardenis", "Maliauka", "Ablamas",
    "Jonaiskis", "Grazetis", "Pavardenis", "Simpsonas", "Dundulis", "Mazetis"};

    //pagrindinis ciklas
    studentai dabartinisStudentas;
    int m;
    cout << "Pasirinkite kiek studentu bus automatiskai sugeneruota\n";
    cin >> m;
    cout << "Iveskite kiek norite namu darbu balu\n";
    int n;
    cin >> n;
    srand(time(NULL));
    for (int i = 0; i < m; i++){
        
        int temp;
        temp = rand() % 10 + 1;
        dabartinisStudentas.vardas = bVardas[temp];
        temp = rand() % 10 + 1;
        dabartinisStudentas.pavarde = bPavarde[temp];
        
        //namu darbu irasai

        // potenciali klaida
        // dabartinisStudentas.balai.clear();
        // cout << dabartinisStudentas.balai.size() << " ";
        // cout << dabartinisStudentas.balai.capacity() << endl;
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
//Nuskaitymas is failo
void NuskaitymasFailo(string fileName){
    ifstream fin;
    
    double startTime;
    startTime = clock();
    
    fin.open(fileName);
    try{
        if(!fin){
            throw "Klaida, failas neegzistuoja!";
        }
    }
    catch(const char* msg){
        cerr << msg << endl;
        return;
    }
    
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
        dabartinisStudentas.balai.clear();
        fin >> dabartinisStudentas.vardas >> dabartinisStudentas.pavarde;
        for (int j = 0; j < i; j++){
            int ivestis;
            fin >> ivestis;
            dabartinisStudentas.balai.push_back(ivestis);
        }
        
        fin >> dabartinisStudentas.egzaminas;
        dabartinisStudentas.vidurkis = vidurkioApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
        dabartinisStudentas.mediana = medianosApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
        duomenys.push_back(dabartinisStudentas);
    }
    cout << "failo skaitymo laikas yra - " <<  (clock() - startTime) / 1000 << " sekundes\n";
    fin.close();
}

//Spausdinimo funkcijos
void spausdinimasFaile(){
    cout << "Kaip norite pavadinti savo faila?\n";
    string pavadinimas;
    cin >> pavadinimas;

    ofstream fout;
    fout.open(pavadinimas);

    fout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    fout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < duomenys.size(); i++){

        fout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde, 15)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas, 15);
        fout << duomenys[i].vidurkis << "             " << duomenys[i].mediana << endl;
        
    }
    fout.close();
}
void spausdinimasTerminale(){
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < duomenys.size(); i++){

        cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde, 15)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas, 15);
        cout << duomenys[i].vidurkis << "             " << duomenys[i].mediana << endl;
        
    }
}

//rusiavimas
bool rusiavimasVardas(const studentai &a, const studentai &b){
    return a.vardas < b.vardas;
}
bool rusiavimasPavarde(const studentai &a, const studentai &b){
    return a.pavarde < b.pavarde;
}

bool rusiavimasMediana(const studentai &a, const studentai &b){
    return a.mediana < b.mediana;
}

bool rusiavimasVidurkis(const studentai &a, const studentai &b){
    return a.vidurkis < b.vidurkis;
}

void rusiavimoMenu(){
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        cout << "Kaip norite rusiuoti output?\n"
        << "( 1 ) - Pagal varda\n"
        << "( 2 ) - Pagal pavarde\n"
        << "( 3 ) - Pagal vidurkis\n"
        << "( 4 ) - Pagal mediana\n";
        
        int pasirinkimas = 0;
        cin >> pasirinkimas;
        double startTime;
        switch (pasirinkimas)
        {
        case 1:
            startTime = clock();
            sort(duomenys.begin(), duomenys.end(), rusiavimasVardas);
            darbasBaigtas = true;
            cout << "rusiavimas vyko - " << (clock() - startTime) / 1000 << " sekundes\n";
            break;
        case 2:
            startTime = clock();
            sort(duomenys.begin(), duomenys.end(), rusiavimasPavarde);
            darbasBaigtas = true;
            cout << "rusiavimas vyko - " << (clock() - startTime) / 1000 << " sekundes\n";
            break;
        case 3:
            startTime = clock();
            sort(duomenys.begin(), duomenys.end(), rusiavimasVidurkis);
            darbasBaigtas = true;
            cout << "rusiavimas vyko - " << (clock() - startTime) / 1000 << " sekundes\n";
            break;
        case 4:
            startTime = clock();
            sort(duomenys.begin(), duomenys.end(), rusiavimasMediana);
            darbasBaigtas = true;
            cout << "rusiavimas vyko - " << (clock() - startTime) / 1000 << " sekundes\n";
            break;
        default:
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            terminate();
            break;
        }
    }
}
string extraSpace (string a, int b){
    
    string space;
    for (int i = 0; i < b; i++){
        space += " ";
    }
    return space;
}

void failoGeneracija(){
    cout << "Parasykite, kokio dydzio norite naujo failo\n";
    int n;
    cin >> n;
    cout << "Parasykite, koks bus kiekis studentu balu\n";
    int m;
    cin >> m;
    cout << "Parasykite failo pavadinima (be .txt)\n";
    string name;
    cin >> name;
    name += ".txt";
    //random
    srand(time(NULL));



    //spausdinimas
    ofstream fout;
    fout.open(name);
    fout << "Vardas         Pavarde        ";
    for (int i = 1; i <= m; i++){
        fout << "ND" << i << tarpai("ND" + to_string(i), 5);
    }
    fout << "Egz." << endl;
    for (int i = 0; i < n; i++){
        fout << "Vardas" << i << tarpai("Vardas" + to_string(i), 15)
        << "Pavarde" << i << tarpai("Pavarde" + to_string(i), 15);
        for (int j = 0; j < m; j++){
            int a = rand() % 10 + 1;
            fout << a;
            if (a == 10){
                fout << "   ";
            }else{
                fout << "    ";
            }
        }
        fout << rand() % 10 + 1 << endl;
    }
    fout.close();
}
