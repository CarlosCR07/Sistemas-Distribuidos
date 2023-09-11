#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double* wcTime){
	struct timeval tp;
	gettimeofday(&tp,NULL);
	*wcTime=(tp.tv_sec + tp.tv_usec/1000000.0);
}

int main(int argc, char* argv[]){
	int i, j, n=3; //Valor de n indicará tamaño de nxn en matrices
	int **matrizA;
	int **matrizB;
	int **matrizC;
	double S1, E1;

	//Inicializando matrices
	matrizA = (int **)malloc(n*sizeof( int *));
	matrizB = (int **)malloc(n*sizeof( int *));
	matrizC = (int **)malloc(n*sizeof( int *));
	for(i=0;i<n;i++){
		*(matrizA+i) = (int *)malloc(n*sizeof(int));
		*(matrizB+i) = (int *)malloc(n*sizeof(int));
		*(matrizC+i) = (int *)malloc(n*sizeof(int));
	}

	//Llenando matrices
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrizA[i][j] = rand() % 6;
			matrizB[i][j] = rand() % 6;
		}
	}

	get_walltime(&S1);

	for (int k = 0; k < n; ++k)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
	get_walltime(&E1);

	printf("Tiempo metodo kji: %f s\n",(E1-S1));
	return 0;
}
	