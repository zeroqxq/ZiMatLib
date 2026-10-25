#pragma once
#include "./core/matrix.hpp"
#include <cstddef>


namespace zimat {

    template <typename T, typename T1>
    inline matrix<T,T1> matrix<T,T1>::operator+(const matrix<T, T1> & other) const
    {

        if (this->rows_ != other.rows_ and this->cols_ != other.cols_) {
        
        }

        matrix<T> temp(this->rows_, this->cols_, this->base_numeric_);

        for (size_t i = 0; i < temp.data_.size(); ++i) {
            temp.data_[i] = this->data_[i] + other.data_[i];
        }
        return temp;
    }


    template <typename T, typename T1>
    inline matrix<T,T1> matrix<T,T1>::operator-(const matrix<T, T1> & other) const
    {

        if (this->rows_ != other.rows_ and this->cols_ != other.cols_) {
        
        }

        matrix<T> temp(this->rows_, this->cols_, this->base_numeric_);


        for (size_t i = 0; i < temp.data_.size(); ++i) {
            temp.data_[i] = this->data_[i] - other.data_[i];
        }
        return temp;
    }


    template <typename T, typename T1>
    inline matrix<T,T1> matrix<T,T1>::operator*(const matrix<T, T1> & other) const
    {

        if (this->cols_ != other.rows_) {
        
        }

        matrix<T> temp(this->rows_, other.cols_, this->base_numeric_);

        for (size_t i = 0; i < this->rows_; ++i) {
            for (size_t j = 0; j < other.cols_; ++j) {
                T sum = T{};

                for (size_t k = 0; k < this->cols_; ++k) {
                    sum += this->data_[i * this->cols_ + k] * other.data_[k * other.cols_ + j];
                }

                temp.data_[i * other.cols_ + j] = sum;
            }
        }

        return temp;
    }
    

}