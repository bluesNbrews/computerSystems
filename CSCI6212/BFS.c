#include <stdio.h>
#include "Queue.h"

void BFS(int G[][8], int start, int n){

	int i = start, j;
	int visited[8] = {0};

	printf("%d \n", i);
	visited[i] = 1;
	enqueue(i);

	while(!isEmpty()){
		i = dequeue();
		for(j = 1; j < n; j++){
			if(G[i][j] == 1 && visited[j] == 0){
				printf("%d \n", j);
				visited[j] = 1;
				enqueue(j);
			}
		}
	}

}

int main(){
	int G[8][8] = {{0,0,0,0,0,0,0,0},
				   {0,0,1,1,1,0,0,0},
				   {0,1,0,1,0,0,0,0},
				   {0,1,1,0,1,1,0,0},
				   {0,1,0,1,0,1,0,0},
				   {0,0,0,1,1,0,1,1},
				   {0,0,0,0,0,1,0,0},
				   {0,0,0,0,0,1,0,0}};

	BFS(G,5,8);

	return 0;
}