#include "funkcijuBaze.h"
#include "includes.h"

int main(){

    int kintamujuTipas;


    //klausiama su kuriais kintamaisiais vartotojas nori dirbti.
    while(true){
        try {
            cout << "Kokius jus naudosite kintamuosius?\n"
            << "( v ) - Vektoriai, ( d ) - Dekai, ( l ) - listai\n";
            char pasirinkimas;
            cin >> pasirinkimas;
            if (pasirinkimas == 'v' || pasirinkimas == 'V'){
                kintamujuTipas = 1;
                break;
            } 
            else if(pasirinkimas == 'd' || pasirinkimas == 'D'){
                kintamujuTipas = 2;
                break;
            }
            else if(pasirinkimas == 'l' || pasirinkimas == 'L'){
                kintamujuTipas = 3;
                break;
            }
            else{
                throw string("Blogai ivesta raide, bandykite dar karta");
            }
        }
        catch(string& msg){
            cerr << msg << endl;
        }
    }
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
            skirstymas();
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
    rusiavimoMenu();
    rusiavimoMenuSkirstymas();




     //klausiama ar vartotojas spausdinti ekrane ar faile
    while(true){
        try {
            cout << "Norite spausdini terminale ( t ) ar faile ( f )?\n";
            string pasirinkimas;
            cin >> pasirinkimas;
            if (pasirinkimas == "t"){
                spausdinimasTerminale();
                spausdinimasTerminaleSkirstymas();
                break;
            } 
            else if(pasirinkimas == "f"){
                spausdinimasFaile();
                spausdinimasFaileSkirstymas();
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



    
    laikoSpausdinimas();
}