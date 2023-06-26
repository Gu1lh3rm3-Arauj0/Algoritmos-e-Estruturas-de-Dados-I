#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 100
#define MAX_IDIOMA 21

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos > 0) {
        int pessoas;
        scanf("%d", &pessoas);

        char idiomas[MAX_PESSOAS][MAX_IDIOMA];
        int i;
        for (i = 0; i < pessoas; i++) {
            scanf("%s", idiomas[i]);
        }

        int j;
        int mesmoIdioma = 1;
        char idiomaApropriado[MAX_IDIOMA];
        strcpy(idiomaApropriado, idiomas[0]);

        for (i = 1; i < pessoas; i++) {
            if (strcmp(idiomas[i], idiomas[i - 1]) != 0) {
                mesmoIdioma = 0;
                break;
            }
        }

        if (mesmoIdioma) {
            printf("%s\n", idiomaApropriado);
        } else {
            printf("ingles\n");
        }

        casos--;
    }

    return 0;
}
