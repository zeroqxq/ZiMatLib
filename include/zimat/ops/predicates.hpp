#pragma once
#include "../core/matrix.hpp"
#include <cstddef>

namespace zimat {

    template<typename T>
    bool matrix<T>::empty() const {
        return rows_ == 0 or cols_ == 0;
    }

    template<typename T>
    bool matrix<T>::is_empty() const {
        return this->empty();
    }


    template<typename T>
    bool matrix<T>::is_zeros() const {
        for (size_t i = 0; i < this->data_.size(); ++i) {
            if (this->data_[i] != 0) {
                return false;
            }
        }

        return true;
    }

    template<typename T>
    bool matrix<T>::zeroqxq() const {
        return this->is_zeros();
    }

    template<typename T>
    bool matrix<T>::is_square() const {
        return rows_ == cols_;
    }

    template<typename T>
    bool matrix<T>::is_identity() const {
        if (!is_square()) {
            return false;
        }

        for (size_t row = 0; row < rows_; ++row) {
            for (size_t col = 0; col < cols_; ++col) {
                const T value = (*this)(row + base_numeric_, col + base_numeric_);
                if (row != col and value != T{0})
                    return false;
                if (row == col and value != T{1})
                    return false;
            }
        }

        return true;
    }

    template<typename T>
    bool matrix<T>::is_diagonal() const {
        if (!is_square()) {
            return false;
        }
        for (size_t row = 0; row < rows_; ++row) {
            for (size_t col = 0; col < cols_; ++col) {
                const T value = (*this)(row + base_numeric_, col + base_numeric_);
                if (row != col and value != T{0})
                    return false;
            }
        }
        return true;

    }

    // template<typename T>
    // bool matrix<T>::is_symmetric() const {
    //     return *this == this->transpose();
    // }
    // Legacy; дольше , лишние выделения данных. Ниже оптималдьный метод

    template <typename T>
    bool matrix<T>::is_symmetric() const {
        if (!is_square()) {
            return false;
        }

        for (size_t row = 0; row < rows_; ++row) {
            for (size_t col = row + 1; col < cols_; ++col) {
                if ((*this)(row + base_numeric_, col + base_numeric_) !=
                    (*this)(col + base_numeric_, row + base_numeric_)) {
                    return false;
                }
            }
        }

        return true;
    }

    template <typename T>
    bool matrix<T>::is_upper_triangular() const {
        if (!is_square()) {
            return false;
        }

        for (size_t row = 1; row < rows_; ++row) {
            for (size_t col = 0; col < row; ++col) {
                if ((*this)(row + base_numeric_, col + base_numeric_) != T{}) {
                    return false;
                }
            }
        }

        return true;
    }

    template <typename T>
    bool matrix<T>::is_lower_triangular() const {
        if (!is_square()) {
            return false;
        }

        for (size_t row = 0; row < rows_; ++row) {
            for (size_t col = row + 1; col < cols_; ++col) {
                if ((*this)(row + base_numeric_, col + base_numeric_) != T{}) {
                    return false;
                }
            }
        }

        return true;
    }
}