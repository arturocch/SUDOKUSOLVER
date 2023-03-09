
#include <stdio.h>
#include "sudoku.h"
int main(void) {
	setbuf(stdout,0);
	int contador = 0;
	int s = 1,i,j;
	int sumaTotal, semiSuma=1;
	int numeros[100]={0};
	numeros[1]=1;
	int arr[9][9];

	FILE * f = fopen("sudoku.txt","r");
	if(f == 0)
		printf("No se puedo abrir el archiuvo.\n");
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
			arr[i][j] = fgetc(f) -'0';
		fgetc(f);
	}
	fclose(f);

	backtrack(arr, &contador, s);
	sumaTotal=(contador*(contador+1))/2;
	if(contador>1&&s!=0)
		while(contador>1&&s!=0)
		{
			printf("\neste sudoku tiene %d soluciones, la unica mostrada es la numero %d, quieres ver otra? escribe el numero de solucion que quieres ver o 0 en caso de no querer ver otra.\n",contador,s);
			scanf("%d",&s);
			if(s!=0){
				contador=0;
				backtrack(arr, &contador, s);
				if(numeros[s]==0){
					numeros[s]=1;
					semiSuma+=s;
				}
			}
			if(semiSuma == sumaTotal){
				printf("ya imprimiste todos los sudokus, ayosh");
				break;
			}
		}
	else if(contador==1)
		printf("\neste sudoku solo tiene una solucion\n");
	else
		printf("\neste sudoku no tiene solucion\n");
	getchar();
	return 0;
}
