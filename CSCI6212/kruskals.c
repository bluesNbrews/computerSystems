#include <stdio.h>

//Use the max value for integer as infinity placeholder
#define I 32767

//Data structures for the minimum spanning tree, the graph, the set for a disjoint subset, and whether or not the edge is included in the solution.
int edge[9][3] = {

	{1,2,28},
	{1,6,10},
	{2,3,16},
	{2,7,14},
	{3,4,12},
	{4,5,22},
	{4,7,18},
	{5,6,25},
	{5,7,24}
};
int mst[2][7];
int included[9] = {0,0,0,0,0,0,0,0,0};
int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

//By definition, Kruskal's algorithm will select the smallest value edge that doesn't form a cycle
//The functions below (union and find)are useful for detecting cycles in the graph

//The join will take the larger set as the parent
//Don't join if they have same parent, it would cause a cycle (might need to change else to another if)

void join(int u, int v){
	if(set[u] < set[v]){
		set[u] += set[v];
		set[v] = u;
	}
	else{
		set[v] += set[u];
		set[u] = v;
	}
}

//Find parent of an element
int find(int u){
	int x = u;
	int v = 0;

	//While not a parent (greater than 0)
	while(set[x] > 0){
		x = set[x];
	}

	//Collasping find - once parent is found, connect directly to parent 
	while(u != x){
		v = set[u];
		set[u] = x;
		u = v;
	}

	return x;
}

int main(){

	int u = 0, v = 0, i = 0, j, k = 0, min = I, n = 9;

	while(i < 6){
		min = I;
		for(j = 0; j < n; j++){
			//Find minimum cost edge, don't repeatedly take same edges
			if(included[j] == 0 && edge [j][2] < min){
				u = edge[j][0]; 
				v = edge[j][1];
				min = edge[j][2];
				k = j;
			}
		}
		//Check to see if minimum cost edge is causing a cycle
		//If equal, then they are in the same set and will create a a cycle
		if (find(u) != find(v)){
			mst[0][i] = u;
			mst[1][i] = v;
			join(find(u), find(v));
			i++;
		}
		else
			included[k] = 1;
	}

	//Print the solution
	printf("Minimum Spanning Tree\n");
	for(i = 0; i < 6; i++){
		printf("%d %d\n", mst[0][i], mst[1][i]);
	}

	return 0;
}