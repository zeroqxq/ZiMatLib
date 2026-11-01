#pragma once
#include "../core/matrix.hpp"
#include <stdexcept>

namespace zimat {

    template<typename T>
    T matrix<T>::trace() const {
        if (rows_ != cols_) {
            throw std::invalid_argument("Trace is only defined for square matrices");
        }

        T sum = {};

        for (size_t i = 1; i <= rows_; ++i) {
            sum += (*this)(i, i);
        }

        return sum;
    }

}