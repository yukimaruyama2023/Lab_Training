CC = gcc
OBJS = 4-6.o suthread.o 4-6.s
CFLAGS += -fsanitize=address -g -Wall

4-6: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

4-6.o: suthread.h

suthread.c: suthread.h
