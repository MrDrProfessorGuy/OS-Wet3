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

server: server2.o Worker.o QueueManager.o JobQueue.o threadQueue.o request2.o segel2.o
	g++ -std=c++11 -o server server2.cpp Worker.cpp QueueManager.cpp JobQueue.cpp threadQueue.cpp request2.cpp segel2.cpp -lpthread

client: client.o segel.o
	$(CC) $(CFLAGS) -o client client.c segel.c -lpthread

output.cgi: output.o
	$(CC) $(CFLAGS) -o output.cgi output.c

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f $(OBJS) server client output.cgi
	-rm -rf public
