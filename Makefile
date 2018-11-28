#------------------------------------------------------------------------------
#Madgraph definitions

#TTH
TTH_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_4/lib
TTH_MADINCDIR=Madgraph/PROC_SA_CPP_sm_4/src
TTH_MADPROCDIR=Madgraph/PROC_SA_CPP_sm_4/SubProcesses/P0_Sigma_sm_gg_ttxh
TTH_MADMODELLIB=model_sm

#T->bW->bjj
THAD_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_DECAY_tbwjj/lib
THAD_MADINCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_tbwjj/src
THAD_MADPROCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_tbwjj/SubProcesses/P0_Sigma_sm_t_budx
THAD_MADMODELLIB=model_sm_tbwjj

#Anti T->bW->bjj
ATHAD_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_DECAY_antitbwjj/lib
ATHAD_MADINCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_antitbwjj/src
ATHAD_MADPROCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_antitbwjj/SubProcesses/P0_Sigma_sm_tx_bxdux
ATHAD_MADMODELLIB=model_sm_antitbwjj

#T->bW->blnu
TLEP_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_DECAY_tbwlnu/lib
TLEP_MADINCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_tbwlnu/src
TLEP_MADPROCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_tbwlnu/SubProcesses/P0_Sigma_sm_t_bepve
TLEP_MADMODELLIB=model_sm_tbwlnu

#H->WW->2l2nu
H2L2NU_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_DECAY_hw2l2nu/lib
H2L2NU_MADINCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_hw2l2nu/src
H2L2NU_MADPROCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_hw2l2nu/SubProcesses/P0_Sigma_sm_h_epveemvex
H2L2NU_MADMODELLIB=model_sm_hw2l2nu

#TTGamma*
TTLL_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_DECAY_ggttll/lib
TTLL_MADINCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_ggttll/src
TTLL_MADPROCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_ggttll/SubProcesses/P0_Sigma_sm_gg_ttxepem
TTLL_MADMODELLIB=model_sm_ggttll

#TTW+
TTWP_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/lib
TTWP_MADINCDIR=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/src
TTWP_MADPROCESS_udx=CPPProcess_P0_Sigma_sm_ckm_udx_ttxepve
TTWP_MADPROCESS_cdx=CPPProcess_P0_Sigma_sm_ckm_cdx_ttxepve
TTWP_MADPROCESS_usx=CPPProcess_P0_Sigma_sm_ckm_usx_ttxepve
TTWP_MADPROCDIR_udx=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/SubProcesses/P0_Sigma_sm_ckm_udx_ttxepve
TTWP_MADPROCDIR_cdx=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/SubProcesses/P0_Sigma_sm_ckm_cdx_ttxepve
TTWP_MADPROCDIR_usx=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/SubProcesses/P0_Sigma_sm_ckm_usx_ttxepve
TTWP_MADMODELLIB=model_sm_ckm_qqttlpvl

#TTW-
TTWM_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/lib
TTWM_MADINCDIR=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/src
TTWM_MADPROCESS_dux=CPPProcess_P0_Sigma_sm_ckm_dux_ttxemvex
TTWM_MADPROCESS_dcx=CPPProcess_P0_Sigma_sm_ckm_dcx_ttxemvex
TTWM_MADPROCESS_sux=CPPProcess_P0_Sigma_sm_ckm_sux_ttxemvex
TTWM_MADPROCDIR_dux=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/SubProcesses/P0_Sigma_sm_ckm_dux_ttxemvex
TTWM_MADPROCDIR_dcx=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/SubProcesses/P0_Sigma_sm_ckm_dcx_ttxemvex
TTWM_MADPROCDIR_sux=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/SubProcesses/P0_Sigma_sm_ckm_sux_ttxemvex
TTWM_MADMODELLIB=model_sm_ckm_qqttlmvl

