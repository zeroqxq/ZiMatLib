#pragma once
#include "./core/matrix.hpp"


namespace zimat {

    template <typename T, typename T1>
    inline matrix<T,T1> matrix<T,T1>::operator+(const matrix<T, T1> & other) const
    {

        if (this->rows_ != other.rows_ and this->cols_ != other.cols_) {
        
        }

        matrix<T> temp(this->rows_, this->cols_, this->base_numeric_);

        temp.data_.resize(temp.rows_*temp.cols_);

        for (size_t i = 0; i < temp.data_.size(); ++i) {
            temp.data_[i] = this->data_[i] + other.data_[i];
        }
        return temp;
    }
    

}