# Makefile for Cilk++ example.  See source code for details.

CILKPP  = cilk++
LIBARG  = -O1 -g -lcilkutil
TARGET  = parallel_bfsc
SRC     = parallel_bfs.cilk bfs_queue.cilk

all: $(TARGET)

$(TARGET): $(SRC)
		$(CILKPP) $(SRC) $(LIBARG) -o $@

clean:
		rm -f $(TARGET)~ $(TARGET)
