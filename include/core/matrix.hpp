#pragma once
#include <vector>

namespace zimat {


    template<typename T, typename T1=int >
    class matrix
    {
    private:
        T1 rows_ = 0;
        T1 cols_ = 0;
        T1 base_numeric_ = 1;
        std::vector<T> data_;

    public:

        matrix(int rows, int cols, int base_numeric = 1)
        {
            rows_ = rows;
            cols_ = cols;
            data_.resize(rows * cols);
            base_numeric_=base_numeric;
        }

        T& operator()(T1 rows, T1 cols) 
        {
            auto index = (rows - base_numeric_) * cols_ + (cols - base_numeric_);
            return data_[index];
        }

        const T& operator()(T1 rows, T1 cols) const
        {
            const auto index = (rows - base_numeric_) * cols_
                            + (cols - base_numeric_);
            return data_[index];
        }

        void resize(T1 rows, T1 cols, T1 base_numeric = 1){
            rows_ = rows;
            cols_ = cols;
            data_.resize(rows * cols);
            base_numeric_ = base_numeric;  
        }

        // GETTERS AND SETTERS
        T1 get_rows()
        {
            return rows_;
        }

        T1 get_cols()
        {
            return cols_;
        }

        const std::vector<T>& get_data()
        {
            return data_;
        }

        

        T1 get_base_numeric()
        {
            return base_numeric_;
        }


        void set_base_numeric(T1 base_numeric)
        {
            base_numeric_ = base_numeric;
        }   
    };     
}

