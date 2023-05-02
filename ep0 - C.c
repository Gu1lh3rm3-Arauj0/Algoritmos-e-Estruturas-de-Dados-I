#include <stdio.h>
#include <math.h>

int main(){
	double A, B, C;
	double R1, R2, Delta;

	scanf("%lf %lf %lf", &A, &B, &C);

	Delta = (B*B)-4*A*C;
	R1 = (-B + sqrt(Delta))/(2*A);
	R2 = (-B - sqrt(Delta))/(2*A);

	if( (Delta < 0) || (A == 0)){
		printf("Impossivel calcular\n");
	}else{
		printf("R1 = %.5lf\n", R1);
		printf("R2 = %.5lf\n", R2);
	}

    return 0;
}
