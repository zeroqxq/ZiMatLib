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
        return *std::max_element(data_.begin(), data_.end());
    }

    template<typename T>
    T matrix<T>::max(const matrix& matrix) const {
        return matrix.max();
    }

    template<typename T>
    T matrix<T>::min() const {
        return *std::min_element(data_.begin(), data_.end());
    }

    template<typename T>
    T matrix<T>::min(const matrix& matrix) const {
        return matrix.min();
    }

    template<typename T>
    T matrix<T>::max_in_row(size_t row) const {
        auto values = get_row(row);
        return *std::max_element(values.begin(), values.end());
    }

    template<typename T>
    T matrix<T>::min_in_row(size_t row) const {
        auto values = get_row(row);
        return *std::min_element(values.begin(), values.end());
    }

    template<typename T>
    T matrix<T>::max_in_col(size_t col) const {
        auto values = get_row(col);
        return *std::max_element(values.begin(), values.end());
    }

    template<typename T>
    T matrix<T>::min_in_col(size_t col) const {
        auto values = get_row(col);
        return *std::min_element(values.begin(), values.end());
    }

}