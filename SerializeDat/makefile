CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRCS = src/Source.cpp
OBJS = $(patsubst src/%.cpp,build/%.o,$(SRCS))
EXEC = build/test
DEPFLAGS = -MMD -MP
INCDIR = -Iinclude

.PHONY: all clean

all: $(EXEC)

debug: CXXFLAGS += -g -DDEBUG
debug: $(EXEC)

release: CXXFLAGS += -O2
release: $(EXEC)

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCDIR) -c $< -o $@

-include $(OBJS:.o=.d)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS) $(OBJS:.o=.d) $(EXEC) build

build:
	mkdir -p build