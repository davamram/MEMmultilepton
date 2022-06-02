LIBDIR=../lib
CXXFLAGS= -Ofast -I.

target=$(LIBDIR)/libmodel_dim6top_LO_UFO_ctl2_ggttll.a

all: $(target)

objects=HelAmps_dim6top_LO_UFO_ctl2_ggttll.o Parameters_dim6top_LO_UFO_ctl2_ggttll.o rambo.o ../../PROC_SA_CPP_sm_4/src/read_slha.o

$(target): $(objects)
	$(AR) cru $@ $(objects)
	ranlib $(target)

.PHONY: clean

clean:
	rm -f $(target)
	rm -f $(objects)

