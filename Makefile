CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=ulid.c src/error.c src/util.c src/message.c src/socket.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ulid
FILES=

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(FILES) $(TESTEXECUTABLE)