#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <malloc.h>
using namespace std;

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end; // объявляем переменные для определения времени выполнения

	start =  clock(); // старт таймера
	int i=0, j=0, r, n = 1000, m = 1000;
	int elem_c;
	int **a, **b, **c;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	
	a = (int**)malloc(n * sizeof(int*));
	while(i<n){
		a[i] = (int*)malloc(m * sizeof(int*));
		while(j<m){
			a[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i=0; j=0;

	b = (int**)malloc(n * sizeof(int*));
	while(i<n){
		b[i] = (int*)malloc(m * sizeof(int*));
		while(j<m){
			b[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	c = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++){
		c[i] = (int*)malloc(m * sizeof(int*));
		for (int j = 0; j < m; j++){
			c[i][j] = 0;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			elem_c=0;
			for(r=0;r<n;r++){
				elem_c=elem_c+a[i][r]*b[r][j];
				c[i][j]=elem_c;
				}
		}
	}
	
	for (int i = 0; i < n; i++){
		free(a[i]);
		free(b[i]);
		free(c[i]);
	}
	free(a);
	free(b);
	free(c);
	end = clock(); // остановка таймера
	float diff = (end - start) / 1000;
	cout << "Time in seconds = " << diff << endl; 

	system("pause");
	return(0);
}
