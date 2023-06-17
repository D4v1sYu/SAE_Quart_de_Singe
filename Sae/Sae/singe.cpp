// Davis Yu 110 19/12/22

#include "singe.h"
#include "joueur.h"
#include "dictionnaire.h"

bool singe(const Conteneur& c, unsigned int ind) {
	if (c.joueur[ind].singe == 1.) return true;
	return false;
}

char lettre_aleatoire() {
	return 65 + (rand() % 26);
}

int correspondance(const char* mot1, const char* mot2) {
	return strncmp(mot1, mot2, strlen(mot1));
}

char rechercheBot(const Dictionnaire& dico, const Conteneur& c, const char* mot, char* sauv) {

	assert(dico.nbmot != 0);

	int deb, mil, fin;

	deb = 0;
	fin = dico.nbmot;
	char verif[MAXCHAR] = "";
	strcpy(verif, mot);

	while (deb <= fin) {

		mil = (deb + fin) / 2;

		//Observe le nombre de joueur pour decider de jouer ou non le mot
		unsigned int action = (strlen(dico.mots[mil].mot) - strlen(mot)) % (c.nbjoueur + 1);

		//Verification que la lettre souhaitee ne complete pas un mot deja existant
		verif[strlen(mot)] = dico.mots[mil].mot[strlen(mot)]; 
		for (unsigned int i = (unsigned int)strlen(mot) + 1; i < MAXCHAR - 1; ++i) { //Vide les lettres inutiles
			verif[i] = NULL;
		}

		// Retourne la lettre une fois qu'un mot existe, que cette lettre ne forme pas un autre mot
		// et que je joueur courant ne termine pas le mot
		if (correspondance(mot, dico.mots[mil].mot) == 0 && action != 0 && !rechercheMot(dico, verif)) {

			strcpy(sauv, dico.mots[mil].mot); //Le mot trouvé est sauvergardé pour le robot
			return dico.mots[mil].mot[strlen(mot)];
		}

		else if (correspondance(mot, dico.mots[mil].mot) > 0) deb = mil + 1;

		else if (correspondance(mot, dico.mots[mil].mot) < 0) fin = mil - 1;

		else if (verif[strlen(mot)] > dico.mots[mil].mot[strlen(mot)]) --fin;

		else ++deb;
	}

	return '?'; //Ici le robot n'abandonne jamais, il defira toujours le joueur precedent
}

char jouer(const Dictionnaire dico, const Conteneur& c, unsigned int ind, char* mot, char* sauv) {

	assert(c.joueur[ind].nom == 'H' || c.joueur[ind].nom == 'R');
	char carac;

	if (c.joueur[ind].nom == 'H') { //Humain
		cin >> carac;
		return toupper(carac);
	}

	else if (strlen(mot) == 0) { //Si le robot est le premier a joué
		carac = lettre_aleatoire();
		char verif[MAXCHAR] = "";
		verif[0] = carac;
		rechercheBot(dico, c, verif, sauv);
	}

	else carac = rechercheBot(dico, c, mot, sauv); //Le robot cherche une lettre optimale

	cout << carac << endl;
	return carac;
}

void abandon(Conteneur& c, unsigned int ind, bool& statut) {

	cout << "le joueur " << ind + 1 << lire(c, ind).nom << " abandonne la manche et prend un quart de singe" << endl;
	ecrire(c, ind);
	statut = true;
	score(c);
}

void conteste(const Dictionnaire& dico, Conteneur& c, char* mot, const char* sauv, unsigned int& ind, bool& statut) {

	assert(dico.nbmot != 0);

	statut = true;
	char verif[MAXCHAR];
	unsigned int precedent = ind + c.nbjoueur - 1;
	precedent %= c.nbjoueur;

	cout << precedent + 1 << lire(c, precedent).nom << ", saisir le mot > ";

	if (c.joueur[precedent].nom == 'H') cin >> verif; //Humain
	//Robot
	else {
		cout << sauv << endl;
		strcpy(verif, sauv);
	}

	for (unsigned int i = 0; i < strlen(verif); i++) { //Mot en majuscule
		verif[i] = toupper(verif[i]);
	}

	if (verif[0] == '!') { //Abandon
		abandon(c, precedent, statut);
		ind = precedent;
		return;
	}

	else if (correspondance(mot, verif) != 0) { //Verification des premieres lettres du mot rentré
		cout << "le mot " << verif << " ne commence pas par les lettres attendues, le joueur " << precedent + 1 << lire(c, precedent).nom << " prend un quart de singe" << endl;
		ecrire(c, precedent);
		ind = precedent;
	}

	else if (rechercheMot(dico, verif) && strlen(verif) > 2) { //Existence du mot
		cout << "le mot " << verif << " existe, le joueur " << ind + 1 << lire(c, ind).nom << " prend un quart de singe" << endl;
		ecrire(c, ind);
	}

	else { // Le mot n'a pas etait trouvé, il n'existe pas
		cout << "le mot " << verif << " n'existe pas, " << precedent + 1 << lire(c, precedent).nom << " prend un quart de singe" << endl;
		ind = precedent;
		ecrire(c, precedent);
	}

	score(c);
}