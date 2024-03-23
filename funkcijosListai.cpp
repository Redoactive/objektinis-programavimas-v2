#include "funkcijuBazeListai.h"
static list<studentaiListai> duomenys;
// static list<studentaiListai> geriStudentai;
static list<studentaiListai> blogiStudentai;

//globalus laikai
// duration<double> createTime;// duration<double> printTime;
static duration<double> readTime;
static duration<double> sortTime;
static duration<double> typeTime;


void darbasSuListais(){
bool arSkirstymasVyksta = false;
bool darbasBaigtas = false;
    //pasirinkimu menu
    while (darbasBaigtas == false)
    {
        cout << "Pasirinkite, ka norite daryti\n"
        << "( 1 ) - Ivesti duomenys ranka\n"
        << "( 2 ) - Generuoti pazymius atsitiktinai\n"
        << "( 3 ) - Generuoti ir pazymius ir studentu vardus, pavardes\n"
        << "( 4 ) - Nuskaityti is failo\n"
        << "( 5 ) - Generuoti faila\n"
        << "( 6 ) - Suskirstyti i gerus mokinius ir i nereikalingus civilizacijai mokinius ir baigti\n"
        << "( 7 ) - Baigti darba be skirstymo\n";
        char pasirinkimas;
        cin >> pasirinkimas;
        string failoPav;
        switch (pasirinkimas)
        {
        case '1':
            pirmasPasirinkimasListai();
            break;
        case '2':
            antrasPasirinkimasListai();
            break;
        case '3':
            treciasPasirinkimasListai();
            break;
        case '4':
            cout << "Iveskite failo pavadinima (be .txt)\n";
            cin >> failoPav;
            failoPav += ".txt";
            NuskaitymasFailoListai(failoPav);
            break;
        case '5':
            failoGeneracija();
            break;
        case '6':
            darbasBaigtas = true;
            arSkirstymasVyksta = true;
            skirstymasListai();
            break;
        case '7':
            darbasBaigtas = true;
            break;
        case '8':
            terminate();
        default:
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            break;
        }
    }



    //klausiama kaip vartotojas nori isrusiuoti outputa
    // siose funkcijoje tikrinama ar yra duomenu ir ar reikia daryti rusiavima 
    
    
    if (arSkirstymasVyksta == true){
        rusiavimoMenuSkirstymasListai();
    }else{
        rusiavimoMenuListai();
    }



     //klausiama ar vartotojas spausdinti ekrane ar faile
    while(true){
        try {
            cout << "Norite spausdini terminale ( t ) ar faile ( f )?\n";
            string pasirinkimas;
            cin >> pasirinkimas;
            if (pasirinkimas == "t"){
                if (arSkirstymasVyksta == true){
                    spausdinimasTerminaleSkirstymasListai();
                }else{
                    spausdinimasTerminaleListai();
                }
                
                
                break;
            } 
            else if(pasirinkimas == "f"){
                if (arSkirstymasVyksta == true){
                    spausdinimasFaileSkirstymasListai();
                }else{
                    spausdinimasFaileListai();
                }
                
                
                break;
            }
            else{
                throw "Blogai ivesta raide, bandykite dar karta\n";
            }
        }
        catch(char const* msg){
            cerr << msg << endl;
        }
    }



    
    laikoSpausdinimas(readTime, sortTime, typeTime);
}




double medianosApsk(list<int> a, int egzaminas){
    a.sort();
    list<int>::iterator itr = a.begin();
    // sort(a.begin(), a.end());
    int n = a.size() / 2;
    advance(itr, n);
    if(n % 2 == 0){
        return *itr * 0.4 + egzaminas * 0.6;
    }
    else {
        list<int>::iterator itr1 = itr;
        itr++;
        return (*itr + *itr1) / 2 * 0.4 + egzaminas * 0.6;
    }
}
double vidurkioApsk(list<int> a, int egzaminas){
    double vidurkis = 0;
    for (int i : a){
        vidurkis += i;
    }
    return vidurkis / a.size() * 0.4 + 0.6 * egzaminas;
}

