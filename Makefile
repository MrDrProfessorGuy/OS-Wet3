#
# To compile, type "make" or make "all"
# To remove files, type "make clean"
#
OBJS =  request.o segel.o client.o Worker.o QueueManager.o JobQueue.o threadQueue.o shit.o
TARGET = server

CC = gcc
CFLAGS = -g -Wall

LIBS = -lpthread 

.SUFFIXES: .c .o .cpp

all: server client output.cgi
	-mkdir -p public
	-cp output.cgi favicon.ico home.html public

server: shit.o Worker.o QueueManager.o JobQueue.o threadQueue.o request.o segel.o
	g++ -std=c++11 shit.cpp Worker.cpp QueueManager.cpp JobQueue.cpp threadQueue.cpp request2.cpp segel2.cpp -lpthread

client: client.o segel.o
	$(CC) $(CFLAGS) -o client client.o segel.o -lpthread 

output.cgi: output.c
	$(CC) $(CFLAGS) -o output.cgi output.c

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f $(OBJS) server client output.cgi
	-rm -rf public
