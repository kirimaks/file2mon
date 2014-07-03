BIN = file2mon
CFLAGS = -Wall -Wextra -g -O2 `pkg-config --cflags gtk+-3.0 MagickWand`
LIBS = `pkg-config --libs gtk+-3.0 MagickWand`
DSTD = /usr/bin
SRC = $(wildcard ./*.c)
OBJ = $(patsubst %.c, %.o,$(SRC))

.PHONY: all clean install uninstall

all:$(BIN)

$@:$<
	$(CC) -o $@ $(CFLAGS) -c $<
	

$(BIN):$(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(LIBS)

clean:
	rm *o $(BIN)

install:
	install ./${BIN} ${DSTD}

uninstall:
	rm -rf ${DSTD}/${BIN}
