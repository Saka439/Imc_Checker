#include "IMC.hpp"

void IMC::afficherImc(double Imc) {
    if (Imc < 18.5) {
        cout << "Vous etes maigre" << endl;
    }
    else if (18.5 <= Imc <= 25) {
        cout << "Vous etes normal" << endl;
    }
    else if (25 <=Imc <= 30) {
        cout << "Vous etes en surpoids" << endl;
    }
    else  {
        cout << "Vous etes obese" << endl;
    }
}

double IMC::calculerImc1() {
    
    double Imc = poids_ / (taille_ * taille_);
   
    afficherImc(Imc);
    cout << Imc;
    return Imc;
}

double IMC::calculerImc2() {
  
    poids_ = poids_ / 2.20462;
    taille_ = taille_ / 3.2808;
    double Imc = poids_ / (taille_ * taille_);
    afficherImc(Imc);

    return Imc;
}
