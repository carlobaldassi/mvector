#include <iostream>
#include <cstdlib>
#include <set>

#include "mvector.hpp"

using namespace std;
using namespace xstd;

std::ostream & operator<<(std::ostream & os, std::set<int> const & ss)
{
	os << "{";
	for (std::set<int>::const_iterator i = ss.begin(); i != ss.end(); ++i) {
		os << *i;
		std::set<int>::const_iterator j(i);
		++j;
		if (j != ss.end()) {
			os << ",";
		}
	}
	os << "}";
	return os;
}

int main(int argc, char ** argv)
{
	//// let's create a small set filled with some random entries
	set<int> a;
	a.insert(3);
	a.insert(6);
	a.insert(-5);
	cout << "a basic set:" << endl;
	cout << a << endl << endl;

	//// 3x4 matrix of sets
	mvector<2, set<int> > b(mshape<2>(3, 4), a);

	cout << "a 3x4 matrix of sets:" << endl;
	cout << b << endl;

	return 0;
}
