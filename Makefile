CC = clang++
LD = clang++
CFLAGS = -stdlib=libc++ -std=c++11 -c -g
LDFLAGS = -stdlib=libc++ -lc++ -lc++abi
EXEC = test
OBJS = main.o \
	   ./src/095_UniqueBinarySearchTreesII.o

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	$(LD) $(LDFLAGS) $(^) -o $(@)

%.o: %.cpp
	$(CC) $(CFLAGS) $(<) -o $(@)

.PHONY: clean
clean:
	-rm -f $(EXEC)
	-rm -f $(OBJS)
