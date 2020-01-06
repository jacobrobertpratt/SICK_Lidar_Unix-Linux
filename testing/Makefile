CC=gcc
CFLAGS=-c -Wall
LDFLAGS=

SOURCES=test.c unity.c ../src/message.c ../src/error.c ../src/socket.c ../src/qnode.c ../src/fifo.c ../src/lidar.c ../src/sopas.c message_test.c error_test.c socket_test.c qnode_test.c fifo_test.c lidar_test.c sopas_test.c
MOCKSRC=mock_lidar.c
OBJECTS=$(SOURCES:.c=.o)
MOCKOBJ=$(MOCKSRC:.c=.o)
EXECUTABLE=test
MOCKEXE=mock_lidar

tests:	$(SOURCES) $(EXECUTABLE) mocks
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

mocks: $(MOCKSRC) $(MOCKEXE)

$(MOCKEXE): $(MOCKOBJ)
	$(CC) $(LDFLAGS) $(MOCKOBJ) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(MOCKOBJ) $(MOCKEXE)