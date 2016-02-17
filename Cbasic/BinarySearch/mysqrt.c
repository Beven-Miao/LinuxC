#include <stdio.h>

double mysqrt(double y)
{
	double mid,start = 0,end = y;

	while(start <= end){
		mid = (start + end)/2;
		if((mid*mid - y) > 0.001)
			end = mid;
		else if ((y - mid*mid) > 0.001)
			start = mid;
		else 
			return mid;
	}
	return -1;
}

int main(void)
{
	double sqrt = mysqrt(9);
	printf("%f\n",sqrt);
	return 0;
}
