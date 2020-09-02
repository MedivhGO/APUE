<meta http-equiv="Content-Type" content="text/html; charset=utf-8" /> 
文件系统

1. 目录和文件

    1.1 获取文件属性
    
    1.2 文件访问权限
    
    1.3 umask
    
    1.4 文件权限的更改/管理
    
    1.5 粘住位
    
    1.6 文件系统:FAT,UFS
    
    1.7 硬链接和符号链接
    
        硬链接:在目录文件中添加一个目录项,与目录项是同义词,并且建立硬链接有限制,不能给分区建立,不能给目录建立
        符号链接: 是一个独立的文件,与原文件无关.不占空间大小.实际内容存储在inode中 可以给分区建立,可以给目录建立
        
        link
        
        unlink快速
        
        remove
        
        rename
        
    1.8 utime
        unix 不记录文件创建时间
    
    1.9 目录的创建和销毁
    
        mkdir
         
        rmdir
    
    1.10 更改当前工作路径
        
        cd chdir函数实现
        
        chroot
        
        getcwd 获取工作目录

    
    1.11 分析目录/读取目录内容
    
        glob
        
        opendir
        
        closedir
        
        3 readdir
        
        rewinddir
        
        seekdir
        
        telldir
        
        
    

2. 系统数据文件和信息

3. 进程环境

