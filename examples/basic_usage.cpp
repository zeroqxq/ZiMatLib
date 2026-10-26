#include "zimat/zimat.hpp"
#include <iostream>


int main(){

    zimat::matrix<int> a(2,2);
    for (int i = 1; i <= a.get_rows(); ++i) {
        for (int j = 1; j <= a.get_cols(); ++j) {
            a(i,j) = 1;
        }
    }

    zimat::matrix<int> b(2,2);
    for (int i = 1; i <= b.get_rows(); ++i) {
        for (int j = 1; j <= b.get_cols(); ++j) {
            b(i,j) = 2;
        }
    }

    zimat::matrix<int> c = a * b;
    zimat::matrix<int> d = c * 2; 
    zimat::matrix<int> e = d / 2; 


    //output full matrix c
    std::cout << "|" << c(1,1) << " " << c(1,2) << "|" << std::endl;
    std::cout << "|" << c(2,1) << " " << c(2,2) << "|" << std::endl;

    std::cout << std::endl;

    //output full matrix d
    std::cout << "|" << d(1,1) << " " << d(1,2) << "|" << std::endl;
    std::cout << "|" << d(2,1) << " " << d(2,2) << "|" << std::endl;

    std::cout << std::endl;

    //output full matrix e
    std::cout << "|" << e(1,1) << " " << e(1,2) << "|" << std::endl;
    std::cout << "|" << e(2,1) << " " << e(2,2) << "|" << std::endl;
    
    std::cout << std::endl;
    
    e(1,2) = 3;

    //output full matrix e with changes
    std::cout << "|" << e(1,1) << " " << e(1,2) << "|" << std::endl;
    std::cout << "|" << e(2,1) << " " << e(2,2) << "|" << std::endl;

    std::cout << std::endl;

    //output determinant for e with changes
    std::cout << e.det() << std::endl;

    return 0;
}