// #include "includes.h"
#include "funckijuBazeDekai.h"

static deque<studentaiDekas> duomenys;
static deque<studentaiDekas> geriStudentai;
static deque<studentaiDekas> blogiStudentai;
//globalus laikai
// duration<double> createTime;// duration<double> printTime;
static duration<double> readTime;
static duration<double> sortTime;
static duration<double> typeTime;

void darbasSuDekais(){
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
            pirmasPasirinkimasDekai();
            break;
        case '2':
            antrasPasirinkimasDekai();
            break;
        case '3':
            treciasPasirinkimasDekai();
            break;
        case '4':
            cout << "Iveskite failo pavadinima (be .txt)\n";
            cin >> failoPav;
            failoPav += ".txt";
            NuskaitymasFailoDekai(failoPav);
            break;
        case '5':
            failoGeneracija();
            break;
        case '6':
            darbasBaigtas = true;
            arSkirstymasVyksta = true;
            skirstymasDekai();
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
        rusiavimoMenuSkirstymasDekai();
    }else{
        rusiavimoMenuDekai();
    }



     //klausiama ar vartotojas spausdinti ekrane ar faile
    while(true){
        try {
            cout << "Norite spausdini terminale ( t ) ar faile ( f )?\n";
            string pasirinkimas;
            cin >> pasirinkimas;
            if (pasirinkimas == "t"){
                if (arSkirstymasVyksta == true){
                    spausdinimasTerminaleSkirstymasDekai();
                }else{
                    spausdinimasTerminaleDekai();
                }
                break;
            } 
            else if(pasirinkimas == "f"){
                if (arSkirstymasVyksta == true){
                    spausdinimasFaileSkirstymasDekai();
                }else{
                    spausdinimasFaileDekai();
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
void pirmasPasirinkimasDekai(){
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


void antrasPasirinkimasDekai(){
    //pagrindinis ciklas
    cout << "hello";
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

void treciasPasirinkimasDekai(){
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
void NuskaitymasFailoDekai(string fileName){
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
void spausdinimasFaileDekai(){

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
void spausdinimasTerminaleDekai(){

    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < duomenys.size(); i++){

        cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde, 15)
        << duomenys[i].vardas <<  tarpai(duomenys[i].vardas, 15);
        cout << duomenys[i].vidurkis << "             " << duomenys[i].mediana << endl;
        
    }
}

void spausdinimasFaileSkirstymasDekai(){

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
    
    for (int i = 0; i < geriStudentai.size(); i++){

        foutG << setprecision(2) << fixed << geriStudentai[i].pavarde << tarpai(geriStudentai[i].pavarde, 15)
        << geriStudentai[i].vardas <<  tarpai(geriStudentai[i].vardas, 15);
        foutG << geriStudentai[i].vidurkis << "             " << geriStudentai[i].mediana << endl;
        
    }
    
    foutG.close();


    foutB << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    foutB << "-------------------------------------------------------------------\n";

    if (!duomenys.empty()){
        for (int i = 0; i < duomenys.size(); i++){

            foutB << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde, 15)
            << duomenys[i].vardas <<  tarpai(duomenys[i].vardas, 15);
            foutB << duomenys[i].vidurkis << "             " << duomenys[i].mediana << endl;
            
        }
    }
    else{
        for (int i = 0; i < blogiStudentai.size(); i++){

            foutB << setprecision(2) << fixed << blogiStudentai[i].pavarde << tarpai(blogiStudentai[i].pavarde, 15)
            << blogiStudentai[i].vardas <<  tarpai(blogiStudentai[i].vardas, 15);
            foutB << blogiStudentai[i].vidurkis << "             " << blogiStudentai[i].mediana << endl;
            
        }
    }
    foutB.close();
    // auto printTimeE = high_resolution_clock::now();
    // printTime = printTimeE - printTimeS;
}
void spausdinimasTerminaleSkirstymasDekai(){
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "------------------------------Geri studentai-------------------------------------\n";

    for (int i = 0; i < geriStudentai.size(); i++){

        cout << setprecision(2) << fixed << geriStudentai[i].pavarde << tarpai(geriStudentai[i].pavarde, 15)
        << geriStudentai[i].vardas <<  tarpai(geriStudentai[i].vardas, 15);
        cout << geriStudentai[i].vidurkis << "             " << geriStudentai[i].mediana << endl;
        
    }
    


    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";

    if (!duomenys.empty()){
        for (int i = 0; i < duomenys.size(); i++){

            cout << setprecision(2) << fixed << duomenys[i].pavarde << tarpai(duomenys[i].pavarde, 15)
            << duomenys[i].vardas <<  tarpai(duomenys[i].vardas, 15);
            cout << duomenys[i].vidurkis << "             " << duomenys[i].mediana << endl;
            
        }
    }
    else{
        for (int i = 0; i < blogiStudentai.size(); i++){

            cout << setprecision(2) << fixed << blogiStudentai[i].pavarde << tarpai(blogiStudentai[i].pavarde, 15)
            << blogiStudentai[i].vardas <<  tarpai(blogiStudentai[i].vardas, 15);
            cout << blogiStudentai[i].vidurkis << "             " << blogiStudentai[i].mediana << endl;
            
        }
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

void rusiavimoMenuDekai(){
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

void rusiavimoMenuSkirstymasDekai(){

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
            if (duomenys.empty()){
                sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVardasDekas);
            }
            else{
                sort(duomenys.begin(), duomenys.end(), rusiavimasVardasDekas);
            }
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVardasDekas);
            darbasBaigtas = true;
            break;
        case 2:
            if (duomenys.empty()){
                sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasPavardeDekas);
            }
            else{
                sort(duomenys.begin(), duomenys.end(), rusiavimasPavardeDekas);
            }
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasPavardeDekas);
            darbasBaigtas = true;
            break;
        case 3:
            if (duomenys.empty()){
                sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVidurkisDekas);
            }
            else{
                sort(duomenys.begin(), duomenys.end(), rusiavimasVidurkisDekas);
            }
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVidurkisDekas);
            darbasBaigtas = true;
            break;
        case 4:
            if (duomenys.empty()){
                sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasMedianaDekas);
            }
            else{
                sort(duomenys.begin(), duomenys.end(), rusiavimasMedianaDekas);
            }
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasMedianaDekas);
            darbasBaigtas = true;
            break;
        default:
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            break;
        }
        auto sortTimeE = high_resolution_clock::now();
        sortTime = sortTimeE - sortTimeS;
    }
    
}
bool Less(studentaiDekas a){
    return a.vidurkis >= 5;
}
bool LessM(studentaiDekas a){
    return a.mediana >= 5;
}

