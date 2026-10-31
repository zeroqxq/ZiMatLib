#pragma once
#include <cstddef>
#include <vector>
#include <algorithm>

namespace zimat {


    template<typename T>
    class matrix
    {
    private:
        size_t rows_ = 0;
        size_t cols_ = 0;
        size_t base_numeric_ = 1;
        std::vector<T> data_;

    public:

        // constructors
        matrix();
        matrix(size_t rows, size_t cols, size_t base_numeric = 1);
        
        // base methods
        T& operator()(size_t rows, size_t cols);
        const T& operator()(size_t rows, size_t cols) const;

        matrix& fill(const T& value);
        void resize(size_t rows, size_t cols, size_t base_numeric = 1);
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

        T max_in_row(size_t row) const;
        T min_in_row(size_t row) const;
        T max_in_col(size_t col) const;
        T min_in_col(size_t col) const;

        

        // getters
        size_t get_rows() const;
        size_t get_cols() const;
        std::vector<T> get_row(size_t row) const;
        std::vector<T> get_col(size_t col) const;
        size_t cols() const;
        size_t rows() const;
        const std::vector<T>& get_data() const;
        const std::vector<T>& data() const;
        size_t get_base_numeric() const;
        size_t base_numeric() const;

        // setters
        void set_base_numeric(size_t base_numeric);

    };     

    template <typename T>
    inline matrix<T>::matrix(size_t rows, size_t cols, size_t base_numeric){
        rows_ = rows;
        cols_ = cols;
        data_.resize(rows * cols);
        base_numeric_=base_numeric;
    }

    template <typename T>
    inline T& matrix<T>::operator()(size_t rows, size_t cols){
        auto index = (rows - base_numeric_) * cols_ + (cols - base_numeric_);
        return data_[index];
    }

    template <typename T>
    inline const T& matrix<T>::operator()(size_t rows, size_t cols) const {
        const auto index = (rows - base_numeric_) * cols_ + (cols - base_numeric_);
        return data_[index];
    }


    template <typename T>
    inline void matrix<T>::resize(size_t rows, size_t cols, size_t base_numeric){
        rows_ = rows;
        cols_ = cols;
        data_.resize(rows * cols);
        base_numeric_ = base_numeric;  
    }

    template <typename T>
    size_t matrix<T>::get_rows() const {
            return rows_;
    }

    template <typename T>
    size_t matrix<T>::rows() const {
            return rows_;
    }
        
    template <typename T>
    size_t matrix<T>::get_cols() const
    {
        return cols_;
    }

    template <typename T>
    size_t matrix<T>::cols() const
    {
        return cols_;
    }

    template <typename T>
    const std::vector<T>& matrix<T>::get_data() const
    {
        return data_;
    }

    template <typename T>
    const std::vector<T>& matrix<T>::data() const
    {
        return data_;
    }

    template <typename T>
    size_t matrix<T>::get_base_numeric() const
    {
        return base_numeric_;
    }

    template <typename T>
    size_t matrix<T>::base_numeric() const
    {
        return base_numeric_;
    }

    template <typename T>
    void matrix<T>::set_base_numeric(size_t base_numeric)
    {
        base_numeric_ = base_numeric;
    }
    
    template <typename T>
    matrix<T>::matrix() 
    {
        rows_ = 0;
        cols_ = 0;
        base_numeric_= 1;
    }

    template <typename T>
    matrix<T>& matrix<T>::fill(const T& value) {
        std::fill(data_.begin(), data_.end(), value);
        return *this;
    }

    template <typename T>  
    size_t matrix<T>::size() const {
        return rows_*cols_;
    }
    
    template <typename T>
    std::vector<T> matrix<T>::get_row(size_t row) const {

        row -= base_numeric_;

        return std::vector<T>(
            data_.begin() + row * cols_,
            data_.begin() + (row + 1) * cols_
        );
    }

    template <typename T>
    std::vector<T> matrix<T>::get_col(size_t col) const {

        col -= base_numeric_;

        std::vector<T> result;
        result.reserve(rows_);

        for (size_t i = 0; i < rows_; ++i) {
            result.push_back(data_[i * cols_ + col]);
        }

        return result;
    }


}

