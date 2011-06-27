.PHONY: all
all : mvector_example1 mvector_example2

CXX = g++
CXXFLAGS = -Wall -g -O3 -I..

mvector_example1 : mvector_example1.cpp ../mvector.hpp
	$(CXX) $(CXXFLAGS) mvector_example1.cpp -o mvector_example1

mvector_example2 : mvector_example2.cpp ../mvector.hpp
	$(CXX) $(CXXFLAGS) mvector_example2.cpp -o mvector_example2

clean:
	rm mvector_example1 mvector_example2
