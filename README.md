<div align="center">

# ZiMatLib

**Header-only библиотека на C++17 для создания и обработки матриц.**

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![Stars](https://img.shields.io/github/stars/zeroqxq/ZiMatLib?style=flat&color=blue)](https://github.com/zeroqxq/ZiMatLib/stargazers)
[![License](https://img.shields.io/github/license/zeroqxq/ZiMatLib)](LICENSE)
[![Status](https://img.shields.io/badge/status-beta-orange.svg)](https://github.com/zeroqxq/ZiMatLib)
[![Размер репозитория](https://img.shields.io/github/repo-size/zeroqxq/ZiMatLib?color=blue)](https://github.com/zeroqxq/ZiMatLib)
[![License](https://img.shields.io/github/license/zeroqxq/ZiMatLib)](LICENSE)
[![Issues](https://img.shields.io/github/issues/zeroqxq/ZiMatLib)](https://github.com/zeroqxq/ZiMatLib/issues)
[![Последний коммит](https://img.shields.io/github/last-commit/zeroqxq/ZiMatLib)](https://github.com/zeroqxq/ZiMatLib/commits/main)

</div>

ZiMatLib предоставляет шаблон `zimat::matrix<T>` с настраиваемой базой индексации, арифметикой, транспонированием, статистическими методами и вычислением определителя для матриц до третьего порядка.

## Возможности

- Непрерывное хранение элементов в порядке строк (row-major).
- Доступ к элементам с индексами от `0`, `1` или другой заданной базы.
- Сложение, вычитание и матричное умножение, умножение и деление на скаляр.
- Транспонирование, сумма, минимумы и максимумы, проверки матрицы.
- Определитель для квадратных матриц `1 × 1`, `2 × 2` и `3 × 3`.

## Требования и подключение

Нужен компилятор с поддержкой C++17. Библиотека подключается через заголовочный файл:

```cpp
#include <zimat/zimat.hpp>
```

При использовании CMake подключите репозиторий как поддиректорию:

```cmake
add_subdirectory(path/to/ZiMatLib)
target_link_libraries(my_app PRIVATE zimat)
```

Цель `zimat` — `INTERFACE`; отдельная сборка библиотеки не нужна.

## Быстрый пример

```cpp
#include <zimat/zimat.hpp>
#include <iostream>

int main() {
    zimat::matrix<int> a(2, 2);
    a(1, 1) = 1; a(1, 2) = 2;
    a(2, 1) = 3; a(2, 2) = 4;

    auto transposed = a.transpose();
    auto doubled = a * 2;

    std::cout << transposed(1, 2) << '\n'; // 3
    std::cout << doubled(2, 2) << '\n';    // 8
}
```

По умолчанию индексация начинается с `1`. Чтобы начать с `0`, передайте `0` третьим аргументом конструктора: `zimat::matrix<int> a(2, 2, 0);`.

## Сборка примера

```bash
cmake -S . -B build
cmake --build build
```

## Документация

Полное описание публичных методов, исключений и ограничений реализации: [документация](docs/documentation.md).

## Лицензия

Проект распространяется по лицензии, указанной в файле [LICENSE](LICENSE).
