#C标准I/O库函数与Unbuffered I/O函数   

fopen(3)
	调用open(2)打开指定的文件，返回一个文件描述符(就是一个int型号的类型),分配一个FILE结构体，其中包含该文件的描述符、I/O缓冲区和当前读写位置等信息，返回这个FILE结构体。   

fgetc(3)
	
