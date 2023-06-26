/* Guilherme Araújo Mendes de Souza - 156437
 * AED 1
 * UNIFESP - ICT
 *
 * Beecrowd - 1257
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0, l = 0;
	char frase[50];
	int result = 0;

	scanf("%d", &n);

	while(n){
		scanf("%d", &l);
		for(int k = 0; k < l; k++){
			scanf("%s", frase);

			for(int i = 0; i < strlen(frase); i++){
				result = result + (frase[i] - 65) + k + i;
			}

		}
		printf("%d\n", result);
		n--;
		result = 0;
	}

    return 0;
}
