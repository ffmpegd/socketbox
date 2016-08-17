CC := g++
CCFLAGS := -g -I. -ILinux

Linux:= $(patsubst %.cpp, %.o, $(shell find Linux/ | grep ".cpp$$"))

all: linuxtcpserver
	@echo
linuxtcpserver: $(Linux) exsample/linuxtcpserver.cpp
	$(CC) $(CCFLAGS) $+ -o $@

$(Linux) : %.o : %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf $(Linux)
