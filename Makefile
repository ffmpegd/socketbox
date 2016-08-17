CC := g++
CCFLAGS := -g -I. -ILinux

Linux:= $(patsubst %.cpp, %.o, $(shell find Linux/ | grep ".cpp$$"))

all: $(Linux)
	@echo
test: $(Linux) testbox.cpp
	$(CC) $(CCFLAGS) $+ -o $@

$(Linux) : %.o : %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf $(Linux)
