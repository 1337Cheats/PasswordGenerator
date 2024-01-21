CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c
OBJS = $(SRCS:.c=.o)
EXEC = passgen

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
