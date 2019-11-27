#include <iostream>

//Use the max value for integer as infinity placeholder
#define I 2147483647

using namespace std;

int cost[][8] = 

				{{I,I,I,I,I,I,I,I},
				{I,I,25,I,I,I,5,I},
				{I,25,I,12,I,I,I,10},
				{I,I,12,I,8,I,I,I},
				{I,I,I,8,I,16,I,14},
				{I,I,I,I,16,I,20,18},
				{I,5,I,I,I,20,I,I},
				{I,I,10,I,14,18,I,I}};

//closest array will keep track of connected vertices
int closest[8]={I,I,I,I,I,I,I,I};
//mst array will keep track as we populate the minimum spanning tree
int mst[2][6];

int main(){

	int i, j, k, u, v;
	int n = 7;
	int min = I;

	//Find the min edge on the "upper triangle" of adjacency matrix.
	//The adjacency matrix has identical values for the following triangles (upper and lower).
	/*  
		|\     -----
		| \     \  |
		|  \     \ |
		-----     \|

	*/

	//Get the initial minimum cost edge
	for(i = 1; i <= n; i++){
		for(j = i; j <= n; j++){
			if(cost[i][j] < min){
				min = cost[i][j];
				u = i;
				v = j;
			}
		}
	}

	//Initial step to populate the minimum spanning tree
	mst[0][0] = u;
	mst[1][0] = v;

	//Set to visited by changing infinity value to 0
	near[u] = near[v] = 0;

	//Check for closest vertex and update as necessary
	for(i = 1; i <= n; i++){
		if(closest[i] != 0){
			if(cost[i][u] < cost[i][v])
				near[i] = u;
			else
				near[i] = v;
		}
	}

	//Find smallest value for remaining edges by updating the closest vertex data structure and
	//using it to determine which edge to put in the minimum spanning tree data structure
	for(i = 1; i < n - 1; i++){
		min = I;
		for(j = 1; j < n; j++){
			if(closest[j] != 0 && cost[j][closest[j]] < min){
				k = j;
				min = cost[j][closest[j]];
			}
		}
		mst[0][i] = k;
		mst[1][i] = closest[k];
		closest[k] = 0;

		for(j = 1; j <= n; j++){
			if(closest[j] != 0 && cost[j][k] < cost[j][closest[j]])
				closest[j] = k;
		}
	}

	//Print output of minimum spanning tree
	for(i = 0; i < n - 1; i++){
		cout << "(" << mst[0][i] << "," << mst[1][i] << ")" << endl;
	}

}