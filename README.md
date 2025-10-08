# Threads-Mutex

## Description
Petit projet d'exercice pour comprendre la synchronisation entre threads à l'aide de mutex et de sémaphores autour du scénario « Panoramix » (druide + villageois).

## Pré-requis
- macOS (ou Linux) avec `clang`/`gcc` et `make`
- Pthreads et sémaphores POSIX

Note macOS: les sémaphores POSIX non nommés ne fonctionnent pas sous macOS. Le projet utilise donc des sémaphores nommés.

## Compilation
```bash
make
```
Le binaire `panoramix` est généré à la racine du projet.

## Utilisation
```bash
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```

### Arguments
- `nb_villagers` : nombre de villageois (≤ limite de threads définie)
- `pot_size` : nombre de doses après un remplissage du chaudron
- `nb_fights` : combats à effectuer par villageois
- `nb_refills` : nombre de recharges que le druide peut encore faire

### Exemple
```bash
./panoramix 5 3 4 2
```

## Conception (résumé)
- Mutex pour protéger `loads` (doses de potion disponibles) lors des lectures/écritures.
- Sémaphore nommé pour réveiller le druide lorsqu'un villageois demande une recharge.
- Les villageois arrêtent quand ils n'ont plus de combats, ou quand il n'y a plus de doses et plus de recharges possibles.

## Nettoyage
```bash
make clean
```
Supprime les objets. Utilisez `make fclean` pour supprimer aussi le binaire.

## A rajouter
- Meilleure gestion de la mémoire en utilisant Free de partout pour libérer la mémoire
