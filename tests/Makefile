CC=gcc
CFLAGS=-c -Wall
LDFLAGS=

SOURCES=test.c unity.c ../src/message.c ../src/error.c message_test.c error_test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

tests:	$(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(FILES) $(TESTEXECUTABLE)

	