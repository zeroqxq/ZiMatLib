#include "../core/matrix.hpp"


namespace zimat {


    template<typename T, typename T1>
    T& matrix<T,T1>::det() const {
        if (this->rows_ == 1 and this ->cols_ == 1){
            return data_[0];
        }
        // для вычисления определитиля выше 3 порядка придется использовать алгоритм барейса
    }
}