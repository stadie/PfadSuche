#O2 for optimization, g for debugging
CFLAGS=-Wall -O2 -g #-I. $(shell root-config --cflags)
LFLAGS= #$(shell root-config --libs)
CC=g++
LD=g++

#all source files
SRCS=$(wildcard *.cc)

OBJS = $(filter-out pfad.o unittest.o, $(SRCS:.cc=.o))

.PHONY: clean all

all: pfad unittest

clean:
	@rm -f *~ *.o *# *.d pfad

pfad: $(OBJS) pfad.o
	$(LD) $(LFLAGS) -o pfad $^

unittest:  $(OBJS) unittest.o
	$(LD) $(LFLAGS) -o unittest $^


#rules
%.o : %.cc
	$(CC) $(CFLAGS) -MMD -c -o $@ $<
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
             -e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.d

-include $(SRCS:%.cc=%.d)

