CPP := g++
#ARCH:=powerpc-e300c3-linux-gnu-
CC := $(ARCH)$(CPP)
CCFLAGS := -lpthread -I. -Ilinux -Ibase -Iclient
TARGET:= linuxtcpserver linuxtcpclient clientmanager clientserver packettest


Linux:= $(patsubst %.cpp, %.o, $(shell find linux/ | grep ".cpp$$"))
Linux+= $(patsubst %.cpp, %.o, $(shell find client/ | grep ".cpp$$"))


all: $(TARGET)
	@echo -n

linuxtcpserver: $(Linux) exsample/linuxtcpserver.cpp
	@$(CC) $(CCFLAGS) $+ -o bin/$@
	@ls -vlh bin/$@
linuxtcpclient: $(Linux) exsample/linuxtcpclient.cpp
	@$(CC) $(CCFLAGS) $+ -o bin/$@
	@ls -vlh bin/$@
clientmanager: $(Linux) exsample/clientmanager.cpp
	@$(CC) $(CCFLAGS) $+ -o bin/$@
	@ls -vlh bin/$@
clientserver: $(Linux) exsample/clientserver.cpp
	@$(CC) $(CCFLAGS) $+ -o bin/$@
	@ls -vlh bin/$@
packettest: $(Linux) exsample/packettest.cpp
	@$(CC) $(CCFLAGS) $+ -o bin/$@
	@ls -vlh bin/$@

$(Linux) : %.o : %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf $(Linux) $(TARGET) bin/*
