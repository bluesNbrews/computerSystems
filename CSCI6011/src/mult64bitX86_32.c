#include<stdio.h>

typedef long long longLong_t;

void store_prod(longLong_t *dest, int x, longLong_t y){
	*dest = x*y;
	//printf("%lld\n", *dest);
}

int main(){
	
	long long *dest;
	long long x,y;
	x = 10;
	y = 5;

	store_prod(dest, 10, 5);

	return 0;
}