CFLAGS := $(shell python-config --cflags) -Wall -Wextra -O2
LIBS := $(shell python-config --libs)
CPPFLAGS := $(shell python-config --includes)
LDFLAGS := $(shell python-config --ldflags)

all: mymodule.so

clean:
	$(RM) mymodule.so mymodule.o
.PHONY: all clean

mymodule.so: %.so: %.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LIBS) -shared -o $@

mymodule.o: %.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -fPIC $< -o $@
