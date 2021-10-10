CC=gcc
CXX=g++
CFLAGS=
LDLIBS=
LDFLAGS=
SRCS=main.cc
OBJS=$(subst .cc,.o,$(SRCS))
CPPFLAGS+=$(LDFLAGS)

all: learningloop

learningloop: $(OBJS)
	$(CXX) $(LDFLAGS) -o learningloop $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) learningloop .depend

include .depend
