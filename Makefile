CC=gcc
CFLAGS=-c -Wall 
LDFLAGS=

SOURCES=ulid.c src/error.c src/util.c src/message.c src/lidar.c src/sopas.c src/socket.c src/qnode.c src/fifo.c src/telegram.c src/uframe.c src/udraw.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ulid

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(FILES) $(TESTEXECUTABLE)

tests:
	cd testing/ && $(MAKE)

cleantests:
	cd testing/ && $(MAKE) clean