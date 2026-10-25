#pragma once
#include <vector>

namespace zimat {


    template<typename T, typename T1=int>
    class matrix
    {
    private:
        T1 rows_ = 0;
        T1 cols_ = 0;
        T1 base_numeric_ = 1;
        std::vector<T> data_;

    public:
        matrix();
        matrix(T1 rows, T1 cols, T1 base_numeric = 1);

        T& operator()(T1 rows, T1 cols);
        const T& operator()(T1 rows, T1 cols) const;
        matrix operator+(const matrix & other) const;
        matrix operator-(const matrix & other) const;
        matrix operator*(const matrix & other) const;

        void resize(T1 rows, T1 cols, T1 base_numeric = 1);

        // GETTERS AND SETTERS
        T1 get_rows() const;
        T1 get_cols() const;
        const std::vector<T>& get_data() const;

        T1 get_base_numeric() const;
        void set_base_numeric(T1 base_numeric);
    };     

    template <typename T, typename T1>
    inline matrix<T,T1>::matrix(T1 rows, T1 cols, T1 base_numeric){
        rows_ = rows;
        cols_ = cols;
        data_.resize(rows * cols);
        base_numeric_=base_numeric;
    }

    template <typename T, typename T1>
    inline T& matrix<T,T1>::operator()(T1 rows, T1 cols){
        auto index = (rows - base_numeric_) * cols_ + (cols - base_numeric_);
        return data_[index];
    }

    template <typename T, typename T1>
    inline const T& matrix<T,T1>::operator()(T1 rows, T1 cols) const {
        const auto index = (rows - base_numeric_) * cols_ + (cols - base_numeric_);
        return data_[index];
    }


    template <typename T, typename T1>
    inline void matrix<T,T1>::resize(T1 rows, T1 cols, T1 base_numeric){
        rows_ = rows;
        cols_ = cols;
        data_.resize(rows * cols);
        base_numeric_ = base_numeric;  
    }

    template <typename T, typename T1>
    T1 matrix<T,T1>::get_rows() const {
            return rows_;
    }
        
    template <typename T, typename T1>
    T1 matrix<T,T1>::get_cols() const
    {
        return cols_;
    }

    template <typename T, typename T1>
    const std::vector<T>& matrix<T,T1>::get_data() const
    {
        return data_;
    }

    template <typename T, typename T1>
    T1 matrix<T,T1>::get_base_numeric() const
    {
        return base_numeric_;
    }

    template <typename T, typename T1>
    void matrix<T,T1>::set_base_numeric(T1 base_numeric)
    {
        base_numeric_ = base_numeric;
    }
    
    template <typename T, typename T1>
    matrix<T,T1>::matrix() 
    {
        rows_ = 0;
        cols_ = 0;
        base_numeric_= 1;
    } 
    

}

