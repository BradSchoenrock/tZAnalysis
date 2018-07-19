ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --libs) -lMinuit -lEG -lTreePlayer
CXX = g++
CXXFLAGS  = -I. -I$(ROOTSYS)/include -L./ -O -Wall -fPIC -I/home/schoenr1/work/ztAnalysis
CXXFLAGS  += $(ROOTCFLAGS) #-L/home/schoenr1/Snowmass/Delphes
LIBS    = $(ROOTLIBS)# -lDelphes

DEPS = ztAnalysis.h #Delphes.h #Delphes2.h
OBJS = ztAnalysis.o #Delphes.o #Delphes2.o

%.o: %.C $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

%.o: %.cxx $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

ztAnalysis: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS) $(LIBS)

# suffix rule
.cc.o:
	$(CXX) -c $(CXXFLAGS) $(GDBFLAGS) $<
# clean
clean:
	rm -f ztAnalysis *~ *.o *.o~ *.so core 