CC=g++
CPPFLAGS=-g -Wall -Wextra
SRCS=src/main.cpp

choc-an: $(SRCS)
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -fv choc-an
