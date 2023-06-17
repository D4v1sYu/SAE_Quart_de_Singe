#ifndef _SINGE_
#define _SINGE_

/**
 * @file singe.h
 * Projet quart de singe
 * @author Davis Yu 110
 * @version 19/12/2022
 * @brief Applicatif du quart de singe
 */

#include <iomanip>
#include "dictionnaire.h"
#include "joueur.h"

/**
* @brief Verifie que le joueur a l'indice ind
* possede ou non quatre quart de singe
* @param[in] c : Conteneur de joueurs
* @param[in] ind : Indice du joueur
* @return Booleen de verite
*/
bool singe(const Conteneur& c, unsigned int ind);

/**
* @brief Affiche les scores des joueurs
* @param[in] c : Conteneur de joueurs
*/
void score(const Conteneur& c);

/**
* @brief Retourne le code ASCII 
* d'une lettre de l'alphabet aleatoirement
* @return Char entre 65 et 90
*/
char lettre_aleatoire();

/**
* @brief Retourne le resultat de la comparaison
* entre deux chaines de caracteres
* @param[in] mot1 : Chaine de caracteres
* @param[in] mot2 : Chaine de caracteres
* @return Valeur negative ou nulle ou positive
* @pre strlen(mot1)<strlen(mot2)
*/
int correspondance(const char* mot1, const char* mot2);

/**
* @brief Recherche le mot le plus aventageux pour 
* le joueur courant et retourne la lettre a jouee
* @param[in] dico : Dictionnaire de mots
* @param[in] c : Conteneur de joueurs
* @param[in] mot : Chaine de caractere en jeu
* @param[out] sauv : Sauvegarde du mot trouvé
* @return Lettre / Char entre 65 et 90
* @pre Dictionnaire non vide
*/
char rechercheBot(const Dictionnaire& dico, const Conteneur& c, const char* mot, char* sauv);

/**
* @brief Retourne la lettre jouee par l'humain ou le robot
* @see rechercheMot, pour la lettre du robot
* @param[in] c : Conteneur de joueurs
* @param[in] ind : Indice du joueur
* @param[in] mot : Chaine de caractere en jeu
* @return Lettre / Char entre 65 et 90
*/
char jouer(const Dictionnaire dico, const Conteneur& c, unsigned int ind, char* mot, char* sauv);

/**
* @brief Le joueur abandonne la manche 
* et prend un quart de singe
* @param[in] ind : Indice du joueur
* @param[out] statut : Booleen de fin de manche
* @param[in-out] c : Conteneur de joueurs
*/
void abandon(Conteneur& c, unsigned int ind, bool& statut);

/**
* @brief Le joueur a l'indice ind demande au
* joueur precedent le mot auquel il pense
* @param[in] mot : Chaine de caracteres en jeu
* @param[in] ind : Indice du joueur
* @param[out] statut : Booleen de fin de manche 
* @param[in-out] c : Conteneur de joueurs
* @pre Dictionnaire non vide
*/
void conteste(const Dictionnaire& dico, Conteneur& c, char* mot, const char* sauv, unsigned int& ind, bool& statut);

#endif