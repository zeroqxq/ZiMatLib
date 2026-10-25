#include "zimat.hpp"
#include <iostream>


int main(){

    zimat::matrix<int> a(2,2);
    for (int i = 1; i <= a.get_rows(); ++i) {
        for (int j = 1; j <= a.get_cols(); ++j) {
            a(i,j) = 5;
        }
    }

    zimat::matrix<int> b(2,2);
    for (int i = 1; i <= b.get_rows(); ++i) {
        for (int j = 1; j <= b.get_cols(); ++j) {
            b(i,j) = 1;
        }
    }

    zimat::matrix<int> c = a - b; 

    std::cout << c(1,1) << std::endl;

    return 0;
}