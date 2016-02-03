
# 3I010 - TP 02

_Sources fournies dans **[le dépôt](http://github.com/3201101/3I010/tree/master/Devoirs/02)**._


## Exercice 1

    $ ▶ time sleep 5
    
    real    0m5.003s
    user    0m0.000s
    sys 0m0.000s

On remarque que le processus a duré rééllement 5,003 secondes qui n'ont été occupés ni par le temps système ni par le temps utilisateur.

## Exercice 2

_Voir fichier **mytimes.c** ci-joint._

## Exercice 3

    $ ▶ ./mytimes "sleep 5" "sleep 10"
    Durée d'exécution = 5003316 µsec
    Durée d'exécution = 10003081 µsec

## Exercice 4

    $ ▶ ./mytimes "sleep 5" "sleep 10"
    # Statistiques de la commande ' sleep 5 '
        > Temps total réel :    5.00s
        > Temps utilisateur :   0.00s
        > Temps système :   0.00s
    
    # Statistiques de la commande ' sleep 10 '
        > Temps total réel :    10.00s
        > Temps utilisateur :   0.00s
        > Temps système :   0.00s

On obtient des résultats comparables à ceux de la question 1.1.

## Exercice 5

    $ ▶ ps -l
    F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
    0 S  1000  4207  4202  0  80   0 -  7603 wait   pts/0    00:00:00 bash
    0 S  1000  6257  4207  0  80   0 - 44610 wait   pts/0    00:00:01 fish
    0 R  1000 18270  6257  0  80   0 -  4306 -      pts/0    00:00:00 ps

On voit que la priorité du processus _ps_, indiqué dans la colonne PRI, est de 80.

    $ ▶ nice -19 ps -l
    F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
    0 S  1000  4207  4202  0  80   0 -  7603 wait   pts/0    00:00:00 bash
    0 S  1000  6257  4207  0  80   0 - 48709 wait   pts/0    00:00:01 fish
    0 R  1000 18622  6257  0  99  19 -  4306 -      pts/0    00:00:00 ps

On remarque que la valeur de priorité du processus _ps_ a augmenté de 19, passant à 99.

    $ ▶ ./mytimes "./boucle" "nice -19 ./boucle"
    Boucle  : 0
    Boucle  : 1
    Boucle  : 2
    Boucle  : 3
    Boucle  : 4
    Boucle  : 5
    Boucle  : 6
    Boucle  : 7
    Boucle  : 8
    Boucle  : 9
    # Statistiques de la commande ' ./boucle '
        > Temps total réel :    21.86s
        > Temps utilisateur :   0.05s
        > Temps système :   0.49s
    
    Boucle  : 0
    Boucle  : 1
    Boucle  : 2
    Boucle  : 3
    Boucle  : 4
    Boucle  : 5
    Boucle  : 6
    Boucle  : 7
    Boucle  : 8
    Boucle  : 9
    # Statistiques de la commande ' nice -19 ./boucle '
        > Temps total réel :    24.27s
        > Temps utilisateur :   0.03s
        > Temps système :   0.56s

_Voir fichier **boucle.c** ci-joint._

On remarque que le processus dont la priorité a été modifié s'exécute plus lentement.
