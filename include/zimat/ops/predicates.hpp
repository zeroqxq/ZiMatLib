#include "../core/matrix.hpp"
#include <cstddef>

namespace zimat {

    template<typename T, typename T1>
    bool matrix<T,T1>::empty() const {
        return this->rows() == 0 or this->cols() == 0;
    }

    template<typename T, typename T1>
    bool matrix<T,T1>::is_empty() const {
        return this->empty();
    }


    template<typename T, typename T1>
    bool matrix<T,T1>::is_zeros() const {
        for (size_t i = 0; i < this->data_.size(); ++i) {
            if (this->data_[i] != 0) {
                return false;
            }
        }

        return true;
    }

    template<typename T, typename T1>
    bool matrix<T,T1>::zeroqxq() const {
        return this->is_zeros();
    }

    template<typename T, typename T1>
    bool matrix<T,T1>::is_square() const {
        return rows_ == this->cols();
    }
}