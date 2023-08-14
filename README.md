# SAE_Quart_de_Singe

Règles du jeu :
-
Les joueurs se relaient pour ajouter une lettre à un mot.
Si un joueur ajoute une lettre qui termine un mot existant de plus de deux lettres, il perd la manche et reçoit un quart de singe.
Le joueur actuel peut demander au joueur précédent à quel mot il pense.  
Si le joueur précédent ne peut pas fournir un mot existant qui convient aux lettres déjà annoncées, il perd la manche. Sinon, le joueur qui a posé la question perd la manche. 
Le premier joueur à collecter quatre quarts de singe perd le jeu.

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
L'idéal est de pouvoir lancer une partie même si l'on a personne avec qui jouer.
C'est pourquoi j'ai implémenté un cpu capable de jouer au jeu. Ainsi les joueurs peuvent etre soit un humain soit un robot.
Il faut également paramétrer l'intelligence de ces robots pour qu'ils soient compétitifs et ne répondent pas avec des lettres aléatoires.
Pour ce projet, les consignes étaient de rendre les robots les plus intelligents possible.

Comment jouent-ils ?
-
Pour commencer, les robots ne peuvent que jouer des caractères valables (alphabet et "?").
On les paramètre ensuite pour qu'ils puissent jouer selon les règles du jeu.
Ils ont aussi accès au dictionnaire contenant une liste de mots standardisée (tout en majuscule et sans accent).
Grace à cela, les robots choississent un mot du dictionnaire pouvant compléter le mot en jeu, même si ils perdent, ils jouent les caractères.

Comment rendre les robots plus intelligent ?
-

Avec les outils à ma disposition et mon niveau en programmation, il était impossible pour moi de développer une IA (apprentissage par renforcement).
J'ai donc fait en sorte qu'un robot puisse toujours gagner contre un humain en partie 1v1.
Pour cela, il s'adapte pour toujours trouver un mot valable du dictionnaire pouvant compléter le mot en jeu, tout en évitant de perdre :
- la lettre qui va etre jouer ne doit pas compléter un mot du dictionnaire
- le mot ne doit pouvoir etre jouer contre soi au prochain tour
- si aucun mot valable n'est trouvé alors le robot joue "?"

Cependant dans des parties avec seulement des robots, on se retrouve à voir un pattern de mêmes mots qui se répète selon le nombre de joueurs.

Conclusion :
-
C'est mon premier projet en langage C++ qui n'est évidemment pas complet car j'ai seulement utilisé quelques outils du langage, à la demande des enseignants.
Mais je pense avoir pu acquérir beaucoup plus d'expérience individuelle et progresser notamment en développement et documentation.
Il faut maintenant que je continue d'apprendre d'avantage sur ce langage et ses fonctionnalités que je n'ai pas pu utilisé.
