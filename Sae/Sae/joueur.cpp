// Davis Yu 110 19/12/22

#include "joueur.h"

void ecrire(Conteneur& c, unsigned int ind) {
	c.joueur[ind].singe += 0.25;
}

Joueur lire(const Conteneur& c, unsigned int ind) {
	assert(ind < c.nbjoueur);
	return c.joueur[ind];
}

void initJeu(Conteneur& c, const char* arg) {

	//Le nombre de joueur correspond a la longueur du parametre d'entré
	c.nbjoueur = (unsigned int)strlen(arg);
	assert(c.nbjoueur >= 2);
	c.joueur = new Joueur[c.nbjoueur];
	char lettre;

	//Chaque joueur est initialisé par son nom (type) et son score
	for (unsigned int i = 0; i < c.nbjoueur; ++i) {
		lettre = arg[i];
		lettre = toupper(lettre);
		assert(lettre == 'H' or lettre == 'R');
		c.joueur[i].nom = lettre;
		c.joueur[i].singe = 0;
	}
}

void score(const Conteneur& c) {
	for (unsigned int i = 0; i < c.nbjoueur; ++i) {
		cout << i + 1 << lire(c, i).nom << " : " << lire(c, i).singe;
		if (i != c.nbjoueur - 1) {
			cout << "; ";
		}
		else cout << endl;
	}
}