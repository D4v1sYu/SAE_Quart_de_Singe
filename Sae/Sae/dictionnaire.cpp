// Davis Yu 110 19/12/22

#include "dictionnaire.h"

void initDico(Dictionnaire& dico) {

	dico.capacite = 1;
	dico.pasExtension = PAS;
	dico.nbmot = 0;
	dico.mots = new Mot[dico.capacite];

	ifstream in("ods4.txt"); //Ouverture du fichier

	if (!in) {
		cout << "le dictionnaire n'a pu etre ouvert" << endl;
		exit(2);
	}

	char mot[MAXCHAR];

	while (in.getline(mot, MAXCHAR, '\n')) {

		if (dico.nbmot >= dico.capacite) { //Allocation proportionnelle au pas d'extension

			unsigned int newTaille = dico.nbmot * dico.pasExtension;
			Mot* newT = new Mot[newTaille];

			for (unsigned int j = 0; j < dico.capacite; ++j)
				newT[j] = dico.mots[j];

			delete[] dico.mots;
			dico.mots = newT;
			dico.capacite = newTaille;
		}
		strcpy(dico.mots[dico.nbmot].mot, mot);
		++dico.nbmot;
	}

	in.close(); //Fermeture du fichier
}

bool rechercheMot(const Dictionnaire& dico, const char* mot) {

	assert(dico.nbmot != 0);

	int deb, mil, fin;
	deb = 0;
	fin = dico.nbmot;

	while (deb <= fin) { //Recherche dichotomique du mot dans le dictionnaire
		mil = (deb + fin) / 2;
		if (strcmp(mot, dico.mots[mil].mot) == 0) {
			return true;
		}
		else if (strcmp(mot, dico.mots[mil].mot) > 0) {
			deb = mil + 1;
		}
		else fin = mil - 1;
	}
	return false;
}