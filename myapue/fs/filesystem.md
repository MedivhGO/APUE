<meta http-equiv="Content-Type" content="text/html; charset=utf-8" /> 
文件系统

1. 目录和文件

    1.1 获取文件属性
       stat: 通过文件路径获取属性,面对符号链接文件时获取的是所指向的文件的属性
       fstat: 通过文件描述符获取属性
       lstat: 面对符号链接时获取的是符号链接文件的属性
    
    1.2 文件访问权限
        st_mode 是一个16位的位图,用于表示文件类型,文件访问权限
    
    1.3 umask
        作用: 防止产生权限过松的文件
    
    1.4 文件权限的更改/管理
        
        chmod
        
        fchmod

    
    1.5 粘住位

        t位
    
    1.6 文件系统:FAT,UFS

        文件系统: 文件或数据的存储和管理
    
    1.7 硬链接和符号链接
    
        硬链接:在目录文件中添加一个目录项,与目录项是同义词,并且建立硬链接有限制,不能给分区建立,不能给目录建立
        符号链接: 是一个独立的文件,与原文件无关.不占空间大小.实际内容存储在inode中 可以给分区建立,可以给目录建立
        
        link
        
        unlink快速
        
        remove
        
        rename
        
    1.8 utime
        unix 不记录文件创建时间,可更改文件的最后读的时间和最后修改的时间
    
    1.9 目录的创建和销毁
    
        mkdir
         
        rmdir
    
    1.10 更改当前工作路径
        
        cd chdir函数实现
        
        chroot
        
        getcwd 获取工作目录

    
    1.11 分析目录/读取目录内容

        在shell命令行中输入”*“，会先被shell程序解析，解析后的字符串再传递给实际执行的程序
    
        glob() : 解析模式/通配符
---------------------------------------------------------        
        //DIR* 目录流
        
        opendir() 
        
        closedir()
        
        3 readdir() //读取目录下的一条记录
        
        rewinddir()
        
        seekdir()
        
        telldir()
        
        
    

2. 系统数据文件和信息

3. 进程环境

2. 系统数据文件和信息

    1. /etc/passwd

        getpwuid()
        getpwnam() 
        //返回用户的详细信息struct passwd 


    2. /etc/group

        getgrgid(); //根据组id获得组的相关信息
        getgrgnam();//根据组name获得组相关信息

    3. /etc/shadow

        hash -- 混淆 (不可逆) 如果原串相同,hash结果,也就是所得串相同,防备管理员坚守自盗.

        加密 -- 解密

        x % 5 = 2 hash不能反推得到x的值

        加密函数效果 原字符串改动一个字符,生成的加密串至少有一半以上的改变

        加密: 安全: 攻击成本大于收益

        安全? 穷举防备: 口令的随机校验: 可能会有机会连续输入2次口令

        shadow加密后串的格式
        $6$str1$str2

        6: 加密的方式
        str1: 杂字串(盐) 原串+str1 通过6这种方式加密 得到str2
        str2: 


        getspnam();
        crypt(); //加密


        


    4. 时间戳: time_t char*  struct tm

        time();
        gmtime();
        mktime();

        strftime() 格式化字符串


        1970-1-1:00:00:00 以秒为单位至今的秒数




    