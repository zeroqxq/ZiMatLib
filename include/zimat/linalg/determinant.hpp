#include "../core/matrix.hpp"


namespace zimat {

    template<typename T, typename T1>
    T matrix<T,T1>::det() const {
        if (this->rows_ == 1 and this ->cols_ == 1){
            return data_[0];
        }
        else if (this->rows_ == 2 and this ->cols_ == 2) {
            T det = this->data_[0] * this->data_[3] - this->data_[1] * this->data_[2];
            return det;
        }
        else if (this->rows_ == 3 and this->cols_ == 3){
            T det =
            this->data_[0] * this->data_[4] * this->data_[8] +
            this->data_[1] * this->data_[5] * this->data_[6] +
            this->data_[2] * this->data_[3] * this->data_[7] -
            this->data_[2] * this->data_[4] * this->data_[6] -
            this->data_[1] * this->data_[3] * this->data_[8] -
            this->data_[0] * this->data_[5] * this->data_[7];
                
            return det;
        
        }
        else {
            return -1;
        }

        // для вычисления определитиля выше 3 порядка придется использовать алгоритм барейса
    }
}