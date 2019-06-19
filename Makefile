CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=ulid.c ulid_error.c ulid_utility.c ulid_tcp_conn.c ulid_sopas_comm.c ulid_lidar.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ulid 
FILES=

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(FILES)