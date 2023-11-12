CC = gcc
CFLAGS = -Wall
LIBS = -lvlc

# all: video_player

main:
	${CC} ${CFLAGS} -o video_player src/main.c ${LIBS}
clean:
	rm -f video_player

