#------------------------------------------------------------------------------
#Madgraph definitions
TTH_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_4/src
THAD_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_DECAY_tbwjj/src
ATHAD_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_DECAY_antitbwjj/src
TLEP_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_DECAY_tbwlnu/src
H2L2NU_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_DECAY_hw2l2nu/src
TTLL_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_DECAY_ggttll/src
TTWP_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/src
TTWM_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/src
TTWPJJ_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/src
TTWMJJ_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/src
TTbar_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_DECAY_ggtt/src
TLLQ_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/src
WZJJ_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_DECAY_gqlnullgq/src
THQ_MADINCDIR=../Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/src
MADINCDIR = -I$(TTH_MADINCDIR) -I$(THAD_MADINCDIR) -I$(ATHAD_MADINCDIR) -I$(TLEP_MADINCDIR) -I$(H2L2NU_MADINCDIR) -I$(TTLL_MADINCDIR) -I$(TTWP_MADINCDIR) -I$(TTWM_MADINCDIR) -I${TTWPJJ_MADINCDIR} -I${TTWMJJ_MADINCDIR} -I${TTbar_MADINCDIR} -I${TLLQ_MADINCDIR} -I${WZJJ_MADINCDIR} -I${THQ_MADINCDIR}
#------------------------------------------------------------------------------
# ROOT definitions
ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs) -lMathMore -lMinuit2
#------------------------------------------------------------------------------
#LHAPDF definitions
LHAPDFINCDIR=-I${LHAPDF}/include
LHAPDFLIB=-L${LHAPDF}/lib -lLHAPDF
#------------------------------------------------------------------------------
# g++ options

CXX = g++
CXXFLAGS = -g -O3 -fPIC -Wall -Wno-deprecated
#LD = g++

#SOFLAGS = #-shared #-dynamiclib #-single_module #-undefined dynamic_lookup

CXXFLAGS     += $(ROOTCFLAGS) ${MADINCDIR} ${LHAPDFINCDIR}

LIBS         = ${ROOTGLIBS} ${ROOTLIBS}  -L../ -lMEMmultilepton ${LHAPDFLIB}

#------------------------------------------------------------------------------
# Compilation

all : simpleMEManalyzer

clean:
	rm *.o
	rm simpleMEManalyzer*

objects= SimpleMEManalyzer.o

simpleMEManalyzer: $(objects) 
	$(CXX) -o simpleMEManalyzer  $(objects) ${LIBS}  $(CXXFLAGS) #${SOFLAGS}

SimpleMEManalyzer.o: SimpleMEManalyzer.cpp 
	$(CXX) ${LIBS} ${CXXFLAGS} -c SimpleMEManalyzer.cpp




