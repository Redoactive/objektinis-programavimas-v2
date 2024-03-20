#include "includes.h"
#include "FunkcijuBaze.h"

deque<studentaiDekas> duomenys;
deque<studentaiDekas> geriStudentai;
deque<studentaiDekas> blogiStudentai;
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

double medianosApsk(deque<int> a, int egzaminas){
    
    sort(a.begin(), a.end());
    int n = a.size() / 2;
    if(n % 2 == 0){
        return a[n] * 0.4 + egzaminas * 0.6;
    }
    else {
        return (a[n] + a[n++]) / 2 * 0.4 + egzaminas * 0.6;
    }
}
double vidurkioApsk(deque<int> a, int egzaminas){
    double vidurkis = 0;
    for (int i : a){
        vidurkis += i;
    }
    return vidurkis / a.size() * 0.4 + 0.6 * egzaminas;
}

//pagrindines funkcijos
void pirmasPasirinkimas(){
    //pagrindinis ciklas
    studentaiDekas dabartinisStudentas;
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
    studentaiDekas dabartinisStudentas;
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
    deque<string> bVardas = {"", "Andrius", "Marius", "Ignas", "Petras",
    "Ieva", "Liepa", "Rugile", "Onute", "Asta", "Ugne", "Deimante", "Povilas"};
    deque<string> bPavarde = {"", "Pavardenis", "Maliauka", "Ablamas",
    "Jonaiskis", "Grazetis", "Pavardenis", "Simpsonas", "Dundulis", "Mazetis", "Petrauskas"};
        
    //pagrindinis ciklas
    studentaiDekas dabartinisStudentas;
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
    
    studentaiDekas dabartinisStudentas;

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

    for (int i = 0; i < duomenys.size(); i++){

        fout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde, 15)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas, 15);
        fout << duomenys[i].vidurkis << "             " << duomenys[i].mediana << endl;
        
    }
    fout.close();
}
void spausdinimasTerminale(){
    if (duomenys.empty()){
        return;
    }
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < duomenys.size(); i++){

        cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde, 15)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas, 15);
        cout << duomenys[i].vidurkis << "             " << duomenys[i].mediana << endl;
        
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

    for (int i = 0; i < geriStudentai.size(); i++){

        foutG << setprecision(2) << fixed << geriStudentai[i].pavarde << tarpai(geriStudentai[i].pavarde, 15)
        << geriStudentai[i].vardas <<  tarpai(geriStudentai[i].vardas, 15);
        foutG << geriStudentai[i].vidurkis << "             " << geriStudentai[i].mediana << endl;
        
    }
    foutG.close();


    foutB << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    foutB << "-------------------------------------------------------------------\n";

    for (int i = 0; i < blogiStudentai.size(); i++){

        foutB << setprecision(2) << fixed << blogiStudentai[i].pavarde << tarpai(blogiStudentai[i].pavarde, 15)
        << blogiStudentai[i].vardas <<  tarpai(blogiStudentai[i].vardas, 15);
        foutB << blogiStudentai[i].vidurkis << "             " << blogiStudentai[i].mediana << endl;
        
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

    for (int i = 0; i < geriStudentai.size(); i++){

        cout << setprecision(2) << fixed << geriStudentai[i].pavarde << tarpai(geriStudentai[i].pavarde, 15)
        << geriStudentai[i].vardas <<  tarpai(geriStudentai[i].vardas, 15);
        cout << geriStudentai[i].vidurkis << "             " << geriStudentai[i].mediana << endl;
        
    }
    cout << "\nPavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "------------------------------Blogi studentai-------------------------------------\n";

    for (int i = 0; i < blogiStudentai.size(); i++){

        cout << setprecision(2) << fixed << blogiStudentai[i].pavarde << tarpai(blogiStudentai[i].pavarde, 15)
        << blogiStudentai[i].vardas <<  tarpai(blogiStudentai[i].vardas, 15);
        cout << blogiStudentai[i].vidurkis << "             " << blogiStudentai[i].mediana << endl;
        
    }
}

//rusiavimas
bool rusiavimasVardasDekas(const studentaiDekas &a, const studentaiDekas &b){
    return a.vardas < b.vardas;
}
bool rusiavimasPavardeDekas(const studentaiDekas &a, const studentaiDekas &b){
    return a.pavarde < b.pavarde;
}

bool rusiavimasMedianaDekas(const studentaiDekas &a, const studentaiDekas &b){
    return a.mediana < b.mediana;
}

bool rusiavimasVidurkisDekas(const studentaiDekas &a, const studentaiDekas &b){
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
            sort(duomenys.begin(), duomenys.end(), rusiavimasVardasDekas);
            darbasBaigtas = true;
            break;
        case 2:
            sort(duomenys.begin(), duomenys.end(), rusiavimasPavardeDekas);
            darbasBaigtas = true;
            break;
        case 3:
            sort(duomenys.begin(), duomenys.end(), rusiavimasVidurkisDekas);
            darbasBaigtas = true;
            break;
        case 4:
            sort(duomenys.begin(), duomenys.end(), rusiavimasMedianaDekas);
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
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVardasDekas);
            sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVardasDekas);
            darbasBaigtas = true;
            break;
        case 2:
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasPavardeDekas);
            sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasPavardeDekas);
            darbasBaigtas = true;
            break;
        case 3:
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVidurkisDekas);
            sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVidurkisDekas);
            darbasBaigtas = true;
            break;
        case 4:
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasMedianaDekas);
            sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasMedianaDekas);
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
    auto typeTimeS = high_resolution_clock::now();
    try{
        if (pasirinkimas == 'v'){
            for (int i = 0; i < duomenys.size(); i++){
                if (duomenys[i].vidurkis < 5){
                    blogiStudentai.push_back(duomenys[i]);
                }
                else{
                    geriStudentai.push_back(duomenys[i]);
                }
            }
            
        }
        else if(pasirinkimas == 'm'){
            for (int i = 0; i < duomenys.size(); i++){
                if (duomenys[i].mediana < 5){
                    blogiStudentai.push_back(duomenys[i]);
                }
                else{
                    geriStudentai.push_back(duomenys[i]);
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