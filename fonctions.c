#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
#include <windows.h> //Gère la couleur

static Voiture voiture[10];
static Groupe membres[8];

void creer_parc_voiture()
{
    strcpy(voiture[0].modele,"TOYOTA");
    fflush(stdin);
    strcpy((voiture[0].matricule),"AT1080");
    fflush(stdin);
    voiture[0].kilometrage=140;
    fflush(stdin);
    strcpy(voiture[0].etat,"Disponible");
    fflush(stdin);

    strcpy(voiture[1].modele,"NISSAN 2015");
    fflush(stdin);
    strcpy(voiture[1].matricule,"AA2080");
    fflush(stdin);
    voiture[1].kilometrage=156;
    fflush(stdin);
    strcpy(voiture[1].etat,"Disponible");
    fflush(stdin);

    strcpy(voiture[2].modele,"LAMBORGUINI NEW");
    fflush(stdin);
    strcpy(voiture[2].matricule,"DD3005");
    fflush(stdin);
    voiture[2].kilometrage=290;
    fflush(stdin);
    strcpy(voiture[2].etat,"Disponible");
    fflush(stdin);

    strcpy(voiture[3].modele,"HONDA 115");
    fflush(stdin);
    strcpy(voiture[3].matricule,"AA1232");
    fflush(stdin);
    voiture[3].kilometrage=270;
    fflush(stdin);
    strcpy(voiture[3].etat,"Disponible");
    fflush(stdin);

    strcpy(voiture[4].modele,"TOYOTA 4X4");
    fflush(stdin);
    strcpy(voiture[4].matricule,"RE1256");
    fflush(stdin);
    voiture[4].kilometrage=240;
    fflush(stdin);
    strcpy(voiture[4].etat,"Disponible");
    fflush(stdin);

    strcpy(voiture[5].modele,"MERCEDECE BENZ");
    fflush(stdin);
    strcpy(voiture[5].matricule,"MB3006");
    fflush(stdin);
    voiture[5].kilometrage=295;
    fflush(stdin);
    strcpy(voiture[5].etat,"Disponible");
    fflush(stdin);

    strcpy(voiture[6].modele,"COROLA 2019");
    fflush(stdin);
    strcpy(voiture[6].matricule,"CA2010");
    fflush(stdin);
    voiture[6].kilometrage=300;
    fflush(stdin);
    strcpy(voiture[6].etat,"En cours de location");
    fflush(stdin);

    strcpy(voiture[7].modele,"VENZA 110");
    fflush(stdin);
    strcpy(voiture[7].matricule,"VZ2001");
    fflush(stdin);
    voiture[7].kilometrage=310;
    fflush(stdin);
    strcpy(voiture[7].etat,"Disponible");
    fflush(stdin);

    strcpy(voiture[8].modele,"MAZDA 100");
    fflush(stdin);
    strcpy(voiture[8].matricule,"MZ1504");
    fflush(stdin);
    voiture[8].kilometrage=280;
    fflush(stdin);
    strcpy(voiture[8].etat,"Disponible");
    fflush(stdin);

    strcpy(voiture[9].modele,"PRADO 450");
    fflush(stdin);
    strcpy(voiture[9].matricule,"IB5000");
    fflush(stdin);
    voiture[9].kilometrage=330;
    fflush(stdin);
    strcpy(voiture[9].etat,"Disponible");
    fflush(stdin);

}

//ETAT DU PARC
void etat_parc_voiture()
{
    int i = 0, total = 0, nombre_L = 0, nombre_D = 0;
    int test1, test2;
    char etat_D[11]="Disponible";
    char etat_E[25]="En cours de location";


    for (i = 0; i<10; i++)
    {
        total = voiture[i].kilometrage + total;
    }
        Color(15,0);
        printf("\nNombre total de voitures: %d\n\n", i);

        printf("Liste des matricules des voitures en cours de location:\n");
        for(i=0; i<10; i++)
        {
            test2=strcmp(etat_E,voiture[i].etat);

            if (test2 == 0)
            {
                    nombre_L+=1;
                    printf("Matricule: %s\n", voiture[i].matricule);
            }
        }

        printf("\nNombre de voitures en cours de location: %d\n", nombre_L);
        printf("\nListe des matricules des voitures disponible:\n");
        for(i=0;i<10;i++)
        {
            test1=strcmp(etat_D,voiture[i].etat);

            if (test1 == 0)
            {
                nombre_D+=1;
                printf("Matricule: %s\n", voiture[i].matricule);
            }
        }
        printf("\nNombre de voitures disponible: %d\n", nombre_D);
        printf("\nLe kilometrage moyen de l'ensemble des voitures est: %d Km\n", total/i);



}

