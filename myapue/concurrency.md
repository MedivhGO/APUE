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


        信号会打断阻塞的系统调用

    3. 信号的不可靠

        不是信号的丢失,是信号的行为不可靠



    4. 可重入函数

        第一次调用没结束,就发生第二次调用.导致第一次结果不可预料.

        所有的系统调用都是可重入,一部分库函数也是可重入的. 比如 memcpy //源,目的不能有重叠,重叠可以使用memmove

    5. 信号的响应过程

        信号从收到到响应有一个不可避免的延迟.(等待中断去陷入内核,从内核态到用户态时进行响应,中间可能有等待内核调度的时间.)

        思考: 信号如何忽略掉的. mask 位置 0

              标准信号为什么要丢失. (pending 置多少次,效果只与收到一次相同)

              标准信号的响应的


        进程(对于内核来说,是靠线程进行调度的)

        mask 位图  //当前信号的状态 32位 一般情况下都是1

        pending 位图 //用来记录当前进程收到哪些信号  初始值 32位 都是0


        当时间片用尽,保存现场,进入到kernel态.

        从kernel到user musk & pending 结果

        响应中断时 mask pending的该中断位置0

        响应中断结束后, mask位重新置1

    6. 信号常用函数

            kill(pid_t pid,int sig); //send signal to a  process

            raise(); // send a signal to a caller

            alarm(unsigned int seconds); //

            pause(); //wait for signal

            abort();

            system();

            sleep(); //alarm + pause 封装 可能还是nanosleep封装


    7. 信号集


    8. 信号屏蔽字/pending集的处理

    9. 扩展

        sigsuspend();

        sigaction();

        setitimer();

    10. 实时信号



2. 多线程