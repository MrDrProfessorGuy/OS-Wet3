#
# To compile, type "make" or make "all"
# To remove files, type "make clean"
#
OBJS =  request.o segel.o client.o Worker.o QueueManager.o JobQueue.o threadQueue.o shit.o
TARGET = server

CC = g++
CFLAGS = -std=c++11 -Wall

LIBS = -lpthread 

.SUFFIXES: .c .o .cpp

all: server client output.cgi
	-mkdir -p public
	-cp output.cgi favicon.ico home.html public

server: shit.o old.o Worker.o QueueManager.o JobQueue.o threadQueue.o
	$(CC) $(CFLAGS) -o server old.o shit.o Worker.o QueueManager.o JobQueue.o threadQueue.o $(LIBS)

old: request.o segel.o
	gcc -g -Wall -c old.o request.o segel.o $(LIBS)

client: client.o segel.o
	$(CC) $(CFLAGS) -o client client.o segel.o

output.cgi: output.c
	$(CC) $(CFLAGS) -o output.cgi output.c

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f $(OBJS) server client output.cgi
	-rm -rf public
