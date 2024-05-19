#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <QObject>
using namespace std;

class IMC: public QObject {
	Q_OBJECT;
public:
	IMC() {};
	double getPoids() const { return poids_; }
	double getTaille() const { return taille_; }


public slots:
	void afficherImc(double Imc);
	double calculerImc1();
	double calculerImc2();

signals:
	//void valueImcModifier(double newValue);


private:
	double poids_;;
	double taille_;
};
