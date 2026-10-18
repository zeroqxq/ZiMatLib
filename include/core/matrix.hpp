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
        matrix();
        ~matrix();

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

    };     
}

