CC      = /usr/bin/gcc
C_FLAGS = -Wall
RM      = /bin/rm

.c.o:
	$(CC) $(C_FLAGS) $(CC_INCLUDE) -c -g $<

QUEUEW_TEST_BIN  = qwtest
QUEUEW_TEST_OBJS = qwtest.o
QUEUEW_TEST_SRCS = qwtest.c

QUEUEW_OBJS = ../src/queuew.o

all: $(QUEUEW_TEST_BIN)

$(QUEUEW_TEST_BIN) : $(QUEUEW_TEST_OBJS)
	$(CC) $(C_FLAGS) -o $(QUEUEW_TEST_BIN) $(QUEUEW_TEST_OBJS) \
	  $(QUEUEW_OBJS)

clean:
	$(RM) -f $(QUEUEW_TEST_OBJS) $(QUEUEW_TEST_BIN)
