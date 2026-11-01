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

        for (size_t i = 0; i < rows_; ++i) {
            const size_t index = i + base_numeric_;
            sum += (*this)(index, index);
        }

        return sum;
    }

}
