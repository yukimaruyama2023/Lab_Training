CC = gcc
OBJS = main.o parser.o token.o

shell: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

main.o: 

parser.o: token.h

token.o: token.h