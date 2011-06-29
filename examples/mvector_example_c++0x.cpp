#include <iostream>
#include <cstdlib>

#include "mvector.hpp"

//// This file is equivalent to mvector_example1, but
//// uses some of the new constructs from C++0x
//// Refer to the other example first.

using namespace std;

//// the mvector class lives in the xstd namespace
using namespace xstd;

int main(int argc, char ** argv)
{
	//// 4x4 matrix, filled with zeroes
	mvector<2, double> a = {4};
	//// note: the above works because it implicitly translates as:
	// mvector<2, double> a = {4, 4};
	//// i.e. if the initializer list is shorter than expected,
	//// the last element of the list is used to fill the rest.

	//// Another example of this behaviour would be:
	// mvector<4, double> a = {2, 3};
	//// which is the same as:
	// mvector<4, double> a = {2, 3, 3, 3};

	//// The same convention applies when using reshape,
	//// see below.

	cout << "4x4 matrix, filled with zeroes:" << endl;
	cout << a << endl << endl;

	//// 2x3x4 "tensor", filled with 1's
	size_t v[3] = {2, 3, 4};
	mvector<3, double> b(v, 1.);

	cout << "2x3x4 tensor, filled with ones:" << endl;
	cout << b << endl << endl;

	//// same as above, alternative "inline" constructor
	mvector<3, double> c({2, 3, 4}, 1.);

	cout << "same as above:" << endl;
	cout << c << endl << endl;

	//// reshape the above "tensor" from 2x3x4 to 3x4x2 and fill with 2's
	c.reshape({3, 4, 2}, 2.);

	//// alternative (non-inline) way to obtain the same reshaping as above:
	// size_t w[3] = {3, 4, 2};
	// c.reshape(w, 2.);

	cout << "the above tensor reshaped to 3x4x2; new elements are filled with twos:" << endl;
	cout << c << endl << endl;

	//// reshape again the above "tensor" from 3x4x2 to 3x3x3 and fill with 3's
	c.reshape(3, 3.);

	//// As with constructors, one would get the same result as above
	//// by using:
	// c.reshape({3}, 3.);
	//// because it is implicitly interpreted as:
	// c.reshape({3, 3, 3}, 3.);

	//// If instead one had written:
	// c.reshape({3, 2}, 3.);
	//// it would have been read as:
	// c.reshape({3, 2, 2}, 3.);

	cout << "the above tensor reshaped again to 3x3x3; new elements are filled with threes:" << endl;
	cout << c << endl << endl;

	return 0;
}
