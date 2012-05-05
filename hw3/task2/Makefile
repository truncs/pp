CILKPP  = cilk++
LIBARG  = -O1 -g -lcilkutil
TARGET  = cilk_qsort
SRC     = par_randomized_looping_qsort.cilk

all: $(TARGET)

$(TARGET): $(SRC)
		$(CILKPP) $(SRC) $(LIBARG) -o $@

clean:
		rm -f $(TARGET)~ 