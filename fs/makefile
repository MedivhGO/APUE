.SUFFIXES:.c .o  
CC=gcc
SRCS=abc.c
OBJS=$(SRCS:.c=.o) #use .o replace .c
EXEC=abc
start:$(OBJS) #only exec this target
	$(CC) $(OBJS) -o $(EXEC)
	@echo '----------ok--------' 
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	rm -f $(OBJS)
	rm -f core*
