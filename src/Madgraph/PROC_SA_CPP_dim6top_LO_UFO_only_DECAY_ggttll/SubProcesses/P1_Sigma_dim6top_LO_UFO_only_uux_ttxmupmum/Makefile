LIBDIR=../../lib
INCDIR=../../src
MODELLIB=model_dim6top_LO_UFO_only_ggttll
CXXFLAGS= -Ofast -I$(INCDIR) -I.
LIBFLAGS= -L$(LIBDIR) -l$(MODELLIB)

main=check

all: $(main)

objects=CPPProcess_P1_Sigma_dim6top_LO_UFO_only_uux_ttxmupmum.o check_sa.o

$(main): $(objects) $(LIBDIR)/lib$(MODELLIB).a
	$(CXX) -o $@ $(objects) $(LIBFLAGS)

$(LIBDIR)/lib$(MODELLIB).a:
	cd ../../src
	make

.PHONY: clean

clean:
	rm -f $(target)
	rm -f $(objects)

