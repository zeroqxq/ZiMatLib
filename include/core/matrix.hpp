#pragma once
#include <vector>

namespace zimat {


    template<typename T>
    class matrix
    {
    private:
        int rows_ = 0;
        int cols_ = 0;
        int base_numeric_ = 1;
        std::vector<T> data_;

    public:

        matrix(int rows, int cols, int base_numeric = 1)
        {
            rows_ = rows;
            cols_ = cols;
            data_.resize(rows * cols);
            base_numeric_=base_numeric;
        }

        T& operator()(int row, int col) 
        {
            int index = (row - base_numeric_) * cols_ + (col - base_numeric_);
            return data_[index];
        }

        void resize(int rows, int cols, int base_nimeric = 1){
            rows_ = rows;
            cols_ = cols;
            data_.resize(rows * cols);
            base_numeric_ = base_nimeric;  
        }

        // GETTERS AND SETTERS
        int get_rows()
        {
            return rows_;
        }

        int get_cols()
        {
            return cols_;
        }

        T get_data()
        {
            return data_;
        }

        int get_base_numeric()
        {
            return base_numeric_;
        }


        void set_base_numeric(int base_numeric)
        {
            base_numeric_ = base_numeric;
        }   
    };     
}

