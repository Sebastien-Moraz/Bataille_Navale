/* --------------------------------------------------------
 * Nom : Bataille Navale
 * Auteur : Sébastien Moraz
 * Déscription : Le but est de jouer la bataille navale seul
 * Version : 1.0
 * --------------------------------------------------------
 */


#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//load des fonction
void Title();
void Aide();
void TempJeu();
void jeu();
void Menu();
void Start();
void Connexion();
void Inscription();
void AideStart();
void PrintScore();

FILE *Log = NULL;


char username[24];
char prenom[50];
char password[24];
int carte[10][10] = {0};

int main() {
    Log = fopen("log.txt", "a");
    fprintf(Log, "Ouverture du programme\n");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle("Bataille Navale");
    Start();
    fprintf(Log, "Fermeture du programme\n\n");
    fclose(Log);
    return 0;

}

void Start(){
    int choix = 0;
    fprintf(Log,"Ouverture du menu principal\n");
    do{
        system("cls");
        Title();
        printf("1 - Connexion\n");
        printf("2 - Inscription\n");
        printf("3 - Aide\n");
        printf("4 - Quitter\n\n");
        printf("Votre choix :");
        scanf("%d", &choix);
    } while (choix <1 || choix > 4);
    fprintf(Log,"Choix du menu principal : %d\n", choix);
    switch (choix){
        case 1:
            Connexion();
            break;
        case 2:
            Inscription();
            break;
        case 3:
            AideStart();
            break;
        case 4:
            system("exit");
        default:
            Start();
            break;
    }
}

void Connexion(){
    fprintf(Log,"Ouverture de la page de connexion\n");
    char val[24];
    system("cls");
    Title();
    printf("Veuillez entrer votre nom d'utilisateur :");
    scanf("%s",username);
    fprintf(Log,"Entrer du nom d'utilisateur : %s\n", username);
    FILE* fichier = NULL;
    fichier = fopen(username, "r+");

    if (fichier != NULL){
        fprintf(Log,"Fichier du l'utilisateur trouver\n");
        fscanf(fichier,"%s\n%s", prenom, password);
        fclose(fichier);

        while (strcmp(val, password)!= 0){
            printf("\nVeuillez entrer votre mot de passe :");
            scanf("%s", val);
            fprintf(Log,"Entrer du mot de passe : %s\n", password);
        }
        strcpy(val,"");
-        fprintf(Log,"Mot de passe valide\n");
        Menu();

    } else{
        printf("\nFichier non trouvé\n");
        system("pause");
        Start();
    }
}

void AideStart(){
    fprintf(Log,"Ouverture du de la page d'AideStart\n");
    system("cls");
    printf("\n\t ________");
    printf("\n\t|  AIDE  |");
    printf("\n\t|________|\n");
    printf("\n- La croix indique que vous avez touché un bateau");
    printf("\n- Le rond indique que vous avez loupé les bateaux");
    printf("\n\nIl y a en tout : \n 1 porte-avion (5 cases)\n 1 croiseur (4 cases)\n 2 contre-torpilleurs (3 cases)\n 1 torpilleur (2 cases)");
    printf("\n\n- Le but du jeu est de trouver tout les bateaux sur la carte\n  avec le moins de coup possible");
    printf("\n\n");
    system("pause");
    Start();
}

void Inscription(){
    fprintf(Log,"Ouverture de la page D'inscription\n");
    system("cls");
    Title();
    printf("Veuillez entrer un nom d'utilisateur :");
    scanf("%s", username);

    //----------Controle de l'utilisation du nom d'utilisateur---------
    FILE* controle = NULL;
    controle = fopen(username, "r+");
    if (controle != NULL) {
        printf("Ce nom d'utilisateur existe deja\n");
        fprintf(Log,"Nom d'utilisateur déja utilisé\n");
        system("pause");
        fclose(controle);
        Inscription();
    }
    //-----------------------------------------------------------------
    fprintf(Log,"Entrer du nom d'utilisateur: %s\n",username);
    system("cls");
    Title();
    printf("Veuillez entrer votre prénom :");
    scanf("%s",prenom);
    fprintf(Log,"Entrer du prenom : %s\n", prenom);
    system("cls");
    Title();
    printf("Veuillez entrer un mot de passe :");
    scanf("%s",password);
    fprintf(Log,"Entrer du mot de passe : %s\n", password);
    FILE *User = NULL;
    fprintf(Log,"Ouverture et creation du fichier de l'utilisateur\n");
    User = fopen(username, "w");
    fprintf(User,"%s\n", prenom);
    fprintf(Log,"Ecriture du prenom dans le fichier de l'utilisateur\n");
    fprintf(User, "%s\n", password);
    fprintf(Log,"Ecriture du mot de passe dans le fichier de l'utilisateur\n");
    fclose(User);
    fprintf(Log,"Fermeture du fichier de l'utilisateur\n");
    Start();
}


