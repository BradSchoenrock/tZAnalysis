ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --libs) -lMinuit -lEG -lTreePlayer
CXX = g++
#CXXFLAGS  = -I. -I$(ROOTSYS)/include -L./ -O -Wall -fPIC -I/msu/data/t3fast1/schoenr1/tZAnalysis/tZ_TriLepton/Root
CXXFLAGS  = -I. -I$(ROOTSYS)/include -L./ -O -Wall -fPIC -I/msu/data/t3fast1/carolina/tZ/tZAnalysis/tZ_TriLepton/Root

CXXFLAGS  += $(ROOTCFLAGS) -lstdc++
LIBS    = $(ROOTLIBS)

DEPS = ztAnalysis.h 
OBJS = ztAnalysis.o 
THING = Stack.o AtlasLabels.o AtlasStyle.o AtlasUtils.o 
THING1 = TexTable.o EventYield.o
SRC1 = ./AtlasStyle/

%.o: %.C $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

%.o: %.cxx $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

ztAnalysis: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS) $(LIBS)

Stack: $(THING)
	$(CXX) -o $@ $(THING) $(CXXFLAGS) $(LIBS) $(ROOTLIBS)

EventYield: $(THING1)
	$(CXX) -o $@ $(THING1) $(CXXFLAGS) $(LIBS) $(ROOTLIBS)


# suffix rule
.cc.o:
	$(CXX) -c $(CXXFLAGS) $(GDBFLAGS) $<
# clean
clean:
	rm -f Stack ztAnalysis *~ *.o *.o~ *.so core 