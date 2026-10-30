#include "../core/matrix.hpp"
#include <numeric>

namespace zimat {
    
    template<typename T, typename T1>
    T matrix<T,T1>::sum() const {
        return std::accumulate(data_.begin(), data_.end(), T{});
    }

    template<typename T, typename T1>
    T matrix<T,T1>::sum(const matrix& matrix) const {
        return matrix.sum();
    }

    template<typename T, typename T1>
    T matrix<T,T1>::max() const {
        return std::max_element(data_.begin(), data_.end());
    }

    template<typename T, typename T1>
    T matrix<T,T1>::max(const matrix& matrix) const {
        return matrix.max();
    }

    template<typename T, typename T1>
    T matrix<T,T1>::min() const {
        return std::min_element(data_.begin(), data_.end());
    }

    template<typename T, typename T1>
    T matrix<T,T1>::min(const matrix& matrix) const {
        return matrix.min();
    }

}