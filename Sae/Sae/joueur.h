#ifndef _JOUEUR_
#define _JOUEUR_

/**
 * @file joueur.h
 * Conteneur de joueur
 * @author Davis Yu 110
 * @version 19/12/2022
 * @brief Applicatif des joueurs
 */

#include <iostream>
#include <cassert>
using namespace std;

/**
* @brief Un Joueur est defini par son nom (type) humain ou robot
* et son nombre de quart de singe est stocké
*/
struct Joueur {
	char nom;
	float singe;
};

/**
* @brief Conteneur de Joueurs et de leur nombre
*/
struct Conteneur {
	unsigned int nbjoueur;
	Joueur* joueur;
};

/**
* @brief Ajoute un quart de singe
* au joueur a l'indice ind
* @param[in] ind : Indice du joueur
* @param[out] c : Conteneur de joueurs
*/
void ecrire(Conteneur& c, unsigned int ind);

/**
* @brief Lecture du Joueur a l'indice ind
* @param[in] c : Conteneur de joueurs
* @param[in] ind : Indice du joueur
* @return Joueur a l'indice ind
* @pre ind<nbjoueur
*/
Joueur lire(const Conteneur& c, unsigned int ind);

/**
* @brief Initialise un Conteneur de joueur
* avec le parametre d'entre
* @param[in] arg : Chaine de caracteres
* @param[out] c : Conteneur de joueurs
* @pre strlen(arg)>=2 arg[i] = H ou R
*/
void initJeu(Conteneur& c, const char* arg);

/**
* @brief Affiche les scores des joueurs
* @param[in] c : Conteneur de joueurs
*/
void score(const Conteneur& c);

#endif