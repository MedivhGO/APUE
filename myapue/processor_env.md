1. main函数




2. 进程终止

	正常终止的方式

		main函数返回  return的返回值为给其父进程的返回值,在shell中调用c程序,其返回值返回给shell,可以使用$?进行查看

		如果没有return main函数返回值为最后一条语句的返回值

		调用exit函数

		调用_exit或_Exit (当程序执行过程中异常终止，为了防止脏数据被写入到磁盘，会直接调用_exit这些函数)

		最后一个线程从其启动历程返回

		最后一个线程调用pthread_exit


	异常终止的方式

		调用abort

		接到一个信号并终止

		最后一个线程对其取消请求作出响应


	atexit()钩子函数


3. 命令行参数的分析

		getopt();
		getopt_long(); //分析长格式 例如--all
    	extern char *optarg; //指向有 “：”修饰的 选项字符串



4. 环境变量

		KEY = VALUE

		export查看环境变量

		PATH shell的外部命令路径

		char** environ //man 7 environ

		getenv();
		setenv();
		putenv();



5. C程序的存储空间布局

		对于32位的操作系统而言

		从高到低地址

		最高1G的地址空间存储操作系统内核代码,0xC0000000开始到0xFFFFFFFF

		然后是存储环境变量env和argv参数的空间

		栈区 (栈不够用 向下浮动)

		静态库和动态库 //静态库比较大,所以一般使用动态库,在代码里只是关联

		堆区 (堆不够用 向上浮动)

		bss 未初始化的数据段

		已初始化的数据段

		文本段

		0x08048000开始 使用

		0x00000000存储一些东西


		pmap(1)

6. 库
		动态库

		静态库

		手工装载库(类似 内核模块)

		dlopen()

		dlclose()

		dlerror()

		dlsym()

		Link with -ldl

7. 函数跳转





8. 资源的获取及控制