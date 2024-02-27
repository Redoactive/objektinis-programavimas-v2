#include "includes.h"
#include "funkcijuBaze.h"

int main(){
    bool darbasBaigtas = false;
    double startTime;
    //pasirinkimu menu
    while (darbasBaigtas == false)
    {
        cout << "Pasirinkite, ka norite daryti\n"
        << "( 1 ) - Ivesti duomenys ranka\n"
        << "( 2 ) - Generuoti pazymius atsitiktinai\n"
        << "( 3 ) - Generuoti ir pazymius ir studentu vardus, pavardes\n"
        << "( 4 ) - Baigti darba\n"
        << "( 5 ) - Nuskaityti is failo\n"
        << "( 6 ) - Testuoti su laiku - studentai10000\n"
        << "( 7 ) - Testuoti su laiku - studentai1000000\n";
        int pasirinkimas;
        cin >> pasirinkimas;
        string failoPav;
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
        case 5:
            cout << "Iveskite failo pavadinima\n";
            cin >> failoPav;
            startTime = clock();
            NuskaitymasFailo(failoPav);
           cout << "failo skaitymo laikas yra - " <<  (clock() - startTime) / 1000 << " sekundes\n";
            break;
        case 6:
            startTime = clock();
            NuskaitymasFailo("studentai10000.txt");
            cout << "failo skaitymo laikas yra - " <<  (clock() - startTime) / 1000 << " sekundes\n";
            break;
        case 7:
            startTime = clock();
            NuskaitymasFailo("studentai1000000.txt");
            cout << "failo skaitymo laikas yra - " <<  (clock() - startTime) / 1000 << " sekundes\n";
            break;
        default:
            
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
            break;
        }
    }
    //klausiama kaip vartotojas nori isrusiuoti outputa
    darbasBaigtas = false;
    while (darbasBaigtas == false){
        cout << "Kaip norite rusiuoti output?\n"
        << "( 1 ) - Pagal varda\n"
        << "( 2 ) - Pagal pavarde\n"
        << "( 3 ) - Pagal vidurkis\n"
        << "( 4 ) - Pagal mediana\n";
        
        int pasirinkimas;
        cin >> pasirinkimas;
        
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
            break;
        }
    }
     //klausiama ar vartotojas spausdinti ekrane ar faile
    darbasBaigtas = false;
    while (darbasBaigtas == false){
        cout << "Norite spausdini terminale ( t ) ar faile ( f )?\n";
        string pasirinkimas;
        cin >> pasirinkimas;

        if (pasirinkimas == "t"){
            spausdinimasTerminale();
            darbasBaigtas = true;
        } 
        else if(pasirinkimas == "f"){
            spausdinimasFaile();
            darbasBaigtas = true;
        }
        else{
            cout << "Blogai ivedete duomenys, bandykite dar karta\n";
        }
    }
}