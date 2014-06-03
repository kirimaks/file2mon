#create_icon.c main.c routines.c update.c

BIN = filemon
CFLAGS = -Wall -Wextra -g `pkg-config --cflags gtk+-3.0 MagickWand`
LIBS = `pkg-config --libs gtk+-3.0 MagickWand`
DSTD = /usr/bin

.PHONY: all clean install uninstall

all: ${BIN}

clean:
	rm ${BIN} *o

main.o: main.c
	gcc -c -o main.o main.c	${CFLAGS}

create_icon.o: create_icon.c
	gcc -c -o create_icon.o create_icon.c ${CFLAGS}

routines.o: routines.c
	gcc -c -o routines.o routines.c ${CFLAGS}

update.o: update.c
	gcc -c -o update.o update.c ${CFLAGS}

filemon: main.o create_icon.o routines.o update.o
	gcc ${CFLAGS} -o ${BIN} main.o create_icon.o routines.o update.o ${LIBS}

install:
	install ./${BIN} ${DSTD}

uninstall:
	rm -rf ${DSTD}/${BIN}
