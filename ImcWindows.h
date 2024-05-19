#pragma once
#pragma once
// La Vue-Controlleur pour mon application qui a pour but d'informer les clients sur leur Indice de Masse Corporel(IMC)
// Par ndzana-missia.saka@polymtl.ca


#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include "IMC.hpp"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#pragma pop()

class ImcWindow : public QMainWindow {
	Q_OBJECT

public:
	ImcWindow(QWidget* parent = nullptr);
	~ImcWindow() override = default;

	

public slots:
	void calculerImcEtAfficher();

private:
	template <typename T = decltype(nullptr)>
	QPushButton* nouveauBouton(const QString& text, const T& slot = nullptr);
	QVBoxLayout* layoutPrincipal;
	IMC imc;  // Le Modèle (pourrait être un pointeur mais pas nécessaire dans ce cas).
	QLineEdit* nameEditor;
	QLineEdit* nameEditor2;
	QLabel* affichage_;  // Pour la version QButtonGroup.
};

