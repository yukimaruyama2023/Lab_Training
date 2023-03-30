CC = gcc
OBJS = 4-9.o suthread.o suthread_util.o 4-9.s 
CFLAGS += -fsanitize=address -g -Wall

4-9: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

4-9.o: suthread.h

suthread.c: suthread.h
