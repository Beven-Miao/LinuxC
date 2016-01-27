#include <stdio.h>

int main()
{
	int i;
	char str[6]="hello";
	char str2[6]="";

	printf("%s\n",str);

	for(i=0;i<5;i++){
		str2[i]=str[4-i];	
	}

	printf("%s\n",str2);
	return 0;
}