//ENREGSTRER L'ETAT DU PARC
void save()
{
    int total = 0, i, nombre_L = 0, nombre_D = 0;
    int test1, test2;
    char etat_D[11]="Disponible";
    char etat_E[25]="En cours de location";
    char nom_fichier[20];
    FILE *saveEtat = NULL;

    Color(15,0);
    printf("\nQuel nom souhaitez-vous utiliser pour sauvegarder l'etat du parc ? ");
    scanf("%s", nom_fichier);

    saveEtat = fopen(nom_fichier, "wb");

    if (saveEtat != NULL)
    {
        for (i = 0; i<10; i++)
        {
            total = voiture[i].kilometrage + total;
        }
        Color(15,0);
        fprintf(saveEtat, "\nNombre total de voitures: %d\n\n", i);

        fprintf(saveEtat, "Liste des matricules des voitures en cours de location:\n");
        for(i=0; i<10; i++)
        {
            test2=strcmp(etat_E,voiture[i].etat);

            if (test2 == 0)
            {
                    nombre_L+=1;
                    fprintf(saveEtat, "Matricule: %s\n", voiture[i].matricule);
            }
        }

        fprintf(saveEtat, "\nNombre de voitures en cours de location: %d\n", nombre_L);
        fprintf(saveEtat, "\nListe des matricules des voitures disponible:\n");
        for(i=0;i<10;i++)
        {
            test1=strcmp(etat_D,voiture[i].etat);

            if (test1 == 0)
            {
                nombre_D+=1;
                fprintf(saveEtat, "Matricule: %s\n", voiture[i].matricule);
            }
        }
        fprintf(saveEtat, "\nNombre de voitures disponible: %d\n", nombre_D);
        fprintf(saveEtat, "\nLe kilometrage moyen de l'ensemble des voitures est: %d Km\n", total/i);

        Color(10,0);
        printf("L'Etat du parc a bien ete sauvegarde.\n");

        fclose(saveEtat);
    }
}

//LOUER
void louer_voiture()
{
    int i,test,test1,test2;
    char matriculesaisi[20];
    char etat_D[11]="Disponible";
    char etat_E[25]="En cours de location";

    for(i=0;i<10;i++)
    {
            Color(15,0);
            printf("\n\t\tVOITURE %d\n", i+1);
            printf("\t\tModele: %s\n",voiture[i].modele);
            printf("\t\tMatricule: %s\n",voiture[i].matricule);
    }

    printf("\nEntrer le numero matricule de la voiture a louer: ");
    scanf("%s", matriculesaisi);
    printf("\n");

    for(i=0;i<10;i++)
    {
         test=strcmp(matriculesaisi,voiture[i].matricule);
         test1=strcmp(etat_D,voiture[i].etat);
         test2=strcmp(etat_E,voiture[i].etat);
         int menu;


        if(test==0 && test1==0)
        {
            printf("La voiture %s immatrculee %s est disponible. Voulez-vous la louer ? \nSi oui, choisissez '1' sinon '0' pour retourner au menu\n", voiture[i].modele, voiture[i].matricule);

            printf("\n1.LOUER\n");
            printf("0.RETOURNER AU MENU\n");

            printf("\n\n");

            do
            {
                printf("Votre choix: ");
                scanf("%d", &menu);

                switch(menu)
                {
                    case 0:
                        printf("\nMerci pour votre visite !!\n");
                        break;
                    case 1:
                        Color(10,0);
                        strcpy(voiture[i].etat, "En cours de location");
                        printf("\nBravo, vous venez de louer la voiture %s. Nous vous remercions\npour votre confiance.\n", voiture[i].modele);
                        break;
                 }
            } while (menu < 0 || menu > 1);
                    break;
           }
           else if(test==0 && test2==0)
           {
               Color(12,0);
               printf("\n\tDESOLE ! Cette voiture est deja en cours de location.\n\n");
               break;
           }
    }

    for(i=0;i<10;i++)
    {
        Color(12,0);
        if(test!=0)
        printf("\n\tDESOLE ! Cette voiture n'existe pas dans notre parc !!! Veuillez reesayez avec un matricule correct.\n\n");
        break;
    }

}

