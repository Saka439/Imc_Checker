// La Vue-Controlleur pour l'afficheur d'Indice de Masse Corporelle
// Par ndzana-missia.saka@polymtl.ca
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include "ImcWindows.h"
#include "IMC.hpp"
#include <iostream>
#include <type_traits>
#include <cppitertools/range.hpp>

using iter::range;




ImcWindow::ImcWindow(QWidget* parent) :
	QMainWindow(parent)
{
	
	auto widgetPrincipal = new QWidget(this);

	setCentralWidget(widgetPrincipal);

	auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);  


	QLabel* poidsLabel = new QLabel("Poids en kg:");
	nameEditor = new QLineEdit;
	QHBoxLayout* poidsLayout = new QHBoxLayout;
	poidsLayout->addWidget(poidsLabel);
	poidsLayout->addWidget(nameEditor);

	QLabel* tailleLabel = new QLabel("Taille en m:");
	nameEditor2 = new QLineEdit;
	QHBoxLayout* tailleLayout = new QHBoxLayout;
	tailleLayout->addWidget(tailleLabel);
	tailleLayout->addWidget(nameEditor2);

	layoutPrincipal->addLayout(poidsLayout);
	layoutPrincipal->addLayout(tailleLayout);


	
	QPushButton* calculerButton = new QPushButton("Calcule ton IMC", this);
	connect(calculerButton, &QPushButton::clicked, this, &ImcWindow::calculerImcEtAfficher);
	layoutPrincipal->addWidget(calculerButton);
	

}

void ImcWindow::calculerImcEtAfficher()
{
	
	double poids = nameEditor->text().toDouble();
	double taille = nameEditor2->text().toDouble();

	
	double resultat = imc.calculerImc1(); 
	//double resultat2 = imc.calculerImc2();

	
	if (layoutPrincipal) {
		
		QLabel* resultatLabel = new QLabel("IMC: " + QString::number(resultat), this);
		layoutPrincipal->addWidget(resultatLabel);
	}
}



template <typename T>
QPushButton* ImcWindow::nouveauBouton(const QString& text, const T& slot)
{
	auto bouton = new QPushButton(this);
	bouton->setText(text);
	bouton->setFixedSize(50, 50);
	if constexpr (!std::is_same_v<T, decltype(nullptr)>)
		QObject::connect(bouton, &QPushButton::clicked, slot);
	return bouton;
}


