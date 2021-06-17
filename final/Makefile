CC:=g++
EXE:=main
FLAGS:=-Wall -g -O3 -static-libgcc -std=c11
SUBDIRS = algorithm function

all: dep
	$(CC) *.o -o $(EXE) $(FLAGS)

dep:
	for i in $(SUBDIRS); do\
		$(CC) $(CFLAGS) -c $$i/*.cpp;\
	done
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f $(EXE) *.o
