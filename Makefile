CC=gcc
CFLAGS=-c -Wall
LDFLAGS=

SOURCES=ulid.c src/error.c src/util.c src/message.c src/socket.c src/qnode.c src/fifo.c src/sopas.c src/lidar.c src/telegram.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ulid

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:	cleantests
	rm $(OBJECTS) $(EXECUTABLE) $(FILES) $(TESTEXECUTABLE) ulid ulid.o

tests:
	cd testing/ && $(MAKE)

cleantests:
	cd testing/ && $(MAKE) clean