CC ?= clang
CFLAGS ?= -Iinclude -Oz
TARGET = cpm

SRC = src/cpm.c \
			src/help.c \
			src/list.c \
			src/update.c \
			src/install.c \

all:
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)
	strip cpm

clean:
	rm -f $(TARGET)
