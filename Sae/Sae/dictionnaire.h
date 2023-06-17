#ifndef _DICTIONNAIRE_
#define _DICTIONNAIRE_

/**
 * @file dictionnaire.h
 * Dictionnaire de mots
 * @author Davis Yu 110
 * @version 19/12/2022
 * @brief Applicatif du dictionnaire
 */

#pragma warning(disable : 4996) //Pour que le strcpy fonctionne

#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;

enum { MAXCHAR = 26, PAS = 2 };

 /**
 * @brief Mot : chaine de caracteres
 */
struct Mot {
	char mot[MAXCHAR];
};

/**
* @brief Dictionnaire de Mots alloués en mémoire dynamique
* de capacité extensible suivant un pas d'extension
*/
struct Dictionnaire {
	unsigned int pasExtension;
	unsigned int capacite;
	unsigned int nbmot;
	Mot* mots;
};

/**
* @brief Initialise un dictionnaire
* Allocation en mémoire dynamique du dictionnaire
* de capacité (1) extensible par pas d'extension (PAS)
* @param[out] dico : Dictionnaire de mots triés
* @pre Lecture correct d'un document
*/
void initDico(Dictionnaire& dico);

/**
* @brief Cherche le mot dans le dictionnaire
* @param[in] dico : Dictionnaire de mots
* @param[in] mot : Chaine de caracteres
* @return Booleen de verite
* @pre Dictionnaire non vide
*/
bool rechercheMot(const Dictionnaire& dico, const char* mot);

#endif