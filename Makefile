CC=gcc
CFLAGS=-c -Wall
LDFLAGS=

SOURCES=ulid.c src/error.c src/util.c src/message.c src/socket.c src/list.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ulid

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(FILES) $(TESTEXECUTABLE)

test: 
	cd tests/ && $(MAKE)

cleantest:
	cd tests/ && $(MAKE) clean