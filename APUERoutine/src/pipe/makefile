.SUFFIXES:.c .o  
CC=gcc
SRCS1=writepipe.c
SRCS2=readpipe.c
OBJS1=$(SRCS1:.c=.o) #use .o replace .c
OBJS2=$(SRCS2:.c=.o) #use .o replace .c
EXEC1=writepipe
EXEC2=readpipe
start:$(OBJS1) $(OBJS2)#only exec this target
	$(CC) $(OBJS1) -o $(EXEC1)
	$(CC) $(OBJS2) -o $(EXEC2)
	@echo '----------ok--------' 
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	rm -f $(OBJS)
	rm -f core*
