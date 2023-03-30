CC = gcc
OBJS = 4-10.o suthread.o suthread_util.o 4-10.s 
CFLAGS += -fsanitize=address -g -Wall

4-10: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

4-10.o: suthread.h

suthread.c: suthread.h
