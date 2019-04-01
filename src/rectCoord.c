//Author: Steven Williams
//CSCI 6011
//Mid term problem 3
#include<stdio.h>

//X and y coordinates for each point
typedef struct coordinate{
	int x;
	int y;
} coord;

//Endpoints of the diagonal for the rectangle
struct rectangle{
	coord point_A;
	coord point_B;
};

//Calulate the area based on the endpoinots of the diagonal
int sides(struct rectangle my_rect){
	int length;
	int width;
	int area;

	//Must subtract the lesser value from the greater value
	//   length = y2 - y1  y2 is the second y from point B, y1 from point A
	//   width  = x2 - x1  x2 is the second x from point B, x1 from point A
	if (my_rect.point_A.y > my_rect.point_B.y)
		length = my_rect.point_A.y - my_rect.point_B.y;
	else
		length = my_rect.point_B.y - my_rect.point_A.y;
	if (my_rect.point_A.x > my_rect.point_B.x)
		width = my_rect.point_A.x - my_rect.point_B.x;
	else 
		width = my_rect.point_B.x - my_rect.point_A.x;

	//Calculate area
	area = length * width;

	//Return area
	return area;
}

int main(void){

	//Create rectangle from structures above
	struct rectangle my_rect;
	int area;

	//Set the coordinates for the diagonal of the rectangle
	my_rect.point_A.x = -3;
	my_rect.point_A.y = -4;

	my_rect.point_B.x = 5;
	my_rect.point_B.y = 6;

	//Return area
	area = sides(my_rect);

	//Print area
	printf("Based on the points of the diagonal (%d,%d) and (%d,%d), ", my_rect.point_A.x, my_rect.point_A.y, my_rect.point_B.x, my_rect.point_B.y);
	printf("the area is %d.\n", area);

	return 0;
}