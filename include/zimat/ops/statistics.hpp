#include "../core/matrix.hpp"
#include <numeric>

namespace zimat {
    
    template<typename T, typename T1>
    T matrix<T,T1>::sum() const {
        return std::accumulate(data_.begin(), data_.end(), T{});
    }

    template<typename T, typename T1>
    T matrix<T,T1>::sum(matrix& matrix) const {
        return matrix.sum;
    }

}