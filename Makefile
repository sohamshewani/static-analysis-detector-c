CC=gcc
CFLAGS=-Wall -Werror -g
SRCS=src/parser.c src/graph_builder.c src/analyzer.c src/main.c
OBJS=$(SRCS:.c=.o)
TARGET=static-analysis-detector-c

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o $@ $^ $(CFLAGS)

%.o: %.c
	${CC} -c $< -o $@ $(CFLAGS)

check: ${TARGET}
	./${TARGET} --test

install: ${TARGET}
	install -D ${TARGET} /usr/local/bin/${TARGET}

uninstall:
	rm -f /usr/local/bin/${TARGET}

.PHONY: clean check test install uninstall

clean:
	rm -f ${OBJS} ${TARGET}