#TTWPJJ
TTWPJJ_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/lib
TTWPJJ_MADINCDIR=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/src
TTWPJJ_MADMODELLIB=model_sm_ckm_ppttlpvljj
TTWPJJ_MADPROCESS_0=CPPProcess_P0_Sigma_sm_ckm_gc_ttxepvegd
TTWPJJ_MADPROCDIR_0=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gc_ttxepvegd
TTWPJJ_MADPROCESS_1=CPPProcess_P0_Sigma_sm_ckm_gdx_ttxepvegcx
TTWPJJ_MADPROCDIR_1=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gdx_ttxepvegcx
TTWPJJ_MADPROCESS_2=CPPProcess_P0_Sigma_sm_ckm_gdx_ttxepvegux
TTWPJJ_MADPROCDIR_2=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gdx_ttxepvegux
TTWPJJ_MADPROCESS_3=CPPProcess_P0_Sigma_sm_ckm_gsx_ttxepvegux
TTWPJJ_MADPROCDIR_3=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gsx_ttxepvegux
TTWPJJ_MADPROCESS_4=CPPProcess_P0_Sigma_sm_ckm_gu_ttxepvegd
TTWPJJ_MADPROCDIR_4=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gu_ttxepvegd
TTWPJJ_MADPROCESS_5=CPPProcess_P0_Sigma_sm_ckm_gu_ttxepvegs
TTWPJJ_MADPROCDIR_5=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/SubProcesses/P0_Sigma_sm_ckm_gu_ttxepvegs

#TTWMJJ
TTWMJJ_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/lib
TTWMJJ_MADINCDIR=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/src
TTWMJJ_MADMODELLIB=model_sm_ckm_ppttlmvljj
TTWMJJ_MADPROCESS_0=CPPProcess_P0_Sigma_sm_ckm_gcx_ttxemvexgdx
TTWMJJ_MADPROCDIR_0=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gcx_ttxemvexgdx
TTWMJJ_MADPROCESS_1=CPPProcess_P0_Sigma_sm_ckm_gd_ttxemvexgc
TTWMJJ_MADPROCDIR_1=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gd_ttxemvexgc
TTWMJJ_MADPROCESS_2=CPPProcess_P0_Sigma_sm_ckm_gd_ttxemvexgu
TTWMJJ_MADPROCDIR_2=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gd_ttxemvexgu
TTWMJJ_MADPROCESS_3=CPPProcess_P0_Sigma_sm_ckm_gs_ttxemvexgu
TTWMJJ_MADPROCDIR_3=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gs_ttxemvexgu
TTWMJJ_MADPROCESS_4=CPPProcess_P0_Sigma_sm_ckm_gux_ttxemvexgdx
TTWMJJ_MADPROCDIR_4=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gux_ttxemvexgdx
TTWMJJ_MADPROCESS_5=CPPProcess_P0_Sigma_sm_ckm_gux_ttxemvexgsx
TTWMJJ_MADPROCDIR_5=Madgraph/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/SubProcesses/P0_Sigma_sm_ckm_gux_ttxemvexgsx

#TTbar
TTbar_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_DECAY_ggtt/lib
TTbar_MADINCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_ggtt/src
TTbar_MADMODELLIB=model_sm_ggtt
TTbar_MADPROCESS_0=CPPProcess_P0_Sigma_sm_gg_ttx
TTbar_MADPROCDIR_0=Madgraph/PROC_SA_CPP_sm_DECAY_ggtt/SubProcesses/P0_Sigma_sm_gg_ttx

#TLLQ
TLLQ_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/lib
TLLQ_MADINCDIR=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/src
TLLQ_MADMODELLIB=model_sm_no_b_mass_pptllq
TLLQ_MADPROCESS_0=CPPProcess_P0_Sigma_sm_no_b_mass_dbx_txepemu
TLLQ_MADPROCDIR_0=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/SubProcesses/P0_Sigma_sm_no_b_mass_dbx_txepemu
TLLQ_MADPROCESS_1=CPPProcess_P0_Sigma_sm_no_b_mass_dxb_tepemux
TLLQ_MADPROCDIR_1=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/SubProcesses/P0_Sigma_sm_no_b_mass_dxb_tepemux
TLLQ_MADPROCESS_2=CPPProcess_P0_Sigma_sm_no_b_mass_ub_tepemd
TLLQ_MADPROCDIR_2=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/SubProcesses/P0_Sigma_sm_no_b_mass_ub_tepemd
TLLQ_MADPROCESS_3=CPPProcess_P0_Sigma_sm_no_b_mass_uxbx_txepemdx
TLLQ_MADPROCDIR_3=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/SubProcesses/P0_Sigma_sm_no_b_mass_uxbx_txepemdx

