QUEUEW_SRC_DIR= src
QUEUEW=queuew

QUEUEW_TEST_DIR= test
QUEUEWT=queuewt

all: $(QUEUEW) $(QUEUEWT)

$(QUEUEW):
	cd $(QUEUEW_SRC_DIR); make

$(QUEUEWT):
	cd $(QUEUEW_TEST_DIR); make

clean:
	cd $(QUEUEW_SRC_DIR); make clean
	cd $(QUEUEW_TEST_DIR); make clean
