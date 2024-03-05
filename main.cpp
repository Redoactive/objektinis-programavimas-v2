#include "funkcijuBaze.h"
#include "includes.h"

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
    rusiavimoMenu();
    
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