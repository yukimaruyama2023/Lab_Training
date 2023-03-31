CC = gcc
OBJS = main.o suthread.o suthread_util.o context_switch.s 
CFLAGS += -fsanitize=address -g -Wall

4-12: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

4-10.o: suthread.h

suthread.c: suthread.h
