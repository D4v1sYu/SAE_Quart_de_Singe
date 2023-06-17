// Davis Yu 110 19/12/22

#include "singe.h"

int main(int argc, const char* argv[]) {

	srand((unsigned int)time(NULL));

	Conteneur jeu;
	Dictionnaire dictionnaire;
	initDico(dictionnaire);
	initJeu(jeu, argv[1]);

	/* Test mot dictionnaire.txt trouvable dans la structure dictionnaire
	ifstream in("ods4.txt");
	char test[MAXCHAR];
	if (!in) return 0;
	while (in >> setw(MAXCHAR) >> test)
		assert(rechercheMot(dictionnaire, test));
	in.close();*/

	/* Test l'existence de joueur sans dépassement
	for (int i = 0; i < jeu.nbjoueur; ++i) {
		assert(jeu.joueur[i].nom == 'H' || jeu.joueur[i].nom == 'R');
	}
	assert(!(jeu.joueur[jeu.nbjoueur].nom == 'H' || jeu.joueur[jeu.nbjoueur].nom == 'R'));*/

	/* Test compteur de point de chaque joueur
	for (int i = 0; i < jeu.nbjoueur; ++i) {
		int cpt = 0;
		while (!singe(jeu, i)) {
			ecrire(jeu, i);
			cpt++;
		}
		assert(cpt == 4);
	}
	score(jeu);*/

	/* Test l'obtention de lettres aléatoires bien comprises entre A et Z
	for (int i = 0; i < 1000; ++i) {
		assert((lettre_aleatoire() >= 'A') && (lettre_aleatoire() <= 'Z'));
	}*/

	unsigned int ind = 0, courant = 0;
	char carac, sauvegarde[MAXCHAR] = "", mot[MAXCHAR] = "";

	while (!singe(jeu, courant)) {

		assert(strlen(mot) < MAXCHAR - 1);

		bool mancheFin = false;
		cout << courant + 1 << lire(jeu, courant).nom << ", (" << mot << ") > ";

		carac = jouer(dictionnaire, jeu, courant, mot, sauvegarde);

		if (carac == '!') abandon(jeu, courant, mancheFin);

		else if (carac == '?') conteste(dictionnaire, jeu, mot, sauvegarde, courant, mancheFin);

		else {
			mot[ind] = carac;
			++ind;

			if (rechercheMot(dictionnaire, mot) && (strlen(mot) > 2)) {
				mancheFin = true;
				ecrire(jeu, courant);
				cout << "le mot " << mot << " existe, le joueur " << courant + 1 << lire(jeu, courant).nom << " prend un quart de singe" << endl;
				score(jeu);
			}
		}

		if (mancheFin || strlen(mot) == MAXCHAR-1) {
			for (unsigned int i = 0; i < ind; i++)
				mot[i] = NULL;
			ind = 0;
			
		}
		else {
			++courant;
			courant %= jeu.nbjoueur;
		}
	}
	cout << "La partie est finie";

	return 0;
}
