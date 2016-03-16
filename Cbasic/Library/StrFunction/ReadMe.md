#字符串操作函数   
1. 程序按功能划分可分为数值运算、符号处理和I/O操作三类，符号处理程序占相当大的比例，符号处理程序无处不在，编译器、浏览器、Office套件等程序的主要功能都是符号处理。无论多复杂的符号处理都是由各种基本的字符串操作组成的。   
   
1.1初始化字符串   
#include <string.h>   
    
void *memset(void *s, int c, size_t n);    
返回值：S指向那，返回的指针就指向哪    

1.2取字符串的长度
#include <string.h>
size_t strlen(const char*s);

1.3拷贝字符串
#include <string.h>
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
返回值：dest指向哪，返回的指针就指向哪。

1.4连接字符串
#include <string.h>
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
把src所指的字符串连接到dest所指的字符串的后面。

1.5比较字符串
#include <string.h>
int memcmp(const void *s1, const void *s2, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
返回值：负值表示s1小于s2,0表示s1等于s2,正值表示s1大于s2。

1.6搜索字符串
#include <string.h>
char *strchr(const char *s, int c);
char *strrchr(const char *s, intc);
返回值：如果找到字符c,返回字符串S中指向字符c的指针，如果找不到就返回NULL。

#include <string.h>
char *strstr(const char *haystack, const char *needle);
返回值：如果找到子串，返回值指向子串的开头，如果找不到就返回NULL。

1.7分割字符串




