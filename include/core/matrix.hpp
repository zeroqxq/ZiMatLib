#pragma once
#include <vector>

namespace zimat {


    class matrix
    {
    private:
        int rows_;
        int cols_;
        int base_numeric_;
        std::vector<double> data_;

    public:
        matrix() = default;
        ~matrix() = default;

        matrix(int rows, int cols, int base_numeric = 1)
        {
            rows_ = rows;
            cols_ = cols;
            data_.resize(rows * cols);
            base_numeric_=base_numeric;
        }

        double&  operator()(int row, int col) 
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

        std::vector<double> get_data()
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

