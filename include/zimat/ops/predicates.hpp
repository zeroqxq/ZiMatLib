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
}