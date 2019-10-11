CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=test.c errortest.c ../src/util.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test
FILES=

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(FILES)