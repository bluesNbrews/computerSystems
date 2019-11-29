#include <stdio.h>

//Use the max value for integer as infinity placeholder
#define I 32767

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

	//Collasping find, connect directly to parent
	//Needs review
	while(u != x){
		v = set[u];
		set[u] = x;
		u = v;
	}

	return x;
}

//Data structures for the minimum spanning tree, the graph, the set(s), and the  

int mst[2][7];
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
}
int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int included[9] = {0,0,0,0,0,0,0,0,0};

int main(){



	return 0;
}