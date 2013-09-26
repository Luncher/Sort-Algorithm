COMPILE 	= 
CC			= $(COMPILE)gcc
CPP			= $(COMPILE)g++
AR			= $(COMPILE)ar
LD			= $(COMPILE)ld
OBJCOPY		= $(COMPILE)objcopy
NM			= $(COMPILE)nm
OBJDUMP		= $(COMPILE)objdump
CHMOD		= chmod
PWD			= $(shell pwd)/..

CFLAGS		+= -g -O0
CFLAGS		+= -I. 


CPPFLAGS	+= $(CFLAGS)
#LDFLAGS		+= -shared

SOURCE		+= $(wildcard *.c)

OBJS		+= $(addsuffix .o, $(basename $(SOURCE)))


all : $(OBJS)
	${CC} -o demo ${OBJS}

clean:
	rm -rf *.o demo
