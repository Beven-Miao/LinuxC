/* main.c */

#include <stdio.h>
#include "ret_ptr.h"

int main(void)
{

	printf("%s %s\n",get_a_day(0),get_a_day(1));//两个函数返回的为同一个地址，都是buf数组的首地址，所以打印出来的都是Sunday
	return 0;
}
