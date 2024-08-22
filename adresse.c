
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *env = getenv("QUERY_STRING");

    if (env == NULL) {
        // Pas de variable QUERY_STRING définie
        printf("content-type: text/html\n\n");
        printf("<!DOCTYPE HTML>\n");
        printf("<HTML>\n");
        printf("<BODY>\n");
        printf("<BR> Erreur: QUERY_STRING non défini </BR>\n");
        printf("</BODY>\n");
        printf("</HTML>\n");
        return 1;
    }

    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    int pas_IP = 256;

    // Analyse de QUERY_STRING
    if (sscanf(env, "Donnes=%d.%d.%d.%d", &num1, &num2, &num3, &num4) != 4) {
        // Échec de l'analyse
        printf("content-type: text/html\n\n");
        printf("<!DOCTYPE HTML>\n");
        printf("<HTML>\n");
        printf("<BODY>\n");
        printf("<BR> Erreur: Format de l'adresse IP invalide </BR>\n");
        printf("</BODY>\n");
        printf("</HTML>\n");
        return 1;
    }

    // Vérification de la validité de l'adresse IP
    if (num1 >= pas_IP || num1 < 0 || num2 >= pas_IP || num2 < 0 || num3 >= pas_IP || num3 < 0 || num4 >= pas_IP || num4 < 0) {
        printf("content-type: text/html\n\n");
        printf("<!DOCTYPE HTML>\n");
        printf("<HTML>\n");
        printf("<BODY>\n");
        printf("<BR> Ce n'est pas une adresse IP valide </BR>\n");
        printf("</BODY>\n");
        printf("</HTML>\n");
    } else {
        printf("content-type: text/html\n\n");
        printf("<!DOCTYPE HTML>\n");
        printf("<HTML>\n");
        printf("<BODY>\n");
        printf("%d.%d.%d.%d</BR>\n", num1, num2, num3, num4);
        printf("<BR> C'est une adresse IP valide </BR>\n");

        // Détermination de la classe d'adresse IP
        if (num1 >= 1 && num1 <= 127) {
            printf("Cette adresse IP est de classe A</BR>\n");
        } else if (num1 >= 128 && num1 <= 191) {
            printf("Cette adresse IP est de classe B</BR>\n");
        } else if (num1 >= 192 && num1 <= 223) {
            printf("Cette adresse IP est de classe C</BR>\n");
        } else if (num1 >= 224 && num1 <= 239) {
            printf("Cette adresse IP est de classe D</BR>\n");
        } else if (num1 >= 240 && num1 <= 255) {
            printf("Cette adresse IP est de classe E</BR>\n");
        }

        printf("</BODY>\n");
        printf("</HTML>\n");
    }

    return 0;
}
