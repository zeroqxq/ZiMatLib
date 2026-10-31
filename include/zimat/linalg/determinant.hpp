#pragma once
#include "../core/matrix.hpp"
#include <stdexcept>



namespace zimat {

    template<typename T>
    T matrix<T>::det() const {
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
            throw std::runtime_error("Unsupported matrix size");

        // для вычисления определитиля выше 3 порядка планируется использовать алгоритм барейса (roadmap)
        }
    }
}   