//RETOUR
void retour_voiture()
{
    int i,test,test1,test2, kilo = 0, menu;
    char matriculesaisi[20];
    char etat_D[15]="Disponible";
    char etat_E[25]="En cours de location";
    for(i=0;i<10;i++)
    {
            Color(15,0);
            printf("\n\t\tVOITURE %d\n", i+1);
            printf("\t\tModele: %s\n",voiture[i].modele);
            printf("\t\tMatricule: %s\n",voiture[i].matricule);
    }
    Color(15,0);
    printf("\nEntrer le numero matricule de la voiture a retourner: ");
    scanf("%s", matriculesaisi);
    printf("\n");

    for(i=0;i<10;i++)
    {
        test=strcmp(matriculesaisi, voiture[i].matricule);
        test1=strcmp(etat_D, voiture[i].etat);
        test2=strcmp(etat_E, voiture[i].etat);

        if(test==0 && test1==0)
        {
            Color(12,0);
            printf("\n\tDESOLE ! Cette voiture n'etait pas en cours de location.\n");
            break;
        }
        else if(test==0 && test2==0)
        {
            Color(15,0);
            printf("La voiture %s immatriculee %s est loue.\nVoulez-vous la retourner ?\nSi oui, choisissez '1' sinon '0' pour retourner au menu.\n", voiture[i].modele, voiture[i].matricule);
            printf("\n1.RETOUR\n");
            printf("0.RETOURNER AU MENU\n");

            printf("\n\n");

            do
            {
                Color(15,0);
                printf("Votre choix: ");
                scanf("%d", &menu);

                switch(menu)
                {
                    case 0:
                        printf("\nMerci pour votre visite !!\n");
                        break;
                    case 1:
                        printf("\nCombien de kilometres avez vous effectues avec la voiture: ");
                        scanf("%d",&kilo);
                        voiture[i].kilometrage += kilo;
                        strcpy(voiture[i].etat, "Disponible");
                        Color(10,0);
                        printf("\nMerci pour votre fidelite. Le retour de la voiture %s vient d'etre effectif.\n", voiture[i].modele);
                        break;
                 }
            } while (menu < 0 || menu > 1);
                    break;
        }
    }
    for(i=0;i<10;i++)
    {
        Color(12,0);
        if(test!=0)
        printf("\n\tDESOLE ! Cette voiture n'existe pas dans notre parc !!! Veuillez reesayez avec un matricule correct\n");
        break;
    }

}

//ETAT
void etat_voiture()
{
    int i,test;
    char matriculesaisi[20];

    Color(15,0);
    printf("\nEntrer le numero matricule de la voiture dont vous voulez connaitre l'etat: ");
    scanf("%s", matriculesaisi);
    printf("\n");

    for(i=0;i<10;i++)
    {
        test=strcmp(matriculesaisi,voiture[i].matricule);

        if(test==0)
        {
            printf("\n\t\tModele: %s\n",voiture[i].modele);
            printf("\n\t\tMatricule: %s\n",voiture[i].matricule);
            printf("\n\t\tKilometrage: %d Km\n",voiture[i].kilometrage);
            printf("\n\t\tEtat : %s\n",voiture[i].etat);
            break;
        }
    }
    for(i=0;i<10;i++)
    {
        Color(12,0);
        if(test!=0)
        printf("\nDESOLE ! Cette voiture n'existe pas dans notre parc !!! Veuillez reesayez avec un matricule correct.\n");
        break;
    }
}

//GOUPE 2
void creer_membres()
{
    strcpy(membres[0].membre, "Mariano GBEGO");
    fflush(stdin);
    strcpy(membres[1].membre, "Audrey EDOH");
    fflush(stdin);
    strcpy(membres[2].membre, "Isaac GOUNTON");
    fflush(stdin);
    strcpy(membres[3].membre, "Pascal CHANGOYOMI");
    fflush(stdin);
    strcpy(membres[4].membre, "Joris AWOUI");
    fflush(stdin);
    strcpy(membres[5].membre, "Richard HOUNMONTO");
    fflush(stdin);
    strcpy(membres[6].membre, "Auxil HOUESSOU");
    fflush(stdin);
    strcpy(membres[7].membre, "Igor AKPATA");
    fflush(stdin);
}

void groupe2()
{
    int i;

    Color(14,0);
    printf("                            CERCO IA              \n");
    printf("Ce programme a ete ecris par la TEAM 2 composee comme suit:\n\n");

    Color(15,0);
    for (i = 0; i<8; i++)
    {
        printf("%s\n", membres[i].membre);
    }
}

//Pour définir une couleur de texte et une couleur de fond du texte.
void Color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H,f*16+t);
}

/**
0 : Noir
1 : Bleu foncé
2 : Vert foncé
3 : Turquoise
4 : Rouge foncé
5 : Violet
6 : Vert caca d'oie
7 : Gris clair
8 : Gris foncé
9 : Bleu fluo
10 : Vert fluo
11 : Turquoise
12 : Rouge fluo
13 : Violet 2
14 : Jaune
15 : Blanc
**/
