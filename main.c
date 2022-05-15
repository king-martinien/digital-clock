#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>


void show_date_and_time() {
    time_t t;
    struct tm *tm;
    char buffer[80];

    t = time(NULL);
    tm = localtime(&t);

    strftime(buffer, 80, "Heure: %H:%M:%S\t Date: %d/%m/%Y", tm);
// Afficher la date et l'heure
    printf("%s\n", buffer);

    sleep(1);

    system("clear");
}

void program_alarm() {

    // On récupère l'heure et les minutes et les secondes de l'alarme
    int heure, minutes, secondes;
    printf("Entrez l'heure: ");
    scanf("%d", &heure);
    printf("Entrez les minutes: ");
    scanf("%d", &minutes);
    printf("Entrez les secondes: ");
    scanf("%d", &secondes);

    // Lorsque le temps actuel est égal à l'heure, minutes et secondes entrés par l'utilisateur afficher une alerte
    while (1) {
        time_t t;
        struct tm *tm;
        char buffer[80];

        t = time(NULL);
        tm = localtime(&t);
        strftime(buffer, 80, "%H:%M:%S", tm);
        // On affiche l'heure et les minutes et les secondes de l'alarme
        printf("L'alarme est programée pour %d:%d:%d\tHeure actuelle : %s\n", heure, minutes, secondes, buffer);
//        printf("%s\n", buffer);
        sleep(1);
        system("clear");

        if (heure == tm->tm_hour && minutes == tm->tm_min && secondes == tm->tm_sec) {
            // Afficher le message Alerte
            printf("ALERTE\n");

            // Faire sonner un son dans un fichier wav situé dans le répertoire download
            system("aplay -q /home/king-martinien/Downloads/alarm.wav");

            break;
        }
    }

}

void chronometre() {
    int heure, minutes, secondes, heure_fin, minutes_fin, secondes_fin;
    heure = 0;
    minutes = 0;
    secondes = 0;

    // on récupère l'heure et les minutes et les secondes auwquels le chronomètre doit s'arrêter
    printf("Entrez l'heure: ");
    scanf("%d", &heure_fin);
    printf("Entrez les minutes: ");
    scanf("%d", &minutes_fin);
    printf("Entrez les secondes: ");
    scanf("%d", &secondes_fin);


    while (1) {
        system("clear");
        printf("%d:%d:%d\n", heure, minutes, secondes);

        // faire un sleep en flottant sur 0.5 secondes
        usleep(100000);

        secondes++;
        if (secondes == 60) {
            minutes++;
            secondes = 0;
        }

        if (minutes == 60) {
            heure++;
            minutes = 0;
        }

        if (heure == heure_fin && minutes == minutes_fin && secondes == secondes_fin) {
            // On affiche le temps qui s'est écoulé
            printf("Le chronomètre s'est arrêté à %d:%d:%d\n", heure, minutes, secondes);
            break;
        }

    }

}

void timer() {
    int heure, minutes, secondes;
    printf("Entrez l'heure: ");
    scanf("%d", &heure);
    printf("Entrez les minutes: ");
    scanf("%d", &minutes);
    printf("Entrez les secondes: ");
    scanf("%d", &secondes);

    while (1) {
        printf("%d:%d:%d\n", heure, minutes, secondes);
        if (heure == 0 && minutes == 0 && secondes == 0) {
            // Faire sonner un son
            printf("Timer Complete\n");
            system("aplay -q /home/king-martinien/Downloads/radar.wav");
            break;
        }
        usleep(100000);
        system("clear"); // On efface la console
        secondes--;
        if (secondes == -1) {
            minutes--;
            secondes = 59;
        }
        if (minutes == -1) {
            heure--;
            minutes = 59;
        }

    }
}

int main() {
    printf("\t*********************************************************************************************\n");
    printf("\t*                                      HORLOGE NUMERIQUE                                    *\n");
    printf("\t*********************************************************************************************\n\n");
    printf("\t                             Vueillez choisr l'action à effectuer                            \n\n");
    printf("\t*                                1 - Afficher l'heure actuelle                              *\n");
    printf("\t*                                2 - Programmer un alarme                                   *\n");
    printf("\t*                                3 - Lancer un chronomètre                                  *\n");
    printf("\t*                                4 - Lancer un minuteur                                     *\n");


    // Récuperer le choix de l'utilisateur
    int choice;
    scanf("%d", &choice);

    // Faire un switch sur le choix de l'utilisateur
    switch (choice) {
        case 1:
            printf("**************************\n");
            printf("       Heure Actuelle     \n");
            printf("**************************\n");
            while (1) {
                show_date_and_time(); // Appel de la fonction pour afficher l'heure
                system("clear"); // Effacer la console
            }
        case 2:
            printf("***********************************\n");
            printf("       Programmez votre Alarme     \n");
            printf("***********************************\n");

            program_alarm(); // Appel de la fonction pour programmer l'alarme
            break;
        case 3:
            printf("***********************************\n");
            printf("       Lancer un chronomètre       \n");
            printf("***********************************\n");

            printf("Appuyer sur une touche pour lancer le chronomètre\n");
            if (getchar()) {
                chronometre();
            }
            break;
        case 4:
            printf("***********************************\n");
            printf("         Lancer un minuteur        \n");
            printf("***********************************\n");

            timer();
            break;
        default:
            printf("Vous n'avez pas choisi une action valide\n");
            break;
    }

    return 0;
}
