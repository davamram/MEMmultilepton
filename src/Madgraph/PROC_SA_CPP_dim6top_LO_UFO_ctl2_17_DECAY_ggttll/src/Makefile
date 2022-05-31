LIBDIR=../lib
CXXFLAGS= -Ofast -I.

target=$(LIBDIR)/libmodel_dim6top_LO_UFO_ctl2_17.a

all: $(target)

objects=HelAmps_dim6top_LO_UFO_ctl2_17.o Parameters_dim6top_LO_UFO_ctl2_17.o rambo.o ../../PROC_SA_CPP_sm_4/src/read_slha.o

$(target): $(objects)
	$(AR) cru $@ $(objects)
	ranlib $(target)

.PHONY: clean

clean:
	rm -f $(target)
	rm -f $(objects)

