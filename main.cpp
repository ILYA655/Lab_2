#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <malloc.h>
using namespace std;

int mltp(){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end; // объявляем переменные для определения времени выполнения

	start =  clock(); // старт таймера
	int i=0, j=0, r, n = 100, m = 100;
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
	cout << "Time in ms = " << diff << endl;
	system("pause");
	return(0);
}

void shell(int items[], int count){
	int i, j, gap, k;
	int x, a[5];
	a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;
	for(k=0; k < 5; k++) {
		gap = a[k];
		for(i=gap; i < count; ++i) {
			x = items[i];
			for(j=i-gap; (x < items[j]) && (j > 0); j=j-gap)
				items[j+gap] = items[j];
				items[j+gap] = x;
		}
	}
}

void qs(int items[], int left, int right){ //вызов функции: qs(items, 0, count-1);
	int i, j;
	int x, y;

	i = left; j = right;
	/* выбор компаранда */
	x = items[(left+right)/2];
	do {
		while((items[i] < x) && (i < right)) i++;
		while((x < items[j]) &&(j > left)) j--;
		if(i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
		i++; j--;
		}
	} while(i <= j);
	if(left < j) qs(items, left, j);
	if(i < right) qs(items, i, right);
}

int compare(const void *x1, const void *x2){
	return ( *(int*)x1 - *(int*)x2 );
}

int main(){
	setlocale(LC_ALL, "Russian");
	clock_t start, end;
	mltp();
	int count;
	ofstream fout;
	fout.open("cppstudio.txt");
	cout << "Введите размер: \n";
	
	cin >> count;
	fout << "	shell	qs	qsort\n";
	fout << "/" << "\n";
	fout << "\\" << "\n";
	fout << "^" << "\n";
	fout.close();
	int *items;
	items = (int*)malloc(count * sizeof(int));
	for(int i = 0; i < count; i++){
		items[i]=rand()% 100 + 1;
		//cout << items[i] << "\n";
	}
	//cout << "Time in seconds = " << diff << endl;
	start =  clock(); // старт таймера
	shell(items, count);
	end = clock(); // остановка таймера
	float diff1 = (end - start) / 1000;
	
	cout << "Time in ms = " << diff1 << endl;
	start =  clock(); // старт таймера
	qs(items, 0, count -1);
	end = clock(); // остановка таймера
	float diff2 = (end - start) / 1000;
	cout << "Time in ms = " << diff2 << endl;
	start =  clock(); // старт таймера
	qsort(items, count, sizeof(int), compare);
	end = clock(); // остановка таймера
	float diff3 = (end - start) / 1000;
	cout << "Time in ms = " << diff3 << endl;

	//for(int ix = 0; ix < 6; ix++)
	system("pause");
	return(0);
}
