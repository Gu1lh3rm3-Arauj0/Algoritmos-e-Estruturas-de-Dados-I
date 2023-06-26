/* Guilherme Araújo Mendes de Souza - 156437
 * UNIFESP - ICT
 * AED I
 *
 * beecrowd | 2651
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char* palavra;
typedef unsigned char* texto;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char* palavra;
typedef unsigned char* texto;

int trivial(palavra a, int m, texto b, int n) {
    int k, r, ocorrs;
    ocorrs = 0;
    for (k = m - 1; k < n; k++) {
        r = 0;
        while (r < m && a[m - r - 1] == b[k - r]) {
            r += 1;
        }
        if (r >= m) {
            ocorrs += 1;
            break;
        }
    }
    return ocorrs;
}

int main() {

    char string[100000];
    char palavra1[] = "ZELDA";

    fgets(string, sizeof(string), stdin);

    for (int i = 0; i < strlen(string); i++) {
        string[i] = toupper(string[i]);
    }

    if (trivial(palavra1, 5, string, strlen(string)) >= 1) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }

    return 0;
}