//-------------print de titre de page-------------
void Title(){
    fprintf(Log,"Affichage du titre\n");
    printf("---------------\n");
    printf("Bataille Navale\n");
    printf("---------------\n\n");
}
//------------------------------------------------

//-----------------print de l'aide----------------
void Aide(){
    fprintf(Log,"Affichage de l'aide du jeu\n");
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
    fprintf(Log,"Ouverture du menu de jeu\n");
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
    fprintf(Log,"Choix du menu principal : %d\n", choixMenu);
    switch (choixMenu){
        case 1:
            system("cls");
            TempJeu();
            break;
        case 2:
            PrintScore();
            break;
        case 3:
            fprintf(Log,"Reinitialisation des variable de l'utilisateur\n");
            strcpy(username,"");
            strcpy(password,"");
            strcpy(prenom,"");
            Start();
            break;
        case 4:
            fprintf(Log, "Fermeture du programme\n\n");
            system("exit");
            break;
        default:
            Menu();
    }
}


void jeu(){
    fprintf(Log,"Ouverture du jeu\n");
    char valide = 88;
    char louper = 79;
    int caseAvecBateau = 0;
    int choix = 0;
    int inc = 1;
    int compteur = 50;
    int win = 0;


    //boucle de jeu
    fprintf(Log,"Affichage de la grille du jeu\n");
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
        fprintf(Log,"Recherche des bateaux restant\n");
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
        fprintf(Log,"Valeur des coordonnée choisi : colonne = %d / ligne = %d\n",colonne,ligne);
        //------------------------------------------------

        //-----controle de si il y a un bateau ou non-----
        if (carte[ligne-1][colonne-1] == 1 || carte[ligne-1][colonne-1] == 9){
            compteur++;
        }

        if (carte[ligne-1][colonne-1] == 5 || carte[ligne-1][colonne-1] == 4 || carte[ligne-1][colonne-1] == 3 || carte[ligne-1][colonne-1] == 2 || carte[ligne-1][colonne-1] == 1 || carte[ligne-1][colonne-1] == 6){
            carte[ligne-1][colonne-1] = 1;
            fprintf(Log,"La case était un bateau\n");
        }else {
            carte[ligne-1][colonne-1] = 9;
        }
        //------------------------------------------------

        //-----controle si il y a encore des bateaux------
        fprintf(Log,"Controle des bateaux restant\n");
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
    fprintf(Log,"Fermeture du jeu\n");


    if (compteur != 0){
        FILE *Score = NULL;
        Score = fopen("Score", "a");
        fprintf(Score,"%s : %d points\n", username, compteur * 100);
        fprintf(Log, "Ecriture du score dans le fichier Score\n");
        fclose(Score);
    }


    //----recherche si vous avez gagnez ou perdu-----
    Title();
    if (compteur == 0){
        fprintf(Log,"partie perdu\n");
        printf("Vous avez perdu\n");
    }
    if (win == 1){
        fprintf(Log,"Partie gagné\n");
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
    fprintf(Log,"Choix de la fin de jeu : %d\n",choix);
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


void PrintScore(){
    fprintf(Log,"Ouverture du menu \"Score\"\n");
    system("cls");
    int text;
    printf(" _________\n");
    printf("|  Score  |\n");
    printf("|_________|\n\n");


    FILE *Score = NULL;
    Score = fopen("Score", "r");


    do {
        text = fgetc(Score);
        printf("%c",text);
    } while (text != EOF);
    printf("\n");
    system("pause");
    Menu();
}




void TempJeu(){
    fprintf(Log,"Ouverture du TempJeu\n");
    int aleatoir = 0;
    int carte1[10][10] = {
            {0,0,0,0,0,0,0,0,0,0},
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
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,2,2,0,0,0,5,0,0},
            {0,0,0,0,0,0,0,5,0,0},
            {0,0,0,0,0,0,0,5,0,0},
            {0,0,0,4,0,0,0,5,0,0},
            {0,0,0,4,0,0,0,5,0,0},
            {0,0,0,4,0,0,0,0,0,0},
            {0,0,0,4,0,0,0,6,6,6},
            {0,0,0,0,0,0,0,0,0,0},
            {0,3,3,3,0,0,0,0,0,0},
    };
    int carte3[10][10] = {
            {0,0,0,0,0,0,0,0,2,2},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,6,6,6,0,0},
            {3,0,0,0,0,0,0,0,0,0},
            {3,0,0,5,0,0,4,0,0,0},
            {3,0,0,5,0,0,4,0,0,0},
            {0,0,0,5,0,0,4,0,0,0},
            {0,0,0,5,0,0,4,0,0,0},
            {0,0,0,5,0,0,0,0,0,0},
    };
    int carte4[10][10] = {
            {0,6,0,0,5,5,5,5,5,0},
            {0,6,0,0,0,0,0,0,0,0},
            {0,6,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,2,2,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,4,4,4,4,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,3,3,3,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
    };
    int carte5[10][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,3,0,0,0,0,0,0},
            {0,0,0,3,0,0,0,0,0,0},
            {0,0,0,3,0,0,0,0,0,4},
            {2,2,0,0,0,0,0,0,0,4},
            {0,5,0,0,0,0,0,0,0,4},
            {0,5,0,0,0,0,0,0,0,4},
            {0,5,0,0,0,6,6,6,0,0},
            {0,5,0,0,0,0,0,0,0,0},
            {0,5,0,0,0,0,0,0,0,0},
    };
    int carte6[10][10] = {
            {0,0,0,0,0,0,2,0,0,0},
            {0,0,0,6,0,0,2,0,0,0},
            {0,5,0,6,0,0,0,0,0,0},
            {0,5,0,6,0,0,0,0,0,0},
            {0,5,0,0,0,0,0,0,0,0},
            {0,5,0,0,3,3,3,0,0,0},
            {0,5,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,4,4,4,4,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
    };
    int carte7[10][10] = {
            {0,0,4,4,4,4,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,2,2,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,6,6,6,0,0,0,0,0},
            {0,0,5,0,0,0,0,0,0,0},
            {0,0,5,0,0,0,0,0,0,0},
            {0,0,5,0,0,0,0,3,0,0},
            {0,0,5,0,0,0,0,3,0,0},
            {0,0,5,0,0,0,0,3,0,0},
    };
    int carte8[10][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,6,0,0},
            {0,0,0,2,2,0,0,6,0,0},
            {0,0,0,0,0,0,0,6,0,0},
            {0,4,4,4,4,0,0,0,0,0},
            {0,0,0,0,0,3,0,0,0,0},
            {0,0,0,0,0,3,0,0,0,0},
            {0,0,0,0,0,3,0,0,0,0},
            {5,5,5,5,5,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
    };
    int carte9[10][10] = {
            {6,0,0,0,0,0,0,0,0,0},
            {6,0,0,0,0,0,0,0,0,0},
            {6,0,0,5,5,5,5,5,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,2,2,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,4,0,0,0,0,0,3,0,0},
            {0,4,0,0,0,0,0,3,0,0},
            {0,4,0,0,0,0,0,3,0,0},
            {0,4,0,0,0,0,0,0,0,0},
    };
    int carte10[10][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,5,5,5,5,5,0},
            {0,0,4,0,0,0,0,0,0,0},
            {0,0,4,0,0,0,0,3,0,0},
            {0,0,4,0,0,0,0,3,0,0},
            {0,0,4,0,0,0,0,3,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,6,6,6,0,0,2,2},
            {0,0,0,0,0,0,0,0,0,0},
    };
    srand((unsigned) time (NULL) );
    aleatoir = 1 + rand() % 10;
    fprintf(Log,"Choix de la carte : %d\n", aleatoir);
    switch (aleatoir){
        case 1:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte1[i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte2[i][j];
                }
            }
            break;
        case 3:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte3[i][j];
                }
            }
            break;
        case 4:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte4[i][j];
                }
            }
            break;
        case 5:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte5[i][j];
                }
            }
            break;
        case 6:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte6[i][j];
                }
            }
            break;
        case 7:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte7[i][j];
                }
            }
            break;
        case 8:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte8[i][j];
                }
            }
            break;
        case 9:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte9[i][j];
                }
            }
            break;
        case 10:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    carte[i][j] = carte10[i][j];
                }
            }
            break;
        default:
            TempJeu();
            break;
    }
    fprintf(Log,"Reussit du transfère de la carte\n");
    jeu();

}