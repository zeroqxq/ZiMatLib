#pragma once
#include <cstddef>
#include <vector>
#include <algorithm>

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

        // constructors
        matrix();
        matrix(T1 rows, T1 cols, T1 base_numeric = 1);
        
        // base methods
        T& operator()(T1 rows, T1 cols);
        const T& operator()(T1 rows, T1 cols) const;

        matrix& fill(const T& value);
        void resize(T1 rows, T1 cols, T1 base_numeric = 1);
        size_t size() const;

        // linalg
        T det() const;
        T trace() const;

        // ops
        matrix t() const;
        matrix transpose() const;
        matrix operator+(const matrix & other) const;
        matrix operator-(const matrix & other) const;
        matrix operator*(const matrix & other) const;
        matrix operator*(const T& other) const;
        matrix operator/(const T& other) const;

        // bool methods
        bool empty() const;
        bool is_empty() const;
        bool zeroqxq() const; // ^_^ 
        bool is_zeros() const;
        bool is_square() const;

        // statistic methods
        T sum() const;
        T sum(const matrix& matrix) const;

        T max() const;
        T max(const matrix& matrix) const;

        T min() const;
        T min(const matrix& matrix) const;

        // getters
        T1 get_rows() const;
        T1 get_cols() const;
        T1 cols() const;
        T1 rows() const;
        const std::vector<T>& get_data() const;
        const std::vector<T>& data() const;
        T1 get_base_numeric() const;
        T1 base_numeric() const;

        // setters
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
    T1 matrix<T,T1>::rows() const {
            return rows_;
    }
        
    template <typename T, typename T1>
    T1 matrix<T,T1>::get_cols() const
    {
        return cols_;
    }

    template <typename T, typename T1>
    T1 matrix<T,T1>::cols() const
    {
        return cols_;
    }

    template <typename T, typename T1>
    const std::vector<T>& matrix<T,T1>::get_data() const
    {
        return data_;
    }

    template <typename T, typename T1>
    const std::vector<T>& matrix<T,T1>::data() const
    {
        return data_;
    }

    template <typename T, typename T1>
    T1 matrix<T,T1>::get_base_numeric() const
    {
        return base_numeric_;
    }

    template <typename T, typename T1>
    T1 matrix<T,T1>::base_numeric() const
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

    template <typename T, typename T1>
    matrix<T,T1>& matrix<T,T1>::fill(const T& value) {
        std::fill(data_.begin(), data_.end(), value);
        return *this;
    }

    template <typename T, typename T1>  
    size_t matrix<T,T1>::size() const {
        return static_cast<size_t>(rows_) * static_cast<size_t>(cols_);
    }
    

}

