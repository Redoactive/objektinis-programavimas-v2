#include "funkcijuBaze.h"
//funckija spausdinti tarpus
string tarpai(string a, int tarpuDydis){
    string kiekis;
    int m = tarpuDydis - a.length();
    for (int i = 0; i < m; i++){
        kiekis += " ";
    }
    return kiekis;
}

string extraSpace (string a, int b){
    
    string space;
    for (int i = 0; i < b; i++){
        space += " ";
    }
    return space;
}

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> distribution (1, 10);

void failoGeneracija(){
    uniform_int_distribution<int> distribution (1, 10);
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

    // auto createTimeS = high_resolution_clock::now();

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
    // auto createTimeE = high_resolution_clock::now();
    // createTime = createTimeE - createTimeS;
}



void laikoSpausdinimas(duration<double> readTime, duration<double> sortTime ,duration<double> typeTime){
    cout << setprecision(7);
    // cout << "Failu kurimas - " << createTime.count() << " s.\n";
    cout << "Duomenu nuskaitymas is failo - " << readTime.count() << " s.\n";
    cout << "Rusiavimas uztruko - " << sortTime.count() << " s.\n";
    cout << "Studentu skirstymas i dvi grupes/kategorijas - " << typeTime.count() << " s.\n";
    // cout << "Surusiuotu studentu isvedimas i du naujus failus - " << printTime.count() << " s.\n";
    // allTime = createTime + readTime + typeTime + sortTime + printTime;
    duration<double> allTime;
    allTime = readTime + typeTime + sortTime;
    cout << "Visos programos veikimo laikas - " << allTime.count() << " s.\n";
}