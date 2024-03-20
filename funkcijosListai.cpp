#include "includes.h"
#include "FunkcijuBaze.h"
list<studentaiListai> duomenys;
list<studentaiListai> geriStudentai;
list<studentaiListai> blogiStudentai;

//globalus laikai
duration<double> createTime;
duration<double> readTime;
duration<double> sortTime;
duration<double> printTime;
duration<double> typeTime;
duration<double> allTime;

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> distribution (1, 10);
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


void antrasPasirinkimas(){
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

void treciasPasirinkimas(){
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
void NuskaitymasFailo(string fileName){
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
void spausdinimasFaile(){
    if (duomenys.empty()){
        return;
    }
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
void spausdinimasTerminale(){
    if (duomenys.empty()){
        return;
    }
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

void spausdinimasFaileSkirstymas(){
    if (geriStudentai.empty()){
        return;
    }
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
    auto printTimeS = high_resolution_clock::now();
    foutB.open(pavadinimas);



    foutG << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    foutG << "-------------------------------------------------------------------\n";
    list<studentaiListai>::iterator itr = duomenys.begin();
    for (int i = 0; i < geriStudentai.size(); i++){

        foutG << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        foutG << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
        
    }
    foutG.close();


    foutB << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    foutB << "-------------------------------------------------------------------\n";
    itr = duomenys.begin();
    for (int i = 0; i < blogiStudentai.size(); i++){

        foutB << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        foutB << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
        
    }
    foutB.close();
    auto printTimeE = high_resolution_clock::now();
    printTime = printTimeE - printTimeS;
}
void spausdinimasTerminaleSkirstymas(){
    if (geriStudentai.empty()){
        return;
    }
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "------------------------------Geri studentai-------------------------------------\n";
    list<studentaiListai>::iterator itr = duomenys.begin();
    for (int i = 0; i < geriStudentai.size(); i++){

        cout << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        cout << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
        
    }
    cout << "\nPavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "------------------------------Blogi studentai-------------------------------------\n";
    itr = duomenys.begin();
    for (int i = 0; i < blogiStudentai.size(); i++){

        cout << setprecision(2) << fixed << itr->pavarde << tarpai(itr->pavarde, 15)
        << itr->vardas << tarpai(itr->vardas, 15);
        cout << itr->vidurkis << "             " << itr->mediana << endl;
        itr++;
        
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
            sort(duomenys.begin(), duomenys.end(), rusiavimasVardas);
            darbasBaigtas = true;
            break;
        case 2:
            sort(duomenys.begin(), duomenys.end(), rusiavimasPavarde);
            darbasBaigtas = true;
            break;
        case 3:
            sort(duomenys.begin(), duomenys.end(), rusiavimasVidurkis);
            darbasBaigtas = true;
            break;
        case 4:
            sort(duomenys.begin(), duomenys.end(), rusiavimasMediana);
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

void rusiavimoMenuSkirstymas(){
    if (geriStudentai.empty()){
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
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVardas);
            sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVardas);
            darbasBaigtas = true;
            break;
        case 2:
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasPavarde);
            sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasPavarde);
            darbasBaigtas = true;
            break;
        case 3:
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVidurkis);
            sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVidurkis);
            darbasBaigtas = true;
            break;
        case 4:
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasMediana);
            sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasMediana);
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

    auto createTimeS = high_resolution_clock::now();

    //spausdinimas
    ofstream fout;
    fout.open(name);
    //pirma eilute
    fout << "Vardas         Pavarde        ";
    for (int i = 1; i <= m; i++){
        fout << "ND" << i << tarpai("ND" + to_string(i), 5);
    }
    fout << "Egz." << endl;
    //kitos eilutes
    for (int i = 0; i < n; i++){
        fout << "Vardas" << i << tarpai("Vardas" + to_string(i), 15)
        << "Pavarde" << i << tarpai("Pavarde" + to_string(i), 15);
        for (int j = 0; j < m; j++){// balu spausdinimas
            int a = distribution(mt);
            fout << a;
            if (a == 10){
                fout << "   ";
            }else{
                fout << "    ";
            }
        }
        int b = distribution(mt);
        fout << b << endl;
    }
    fout.close();
    auto createTimeE = high_resolution_clock::now();
    createTime = createTimeE - createTimeS;
}

void skirstymas(){
    cout << "Pagal ka norite skirstyti vaikus? (v - vidurkis; m - mediana)\n";
    char pasirinkimas;
    cin >> pasirinkimas;
    list<studentaiListai>::iterator itr = duomenys.begin();
    auto typeTimeS = high_resolution_clock::now();
    try{
        if (pasirinkimas == 'v'){
            for (int i = 0; i < duomenys.size(); i++){
                if (itr->vidurkis < 5){
                    blogiStudentai.push_back(*itr);
                }
                else{
                    geriStudentai.push_back(*itr);
                }
            }
            
        }
        else if(pasirinkimas == 'm'){
            for (int i = 0; i < duomenys.size(); i++){
                if (itr->mediana < 5){
                    blogiStudentai.push_back(*itr);
                }
                else{
                    geriStudentai.push_back(*itr);
                }
            }
        }

        else{
            throw "Blogai ivesta";
        }
        duomenys.clear();
    }
    catch (const char* msg){
        cerr << msg;
        terminate();
    }
    auto typeTimeE = high_resolution_clock::now();
    typeTime = typeTimeE - typeTimeS;
}

void laikoSpausdinimas(){
        // cout << "Failu kurimas - " << createTime.count() << " s.\n";
        cout << "Duomenu nuskaitymas is failo - " << readTime.count() << " s.\n";
        cout << "Rusiavimas uztruko - " << sortTime.count() << " s.\n";
        cout << "Studentu skirstymas i dvi grupes/kategorijas - " << typeTime.count() << " s.\n";
        // cout << "Surusiuotu studentu isvedimas i du naujus failus - " << printTime.count() << " s.\n";
        // allTime = createTime + readTime + typeTime + sortTime + printTime;
        allTime = readTime + typeTime + sortTime;
        cout << "Visos programos veikimo laikas - " << allTime.count() << " s.\n";
    }