进程基本知识

已经进入多进程阶段


1. 进程标识符pid

    pid_t 有符号16位整形数  3w多个进程

    通过typedef 可以重新 定义pid_t大小

    进程号是顺次向下使用

    getpid()

    getppid()


2. 进程的产生

    fork();

    复制一个进程, 所执行到的位置都相同

    fork后父子进程的区别:

        fork的返回值不一样

        pid不一样

        ppid也不相同

        未决信号和文件锁不继承,资源利用量清0

    调度器的调度策略来决定哪个进程先运行

    vfork();

        只能保证_exit(2) 和 exec 的结果,其他都是未定义行为

    init进程 进程1,是所有进程的祖先进程



3. 进程消亡及释放资源

    wait(); //wait for process to change state
        不能确定回收的是哪个进程的资源,需要进一步确认.

        会一直死等 会阻塞

    waitpid(pid_t pid, int *status,int options); //使用option可以将wait由阻塞变成非阻塞.

    waitid();

    wait3();

    wait4();

4. exec函数族的使用

    execl(); //执行一个文件 //pid不变

    execlp();

    execle(); //定餐函数

    execv();

    execvp();

    //注意flush的使用



5. 用户权限和组权限

    u+s 是怎么实现的

        uid 存了三个值 r(real) , e(effective), s(save) (可能不存在)

        root的uid为0

        passwd fork之后 e和s的值置0


    getuid()

    geteuid()

    getgid()

    getegid()

    setuid() //sets the effective user id

    setgid()

    setreuid() //原子操作

    setregid() //原子操作

    seteuid()

    setegid()


    init 进程 root用户权限

        fork + exec  (getty进程:请求name:)
                     exec (login: 输入password ) root

                     成功的话 fork + exec 执行shell,shell程序的身份.





    g+s 是怎么实现的

6. 观摩课: 解释器文件

7. system()

8. 进程会计

9. 进程时间

10. 守护进程

11. 系统日志