#WZJJ
WZJJ_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_DECAY_gqlnullgq/lib
WZJJ_MADINCDIR=Madgraph/PROC_SA_CPP_sm_DECAY_gqlnullgq/src
WZJJ_MADMODELLIB=model_sm_gqlnullgq
WZJJ_MADPROCESS_0=CPPProcess_P0_Sigma_sm_gdx_epvemupmumgux
WZJJ_MADPROCDIR_0=Madgraph/PROC_SA_CPP_sm_DECAY_gqlnullgq/SubProcesses/P0_Sigma_sm_gdx_epvemupmumgux
WZJJ_MADPROCESS_1=CPPProcess_P0_Sigma_sm_gu_epvemupmumgd
WZJJ_MADPROCDIR_1=Madgraph/PROC_SA_CPP_sm_DECAY_gqlnullgq/SubProcesses/P0_Sigma_sm_gu_epvemupmumgd

#THQ
THQ_MADLIBDIR=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/lib
THQ_MADINCDIR=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/src
THQ_MADMODELLIB=model_sm_no_b_mass_ppthq
THQ_MADPROCESS_0=CPPProcess_P0_Sigma_sm_no_b_mass_dbx_txhu
THQ_MADPROCDIR_0=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/SubProcesses/P0_Sigma_sm_no_b_mass_dbx_txhu
THQ_MADPROCESS_1=CPPProcess_P0_Sigma_sm_no_b_mass_dxb_thux
THQ_MADPROCDIR_1=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/SubProcesses/P0_Sigma_sm_no_b_mass_dxb_thux
THQ_MADPROCESS_2=CPPProcess_P0_Sigma_sm_no_b_mass_ub_thd
THQ_MADPROCDIR_2=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/SubProcesses/P0_Sigma_sm_no_b_mass_ub_thd
THQ_MADPROCESS_3=CPPProcess_P0_Sigma_sm_no_b_mass_uxbx_txhdx
THQ_MADPROCDIR_3=Madgraph/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/SubProcesses/P0_Sigma_sm_no_b_mass_uxbx_txhdx


#------------------------------------------------------------------------------
# GoSam definitions

GOSAM_DIR=

#------------------------------------------------------------------------------
# ROOT definitions
ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs) -lMathMore -lMinuit2

#------------------------------------------------------------------------------
# LHAPDF definitions
LHAPDFINCDIR=-I${LHAPDF}/include
LHAPDFLIB=-L${LHAPDF}/lib -lLHAPDF

#------------------------------------------------------------------------------
# g++ options

CXX = g++
CXXFLAGS = -g -fPIC  -O0 -Wall -Wno-deprecated -static -fpermissive
LD = g++

SOFLAGS = #-shared #-dynamiclib #-single_module #-undefined dynamic_lookup

CXXFLAGS     += $(ROOTCFLAGS) -I${TTH_MADPROCDIR} -I$(TTH_MADINCDIR) -I${THAD_MADPROCDIR} -I$(THAD_MADINCDIR) -I${ATHAD_MADPROCDIR} -I$(ATHAD_MADINCDIR) -I${TLEP_MADPROCDIR} -I$(TLEP_MADINCDIR) -I${H2L2NU_MADPROCDIR} -I$(H2L2NU_MADINCDIR) -I${TTLL_MADPROCDIR} -I$(TTLL_MADINCDIR) -I${TTWP_MADPROCDIR_udx} -I${TTWP_MADPROCDIR_cdx} -I${TTWP_MADPROCDIR_usx} -I$(TTWP_MADINCDIR) -I${TTWM_MADPROCDIR_dux} -I${TTWM_MADPROCDIR_dcx} -I${TTWM_MADPROCDIR_sux} -I$(TTWM_MADINCDIR) ${LHAPDFINCDIR}  -I${TTWPJJ_MADPROCDIR_0} -I${TTWPJJ_MADPROCDIR_1} -I${TTWPJJ_MADPROCDIR_2} -I${TTWPJJ_MADPROCDIR_3} -I${TTWPJJ_MADPROCDIR_4} -I${TTWPJJ_MADPROCDIR_5} -I${TTWPJJ_MADINCDIR}  -I${TTWMJJ_MADPROCDIR_0} -I${TTWMJJ_MADPROCDIR_1} -I${TTWMJJ_MADPROCDIR_2} -I${TTWMJJ_MADPROCDIR_3} -I${TTWMJJ_MADPROCDIR_4} -I${TTWMJJ_MADPROCDIR_5} -I${TTWMJJ_MADINCDIR} -I${TTbar_MADPROCDIR_0} -I${TTbar_MADINCDIR}  -I${TLLQ_MADPROCDIR_0} -I${TLLQ_MADPROCDIR_1} -I${TLLQ_MADPROCDIR_2} -I${TLLQ_MADPROCDIR_3} -I${TLLQ_MADINCDIR} -I${WZJJ_MADPROCDIR_0} -I${WZJJ_MADPROCDIR_1} -I${WZJJ_MADINCDIR}  -I${THQ_MADPROCDIR_0} -I${THQ_MADPROCDIR_1} -I${THQ_MADPROCDIR_2} -I${THQ_MADPROCDIR_3} -I${THQ_MADINCDIR}

