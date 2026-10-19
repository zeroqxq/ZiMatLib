#pragma once
#include <vector>



namespace zimat {


    class matrix
    {
    private:
        int rows;
        int cols;
        int base_numeric;
        std::vector<double> data;

    public:
        matrix() = default;
        ~matrix() = default;

        matrix(int rows, int cols, int base_numeric = 1)
        {
            this->rows = rows;
            this->cols = cols;
            this->data.resize(rows * cols);
            this->base_numeric=base_numeric;
        }

        double&  operator()(int row, int col) 
        {
            int index = (row - this->base_numeric) * this->cols + (col - this->base_numeric);
            return this->data[index];
        }

        // GETTERS AND SETTERS
        int get_rows()
        {
            return this->rows;
        }

        int get_cols()
        {
            return this->cols;
        }

        std::vector<double> get_data()
        {
            return this->data;
        }

        int get_base_numeric()
        {
            return this->base_numeric;
        }


        void set_rows(int rows)
        {
            this->rows = rows;
        }

        void set_cols(int cols)
        {
            this->cols = cols;
        }

        void set_base_numeric(int base_numeric)
        {
            this->base_numeric = base_numeric;
        }   
    };     
}

