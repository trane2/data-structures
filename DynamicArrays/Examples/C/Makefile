OBJS	= dynarray.o tester.o
SOURCE	= dynarray.c tester.c
HEADER	= dynarray.h test_data.h
OUT	= test
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

dynarray.o: dynarray.c
	$(CC) $(FLAGS) dynarray.c 

tester.o: tester.c
	$(CC) $(FLAGS) tester.c 


clean:
	rm -f $(OBJS) $(OUT)