LIBS         = ${ROOTGLIBS} ${ROOTLIBS} 
#------------------------------------------------------------------------------
# Compilation

all: libMEMmultilepton.a

clean:
	rm *.o
	rm *.a

memobjects = MEPhaseSpace.o MultiLepton.o HypIntegrator.o TransferFunctions.o ParticleSelector.o Permutations.o ConfigParser.o Tools.o

processobjects = ${TTH_MADPROCDIR}/CPPProcess.o ${THAD_MADPROCDIR}/CPPProcess_tbwjj.o ${ATHAD_MADPROCDIR}/CPPProcess_antitbwjj.o ${TLEP_MADPROCDIR}/CPPProcess_tbwlnu.o ${H2L2NU_MADPROCDIR}/CPPProcess_hw2l2nu.o ${TTLL_MADPROCDIR}/CPPProcess_ggttll.o ${TTWP_MADPROCDIR_udx}/${TTWP_MADPROCESS_udx}.o ${TTWP_MADPROCDIR_cdx}/${TTWP_MADPROCESS_cdx}.o ${TTWP_MADPROCDIR_usx}/${TTWP_MADPROCESS_usx}.o ${TTWM_MADPROCDIR_dux}/${TTWM_MADPROCESS_dux}.o ${TTWM_MADPROCDIR_dcx}/${TTWM_MADPROCESS_dcx}.o ${TTWM_MADPROCDIR_sux}/${TTWM_MADPROCESS_sux}.o ${TTWPJJ_MADPROCDIR_0}/${TTWPJJ_MADPROCESS_0}.o ${TTWPJJ_MADPROCDIR_1}/${TTWPJJ_MADPROCESS_1}.o ${TTWPJJ_MADPROCDIR_2}/${TTWPJJ_MADPROCESS_2}.o ${TTWPJJ_MADPROCDIR_3}/${TTWPJJ_MADPROCESS_3}.o ${TTWPJJ_MADPROCDIR_4}/${TTWPJJ_MADPROCESS_4}.o ${TTWPJJ_MADPROCDIR_5}/${TTWPJJ_MADPROCESS_5}.o  ${TTWMJJ_MADPROCDIR_0}/${TTWMJJ_MADPROCESS_0}.o ${TTWMJJ_MADPROCDIR_1}/${TTWMJJ_MADPROCESS_1}.o ${TTWMJJ_MADPROCDIR_2}/${TTWMJJ_MADPROCESS_2}.o ${TTWMJJ_MADPROCDIR_3}/${TTWMJJ_MADPROCESS_3}.o ${TTWMJJ_MADPROCDIR_4}/${TTWMJJ_MADPROCESS_4}.o ${TTWMJJ_MADPROCDIR_5}/${TTWMJJ_MADPROCESS_5}.o  ${TTbar_MADPROCDIR_0}/${TTbar_MADPROCESS_0}.o ${TLLQ_MADPROCDIR_0}/${TLLQ_MADPROCESS_0}.o ${TLLQ_MADPROCDIR_1}/${TLLQ_MADPROCESS_1}.o ${TLLQ_MADPROCDIR_2}/${TLLQ_MADPROCESS_2}.o ${TLLQ_MADPROCDIR_3}/${TLLQ_MADPROCESS_3}.o  ${WZJJ_MADPROCDIR_0}/${WZJJ_MADPROCESS_0}.o ${WZJJ_MADPROCDIR_1}/${WZJJ_MADPROCESS_1}.o  ${THQ_MADPROCDIR_0}/${THQ_MADPROCESS_0}.o ${THQ_MADPROCDIR_1}/${THQ_MADPROCESS_1}.o ${THQ_MADPROCDIR_2}/${THQ_MADPROCESS_2}.o ${THQ_MADPROCDIR_3}/${THQ_MADPROCESS_3}.o

