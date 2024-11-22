#include "StdAfx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "string.h"
#include <cmath>
#include <queue>
using namespace std;


int **createG(int size){
	int **G;
	G = (int**)malloc(size * sizeof(int*));
	for(int i=0; i < size; i++){
		G[i] = ((int*)malloc(size * sizeof(int)));
	}

	for (int i=0; i < size; i++){
		for(int j = i; j<size; j++){
			G[i][j] = rand()%2;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void **printG(int **G, int size){
	for (int i=0; i < size; i++){
		for(int j = 0; j<size; j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void **BFS(int **G, int v, int size, int *dist)
{
	queue <int> q;
	q.push (v);
	dist[v]=0;

	while (!q.empty()){
		v=q.front();
		q.pop();
		for (int i=0; i<size; i++){
			if (G[v][i] == 1 && dist[i]==-1){
				q.push (i);
				dist[i]=dist[v]+1;
			}		
		}
	}
	return 0;
}

int main(){
	int size = 0, s = 0, *vis;
    srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	printf("Введите размер массива: ");
	scanf("%d",&size);
	printf("Введите начальную вершину ");
	scanf("%d",&s);

	vis = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++) vis[i] = -1;
	int **G1 = createG(size);
	printG(G1, size);
	printf("\n");
	BFS(G1, s, size, vis);
	
	for(int i=0; i<size; i++) printf("Расстояние до %d вершины = %d\n", i, vis[i]);;
	printf("\n");
	for(int i=0; i<size; i++){
		if (vis[i] == -1) printf("Вершина %d изолированная\n", i);
	}
}