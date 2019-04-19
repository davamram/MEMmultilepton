LIBDIR=../../lib
INCDIR=../../src
MODELLIB=model_sm_tbwlnu
CXXFLAGS= -O -I$(INCDIR) -I.
LIBFLAGS= -L$(LIBDIR) -l$(MODELLIB)

main=CPPProcess_tbwlnu.o

all: $(main)

objects=CPPProcess_tbwlnu.o 

#$(main): $(objects) $(LIBDIR)/lib$(MODELLIB).a
#	$(CXX) -o $@ $(objects) $(LIBFLAGS)

$(LIBDIR)/lib$(MODELLIB).a:
	cd ../../src
	make

.PHONY: clean

clean:
	rm -f $(target)
	rm -f $(objects)

