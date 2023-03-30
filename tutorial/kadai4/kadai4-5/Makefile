CC = gcc
OBJS = 4-5.o suthread.o 4-5.s

4-5: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

4-5.o: suthread.h

suthread.c: suthread.h
