.PHONY: all
all : mvector_example1 mvector_example2 mvector_example_c++0x mvector_test

CXX = g++
CXXFLAGS = -Wall -g -O3 -I.. -std=c++0x

mvector_example1 : mvector_example1.cpp ../mvector.hpp
	$(CXX) $(CXXFLAGS) mvector_example1.cpp -o mvector_example1

mvector_example2 : mvector_example2.cpp ../mvector.hpp
	$(CXX) $(CXXFLAGS) mvector_example2.cpp -o mvector_example2

mvector_example_c++0x : mvector_example_c++0x.cpp ../mvector.hpp
	$(CXX) $(CXXFLAGS) mvector_example_c++0x.cpp -o mvector_example_c++0x
	
mvector_test : mvector_test.cpp ../mvector.hpp
	$(CXX) $(CXXFLAGS) mvector_test.cpp -o mvector_test

clean:
	rm mvector_example1 mvector_example2 mvector_example_c++0x mvector_test
