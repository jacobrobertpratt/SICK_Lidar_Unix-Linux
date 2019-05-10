CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=ullid_test.c ullid_comm_format.c ullid_error.c ullid_utility.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ullid_test
FILES=*Log.txt 

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(FILES)