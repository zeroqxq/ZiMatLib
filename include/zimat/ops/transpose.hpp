#pragma once
#include "../core/matrix.hpp"

namespace zimat {
    template<typename T, typename T1>
    matrix<T,T1> matrix<T,T1>::t() const {
        matrix<T, T1> temp(this->cols_, this->rows_, this->base_numeric_);

        for (T1 i = 0; i < this->rows_; ++i) {
            for (T1 j = 0; j < this->cols_; ++j) {
                temp(j + this->base_numeric_, i + this->base_numeric_) =
                    (*this)(i + this->base_numeric_, j + this->base_numeric_);
            }
        }
        return temp;
    }

    template<typename T, typename T1>
    matrix<T,T1> matrix<T,T1>::transpose() const {
        return this->t();
    }
    
}
