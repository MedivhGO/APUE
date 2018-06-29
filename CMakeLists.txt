cmake_minimum_required(VERSION 3.10)
project(APUE)

set(CMAKE_CXX_STANDARD 11)

add_executable(APUE main.cpp FileAPI/FD.cpp FileAPI/Fgets.cpp FileAPI/Fprintf.cpp FileAPI/Fputs.c FileAPI/Fread.c FileAPI/Fscanf.c FileAPI/Fstat.c FileAPI/Fwrite.c FileAPI/GetCwd.c FileAPI/Log.c FileAPI/Read.c FileAPI/Remove.cpp FileAPI/Rname.cpp FileAPI/SFwrite.cpp FileAPI/Write.cpp Fork/Fork.cpp Fork/Exec.cpp Fork/Abort.cpp Fork/Kill.cpp Fork/Pid.cpp Fork/Pn.cpp Fork/Sys.cpp Fork/Wait.cpp MyLS.cpp Pipe/WritePipe.cpp Pipe/ReadPipe.cpp Pipe/NonaPipe.cpp Tcp/Server.cpp Tcp/Sock.cpp apue.h Utility/noncopyable.h Utility/MutexLock.h)