#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

typedef struct Voiture Voiture;
struct Voiture
{
    char modele[25];
    char matricule[25];
    char etat[25];

    int kilometrage;
};

typedef struct Groupe Groupe;
struct Groupe
{
    char membre[50];
};

void creer_parc_voiture();
void etat_parc_voiture();
void save();
void louer_voiture();
void retour_voiture();
void etat_voiture();
void Color(int t,int f);
void creer_membres();
void groupe2();



#endif // PROTOTYPES_H_INCLUDED
