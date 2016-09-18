CPP := g++
ARCH:=powerpc-e300c3-linux-gnu-
CC := $(ARCH)$(CPP)
CCFLAGS := -g -I. -ILinux -IBase

Linux:= $(patsubst %.cpp, %.o, $(shell find Linux/ | grep ".cpp$$"))
TARGET:= linuxtcpserver linuxtcpclient


all: $(TARGET)
	@echo

linuxtcpserver: $(Linux) exsample/linuxtcpserver.cpp
	$(CC) $(CCFLAGS) $+ -o bin/$@

linuxtcpclient: $(Linux) exsample/linuxtcpclient.cpp
	$(CC) $(CCFLAGS) $+ -o bin/$@

$(Linux) : %.o : %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf $(Linux) $(TARGET) bin/*
