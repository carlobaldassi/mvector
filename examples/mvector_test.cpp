#include "mvector.hpp"
#include <iostream>
#include <exception>
#include <cassert>

// print message separately before exit, re-evaluate assert to display line number and file details
#define ASSERT_MSG(test, msg) if(!(test)) { std::cerr << msg << std::endl; assert(test); }

int main()
{
    std::vector<double> v11 = { 1, 2, 3 };
    std::vector<double> v21 = { 6, 5, 4 };
    xstd::mvector<1, double> mv1 = v11;
    std::vector<double> v12 = mv1;
    ASSERT_MSG(mv1.size() == 3 && mv1[0] == 1 && mv1[1] == 2 && mv1[2] == 3, "Failed mvector<1,T> assign with vector<T> =operator");
    ASSERT_MSG(v12.size() == 3 && v12[0] == 1 && v12[1] == 2 && v12[2] == 3, "Failed vector<T> assign with mvector<1,T> =operator");    
    xstd::mvector<2, double> mv2({1, 3}), mv3({2, 3});
    xstd::mvector<2, double> mv4, mv5, mv6, mv7;    
    mv2[0] = v11;
    mv3[0] = v21;
    mv3[1] = v11;
    mv4 = xstd::mvector<2, double>({2, 3});
    mv4[1] = v21;
    mv5 = xstd::mvector<2, double>({3, 0});
    xstd::mvector<1, double> mv52(3);
    mv52[0] = 7;
    mv52[1] = 8;
    mv52[2] = 9;    
    ASSERT_MSG(mv2.size() == 1 && mv2[0].size() == 3 && mv2[0][0] == 1 && mv2[0][1] == 2 && mv2[0][2] == 3, 
               "Failed mvector<2,T> indexed assign with vector<T> =operator");
    ASSERT_MSG(mv3.size() == 2 && mv3[0].size() == 3 && mv3[1].size() == 3 && 
               mv3[0][0] == 6 && mv3[0][1] == 5 && mv3[0][2] == 4 &&
               mv3[1][0] == 1 && mv3[1][1] == 2 && mv3[1][2] == 3, 
               "Failed to fully assign mvector<2,T> sub-vectors from vector<T> instances");
    ASSERT_MSG(mv4.size() == 2 && mv4[0].size() == 3 && mv4[1].size() == 3, 
               "Failed to properly initialized mvector<2,T> specified dimensions although not all assigned yet");
    ASSERT_MSG(mv4[0][0] == 0 && mv4[0][1] == 0 && mv4[0][2] == 0 &&
               mv4[1][0] == 6 && mv4[1][1] == 5 && mv4[1][2] == 4, 
               "Failed to partially assign mvector<2,T> sub-vector from vector<T> instance, other left to default");
    ASSERT_MSG(mv5.size() == 3 && mv5[0].size() == 0 && mv5[1].size() == 0 && mv5[2].size() == 0, 
               "Failed mvector<2,T> default empty size when not yet assigned and size=0");
    mv5[1] = mv52;
    ASSERT_MSG(mv5.size() == 3 && mv5[0].size() == 0 && mv5[1].size() == 3 && mv5[2].size() == 0, 
               "Failed mvector<2,T> size when only partially assigned");
    mv5[0] = std::vector<double>{ 9, 7, 5, 3, 1 };    
    mv5[2] = std::vector<double>(2, 1);
    ASSERT_MSG(mv5.size() == 3 && mv5[0].size() == 5 && mv5[1].size() == 3 && mv5[2].size() == 2, 
               "Failed mvector<2,T> element assign with different size and type vectors");
    ASSERT_MSG(mv5[0][0] == 9 && mv5[0][1] == 7 && mv5[0][2] == 5 && mv5[0][3] == 3 && mv5[0][4] == 1, 
               "Failed mvector<2,T> element assign with iterator");
    ASSERT_MSG(mv5[1][0] == 7 && mv5[1][1] == 8 && mv5[1][2] == 9, 
               "Failed mvector<2,T> element assign with iterator");
    ASSERT_MSG(mv5[2][0] == 1 && mv5[2][1] == 1, 
               "Failed mvector<2,T> element assign with vector<T> constructor");
    mv6 = mv3;
    ASSERT_MSG(mv6.size() == 2 && mv6[0].size() == 3 && mv6[1].size() == 3 && 
               mv6[0][0] == 6 && mv6[0][1] == 5 && mv6[0][2] == 4 &&
               mv6[1][0] == 1 && mv6[1][1] == 2 && mv6[1][2] == 3, 
               "Failed mvector<2,T> copy constructor from other mvector<2,T>");
    ASSERT_MSG(mv7.size() == 0, 
               "Failed to initialize mvector<2,T> to default empty size");
    mv7.push_back(v21);
    ASSERT_MSG(mv7.size() == 1 && mv7[0].size() == 3 &&
               mv7[0][0] == 6 && mv7[0][1] == 5 && mv7[0][2] == 4, 
               "Failed mvector<2,T> inserting with vector<T> push_back");  
    mv7.push_back(mv5[0]);
    ASSERT_MSG(mv7.size() == 2 && mv7[0].size() == 3 && mv7[1].size() == 5 &&                
               mv7[0][0] == 6 && mv7[0][1] == 5 && mv7[0][2] == 4 &&
               mv7[1][0] == 9 && mv7[1][1] == 7 && mv7[1][2] == 5 && mv7[1][3] == 3 && mv7[1][4] == 1, 
               "Failed mvector<2,T> inserting with different size vector<T> push_back");        
    mv7.push_back(mv5[1]);
    ASSERT_MSG(mv7.size() == 3 && mv7[0].size() == 3 && mv7[1].size() == 5 && mv7[2].size() == 3 &&
               mv7[0][0] == 6 && mv7[0][1] == 5 && mv7[0][2] == 4 &&
               mv7[1][0] == 9 && mv7[1][1] == 7 && mv7[1][2] == 5 && mv7[1][3] == 3 && mv7[1][4] == 1 &&
               mv7[2][0] == 7 && mv7[2][1] == 8 && mv7[2][2] == 9,
               "Failed mvector<2,T> inserting with mvector<1,T> push_back from indirectly accessed within another mvector<2,T>"); 

    std::vector<double> v3 = mv2[0];
    std::vector<double> v4(mv1);
    std::vector<double> v5(mv2[0]);
    ASSERT_MSG(v4.size() == 3 && v4[0] == 1 && v4[1] == 2 && v4[2] == 3, 
               "Failed vector<T> assign with mvector<1,T> iterator constructor");
    ASSERT_MSG(v5.size() == 3 && v5[0] == 1 && v5[1] == 2 && v5[2] == 3, 
               "Failed vector<T> assign with indexed mvector<2,T> iterator constructor");

    std::vector<double> v6 = xstd::mvector<1, double>(v11);
    std::vector<double> v7 = xstd::mvector<1, double>(mv1);
    xstd::mvector<1, double> mv8 = std::vector<double>(mv1);
    ASSERT_MSG(v6.size() == 3 && v6[0] == 1 && v6[1] == 2 && v6[2] == 3, 
               "Failed vector<T> assign with mvector<1,T> constructor from other vector<T>");
    ASSERT_MSG(v7.size() == 3 && v7[0] == 1 && v7[1] == 2 && v7[2] == 3, 
               "Failed vector<T> assign with mvector<1,T> constructor from other mvector<1,T>");
    ASSERT_MSG(mv8.size() == 3 && mv8[0] == 1 && mv8[1] == 2 && mv8[2] == 3, 
               "Failed mvector<1,T> assign with vector<T> constructor from other mvector<1,T>");

    std::cout << "All tests passed!" << std::endl;
    std::getchar(); // wait key to allow message visualisation

    return 0;
}
