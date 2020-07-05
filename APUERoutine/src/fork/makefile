.SUFFIXES:.c .o  
CC=gcc
SRCS=test.c
OBJS=$(SRCS:.c=.o) #use .o replace .c
EXEC=libtest.so
start:$(OBJS) #only exec this target
	$(CC) $(OBJS) -shared -o   $(EXEC)
	@echo '----------ok--------' 
.c.o:
	$(CC) -Wall -g -fPIC -o $@ -c $<
clean:
	rm -f $(OBJS)
	rm -f core*
