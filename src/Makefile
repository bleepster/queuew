CC      = /usr/bin/gcc
C_FLAGS = -Wall
RM      = /bin/rm

.c.o:
	$(CC) $(C_FLAGS) $(CC_INCLUDE) -c -g $<

QUEUEW_OBJS = queuew.o
QUEUEW_SRCS = queuew.c

all: $(QUEUEW_OBJS)
	$(CC) $(C_FLAGS) -c $(QUEUEW_SRCS)

#$(QUEUEW_OBJS) : $(QUEUEW_OBJS)
#	$(CC) $(C_FLAGS) -c $(QUEUEW_SRCS)

clean:
	$(RM) -f $(QUEUEW_OBJS)
