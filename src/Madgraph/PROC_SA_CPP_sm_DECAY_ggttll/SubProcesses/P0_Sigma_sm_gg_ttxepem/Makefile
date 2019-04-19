LIBDIR=../../lib
INCDIR=../../src
MODELLIB=model_sm_ggttll
CXXFLAGS= -O -I$(INCDIR) -I.
LIBFLAGS= -L$(LIBDIR) -l$(MODELLIB)

main=CPPProcess_ggttll.o

all: $(main)

objects=CPPProcess_ggttll.o 

#$(main): $(objects) $(LIBDIR)/lib$(MODELLIB).a
#	$(CXX) -o $@ $(objects) $(LIBFLAGS)

$(LIBDIR)/lib$(MODELLIB).a:
	cd ../../src
	make

.PHONY: clean

clean:
	rm -f $(target)
	rm -f $(objects)

