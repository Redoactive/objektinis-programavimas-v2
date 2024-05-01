#include "funkcijuBazeVektoriai.h"

studentai_class::studentai_class(int dydis)
{
    dydis_ = dydis;
    rodykle_ = new int[dydis_];
    for(int i = 0; i < dydis_; i++){
        rodykle_[i] = i;
    }
};

void studentai_class::testav(){
    if (rodykle_==nullptr){
        cout << "Rodykle tuscia\n";
        return;
    }
    for(int i = 0; i < dydis_; i++){
        cout << rodykle_[i] << " ";
    }
    cout << endl;
}

ostream& operator<<(ostream& out, studentai_class a) // output overloading
{
    out << setprecision(2) << fixed << a.pavarde_ << tarpai(a.pavarde_, 15) << a.vardas_ <<
    tarpai(a.vardas_, 15) << a.vidurkis_ << "             " << a.mediana_ << endl;
    return out;
};
istream& operator>>(istream& in, studentai_class &a)
{
    cout << "Iveskite varda ir pavarde\n";
    in >> a.vardas_;
    in >> a.pavarde_;
    int i = 0, temp;
    cout << "Iveskite namu darbu balus, parasykite -1, jei norite sustoti\n";
    do{
        in >> temp;
        a.balai_.push_back(temp);
        i++;
    }
    while(a.balai_[i - 1] != -1);
    a.balai_.pop_back();//panaikinamas -1
    cout << "Iveskite egzamino bala\n";
    in >> a.egzaminas_;
    a.vidurkis_ = vidurkioApsk(a.balai_, a.egzaminas_);
    a.mediana_ = medianosApsk(a.balai_, a.egzaminas_);
    return in;
};
// kopiviavimo konstruktorius
studentai_class::studentai_class(const studentai_class& a){
    vardas_ = a.vardas_;
    pavarde_ = a.pavarde_;
    balai_ = a.balai_;
    egzaminas_ = a.egzaminas_;
    vidurkis_ = a.vidurkis_;
    mediana_ = a.mediana_;

    for (int i = 0; i < a.balai_.size(); i++){
        balai_[i] = a.balai_[i];
    }
    
    //testavimas 
    dydis_ = a.dydis_;
    rodykle_ = new int[a.dydis_];
    for (int i = 0; i < a.dydis_; i++){
        rodykle_[i] = a.rodykle_[i];
    }
}

studentai_class studentai_class::operator=(const studentai_class& a){ // kopiviavimo operatorius / priskirimas
    if (&a == this){
        return *this;
    }
    vardas_ = a.vardas_;
    pavarde_ = a.pavarde_;
    for (int i = 0; i < a.balai_.size(); i++){
        balai_[i] = a.balai_[i];
    }
    egzaminas_ = a.egzaminas_;
    vidurkis_ = a.vidurkis_;
    mediana_ = a.mediana_;
    
    //testavimas
    int *temporaryPointer = new int[a.dydis_];
    delete[] rodykle_;
    dydis_ = a.dydis_;
    for (int i = 0; i < a.dydis_; i++){
        temporaryPointer[i] = a.rodykle_[i];
    }
    rodykle_ = temporaryPointer;
    return *this;
}

studentai_class::studentai_class (studentai_class&& a){ // move konstruktorius
    vardas_ = a.vardas_;
    pavarde_ = a.pavarde_;
    balai_ = a.balai_;
    egzaminas_ = a.egzaminas_;
    vidurkis_ = a.vidurkis_;
    mediana_ = a.mediana_;
    for (int i = 0; i < a.balai_.size(); i++){
        balai_[i] = a.balai_[i];
        a.balai_[i] = 0;
    }
    a.vardas_ = "";
    a.pavarde_ = "";
    a.egzaminas_ = 0;
    a.mediana_ = 0;
    a.vidurkis_ = 0;
    //testavimas
    dydis_ = a.dydis_;
    rodykle_ = a.rodykle_;
    a.rodykle_ = nullptr;
}

studentai_class studentai_class::operator=(studentai_class&& a){ // move operatorius
    if (&a == this){
        return *this;
    }
    vardas_ = a.vardas_;
    pavarde_ = a.pavarde_;
    for (int i = 0; i < a.balai_.size(); i++){
        balai_[i] = a.balai_[i];
    }
    egzaminas_ = a.egzaminas_;
    vidurkis_ = a.vidurkis_;
    mediana_ = a.mediana_;
    //testavimas
    delete[] rodykle_;
    rodykle_ = a.rodykle_;
    dydis_ = a.dydis_;
    a.rodykle_ = nullptr;
    a.dydis_ = 0;
    a.vardas_ = "";
    a.pavarde_ = "";
    a.egzaminas_ = 0;
    a.mediana_ = 0;
    a.vidurkis_ = 0;
    return *this;
}


studentai_class::studentai_class(){
    vardas_ = "";
    pavarde_ = "";
    balai_;
    egzaminas_ = 0;
    vidurkis_ = 0;
    mediana_ = 0;
    rodykle_ = nullptr;
    dydis_ = 0;
}

studentai_class::studentai_class(string vardas, string pavarde, vector<int> balai, int egzaminas, double vidurkis, double mediana){
    vardas_ = vardas;
    pavarde_ = pavarde;
    balai_ = balai;
    egzaminas_ = egzaminas;
    vidurkis_ = vidurkis;
    mediana_ = mediana;
    rodykle_ = nullptr;
    dydis_ = 0;
}













