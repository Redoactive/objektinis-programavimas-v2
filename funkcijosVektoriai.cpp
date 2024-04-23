#include "funkcijuBazeVektoriai.h"
static vector<studentai_class> duomenys;
static vector<studentai_class> geriStudentai;
static vector<studentai_class> blogiStudentai;
//globalus laikai
// static duration<double> createTime;
// static duration<double> printTime;
static duration<double> readTime;
static duration<double> sortTime;
static duration<double> typeTime;

static bool arSkirtingiVektoriai = false;


void darbasSuVektoriais(){

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
        << "( 7 ) - Baigti darba be skirstymo\n"
        << "( 8 ) - Testuoti klases\n";
        char pasirinkimas;
        cin >> pasirinkimas;
        string failoPav;
        switch (pasirinkimas)
        {
        case '1':
            pirmasPasirinkimas();
            break;
        case '2':
            antrasPasirinkimas();
            break;
        case '3':
            treciasPasirinkimas();
            break;
        case '4':
            cout << "Iveskite failo pavadinima (be .txt)\n";
            cin >> failoPav;
            failoPav += ".txt";
            NuskaitymasFailo(failoPav);
            break;
        case '5':
            failoGeneracija();
            break;
        case '6':
            darbasBaigtas = true;
            arSkirstymasVyksta = true;
            skirstymas();
            break;
        case '7':
            darbasBaigtas = true;
            break;
        case '8':
            klasiuTestavimas();
            return;
        default:
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            break;
        }
    }



    //klausiama kaip vartotojas nori isrusiuoti outputa
    // siose funkcijoje tikrinama ar yra duomenu ir ar reikia daryti rusiavima 
    if (arSkirstymasVyksta == true){
        rusiavimoMenuSkirstymas();
    }else{
        rusiavimoMenu();
    }
    
    




     //klausiama ar vartotojas spausdinti ekrane ar faile
    while(true){
        try {
            cout << "Norite spausdini terminale ( t ) ar faile ( f )?\n";
            string pasirinkimas;
            cin >> pasirinkimas;
            if (pasirinkimas == "t"){
                if(arSkirstymasVyksta == true){
                    spausdinimasTerminaleSkirstymas();
                }else{
                    spausdinimasTerminale();
                }
                
                
                break;
            } 
            else if(pasirinkimas == "f"){
                if(arSkirstymasVyksta == true){
                    spausdinimasFaileSkirstymas();
                }else{
                    spausdinimasFaile();
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
void klasiuTestavimas(){
    studentai_class a;

    // testuoti cin
    // cin >> a;

    // testuoti cout
    // cout << "Klase a\n" << a;

    //testuoti Copy operatoriu
    cout << "\nKopijavimo konstruktorius\n";
    studentai_class b(5);
    cout << "Klase b su rodykle ir masyvu\n";
    b.testav(); //spausdinimo funkcija
    b.setMasyvas(1, 100); // antras elementas pakeistas
    cout << "antras elementas pakeistas i 100\n";
    b.testav();
    studentai_class c = b;
    cout << "Klase c nukopijuotas b su pakeistu skaicium \n"; c.testav();

    //testuoti Copy operatoriu
    cout << "\nKopijavimo operatorius\n";
    cout << "c masyvas\n";
    c.testav();
    cout << "b klases 4 elementas pakeistas i 65423\n";
    b.setMasyvas(3, 65423);
    b.testav();
    c = b;
    cout << "Klase c nukopijuotas b su pakeistu skaicium \n"; c.testav();

    //testuoti move
    cout << "\nMove konstruktorius\n";
    cout << "c masyvas\n";
    c.testav();
    cout << "c klases 1 elementas pakeistas i -555\n";
    c.setMasyvas(1, -555);
    c.testav();
    studentai_class d = std::move(c);
    cout << "Naujai klasei d nustumta c klase su pakeistu skaicium \n"; d.testav();
    cout << "Likusios klases c rodykle\n"; c.testav();

    //testuoti move operatoriu
    cout << "\nMove operatorius\n";
    cout << "d masyvas\n";
    d.testav();
    cout << "d klases trecia elementas pakeistas i 987\n";
    d.setMasyvas(2, 987);
    d.testav();
    c = std::move(d);
    cout << "Klasei c nustumta d klase su pakeistu skaicium \n"; c.testav();
    cout << "Likusios klases d rodykle\n"; d.testav();
    //testuoti destruktorius
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
//pagrindines funkcijos
void pirmasPasirinkimas(){
    string a;
    int temporary;
    vector<int> bal;
    //pagrindinis ciklas
    studentai_class dabartinisStudentas;
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
void antrasPasirinkimas(){
    string a;
    vector<int> bal;
    //pagrindinis ciklas
    studentai_class dabartinisStudentas;
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
void treciasPasirinkimas(){
    vector<int> bal;
    //Vardu baze || vardai gali nesutapti su ne mergiotinem pavardem
    vector<string> bVardas = {"", "Andrius", "Marius", "Ignas", "Petras",
    "Ieva", "Liepa", "Rugile", "Onute", "Asta", "Ugne", "Deimante", "Povilas"};
    vector<string> bPavarde = {"", "Pavardenis", "Maliauka", "Ablamas",
    "Jonaiskis", "Grazetis", "Pavardenis", "Simpsonas", "Dundulis", "Mazetis", "Petrauskas"};
        
    //pagrindinis ciklas
    studentai_class dabartinisStudentas;
    int m;
    cout << "Pasirinkite kiek studentu bus automatiskai sugeneruota\n";
    cin >> m;
    cout << "Iveskite kiek norite namu darbu balu\n";
    int n;
    cin >> n;

    for (int i = 0; i < m; i++){
        int temp; 
        temp = distribution(mt);
        dabartinisStudentas.setVardas(bVardas[temp]);
        temp = distribution(mt);
        dabartinisStudentas.setPavarde(bPavarde[temp]);
        
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
    
    studentai_class dabartinisStudentas;

    string temp;
    int temporary;
    vector<int> bal;

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
void spausdinimasFaile(){

    cout << "Kaip norite pavadinti savo faila? (be .txt)\n";
    string pavadinimas;
    cin >> pavadinimas;
    pavadinimas += ".txt";
    ofstream fout;
    fout.open(pavadinimas);

    fout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    fout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < duomenys.size(); i++){
        cout << duomenys[i];
    }
    fout.close();
}
void spausdinimasTerminale(){

    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < duomenys.size(); i++){
        cout << duomenys[i];    
    }
}
void spausdinimasFaileSkirstymas(){

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
    foutB.open(pavadinimas);



    foutG << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    foutG << "-------------------------------------------------------------------\n";
    
    for (int i = 0; i < geriStudentai.size(); i++){
        foutG << geriStudentai[i];
        // foutG << setprecision(2) << fixed << geriStudentai[i].getPavarde() << tarpai(geriStudentai[i].getPavarde(), 15)
        // << geriStudentai[i].getVardas() <<  tarpai(geriStudentai[i].getVardas(), 15);
        // foutG << geriStudentai[i].getVidurkis() << "             " << geriStudentai[i].getMediana() << endl;
        
    }
    
    foutG.close();

    foutB << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    foutB << "-------------------------------------------------------------------\n";

    if (!arSkirtingiVektoriai){
        for (int i = 0; i < duomenys.size(); i++){
            foutB << duomenys[i];            
        }
    }
    else{
        for (int i = 0; i < blogiStudentai.size(); i++){
            foutB << blogiStudentai[i];            
        }
    }
    foutB.close();
}
void spausdinimasTerminaleSkirstymas(){
// cout << setprecision(2) << fixed << geriStudentai[i].getPavarde() << tarpai(geriStudentai[i].getPavarde(), 15)
// << geriStudentai[i].getVardas() <<  tarpai(geriStudentai[i].getVardas(), 15);
// cout << geriStudentai[i].getVidurkis() << "             " << geriStudentai[i].getMediana() << endl;
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "------------------------------Geri studentai-------------------------------------\n";

    for (int i = 0; i < geriStudentai.size(); i++){
        cout << geriStudentai[i];       
    }
    
    cout << "Pavarde        Vardas         Galutinis (Vid.) Galutinis (Med.)\n";
    cout << "-------------------------------------------------------------------\n";

    if (!arSkirtingiVektoriai){
        for (int i = 0; i < duomenys.size(); i++){
            cout << duomenys[i];
        }
    }
    else{
        for (int i = 0; i < blogiStudentai.size(); i++){
            cout << blogiStudentai[i];
        }
    }
}
//rusiavimas
bool rusiavimasVardas(studentai_class &a, studentai_class &b){
    return a.getVardas() < b.getVardas();
}
bool rusiavimasPavarde(studentai_class &a, studentai_class &b){
    return a.getPavarde() < b.getPavarde();
}
bool rusiavimasMediana(studentai_class &a, studentai_class &b){
    return a.getMediana() < b.getMediana();
}
bool rusiavimasVidurkis(studentai_class &a, studentai_class &b){
    return a.getVidurkis() < b.getVidurkis();
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
            if (arSkirtingiVektoriai){
                sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVardas);
            }
            else{
                sort(duomenys.begin(), duomenys.end(), rusiavimasVardas);
            }
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVardas);
            darbasBaigtas = true;
            break;
        case 2:
            if (arSkirtingiVektoriai){
                sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasPavarde);
            }
            else{
                sort(duomenys.begin(), duomenys.end(), rusiavimasPavarde);
            }
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasPavarde);
            darbasBaigtas = true;
            break;
        case 3:
            if (arSkirtingiVektoriai){
                sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasVidurkis);
            }
            else{
                sort(duomenys.begin(), duomenys.end(), rusiavimasVidurkis);
            }
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasVidurkis);
            darbasBaigtas = true;
            break;
        case 4:
            if (arSkirtingiVektoriai){
                sort(blogiStudentai.begin(), blogiStudentai.end(), rusiavimasMediana);
            }
            else{
                sort(duomenys.begin(), duomenys.end(), rusiavimasMediana);
            }
            sort(geriStudentai.begin(), geriStudentai.end(), rusiavimasMediana);
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
bool Less(studentai_class a){
    return a.getVidurkis() >= 5;
}
bool LessM(studentai_class a){
    return a.getMediana() >= 5;
}
void skirstymas(){
    
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
            arSkirtingiVektoriai = true;

            for (int i = 0; i < duomenys.size(); i++){
                if (duomenys[i].getVidurkis() < 5){
                    blogiStudentai.push_back(duomenys[i]);
                }
                else{
                    geriStudentai.push_back(duomenys[i]);
                }
            }
            duomenys.clear();
        }
        if (strategija == '2'){
            sort(duomenys.begin(), duomenys.end(), rusiavimasVidurkis);
            for (int i = b; i > 0; i--){
                
                if(duomenys[i - 1].getVidurkis() >= 5){
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
            partition(duomenys.begin(), duomenys.end(), [](studentai_class a){return a.getVidurkis() < 5;});
            for (int i = b; i > 0; i--){
                if(duomenys[i - 1].getVidurkis() >= 5){
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
            arSkirtingiVektoriai = true;
            for (int i = 0; i < duomenys.size(); i++){
                if (duomenys[i].getMediana() < 5){
                    blogiStudentai.push_back(duomenys[i]);
                }
                else{
                    geriStudentai.push_back(duomenys[i]);
                }
            }
            duomenys.clear();
        }
        if (strategija == '2'){
            sort(duomenys.begin(), duomenys.end(), rusiavimasMediana);
            for (int i = b; i > 0; i--){
                
                if(duomenys[i - 1].getMediana() >= 5){
                    geriStudentai.push_back(duomenys[i - 1]);
                    duomenys.pop_back();
                    
                }
                else{
                    break;
                }
            }
        }
        if (strategija == '3'){
            partition(duomenys.begin(), duomenys.end(), [](studentai_class a){return a.getMediana() < 5;});
            for (int i = b; i > 0; i--){
                if(duomenys[i - 1].getMediana() >= 5){
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