void skirstymasDekai(){
    char pasirinkimas;
    char strategija;
    int b =duomenys.size();
    while(true){
        try{
            cout << "Pagal ka norite skirstyti vaikus? (v - vidurkis; m - mediana)\n";
            cin >> pasirinkimas;
            if (pasirinkimas == 'v' || pasirinkimas == 'm'){} 
            else{ throw string("Blogai ivesta raide"); }

            cout << "Iveskite kokia strategija norite naudoti ( 1 ; 2 ; 3 )\n";
            cin >> strategija;
            if (strategija == '1' || strategija == '2' || strategija == '3'){}
            else{ throw string("Blogai ivesta raide"); }
            break;
        }
        catch(string msg){
            cout << msg << endl;
        }
    }
    auto typeTimeS = high_resolution_clock::now();
    if (pasirinkimas == 'v'){
        if (strategija == '1'){
            for (int i = 0; i < duomenys.size(); i++){
                if (duomenys[i].vidurkis < 5){
                    blogiStudentai.push_back(duomenys[i]);
                }
                else{
                    geriStudentai.push_back(duomenys[i]);
                }
            }
            duomenys.clear();
        }
        if (strategija == '2'){
            sort(duomenys.begin(), duomenys.end(), rusiavimasVidurkisDekas);
            for (int i = b; i > 0; i--){
                
                if(duomenys[i - 1].vidurkis >= 5){
                    geriStudentai.push_back(duomenys[i - 1]);
                    duomenys.pop_back();
                    
                }
                else{
                    break;
                }
            }
        }
        if (strategija == '3'){
            // vector<studentai>::iterator itr;
            // while (true){
            //     itr = find_if(duomenys.begin(),duomenys.end(), Less);
            //     if(itr->vidurkis < 5){
            //         break;
            //     }
            //     geriStudentai.push_back(*itr);
            //     duomenys.erase(itr);
            // }
            partition(duomenys.begin(), duomenys.end(), [](studentaiDekas a){return a.vidurkis < 5;});
            for (int i = b; i > 0; i--){
                if(duomenys[i - 1].vidurkis >= 5){
                    geriStudentai.push_back(duomenys[i - 1]);
                    duomenys.pop_back();
                }
                else{
                    break;
                }
            }
        }
    }
    else if (pasirinkimas == 'm'){
        if (strategija == '1'){
            for (int i = 0; i < duomenys.size(); i++){
                if (duomenys[i].mediana < 5){
                    blogiStudentai.push_back(duomenys[i]);
                }
                else{
                    geriStudentai.push_back(duomenys[i]);
                }
            }
            duomenys.clear();
        }
        if (strategija == '2'){
            sort(duomenys.begin(), duomenys.end(), rusiavimasMedianaDekas);
            for (int i = b; i > 0; i--){
                
                if(duomenys[i - 1].mediana >= 5){
                    geriStudentai.push_back(duomenys[i - 1]);
                    duomenys.pop_back();
                    
                }
                else{
                    break;
                }
            }
        }
        if (strategija == '3'){
            partition(duomenys.begin(), duomenys.end(), [](studentaiDekas a){return a.mediana < 5;});
            for (int i = b; i > 0; i--){
                if(duomenys[i - 1].mediana >= 5){
                    geriStudentai.push_back(duomenys[i - 1]);
                    duomenys.pop_back();
                }
                else{
                    break;
                }
            }
        }
    }


    auto typeTimeE = high_resolution_clock::now();
    typeTime = typeTimeE - typeTimeS;
}