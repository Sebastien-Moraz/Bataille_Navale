/* --------------------------------------------------------
 * Nom : Bataille Navale
 * Déscription : Le but est de jouer la bataille navale seul
 * Version : 0.1
 * --------------------------------------------------------
 */


#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//load des fonction
void Title();
void Aide();
void TempJeu();
void jeu();
void Menu();


int carte[10][10] = {0};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle("Bataille Navale");
    //declaration des variables
    Menu();
    return 0;

}

//-------------print de titre de page-------------
void Title(){
    printf("---------------\n");
    printf("Bataille Navale\n");
    printf("---------------\n\n");
}
//------------------------------------------------

//-----------------print de l'aide----------------
void Aide(){
    printf("\n\t ________");
    printf("\n\t|  AIDE  |");
    printf("\n\t|________|\n");
    printf("\n- La croix indique que vous avez touché un bateau");
    printf("\n- Le rond indique que vous avez loupé les bateaux");
    printf("\n\nIl y a en tout : \n 1 porte-avion (5 cases)\n 1 croiseur (4 cases)\n 2 contre-torpilleurs (3 cases)\n 1 torpilleur (2 cases)");
    printf("\n\n- Le but du jeu est de trouver tout les bateaux sur la carte\n  avec le moins de coup possible");
    printf("\n\n");
}
//------------------------------------------------



void Menu(){
    int choixMenu = 0;
    int temp = 0;
    system("cls");
    Title();
    printf("__________________________________\n");
    printf("| 1 - Jouer a la bataille navale |\n");
    printf("| 2 - Afficher le score          |\n");
    printf("| 3 - Se déconnecter             |\n");
    printf("| 4 - Quitter                    |\n");
    printf("|________________________________|\n\n");
    printf("Votre choix :");
    scanf("%d", &choixMenu);
    do{ //source : https://openclassrooms.com/forum/sujet/vider-le-buffer-de-scanf-90403
        temp = getchar();
    } while (temp != EOF && temp != '\n');
    switch (choixMenu){
        case 1:
            TempJeu();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            Menu();
    }
}