//pagrindines funkcijos
void pirmasPasirinkimasListai(){
    //pagrindinis ciklas
    studentaiListai dabartinisStudentas;
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
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
            continue;
        }

        //ivedami namu darbu irasai ranka
        cout << "Iveskite namu darbu balus. Jei norite nustoti ivedineti, parasykite ( -1 )\n";
        string input;
        int temporary;
        while (true){
            //tikrinama ar desimtbaleje sistemoje
            try{
                cin >> input;
                
                temporary = stoi(input);
                if (temporary == -1){
                    break;
                }
                else if(temporary > 10 || temporary < 1){
                    throw string("Klaida, skaicius nera desimtbaleje sistemoje!\n");
                }
            }
            catch(string& e){
                cerr << e;
            }
            catch(invalid_argument& e){
                cerr << "Klaida, ivestis nera skaicius!\n";
                continue;
            }
            catch(...)
            {
                cerr << "Nezinoma klaida! \n";
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


void antrasPasirinkimasListai(){
    //pagrindinis ciklas
    studentaiListai dabartinisStudentas;
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
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
            continue;
        }
        
        //namu darbu irasai
        cout << "Iveskite kiek norite namu darbu balu\n";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            int temp = distribution(mt);
            dabartinisStudentas.balai.push_back(temp);
        }

        dabartinisStudentas.egzaminas = distribution(mt);
        
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

void treciasPasirinkimasListai(){
    //Vardu baze || vardai gali nesutapti su ne mergiotinem pavardem
    vector<string> bVardas = {"", "Andrius", "Marius", "Ignas", "Petras",
    "Ieva", "Liepa", "Rugile", "Onute", "Asta", "Ugne", "Deimante", "Povilas"};
    vector<string> bPavarde = {"", "Pavardenis", "Maliauka", "Ablamas",
    "Jonaiskis", "Grazetis", "Pavardenis", "Simpsonas", "Dundulis", "Mazetis", "Petrauskas"};
        
    //pagrindinis ciklas
    studentaiListai dabartinisStudentas;
    int m;
    cout << "Pasirinkite kiek studentu bus automatiskai sugeneruota\n";
    cin >> m;
    cout << "Iveskite kiek norite namu darbu balu\n";
    int n;
    cin >> n;

    for (int i = 0; i < m; i++){
        int temp; 
        temp = distribution(mt);
        dabartinisStudentas.vardas = bVardas[temp];
        temp = distribution(mt);
        dabartinisStudentas.pavarde = bPavarde[temp];
        
        //namu darbu irasai
        for (int i = 0; i < n; i++){
            int temp = distribution(mt);
            
            dabartinisStudentas.balai.push_back(temp);
        }
        
        
        dabartinisStudentas.egzaminas = distribution(mt);

        dabartinisStudentas.vidurkis = vidurkioApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
        dabartinisStudentas.mediana = medianosApsk(dabartinisStudentas.balai, dabartinisStudentas.egzaminas);
        //issaugomi duomenys
        duomenys.push_back(dabartinisStudentas);      
    }
}



//Nuskaitymas is failo
void NuskaitymasFailoListai(string fileName){
    ifstream fin;
    
    auto readTimeS = high_resolution_clock::now();
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
    
    studentaiListai dabartinisStudentas;

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
    auto readTimeE = high_resolution_clock::now();
    readTime = readTimeE - readTimeS;
    fin.close();
}

//Spausdinimo funkcijos
void spausdinimasFaileListai(){
    cout << "Kaip norite pavadinti savo faila? (be .txt)\n";
    string pavadinimas;
    cin >> pavadinimas;
    pavadinimas += ".txt";
    ofstream fout;
    fout.open(pavadinimas);

    fout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    fout << "-------------------------------------------------------------------\n";
    list<studentaiListai>::iterator itr = duomenys.begin();
    for (int i = 0; i < duomenys.size(); i++){

        fout << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        fout << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
    }
    fout.close();
}
void spausdinimasTerminaleListai(){
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";
    list<studentaiListai>::iterator itr = duomenys.begin();
    for (int i = 0; i < duomenys.size(); i++){

        cout << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        cout << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
    }
}

void spausdinimasFaileSkirstymasListai(){
    string pavadinimas;

    cout << "Kaip norite pavadinti savo faila geriems studentams? (be .txt)\n";
    cin >> pavadinimas;
    pavadinimas += ".txt";
    ofstream foutG;
    foutG.open(pavadinimas);

    cout << "Kaip norite pavadinti savo faila blogiems studentams? (be .txt)\n";
    cin >> pavadinimas;
    pavadinimas += ".txt";
    ofstream foutB;
    // auto printTimeS = high_resolution_clock::now();
    foutB.open(pavadinimas);



    foutG << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    foutG << "-------------------------------------------------------------------\n";
    list<studentaiListai>::iterator itr = duomenys.begin();
    for (int i = 0; i < duomenys.size(); i++){

        foutG << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        foutG << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
        
    }
    foutG.close();


    foutB << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    foutB << "-------------------------------------------------------------------\n";
    itr = blogiStudentai.begin();
    for (int i = 0; i < blogiStudentai.size(); i++){

        foutB << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        foutB << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
        
    }
    foutB.close();
    // auto printTimeE = high_resolution_clock::now();
    // printTime = printTimeE - printTimeS;
}
void spausdinimasTerminaleSkirstymasListai(){
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "------------------------------Geri studentai-------------------------------------\n";
    list<studentaiListai>::iterator itr = duomenys.begin();
    for (int i = 0; i < duomenys.size(); i++){

        cout << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        cout << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
        
    }
    cout << "\nPavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "------------------------------Blogi studentai-------------------------------------\n";
    itr = blogiStudentai.begin();
    for (int i = 0; i < blogiStudentai.size(); i++){

        cout << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        cout << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
        
    }
}

//rusiavimas
bool rusiavimasVardasListai(const studentaiListai &a, const studentaiListai &b){
    return a.vardas < b.vardas;
}
bool rusiavimasPavardeListai(const studentaiListai &a, const studentaiListai &b){
    return a.pavarde < b.pavarde;
}

bool rusiavimasMedianaListai(const studentaiListai &a, const studentaiListai &b){
    return a.mediana < b.mediana;
}

bool rusiavimasVidurkisListai(const studentaiListai &a, const studentaiListai &b){
    return a.vidurkis < b.vidurkis;
}

void rusiavimoMenuListai(){
    if (duomenys.empty()){
        return;
    }
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        cout << "Kaip norite rusiuoti output?\n"
        << "( 1 ) - Pagal varda\n"
        << "( 2 ) - Pagal pavarde\n"
        << "( 3 ) - Pagal vidurkis\n"
        << "( 4 ) - Pagal mediana\n";
        
        int pasirinkimas = 0;
        cin >> pasirinkimas;
        auto sortTimeS = high_resolution_clock::now();
        switch (pasirinkimas)
        {
        case 1:
            duomenys.sort(rusiavimasVardasListai);
            // sort(duomenys.begin(), duomenys.end(), rusiavimasVardasListai);
            darbasBaigtas = true;
            break;
        case 2:
            duomenys.sort(rusiavimasPavardeListai);
            // sort(duomenys.begin(), duomenys.end(), rusiavimasPavardeListai);
            darbasBaigtas = true;
            break;
        case 3:
            duomenys.sort(rusiavimasVidurkisListai);
            // sort(duomenys.begin(), duomenys.end(), rusiavimasVidurkisListai);
            darbasBaigtas = true;
            break;
        case 4:
            duomenys.sort(rusiavimasMedianaListai);
            // sort(duomenys.begin(), duomenys.end(), rusiavimasMedianaListai);
            darbasBaigtas = true;
            break;
        default:
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            terminate();
            break;
        }
        auto sortTimeE = high_resolution_clock::now();
        sortTime = sortTimeE - sortTimeS;
    }
}

