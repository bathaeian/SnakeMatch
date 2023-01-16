CC ?= gcc
CXX ?= g++
PROGRAM = snakematch
CXXFILES = MatchArea.cpp snakeGTK.cpp Board.cpp Control.cpp MatchW.cpp Snake.cpp StartW.cpp
OBJS = $(BUILT_SRC:.c=.o) $(CXXFILES:.cpp=.o)
DEPDIR = .deps
CXXFLAGS = `pkg-config --cflags gtkmm-3.0` -std=c++11 -Wall -g
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtkmm-3.0`
GLIB_COMPILE_RESOURCES = $(shell pkg-config --variable=glib_compile_resources gio-2.0)

all: $(PROGRAM)

-include $(OBJS:%.o=$(DEPDIR)/%.Po)

%.o: %.cpp
	@mkdir -p $(DEPDIR)
	$(CXX) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $(CXXFLAGS) $<
	@mv -f $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $(OBJS) $(LIBS)

clean:
	rm -f $(BUILT_SRC)
	rm -f $(OBJS)
	rm -f $(PROGRAM)