void jeu(){
    char valide = 88;
    char louper = 79;
    int caseAvecBateau = 0;
    int choix = 0;
    int inc = 1;
    int compteur = 50;
    int win = 0;


    //boucle de jeu
    do{
        inc = 1;
        int colonne = 0;
        int ligne = 0;
        Title();

        //--------------print du tableau----------------
        printf("    1   2   3   4   5   6   7   8   9   10  Colonne\n");
        printf("   ");
        for (int i = 0; i < 41; ++i) {
            printf("-");
        }
        printf("\n");
        for (int ligne = 0; ligne < 10; ++ligne) {
            printf("%2d ",inc);
            for (int colonne = 0; colonne < 10; ++colonne) {
                if(carte[ligne][colonne] == 1){
                    printf("| %c ",valide);
                } else if (carte[ligne][colonne] == 9){
                    printf("| %c ",louper);
                }else{
                    printf("|   ");
                }

            }
            printf("|\n");
            printf("   ");
            for (int i = 0; i < 41; ++i) {
                printf("-");
            }
            inc++;
            printf("\n");
        }
        //------------------------------------------------

        //-------------declaration des bateaux-------------
        int porteAvions = 0;
        int croiseur = 0;
        int contreTorpilleurs1 = 0;
        int contreTorpilleurs2 = 0;
        int totalContreTorpilleurs = 0;
        int torpilleur = 0;

        for (int k = 0; k < 10; ++k) {
            for (int i = 0; i < 10; ++i) {
                if (carte[k][i] == 5){
                    porteAvions++;
                } else if (carte[k][i] == 4){
                    croiseur++;
                } else if (carte[k][i] == 3){
                    contreTorpilleurs1++;
                } else if (carte[k][i] == 2){
                    torpilleur++;
                } else if (carte[k][i] == 6){
                    contreTorpilleurs2++;
                }
            }
        }
        if (porteAvions != 0){
            porteAvions = 1;
        }
        if (croiseur != 0){
            croiseur = 1;
        }
        if (contreTorpilleurs1 != 0){
            totalContreTorpilleurs++;
        }
        if (contreTorpilleurs2 != 0){
            totalContreTorpilleurs++;
        }
        if (torpilleur != 0){
            torpilleur = 1;
        }
        printf("Ligne\n\nCompteur : %d\tPorte-avions : %d\tCroiseur : %d\tContre-torpilleurs : %d\tTorpilleur : %d\n\n", compteur, porteAvions, croiseur, totalContreTorpilleurs, torpilleur);
        //------------------------------------------------

        //---------------demande des valeurs--------------
        do{
            printf("Veuillez entrer une colonne (11 - aide) :");
            scanf("%d", &colonne);
            int temp;
            do{ //source : https://openclassrooms.com/forum/sujet/vider-le-buffer-de-scanf-90403
                temp = getchar();
            } while (temp != EOF && temp != '\n');
            if (colonne == 11){
                Aide();
            }
        }while (colonne <=0 || colonne >= 11);


        do{
            printf("Veuillez entrer une ligne (11 - aide) :");
            scanf("%d", &ligne);
            int temp;
            do{ //source : https://openclassrooms.com/forum/sujet/vider-le-buffer-de-scanf-90403
                temp = getchar();
            } while (temp != EOF && temp != '\n');

            if (ligne == 11){
                Aide();
            }
        }while (ligne<=0 || ligne >= 11);
        //------------------------------------------------

        //-----controle de si il y a un bateau ou non-----
        if (carte[ligne-1][colonne-1] == 1 || carte[ligne-1][colonne-1] == 9){
            compteur++;
        }

        if (carte[ligne-1][colonne-1] == 5 || carte[ligne-1][colonne-1] == 4 || carte[ligne-1][colonne-1] == 3 || carte[ligne-1][colonne-1] == 2 || carte[ligne-1][colonne-1] == 1 || carte[ligne-1][colonne-1] == 6){
            carte[ligne-1][colonne-1] = 1;
        }else {
            carte[ligne-1][colonne-1] = 9;
        }
        //------------------------------------------------

        //-----controle si il y a encore des bateaux------
        caseAvecBateau = 0;
        for (int j = 0; j < 10; ++j) {
            for (int i = 0; i < 10; ++i) {
                if (carte[j][i] == 2 || carte[j][i] == 3 || carte[j][i] == 4 || carte[j][i] == 5 || carte[j][i] == 6){
                    caseAvecBateau++;
                }
            }
        }
        if (caseAvecBateau == 0){
            win = 1;
        }
        //------------------------------------------------
        compteur--;
        system("cls");
    }while (compteur > 0 && win == 0); // fin de la boucle de jeu

    //----recherche si vous avez gagnez ou perdu-----
    Title();
    if (compteur == 0){
        printf("Vous avez perdu\n");
    }
    if (win == 1){
        printf("Vous avez gagné !!\n");
    }
    //------------------------------------------------

    //--demande si oui ou non il faut reexecuter le programme--
    printf("Voulez vous rejouer ? \n");
    printf("1 - oui");
    printf("\n2 - non");
    do{
        printf("\nVotre choix :");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 2);
    switch (choix) {
        case 1:
            system("cls");
            TempJeu();
            break;
        case 2:
            Menu();
    }
    //------------------------------------------------

    Menu();//si jamais
}

void TempJeu(){
    int aleatoir = 0;
    int carte1[10][10] = {
        {1,0,0,0,0,0,0,0,0,0},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int carte2[10][10] = {
        {0,1,0,0,0,0,0,0,0,0},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int carte3[10][10] = {
        {0,0,1,0,0,0,0,0,0,0},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int carte4[10][10] = {
        {0,0,0,1,0,0,0,0,0,0},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int carte5[10][10] = {
        {0,0,0,0,1,0,0,0,0,0},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int carte6[10][10] = {
        {0,0,0,0,0,1,0,0,0,0},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int carte7[10][10] = {
        {0,0,0,0,0,0,1,0,0,0},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int carte8[10][10] = {
        {0,0,0,0,0,0,0,1,0,0},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int carte9[10][10] = {
        {0,0,0,0,0,0,0,0,1,0},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    int carte10[10][10] = {
        {0,0,0,0,0,0,0,0,0,1},
        {0,5,5,5,5,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,3,3,3,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,0,0,0,2,0},
        {0,0,0,6,6,6,0,0,2,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    srand((unsigned) time (NULL) );
    aleatoir = 1 + rand() % 10;

    switch (aleatoir){
        case 1:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte1[i][j];
                }
            }
            jeu();
            break;
        case 2:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte2[i][j];
                }
            }
            jeu();
            break;
        case 3:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte3[i][j];
                }
            }
            jeu();
            break;
        case 4:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte4[i][j];
                }
            }
            jeu();
            break;
        case 5:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte5[i][j];
                }
            }
            jeu();
            break;
        case 6:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte6[i][j];
                }
            }
            jeu();
            break;
        case 7:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte7[i][j];
                }
            }
            jeu();
            break;
        case 8:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte8[i][j];
                }
            }
            jeu();
            break;
        case 9:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte9[i][j];
                }
            }
            jeu();
            break;
        case 10:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte10[i][j];
                }
            }
            jeu();
            break;
        default:
            TempJeu();

    }

}