void rusiavimoMenuSkirstymasListai(){
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        cout << "Kaip norite rusiuoti output?\n"
        << "( 1 ) - Pagal varda\n"
        << "( 2 ) - Pagal pavarde\n"
        << "( 3 ) - Pagal vidurkis\n"
        << "( 4 ) - Pagal mediana\n";
        
        int pasirinkimas = 0;
        cin >> pasirinkimas;
        auto sortTimeS = high_resolution_clock::now();
        switch (pasirinkimas)
        {
        case 1:
            duomenys.sort(rusiavimasVardasListai);
            blogiStudentai.sort(rusiavimasVardasListai);
            // sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVardasListai);
            // sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVardasListai);
            darbasBaigtas = true;
            break;
        case 2:
            duomenys.sort(rusiavimasPavardeListai);
            blogiStudentai.sort(rusiavimasPavardeListai);
            // sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasPavardeListai);
            // sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasPavardeListai);
            darbasBaigtas = true;
            break;
        case 3:
            duomenys.sort(rusiavimasVidurkisListai);
            blogiStudentai.sort(rusiavimasVidurkisListai);
            // sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVidurkisListai);
            // sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVidurkisListai);
            darbasBaigtas = true;
            break;
        case 4:
            duomenys.sort(rusiavimasMedianaListai);
            blogiStudentai.sort(rusiavimasMedianaListai);
            // sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasMedianaListai);
            // sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasMedianaListai);
            darbasBaigtas = true;
            break;
        default:
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            terminate();
            break;
        }
        auto sortTimeE = high_resolution_clock::now();
        sortTime = sortTimeE - sortTimeS;
    }
    
}


void skirstymasListai(){
    cout << "Pagal ka norite skirstyti vaikus? (v - vidurkis; m - mediana)\n";
    char pasirinkimas;
    cin >> pasirinkimas;
    int b = duomenys.size();
    list<studentaiListai>::iterator itr = duomenys.begin();

    auto typeTimeS = high_resolution_clock::now();
    try{
        if (pasirinkimas == 'v'){
            for (int i = 0; i < b; i++){
                if (itr->vidurkis < 5){
                    blogiStudentai.push_back(*itr);
                    itr++;
                    duomenys.pop_front();
                }
                else{
                    duomenys.push_back(*itr);
                    itr++;
                    duomenys.pop_front();
                }
                
            }

        }
        
        else if(pasirinkimas == 'm'){
            for (int i = 0; i < b; i++){
                if (itr->mediana < 5){
                    blogiStudentai.push_back(*itr);
                    itr++;
                    duomenys.pop_front();
                }
                else{
                    duomenys.push_back(*itr);
                    itr++;
                    duomenys.pop_front();
                }
                
            }
        }

        else{
            throw "Blogai ivesta";
        }
    }
    catch (const char* msg){
        cerr << msg;
    }
    auto typeTimeE = high_resolution_clock::now();
    typeTime = typeTimeE - typeTimeS;
}