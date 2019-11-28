#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
#include <windows.h> //Gère la couleur


int main()
{
    creer_parc_voiture();
    creer_membres();

    int choix;
    do
    {              //Le caractere \xDB correspond au caractere ASCII numero 219 qui est un bete carre notr
        Color(11,0);
        printf("\n\n             \xDB|--------------- ####### MENU DU PARC #######----------------|\xDB\n             \xDB                                                              \xDB\n             \xDB                                                              \xDB");
        printf("\n             \xDB|                  1:LOUER UNE VOITURE                       |\xDB\n             \xDB                                                              \xDB");
        printf("\n             \xDB|                  2:RETOURNER UNE VOITURE                   |\xDB\n             \xDB                                                              \xDB");
        printf("\n             \xDB|                  3:ETAT D'UNE VOITURE                      |\xDB\n             \xDB                                                              \xDB");
        printf("\n             \xDB|                  4:ETAT DU PARC DE VOITURE                 |\xDB\n             \xDB                                                              \xDB");
        printf("\n             \xDB|                  5:SAUVEGARDER L'ETAT DU PARC              |\xDB\n             \xDB                                                              \xDB");
        printf("\n             \xDB|_________________ 0:FIN DU PROGRAMME      __________________|\xDB\n\n");
        printf("\n\n                     Entrez votre choix : ");
        scanf("%d", &choix);

     switch(choix)
      {
         case 1: system("cls");
         printf("\n                  **LOUER UNE VOITURE**");
         louer_voiture();
         break;
         case 2: system("cls");
         printf("\n                   **RETOURNER UNE VOITURE**");
         retour_voiture();
         break;
         case 3: system("cls");
         printf("\n                   **ETAT D'UNE VOITURE**");
         etat_voiture();
         break;
         case 4: system("cls");
         printf("\n                   **ETAT DU PARC DE VOITURE**");
         etat_parc_voiture();
         break;
         case 5: system("cls");
         printf("\n                   **SAUVEGARDER L'ETAT DU PARC**");
         save();
         break;
         case 0: system("cls");
         printf("\n                   **FIN DU PROGRAMME**\n");
         groupe2();
         break;
         default: system("cls");
         Color(12,0);
         printf("\n              ERREUR!! Choississez 1 ou 2 ou 3 ou 4 ou 5 ou 0: ");
      }
    } while(choix != 0);

    return 0;
}
