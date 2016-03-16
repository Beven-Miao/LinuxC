#Linux平台提供的C标准库包括：   
    
1.一组头文件，定义了很多类型和宏，声明了很多库函数。这些头文件放在哪些目录下取决于不同的编译器，在教程的系统上，stdarg.h和stddef.h位于/usr/lib/gcc/i486-linux-gnu/4.3.2/include目录下，stdio.h,stdlib.h,time.h,math.h,assert.h位于/usr/include目录下。C99标准定义的文件有24个。    
    
2.一组库文件，提供了库函数的实现。大多数库函数在libc共享库中，有些库函数在另外的共享库中，例如数学函数在libm中，通常libc共享库是/lib/libc.so.6    


