# SAE_Quart_de_Singe

Projet réalisé lors de ma première année de BUT Informatique

Règles du jeu :
-
Les joueurs se relaient pour ajouter une lettre à un mot en construction.  
Si un joueur ajoute une lettre qui forme un mot existant de plus de deux lettres, il perd la manche et reçoit un quart de singe.  
À tout moment, le joueur actif peut demander au joueur précédent à quel mot il pense.  
Si ce dernier est incapable de donner un mot valide correspondant aux lettres déjà posées, il perd la manche. Sinon, c’est le joueur qui a posé la question qui perd.  

Le premier joueur à accumuler **quatre quarts de singe** (donc un singe entier) perd la partie.

Exemple :
-
*J1 : A*  
Mot : "A"  
*J2 : A*  
Mot : "AA"  
*J1 : S*  
Le mot "AAS" existe, J1 prend un quart de singe  
J1 : 0.25, J2 : 0

*J1 : S*  
Mot : "S"  
*J2 : Q*  
Mot : "SQ"  
*J1 : U*  
Mot : "SQU"  
*J2 : ?*  
J1 doit saisir le mot auquel il pense  
*J1 : SQUAT*  
Le mot "SQUAT" existe, J2 prend un quart de singe  
J1 : 0.25, J2 : 0.25

En pratique :
-
L’idéal est de pouvoir lancer une partie même sans autre joueur humain.  
C’est pourquoi j’ai implémenté un **CPU capable de jouer au jeu**. Chaque joueur peut donc être un humain ou un robot.  

L’intelligence des robots est paramétrée pour qu’ils ne jouent pas de lettres aléatoires mais respectent les règles du jeu de manière compétitive.
L’objectif du projet était de rendre ces robots **aussi intelligents que possible**.

Comment jouent-ils ?
-
Les robots ne peuvent jouer que des caractères valides (lettres de l’alphabet ou "?").  
Ils suivent les règles du jeu, en utilisant un dictionnaire standardisé (mots en majuscules, sans accents) pour choisir des mots qui complètent la chaîne en cours.  
Même s’ils finissent par perdre, ils choisissent toujours une lettre qui peut théoriquement mener à un mot du dictionnaire.

Comment les rendre plus intelligents ?
-
Avec les outils à ma disposition et mon niveau en programmation, il m’était impossible de développer une vraie IA (type apprentissage par renforcement).

Cependant, j’ai conçu un système pour que le **robot gagne toujours contre un humain** en duel 1v1, en suivant ces règles :
- ne jamais compléter un mot existant (éviter de perdre immédiatement)
- ne pas poser une lettre qui permettrait à l’adversaire de compléter un mot au tour suivant
- Si aucune solution valable n’existe, le robot joue "?" pour provoquer une demande de mot

⚠️ Lors des parties uniquement composées de robots, on observe cependant une répétition des mêmes mots, selon le nombre de joueurs.

Conclusion :
-
Il s’agit de mon tout premier projet en C++, réalisé lors de ma première année de BUT Informatique.  
Il n’est évidemment pas exhaustif : j’ai uniquement utilisé un sous-ensemble des fonctionnalités du langage, conformément aux attentes pédagogiques.  
Mais je pense avoir pu acquérir beaucoup plus d'expérience individuelle et progresser notamment en développement et documentation.  
Il faut que je continue d'apprendre d'avantage sur ce langage et ses fonctionnalités que je n'ai pas pu utilisé.
