CC = gcc
OBJS = 4-7.o suthread.o 4-7.s
CFLAGS += -fsanitize=address -g -Wall

4-7: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

4-7.o: suthread.h

suthread.c: suthread.h
