CC=gcc
CF=-g -O0 -Wall

default: pc

pc: pc.c common.h tokenizer.h parser.h
	${CC} ${CF} pc.c -o pc

clean:
	rm pc
