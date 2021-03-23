//Program to perform Matrix Multiplication
// Aditya Mitra 20BCE2044
#include <stdio.h>
int main(){
	int m, n; 
	printf("Enter the number of rows \n");
	scanf("%d", &m);
	printf("Enter the number of columns \n");
	scanf("%d", &n);
	int arr1[m][n], arr2[m][n],mul[m][n];
	//To accept matrix 1
	printf("Enter the matrix elements\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &arr1[i][j]);
		}
	}
	//To accept matrix 2
	printf("Enter the matrix elements\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &arr2[i][j]);
		}
	}
	//To perform Multiplication
	printf("Multiplication of the matrix\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			mul[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				mul[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	//To print result
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("%d\t", mul[i][j]);
		}
		printf("\n");
	}
	return 0;
}

