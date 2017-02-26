#include "mvector.hpp"
#include <cassert>
#include <iostream>

// print message separately before the failed assertion, re-evaluate assert to display line number and file details
#define ASSERT(test, msg) if(!test) { std::cerr << msg << std::endl; assert(test); }

void main()
{
    std::vector<double> v11 = { 1, 2, 3 };
    xstd::mvector<1, double> mv1 = v11;
    std::vector<double> v12 = mv1;
    ASSERT(mv1.size() == 3 && mv1[0] == 1 && mv1[1] == 2 && mv1[2] == 3, "Failed mvector<1,T> assign with vector<T> =operator");
    ASSERT(v12.size() == 3 && v12[0] == 1 && v12[1] == 2 && v12[2] == 3, "Failed vector<T> assign with mvector<1,T> =operator");
    
    xstd::mvector<2, double> mv2({1, 3}), mv3;
    mv2[0] = v11;
    mv3.push_back(v11);
    std::vector<double> v3 = mv2[0];
    std::vector<double> v4 = mv3[0];
    ASSERT(mv2.size() == 1 && mv2[0].size() == 3 && mv2[0][0] == 1 && mv2[0][1] == 2 && mv2[0][2] == 3, "Failed mvector<2,T> indexed assign with vector<T> =operator");
    ASSERT(mv3.size() == 1 && mv3[0].size() == 3 && mv3[0][0] == 1 && mv3[0][1] == 2 && mv3[0][2] == 3, "Failed vector<T> assign with mvector<2,T> push_back");

    std::vector<double> v5(mv1);
    std::vector<double> v6(mv2[0]);
    ASSERT(v5.size() == 3 && v5[0] == 1 && v5[1] == 2 && v5[2] == 3, "Failed vector<T> assign with mvector<1,T> iterator constructor");
    ASSERT(v6.size() == 3 && v6[0] == 1 && v6[1] == 2 && v6[2] == 3, "Failed vector<T> assign with indexed mvector<2,T> iterator constructor");

    std::vector<double> v7 = xstd::mvector<1, double>(v11);
    std::vector<double> v8 = xstd::mvector<1, double>(mv1);
    xstd::mvector<1, double> mv4 = std::vector<double>(mv1);    
    ASSERT(v7.size() == 3 && v7[0] == 1 && v7[1] == 2 && v7[2] == 3, "Failed vector<T> assign with mvector<1,T> constructor from other vector<T>");
    ASSERT(v8.size() == 3 && v8[0] == 1 && v8[1] == 2 && v8[2] == 3, "Failed vector<T> assign with mvector<1,T> constructor from other mvector<1,T>");
    ASSERT(mv4.size() == 3 && mv4[0] == 1 && mv4[1] == 2 && mv4[2] == 3, "Failed mvector<1,T> assign with vector<T> constructor from other mvector<1,T>");

    std::cout << "All tests passed!" << std::endl;
    std::getchar(); // wait key to allow message visualisation
}
