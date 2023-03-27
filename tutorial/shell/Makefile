CC = gcc
OBJS = main.o parser.o token.o
CFLAGS += -fsanitize=address -g -Wall

shell: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

main.o: 

parser.o: token.h

token.o: token.h