#include "funkcijuBaze.h"

int main(int argc, char** argv){
    
    darbasSuVektoriais();

    //Veikia per vs
    
    //klausiama su kuriais kintamaisiais vartotojas nori dirbti.
    // while(true){
    //     try {
    //         cout << "Kokius jus naudosite kintamuosius?\n"
    //         << "( v ) - Vektoriai, ( d ) - Dekai, ( l ) - listai\n";
    //         char pasirinkimas;
    //         cin >> pasirinkimas;
    //         if (pasirinkimas == 'v' || pasirinkimas == 'V'){
    //             darbasSuVektoriais();
    //             break;
    //         } 
    //         else if(pasirinkimas == 'd' || pasirinkimas == 'D'){
    //             darbasSuDekais();
    //             break;
    //         }
    //         else if(pasirinkimas == 'l' || pasirinkimas == 'L'){
    //             darbasSuListais();
    //             break;
    //         }
    //         else{
    //             throw string("Blogai ivesta raide, bandykite dar karta");
    //         }
    //     }
    //     catch(string& msg){
    //         cerr << msg << endl;
    //     }
    // }
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}