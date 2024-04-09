#include "funkcijuBazeListai.h"
static list<studentai_classList> duomenys;
static list<studentai_classList> geriStudentai;
static list<studentai_classList> blogiStudentai;

//globalus laikai
// duration<double> createTime;// duration<double> printTime;
static duration<double> readTime;
static duration<double> sortTime;
static duration<double> typeTime;
static bool arSkirtingi = false;

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
    string a;
    int temporary;
    list<int> bal;
    //pagrindinis ciklas
    studentai_classList dabartinisStudentas;
    bool darbasBaigtas = false;
    
    while (darbasBaigtas == false){
        try{
            
            cout << "Iveskite pavarde\n";
            cin >> a;
            dabartinisStudentas.setPavarde(a); 
            if(dabartinisStudentas.getPavarde().length() > 15){
                throw "Jusu ivesta pavarde yra per ilga (limitas yra 15 simboliu)";
            }
            cout << "Iveskite varda\n";
            cin >> a;
            dabartinisStudentas.setVardas(a);
            if(dabartinisStudentas.getVardas().length() > 15){
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
            bal.push_back(temporary);
            
            
        }
        dabartinisStudentas.setBalai(bal);
        cout << "Iveskite egzamino rezultata\n";
        cin >> temporary;
        dabartinisStudentas.setEgzaminas(temporary);

        dabartinisStudentas.setVidurkis(vidurkioApsk(bal, temporary)) ;
        dabartinisStudentas.setMediana(medianosApsk(bal, temporary));
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
    string a;
    list<int> bal;
    //pagrindinis ciklas
    studentai_classList dabartinisStudentas;
    bool darbasBaigtas = false;
    while (darbasBaigtas == false){
        try{
            cout << "Iveskite pavarde\n";
            cin >> a;
            dabartinisStudentas.setPavarde(a); 
            if(dabartinisStudentas.getPavarde().length() > 15){
                throw "Jusu ivesta pavarde yra per ilga (limitas yra 15 simboliu)";
            }
            cout << "Iveskite varda\n";
            cin >> a;
            dabartinisStudentas.setVardas(a);
            if(dabartinisStudentas.getVardas().length() > 15){
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
            bal.push_back(temp);
        }
        dabartinisStudentas.setBalai(bal);
        dabartinisStudentas.setEgzaminas(distribution(mt));
        dabartinisStudentas.setVidurkis(vidurkioApsk(bal, dabartinisStudentas.getEgzaminas()));
        dabartinisStudentas.setMediana(medianosApsk(bal, dabartinisStudentas.getEgzaminas()));
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
    list<int> bal;
    //Vardu baze || vardai gali nesutapti su ne mergiotinem pavardem
    list<string> bVardas = {"", "Andrius", "Marius", "Ignas", "Petras",
    "Ieva", "Liepa", "Rugile", "Onute", "Asta", "Ugne", "Deimante", "Povilas"};
    list<string> bPavarde = {"", "Pavardenis", "Maliauka", "Ablamas",
    "Jonaiskis", "Grazetis", "Pavardenis", "Simpsonas", "Dundulis", "Mazetis", "Petrauskas"};
        
    //pagrindinis ciklas
    studentai_classList dabartinisStudentas;
    int m;
    cout << "Pasirinkite kiek studentu bus automatiskai sugeneruota\n";
    cin >> m;
    cout << "Iveskite kiek norite namu darbu balu\n";
    int n;
    cin >> n;

    for (int i = 0; i < m; i++){
        int temp; 
        temp = distribution(mt);
        list<string>::iterator itr = bVardas.begin();
        advance(itr, temp);
        dabartinisStudentas.setVardas(*itr);
        temp = distribution(mt);
        itr = bPavarde.begin();
        advance(itr, temp);
        dabartinisStudentas.setPavarde(*itr);
        
        //namu darbu irasai
        for (int i = 0; i < n; i++){
            int temp = distribution(mt);
            
            bal.push_back(temp);
        }
        
        dabartinisStudentas.setBalai(bal);
        dabartinisStudentas.setEgzaminas(distribution(mt));

        dabartinisStudentas.setVidurkis(vidurkioApsk(bal, dabartinisStudentas.getEgzaminas()));
        dabartinisStudentas.setMediana(medianosApsk(bal, dabartinisStudentas.getEgzaminas()));
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
    
    studentai_classList dabartinisStudentas;

    string temp;
    int temporary;
    list<int> bal;

    //patikrinti kiek namu darbu yra faile
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
        bal.clear();
        fin >> temp; dabartinisStudentas.setVardas(temp); 
        fin >> temp; dabartinisStudentas.setPavarde(temp);
        for (int j = 0; j < i; j++){
            fin >> temporary;
            bal.push_back(temporary);
        }
        
        fin >> temporary;
        dabartinisStudentas.setEgzaminas(temporary);
        dabartinisStudentas.setVidurkis(vidurkioApsk(bal, temporary));
        dabartinisStudentas.setMediana(medianosApsk(bal, temporary));
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
    list<studentai_classList>::iterator itr = duomenys.begin();
    for (int i = 0; i < duomenys.size(); i++){

        fout << setprecision(2) << fixed << itr->getPavarde() << tarpai(itr->getPavarde(), 15)
        << itr->getVardas() << tarpai(itr->getVardas(), 15);
        fout << itr->getVidurkis() << "             " << itr->getMediana() << endl;
        itr++;
    }
    fout.close();
}
void spausdinimasTerminaleListai(){
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";
    list<studentai_classList>::iterator itr = duomenys.begin();
    for (int i = 0; i < duomenys.size(); i++){

        cout << setprecision(2) << fixed << itr->getPavarde() << tarpai(itr->getPavarde(), 15)
        << itr->getVardas() << tarpai(itr->getVardas(), 15);
        cout << itr->getVidurkis() << "             " << itr->getMediana() << endl;
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
    list<studentai_classList>::iterator itr = geriStudentai.begin();
    for (int i = 0; i < geriStudentai.size(); i++){

        foutG << setprecision(2) << fixed << itr->getPavarde() << tarpai(itr->getPavarde(), 15)
        << itr->getVardas() << tarpai(itr->getVardas(), 15);
        foutG << itr->getVidurkis() << "             " << itr->getMediana() << endl;
        itr++;
        
    }
    
    foutG.close();


    foutB << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    foutB << "-------------------------------------------------------------------\n";
    if (!arSkirtingi){
        itr = duomenys.begin();
        for (int i = 0; i < duomenys.size(); i++){

            foutB << setprecision(2) << fixed << itr->getPavarde() << tarpai(itr->getPavarde(), 15)
            << itr->getVardas() << tarpai(itr->getVardas(), 15);
            foutB << itr->getVidurkis() << "             " << itr->getMediana() << endl;
            itr++;

        }
    }
    else{
        itr = blogiStudentai.begin();
        for (int i = 0; i < blogiStudentai.size(); i++){

            foutB << setprecision(2) << fixed << itr->getPavarde() << tarpai(itr->getPavarde(), 15)
            << itr->getVardas() << tarpai(itr->getVardas(), 15);
            foutB << itr->getVidurkis() << "             " << itr->getMediana() << endl;
            itr++;
        }
    }
    foutB.close();
    // auto printTimeE = high_resolution_clock::now();
    // printTime = printTimeE - printTimeS;
}
void spausdinimasTerminaleSkirstymasListai(){
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "------------------------------Geri studentai-------------------------------------\n";
    list<studentai_classList>::iterator itr = geriStudentai.begin();
    for (int i = 0; i < geriStudentai.size(); i++){

        cout << setprecision(2) << fixed << itr->getPavarde() << tarpai(itr->getPavarde(), 15)
        << itr->getVardas() << tarpai(itr->getVardas(), 15);
        cout << itr->getVidurkis() << "             " << itr->getMediana() << endl;
        itr++;
    }
    


    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";

    if (!arSkirtingi){
        itr = duomenys.begin();
        for (int i = 0; i < duomenys.size(); i++){

        cout << setprecision(2) << fixed << itr->getPavarde() << tarpai(itr->getPavarde(), 15)
        << itr->getVardas() << tarpai(itr->getVardas(), 15);
        cout << itr->getVidurkis() << "             " << itr->getMediana() << endl;
        itr++;
        }
    }
    else{
        itr = blogiStudentai.begin();

        for (int i = 0; i < blogiStudentai.size(); i++){

        cout << setprecision(2) << fixed << itr->getPavarde() << tarpai(itr->getPavarde(), 15)
        << itr->getVardas() << tarpai(itr->getVardas(), 15);
        cout << itr->getVidurkis() << "             " << itr->getMediana() << endl;
        itr++;
        }
    }
}

//rusiavimas
bool rusiavimasVardasListai(studentai_classList &a, studentai_classList &b){
    return a.getVardas() < b.getVardas();
}
bool rusiavimasPavardeListai(studentai_classList &a, studentai_classList &b){
    return a.getPavarde() < b.getPavarde();
}
bool rusiavimasMedianaListai(studentai_classList &a, studentai_classList &b){
    return a.getMediana() < b.getMediana();
}
bool rusiavimasVidurkisListai(studentai_classList &a, studentai_classList &b){
    return a.getVidurkis() < b.getVidurkis();
}

bool rusiavimasVidurkisListaiS(studentai_classList &a, studentai_classList &b){
    return a.getVidurkis() >= b.getVidurkis();
}
bool rusiavimasMedianaListaiS(studentai_classList &a, studentai_classList &b){
    return a.getMediana() >= b.getMediana();
}


void rusiavimoMenuListai(){
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
            if (arSkirtingi){
                // sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVardasListai);
                blogiStudentai.sort(rusiavimasVardasListai);
            }
            else{
                duomenys.sort(rusiavimasVardasListai);
                // sort(duomenys.begin(), duomenys.end(), rusiavimasVardasListai);
            }
            geriStudentai.sort(rusiavimasVardasListai);
            // sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVardasListai);
            darbasBaigtas = true;
            break;
        case 2:
            if (arSkirtingi){
                blogiStudentai.sort(rusiavimasPavardeListai);
            }
            else{
                duomenys.sort(rusiavimasPavardeListai);
            }
            geriStudentai.sort(rusiavimasPavardeListai);
            darbasBaigtas = true;
            break;
        case 3:
            if (arSkirtingi){
                blogiStudentai.sort(rusiavimasVidurkisListai);
            }
            else{
                duomenys.sort(rusiavimasVidurkisListai);
            }
            geriStudentai.sort(rusiavimasVidurkisListai);
            darbasBaigtas = true;
            break;
        case 4:
            if (arSkirtingi){
                blogiStudentai.sort(rusiavimasMedianaListai);
            }
            else{
                duomenys.sort(rusiavimasMedianaListai);
            }
            geriStudentai.sort(rusiavimasMedianaListai);
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
bool Less(studentai_classList a){
    return a.getVidurkis() >= 5;
}
bool LessM(studentai_classList a){
    return a.getMediana() >= 5;
}
void skirstymasListai(){
    
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
            arSkirtingi = true;
            list<studentai_classList>::iterator itr = duomenys.begin();
            for (int i = 0; i < duomenys.size(); i++){
                if (itr->getVidurkis() < 5){
                    blogiStudentai.push_back(*itr);
                }
                else{
                    geriStudentai.push_back(*itr);
                }
                itr++;
            }
            duomenys.clear();
        }
        if (strategija == '2'){
            duomenys.sort(rusiavimasVidurkisListaiS);
            list<studentai_classList>::iterator itr = duomenys.begin();
            
            for (int i = 0; i < b; i++){
                
                if(itr->getVidurkis() >= 5){
                    geriStudentai.push_back(*itr);
                    itr++;
                    duomenys.pop_front();
                    
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
            partition(duomenys.begin(), duomenys.end(), [](studentai_classList a){return a.getVidurkis() >= 5;});
            list<studentai_classList>::iterator itr = duomenys.begin();
            for (int i = 0; i < b; i--){
                if(itr->getVidurkis() >= 5){
                    geriStudentai.push_back(*itr);
                    itr++;
                    duomenys.pop_front();
                }
                else{
                    break;
                }
            }
        }
    }
    else if (pasirinkimas == 'm'){
        if (strategija == '1'){
            arSkirtingi = true;
            list<studentai_classList>::iterator itr = duomenys.begin();
            for (int i = 0; i < duomenys.size(); i++){
                if (itr->getMediana() < 5){
                    blogiStudentai.push_back(*itr);
                }
                else{
                    geriStudentai.push_back(*itr);
                }
                itr++;
            }
            duomenys.clear();
        }
        if (strategija == '2'){
            duomenys.sort(rusiavimasMedianaListaiS);
            list<studentai_classList>::iterator itr = duomenys.begin();
            
            for (int i = 0; i < b; i++){
                
                if(itr->getMediana() >= 5){
                    geriStudentai.push_back(*itr);
                    itr++;
                    duomenys.pop_front();
                    
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
            partition(duomenys.begin(), duomenys.end(), [](studentai_classList a){return a.getMediana() >= 5;});
            list<studentai_classList>::iterator itr = duomenys.begin();
            for (int i = 0; i < b; i--){
                if(itr->getMediana() >= 5){
                    geriStudentai.push_back(*itr);
                    itr++;
                    duomenys.pop_front();
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