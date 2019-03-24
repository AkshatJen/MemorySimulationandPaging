CFLAGS = -c -Wall
CC     = gcc
DISTDIR= dist
DATADIR= data
LIBDIR = lib
OBJECTS= $(DISTDIR)/simulate.o\
         $(DISTDIR)/myfunctions.o

link: $(OBJECTS)
	$(CC) $? -o $(DISTDIR)/simulate

$(DISTDIR)/simulate.o: simulate.c
	$(CC) $(CFLAGS) $? -o $(DISTDIR)/simulate.o

$(DISTDIR)/myfunctions.o: $(LIBDIR)/myfunctions.c
	$(CC) $(CFLAGS) $? -o $(DISTDIR)/myfunctions.o

clean:
	rm -rf ./$(DISTDIR) && mkdir ./$(DISTDIR) && rm -rf ./$(DATADIR) && mkdir ./$(DATADIR)

start:
	./$(DISTDIR)/simulate
