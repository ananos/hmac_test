CFLAGS += -O2 -msse2 -std=c99
LDFLAGS += -static
SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

all: hmac_test



hmac_test: $(OBJECTS)
	$(CC) $(OBJECTS) -o hmac_test

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o hmac_test
