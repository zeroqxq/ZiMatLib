#include "../core/matrix.hpp"
#include <numeric>

namespace zimat {
    
    template<typename T>
    T matrix<T>::sum() const {
        return std::accumulate(data_.begin(), data_.end(), T{});
    }

    template<typename T>
    T matrix<T>::sum(const matrix& matrix) const {
        return matrix.sum();
    }

    template<typename T>
    T matrix<T>::max() const {
        return std::max_element(data_.begin(), data_.end());
    }

    template<typename T>
    T matrix<T>::max(const matrix& matrix) const {
        return matrix.max();
    }

    template<typename T>
    T matrix<T>::min() const {
        return std::min_element(data_.begin(), data_.end());
    }

    template<typename T>
    T matrix<T>::min(const matrix& matrix) const {
        return matrix.min();
    }

}