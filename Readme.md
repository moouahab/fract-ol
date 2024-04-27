
# Cub3D

## Introduction
Ce projet est inspiré de Wolfenstein 3D et implémente une technique de ray-casting pour créer une vue dynamique à la première personne au sein d'un labyrinthe.

## 1. Prérequis et Configuration de l'Environnement
- **Installer les outils** : Assurez-vous que GCC et minilibX sont installés sur votre système.
- **Organisation du projet** : Créez des répertoires pour les fichiers sources (`src`), les en-têtes (`include`), et les ressources (`assets`).

## 2. Initialisation et Gestion de la Fenêtre Graphique
- **Initialiser minilibX** pour créer et gérer une fenêtre graphique.
- **Implémenter la gestion des événements** pour les interactions clavier et souris.

## 3. Parsing de la Carte
- **Format de fichier .cub** : Développez un parser pour lire les fichiers décrivant les murs et les espaces libres.
- **Stockage des données** : Utilisez des structures adaptées pour conserver les informations de la carte.

## 4. Ray-Casting
- **Lancer des rayons** pour simuler une vue 3D à partir de la position du joueur.
- **Calculer les collisions** pour déterminer les distances aux obstacles.

## 5. Rendu Graphique
- **Dessiner les murs** en utilisant les distances obtenues par le ray-casting.
- **Ajuster la perspective** pour éviter l'effet fisheye.

## 6. Textures et Optimisations
- **Appliquer des textures** aux murs selon leur orientation (Nord, Sud, Est, Ouest).
- **Optimiser le rendu** pour améliorer la fluidité du jeu.

## 7. Contrôles et Interactivité
- **Gérer les mouvements et rotations** du joueur avec les touches WASD et les flèches.
- **Implémenter la fermeture propre** du programme via la touche ESC et la croix de la fenêtre.

## 8. Debugging et Finitions
- **Déboguer le**
