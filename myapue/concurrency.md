并发(信号,线程)

同步:



异步: 什么时候到来不知道,会产生什么样的结果不知道.

异步事件的处理:

    1. 查询法 (发生的频率比较高)

    2. 通知法 (发生的比较稀疏)





1. 信号

    1. 什么是信号(信号的概念)

        信号是软件中断

        信号的响应依赖于中断机制


        kill -l

            1-31  标准信号

            32-64 实时信号

    2. signal()

        void  (*signal(int signum,void (*func)(int)))(int);

    3. 信号的不可靠

    4. 可重入函数

    5. 信号的响应过程

    6. 信号常用函数

            kill();

            raise();

            alarm();

            pause();

            abort();

            system();

            sleep();


    7. 信号集


    8. 信号屏蔽字/pending集的处理

    9. 扩展

        sigsuspend();

        sigaction();

        setitimer();

    10. 实时信号



2. 多线程