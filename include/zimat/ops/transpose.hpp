#pragma once
#include "../core/matrix.hpp"
#include <cstddef>

namespace zimat {
    template<typename T>
    matrix<T> matrix<T>::t() const {
        matrix<T> temp(this->cols_, this->rows_, this->base_numeric_);

        for (size_t i = 0; i < this->rows_; ++i) {
            for (size_t j = 0; j < this->cols_; ++j) {
                temp(j + this->base_numeric_, i + this->base_numeric_) =
                    (*this)(i + this->base_numeric_, j + this->base_numeric_);
            }
        }
        return temp;
    }

    template<typename T>
    matrix<T> matrix<T>::transpose() const {
        return this->t();
    }
    
}
