#include "includes.h"
#include "funkcijuBaze.h"

int main(){
    bool darbasBaigtas = false;

    //pasirinkimu menu
    while (darbasBaigtas == false)
    {
        cout << "Pasirinkite, ka norite daryti\n"
        << "( 1 ) - Ivesti duomenys ranka\n"
        << "( 2 ) - Generuoti pazymius atsitiktinai\n"
        << "( 3 ) - Generuoti ir pazymius ir studentu vardus, pavardes\n"
        << "( 4 ) - Nuskaityti is failo\n"
        << "( 5 ) - Testuoti automatiskai faila - studentai1000000\n"
        << "( 6 ) - Baigti darba\n";
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
            cout << "Iveskite failo pavadinima\n";
            cin >> failoPav;
            NuskaitymasFailo(failoPav);
            break;
        case 5:
            NuskaitymasFailo("studentai1000000.txt");
            break;
        case 6:
            darbasBaigtas = true;
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
            break;
        }
    }
     //klausiama ar vartotojas spausdinti ekrane ar faile
    while(true){
        try {
            cout << "Norite spausdini terminale ( t ) ar faile ( f )?\n";
            string pasirinkimas;
            cin >> pasirinkimas;
            if (pasirinkimas == "t"){
                spausdinimasTerminale();
                break;
            } 
            else if(pasirinkimas == "f"){
                spausdinimasFaile();
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
}