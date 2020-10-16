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


    mysu chown root mysu
         chmod u+s mysu



    g+s 是怎么实现的

6. 观摩课: 解释器文件

    只讲机制,不讲策略

7. system()

    执行一个shell命令
    fork exec wait的封装

8. 进程会计

    acct() 不可移植

9. 进程时间

    times();

10. 守护进程

        1. 脱离终端

        2. 会话的leader

        3. group的leader


        // 会话(终端)ctrl+alt+f1~f7(虚拟终端)

        //session的标识sid
        setsid()实现守护进程(不能是父进程调用),调用方会成为当前进程组的leader,并脱离当前终端. 守护进程的ppid值为1 (pid pgid sid)三个值相同

        //一个shell(session)中有很多进程组.

        //前台进程组(最多只能有一个),后台进程组.


        getpgrp();

        getpgrp(psid_t pid); //看指定进程的组id


        getpgid();
        setpgid(pid_t pid,pid_t pgid); 指定一个进程到指定组

11. 系统日志

        syslog

        <syslog.h>

        openlog();
        syslog(int priority,const char *format,...);//类似printf priority有具体的级别  error及以上级别就不能执行,大于等于LOG_INFO的才会写到系统的/var/log/message下
        closelog();
