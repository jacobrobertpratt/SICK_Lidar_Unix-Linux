CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=ullid.c ullid_comm_format.c ullid_error.c ullid_utility.c ullid_connection_tcp.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ullid
FILES=

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(FILES)