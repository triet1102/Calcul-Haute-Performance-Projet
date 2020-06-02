# Calcul-Haute-Performance-Projet

### Projet description:
Utiliser openmp pour les calculs parallèles.

Étant donné un fichier dict.txt contient des mots clairs et le fichier shadow.txt contient des mots de passe hachés,
vérifier combien de mots en dict.txt sont en shadow.txt

### Fichiers inclus:

**dict.txt** : contient des mots clairs dans un dictionnaire

**dict_hashed.txt** : contient des mots hachés du dict.txt

**shadow.txt** : contient des mots de passe hachés

**shadowSmall.txt** : une petite version de shadow.txt

**my_sha_dict_generator.c** : à partir de dict.txt, créer dict_hash.txt

**my_sha_shadow_generator.c** : étant donné un fichier contient des mots clairs (par example dict.txt), hasher n mots aléatoires et mettre dans un autre fichier (par example shadowSmall.txt)

**multiattack.c** : en utilisant **fork()**, vérifier combien de mots en dict_hashed.txt (dict.txt haché) sont en shadow.txt (ou en shadowSmall.txt) 

**openmp_parallel.c** : en utilisant **openmp**, vérifier combien de mots en dict_hashed.txt (dict.txt haché) sont en shadow.txt (ou en shadowSmall.txt) 

### Compiler
**gcc -o my_sha_dict_generator my_sha_dict_generator.c -lssl -lcrypto** : compiler my_sha_dict_generator.c

**gcc -o my_sha_shadow_generator my_sha_shadow_generator.c -lssl -lcrypto** : compiler my_sha_shadow_generator.c

**gcc -o multiattack multiattack.c** : compiler multiattack.c

**gcc -fopenmp -o openmp openmp_parallel.c** : compiler openmp_parallel.c

### Syntax


**./my_sha_dict_generator dict_file dict_file_hashed.txt** : hasher dict.txt et mettre dans dict_hashed.txt
(./my_sha_dict_generator dict.txt dict_hashed.txt)

**./my_sha_shadow_generator dict_file shasum_file nombre_de_mot** : hasher nombre_de_mot mots aléatoires
(./my_sha_shadow_generator dict.txt shadowSmall.txt 30)

**./multiattack nombre_processus dict_file_hashed shasum_file** : utiliser nombre_processus processus pour les calculs parallèles (nombre_processus est le nombre de processus fils quand on utilise fork() )

(./multiattack 4 dict_hashed.txt shadow.txt)

**./openmp nombre_thread dict_file_hashed shasum_file** :  utiliser nombre_thread threads pour les calculs parallèles.
(./openmp 8 dich_hashed.txt shadow.txt)

### Note pour fichier openmp_parallel.c
Dans le boucle **for (i=0; i<3000; ++i)**
Le numéro 3000 dans ce cas est le nombre de ligne dans le fichier shadow.txt, si on veut tester sur un autre fichier, il faut juste remplacer le numéro 3000 par le nombre de ligne dans le shasum_file qu'on veut utiliser.

## Le travail est décrit plus en détail dans le rapport













