#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {

    // Afficher l'heure et la date actuelle sous le format: "Heure:Minutes:Secondes:Jour/Mois/Année" après cahque seconde
    time_t t;
    struct tm *tm;
    char buffer[80];
    int i = 0;

    while (1) {
        t = time(NULL);
        tm = localtime(&t);
        strftime(buffer, 80, "%H:%M:%S:%d/%m/%Y", tm);
        printf("%s\n", buffer);
        sleep(1);
    }

    return 0;
}