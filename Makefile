CC := g++
CCFLAGS := -g -I. -ILinux

Linux:= $(patsubst %.cpp, %.o, $(shell find Linux/ | grep ".cpp$$"))

all: linuxtcpserver linuxtcpclient
	@echo
linuxtcpserver: $(Linux) exsample/linuxtcpserver.cpp
	$(CC) $(CCFLAGS) $+ -o $@
linuxtcpclient: $(Linux) exsample/linuxtcpclient.cpp
	$(CC) $(CCFLAGS) $+ -o $@

$(Linux) : %.o : %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf $(Linux)
