#include <zimat/zimat.hpp>

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& values, const std::string& title) {
    std::cout << title << ": [ ";

    for (const auto& value : values) {
        std::cout << value << ' ';
    }

    std::cout << "]\n";
}

template <typename T>
void print_matrix(const zimat::matrix<T>& matrix, const std::string& title) {
    std::cout << "\n" << title << " (" << matrix.rows()
              << " x " << matrix.cols()
              << ", base = " << matrix.base_numeric() << ")\n";

    if (matrix.empty()) {
        std::cout << "[empty]\n";
        return;
    }

    const std::size_t base = matrix.base_numeric();

    for (std::size_t row = base; row < base + matrix.rows(); ++row) {
        std::cout << "| ";

        for (std::size_t col = base; col < base + matrix.cols(); ++col) {
            std::cout << matrix(row, col) << ' ';
        }

        std::cout << "|\n";
    }
}

int main() {
    std::cout << "=== ZiMatLib basic example ===\n";

    // 1. Создание матриц
    zimat::matrix<int> empty_matrix;
    zimat::matrix<int> filled(2, 3);
    filled.fill(7);

    zimat::matrix<int> a{
        {1, 2, 3},
        {4, 5, 6}
    };

    // Индексация с нуля.
    zimat::matrix<int> zero_based({
        {10, 20},
        {30, 40}
    }, 0);

    print_matrix(empty_matrix, "Empty matrix");
    print_matrix(filled, "Filled with 7");
    print_matrix(a, "Matrix A");
    print_matrix(zero_based, "Zero-based matrix");

    // 2. Доступ к элементам через operator()
    a(1, 2) = 20;
    std::cout << "\nA(1, 2) = " << a(1, 2) << '\n';
    std::cout << "zero_based(0, 1) = " << zero_based(0, 1) << '\n';

    // 3. Свободные функции-конструкторы
    const auto zeros = zimat::zeros<int>(2, 3);
    const auto ones = zimat::ones<int>(2, 3);
    const auto identity = zimat::identity<int>(3);
    const auto diagonal = zimat::diagonal<int>({2, 4, 6});

    print_matrix(zeros, "zeros<int>(2, 3)");
    print_matrix(ones, "ones<int>(2, 3)");
    print_matrix(identity, "identity<int>(3)");
    print_matrix(diagonal, "diagonal<int>({2, 4, 6})");

    // 4. Арифметика
    const zimat::matrix<int> b{
        {1, 2},
        {3, 4}
    };

    const zimat::matrix<int> c{
        {5, 6},
        {7, 8}
    };

    print_matrix(b + c, "B + C");
    print_matrix(c - b, "C - B");
    print_matrix(b * c, "B * C");
    print_matrix(b * 3, "B * 3");
    print_matrix(c / 2, "C / 2");

    // 5. Транспонирование: t() и transpose() — одинаковые операции
    print_matrix(a.t(), "A.t()");
    print_matrix(a.transpose(), "A.transpose()");

    // 6. Линейная алгебра
    const zimat::matrix<int> square{
        {1, 2, 3},
        {0, 4, 5},
        {1, 0, 6}
    };

    print_matrix(square, "Square matrix");
    std::cout << "det(square) = " << square.det() << '\n';
    std::cout << "trace(square) = " << square.trace() << '\n';

    // 7. Статистика
    std::cout << "\n=== Statistics ===\n";
    std::cout << "sum() = " << square.sum() << '\n';
    std::cout << "max() = " << square.max() << '\n';
    std::cout << "min() = " << square.min() << '\n';
    std::cout << "max_in_row(2) = " << square.max_in_row(2) << '\n';
    std::cout << "min_in_row(2) = " << square.min_in_row(2) << '\n';
    std::cout << "max_in_col(3) = " << square.max_in_col(3) << '\n';
    std::cout << "min_in_col(3) = " << square.min_in_col(3) << '\n';

    print_vector(square.get_row(2), "get_row(2)");
    print_vector(square.get_col(3), "get_col(3)");
    print_vector(square.data(), "data()");

    // 8. Свойства матриц
    std::cout << "\n=== Properties ===\n";
    std::cout << std::boolalpha;
    std::cout << "empty_matrix.empty() = " << empty_matrix.empty() << '\n';
    std::cout << "empty_matrix.is_empty() = " << empty_matrix.is_empty() << '\n';
    std::cout << "zeros.is_zeros() = " << zeros.is_zeros() << '\n';
    std::cout << "square.is_square() = " << square.is_square() << '\n';
    std::cout << "B == B = " << (b == b) << '\n';
    std::cout << "B != C = " << (b != c) << '\n';

    // 9. Размеры и база индексации
    std::cout << "\n=== Size and indexing ===\n";
    std::cout << "rows(): " << square.rows() << '\n';
    std::cout << "cols(): " << square.cols() << '\n';
    std::cout << "size(): " << square.size() << '\n';
    std::cout << "base_numeric(): " << square.base_numeric() << '\n';

    // 10. resize() и set_base_numeric()
    zimat::matrix<int> resized(2, 2);
    resized.fill(1);
    resized.resize(3, 2);
    resized.fill(9);
    print_matrix(resized, "After resize(3, 2)");

    resized.set_base_numeric(0);
    print_matrix(resized, "After set_base_numeric(0)");
    return 0;
}