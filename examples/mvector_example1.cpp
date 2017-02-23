#include <iostream>
#include <cstdlib>

#include "mvector.hpp"

using namespace std;

//// the mvector and mshape classes live in the xstd namespace
using namespace xstd;

int main(int argc, char ** argv)
{
    //// 4x4 matrix, filled with zeroes
    mvector<2, double> a(4);

    cout << "4x4 matrix, filled with zeroes:" << endl;
    cout << a << endl << endl;

    //// 2x3x4 "tensor", filled with 1's
    size_t v[3] = {2, 3, 4};
    mvector<3, double> b(v, 1.);

    cout << "2x3x4 tensor, filled with ones:" << endl;
    cout << b << endl << endl;

    //// same as above, alternative "inline" constructor
    mvector<3, double> c(mshape<3>(2, 3, 4), 1.);

    cout << "same as above:" << endl;
    cout << c << endl << endl;

    //// reshape the above "tensor" from 2x3x4 to 3x4x2 and fill with 2's
    c.reshape(mshape<3>(3, 4, 2), 2.);

    //// alternative (non-inline) way to obtain the same reshaping as above:
    // size_t w[3] = {3, 4, 2};
    // c.reshape(w, 2.);

    cout << "the above tensor reshaped to 3x4x2; new elements are filled with twos:" << endl;
    cout << c << endl << endl;

    //// reshape again the above "tensor" from 3x4x2 to 3x3x3 and fill with 3's
    c.reshape(3, 3.);

    cout << "the above tensor reshaped again to 3x3x3; new elements are filled with threes:" << endl;
    cout << c << endl << endl;

    return 0;
}