modelobjects = ${TTH_MADINCDIR}/read_slha.o ${TTH_MADINCDIR}/HelAmps_sm.o ${TTH_MADINCDIR}/Parameters_sm.o ${THAD_MADINCDIR}/HelAmps_sm_tbwjj.o ${THAD_MADINCDIR}/Parameters_sm_tbwjj.o ${ATHAD_MADINCDIR}/HelAmps_sm_antitbwjj.o ${ATHAD_MADINCDIR}/Parameters_sm_antitbwjj.o ${TLEP_MADINCDIR}/HelAmps_sm_tbwlnu.o ${TLEP_MADINCDIR}/Parameters_sm_tbwlnu.o ${H2L2NU_MADINCDIR}/HelAmps_sm_hw2l2nu.o ${H2L2NU_MADINCDIR}/Parameters_sm_hw2l2nu.o ${TTLL_MADINCDIR}/HelAmps_sm_ggttll.o ${TTLL_MADINCDIR}/Parameters_sm_ggttll.o ${TTWP_MADINCDIR}/HelAmps_sm_ckm_qqttlpvl.o ${TTWP_MADINCDIR}/Parameters_sm_ckm_qqttlpvl.o ${TTWM_MADINCDIR}/HelAmps_sm_ckm_qqttlmvl.o ${TTWM_MADINCDIR}/Parameters_sm_ckm_qqttlmvl.o ${TTWPJJ_MADINCDIR}/HelAmps_sm_ckm_ppttlpvljj.o ${TTWPJJ_MADINCDIR}/Parameters_sm_ckm_ppttlpvljj.o ${TTWMJJ_MADINCDIR}/HelAmps_sm_ckm_ppttlmvljj.o ${TTWMJJ_MADINCDIR}/Parameters_sm_ckm_ppttlmvljj.o ${TTbar_MADINCDIR}/HelAmps_sm_ggtt.o ${TTbar_MADINCDIR}/Parameters_sm_ggtt.o ${TLLQ_MADINCDIR}/HelAmps_sm_no_b_mass_pptllq.o ${TLLQ_MADINCDIR}/Parameters_sm_no_b_mass_pptllq.o ${WZJJ_MADINCDIR}/HelAmps_sm_gqlnullgq.o ${WZJJ_MADINCDIR}/Parameters_sm_gqlnullgq.o ${THQ_MADINCDIR}/HelAmps_sm_no_b_mass_ppthq.o ${THQ_MADINCDIR}/Parameters_sm_no_b_mass_ppthq.o

objects = ${memobjects} ${processobjects} ${modelobjects}

libMEMmultilepton.a: $(objects) 
	ar -r libMEMmultilepton.a -o $(objects) 


Tools.o: src/Tools.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c src/Tools.cpp

ParticleSelector.o: src/ParticleSelector.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c src/ParticleSelector.cpp

Permutations.o: src/Permutations.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c src/Permutations.cpp

TransferFunctions.o: src/TransferFunctions.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c src/TransferFunctions.cpp

ConfigParser.o: src/ConfigParser.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c src/ConfigParser.cpp

HypIntegrator.o: src/HypIntegrator.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c src/HypIntegrator.cpp

MEPhaseSpace.o: src/MEPhaseSpace.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c src/MEPhaseSpace.cpp

MultiLepton.o: src/MultiLepton.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c src/MultiLepton.cpp


