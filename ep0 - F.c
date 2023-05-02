#include <stdio.h>

int main(){
    int i, j=0, tam, l;
    char A[50], B[50], C[]={'a', 'e', 'i', 'o', 'u'};

    scanf("%s", A);

    for(i=0; A[i]; i++){
        for(l=0; l<5; l++){
             if(A[i]==C[l]){
                 B[j] = A[i];
                 j++;
            }
        }
    }

    tam = strlen(B);

    for(i=0, j=tam-1; i < tam; i++, j--){
        if(B[i] != B[j]){
            printf("N\n");
            return 0;
        }
    }

    printf("S\n");
    return 0;
}
