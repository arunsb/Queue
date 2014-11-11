
obj: queue-link-list.o testMain.o Thr-queue-main.o

test-bin = testMain.o queue-link-list.o
thr-bin = queue-link-list.o Thr-queue-main.o
TARGETS = test-bin thr-bin

queue-link-list.o: $(queue-link-list.o)
		cc  -DLOG_INFO queue-link-list.c -c $(queue-link-list.o)                  

test-bin: $(test-bin) 
	cc $(test-bin) -o test-queue

thr-bin: $(thr-bin) 
	cc $(thr-bin) -lpthread

#all: $(thr-bin) 
#	cc $(thr-bin) -lpthread
all: $(TARGETS)

clean: 
	rm -f queue-link-list.o Thr-queue-main.o testMain.o  a.out
