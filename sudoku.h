/*
 * sudoku.h
 *
 *  Created on: 18 jul. 2019
 *      Author: arturol
 */

#ifndef SUDOKU_H_
#define SUDOKU_H_

int espacioVacio(int arr[9][9], int *columna, int *renglon){
	int i,j;
	for(i = 0; i < 9; i++)
		for(j = 0; j < 9; j++)
			if(arr[i][j] == 0){
				*renglon = i;
				*columna = j;
				return 1;
			}
	return 0;
}
int comprobacion(int arr[][9], int n, int columna, int renglon){
	int i, j;
	int iniciocolumna, iniciorenglon;
	iniciocolumna=(columna/3)*3;
	iniciorenglon=(renglon/3)*3;
	for(i = 0; i <  9; i++)
		if(arr[renglon][i] == n)
			return 0;
	for(i = 0; i <  9; i++)
			if(arr[i][columna] == n)
				return 0;
	for(i = iniciorenglon; i <  iniciorenglon+3; i++)
		for(j = iniciocolumna; j < iniciocolumna+3; j++)
			if(arr[i][j] == n)
				return 0;
	return 1;

}


void imprimirSudoku(int arr[][9]){
	int i, j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}
int backtrack(int arr[9][9], int * pcontador, int s){
	int  renglon;
	int  columna;
	int n;
	if(espacioVacio(arr, &columna, &renglon) == 0){

		(* pcontador)++;
	}
	if(espacioVacio(arr, &columna, &renglon) == 0&&(* pcontador)==s)
		imprimirSudoku(arr);

	for(n = 1; n <= 9; n++){
		if(comprobacion(arr, n, columna, renglon))
		{
			arr[renglon][columna] = n;
			if(backtrack(arr, pcontador,s))
				return 1;
			arr[renglon][columna] = 0;
		}
	}
	return 0;
}

#endif /* SUDOKU_H_ */
