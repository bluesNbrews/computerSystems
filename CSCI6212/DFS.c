#include <stdio.h>

void DFS (int G[][8], int start, int n){
	
	static int visited[8] = {0};
	int j;

	if(visited[start] == 0){
		printf("%d \n", start);
		visited[start] = 1;

		for (j = 1; j < n; j++){
			if(G[start][j] == 1 && visited[j] == 0)
				DFS(G,j,n);
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

	DFS(G,5,8);

	return 0;
}