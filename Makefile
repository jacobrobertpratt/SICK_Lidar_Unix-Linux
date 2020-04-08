CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-Wl


SOURCES=ulid.c src/error.c src/util.c src/message.c src/lidar.c src/sopas.c src/socket.c src/qnode.c src/fifo.c src/telegram.c src/uframe.c src/udraw.c src/usave.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ulid
FFMPEG_LIB=-lavformat -lavutil -lavcodec -lavfilter -lavdevice -lswscale

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(FFMPEG_LIB) -o  $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(FILES) $(TESTEXECUTABLE)

tests:
	cd testing/ && $(MAKE)

cleantests:
	cd testing/ && $(MAKE) clean