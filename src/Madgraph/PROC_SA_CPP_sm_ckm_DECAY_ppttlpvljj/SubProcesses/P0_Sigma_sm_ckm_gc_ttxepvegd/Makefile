LIBDIR=../../lib
INCDIR=../../src
MODELLIB=model_sm_ckm_ppttlpvljj
CXXFLAGS= -O -I$(INCDIR) -I.
LIBFLAGS= -L$(LIBDIR) -l$(MODELLIB)

main=CPPProcess_P0_Sigma_sm_ckm_gc_ttxepvegd.o

all: $(main)

objects=CPPProcess_P0_Sigma_sm_ckm_gc_ttxepvegd.o 

#$(main): $(objects) $(LIBDIR)/lib$(MODELLIB).a
#	$(CXX) -o $@ $(objects) $(LIBFLAGS)

$(LIBDIR)/lib$(MODELLIB).a:
	cd ../../src
	make

.PHONY: clean

clean:
	rm -f $(target)
	rm -f $(objects)

