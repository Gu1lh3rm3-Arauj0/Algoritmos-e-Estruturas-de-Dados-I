#include<stdio.h>
#include <string.h>

int main (){
	char A[50], B[50];
  int qtd, mov, cont, tam;

  scanf("%i", &qtd);

	for(int j=0; j<qtd; j++){
	    scanf("%s", A);
        scanf("%i", &mov);
        cont=0;
        tam=strlen(A);
       // printf("%i\n", strlen(A));
        for(int k=0; k<50; k++){
            B[k]=0;
        }

    for(int i=0; i<tam; i++){
      if((A[i]-mov)>=65 && (A[i]-mov)<=90){
        B[cont]=A[i]-mov;
        cont++;
     }else{
        B[cont]=(A[i]-mov+26);
        cont++;
      }
    }
    printf("%s\n", B);
  }
	return 0;
}
