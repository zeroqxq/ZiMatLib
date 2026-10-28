<div align="center">

# ZiMatLib

**Лёгкая C++ библиотека для создания матриц и базовых операций над ними.**

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![Stars](https://img.shields.io/github/stars/zeroqxq/ZiMatLib?style=flat&color=blue)](https://github.com/zeroqxq/ZiMatLib/stargazers)
[![Размер репозитория](https://img.shields.io/github/repo-size/zeroqxq/ZiMatLib?color=blue)](https://github.com/zeroqxq/ZiMatLib)
[![License](https://img.shields.io/github/license/zeroqxq/ZiMatLib)](LICENSE)
[![Issues](https://img.shields.io/github/issues/zeroqxq/ZiMatLib)](https://github.com/zeroqxq/ZiMatLib/issues)
[![Последний коммит](https://img.shields.io/github/last-commit/zeroqxq/ZiMatLib)](https://github.com/zeroqxq/ZiMatLib/commits/main)

</div>

ZiMatLib — небольшая библиотека на C++ для создания матриц, доступа к их элементам и выполнения базовых операций. Сейчас проект находится на ранней стадии разработки. В будущем он может получить дополнительные возможности или сменить направление развития.

## Возможности

- Матрицы с элементами числового или другого поддерживаемого типа `T`.
- Хранение элементов в непрерывном массиве в порядке строк (row-major).
- Настраиваемая нумерация строк и столбцов при доступе через `operator()`.
- Сложение, вычитание и умножение матриц.
- Умножение и деление матрицы на скаляр.
- Интерфейс библиотеки на заголовочных файлах; отдельная сборка библиотеки не требуется.

> Проект находится в разработке. Дополнительные матричные алгоритмы могут появиться в будущих версиях.

## Требования

- Компилятор с поддержкой C++17.
- CMake 3.10 или новее — для сборки примера.

## Подключение

Подробная документация по классу `matrix` и операциям находится в [документации](docs/documentation.md).

Подключите каталог `include` к проекту и включите зонтичный заголовок:

```cpp
#include <zimat/zimat.hpp>
```

При использовании CMake из этого репозитория добавьте ZiMatLib как поддиректорию и свяжите цель `zimat` с вашей программой:

```cmake
add_subdirectory(path/to/ZiMatLib)

target_link_libraries(my_app PRIVATE zimat)
```

Цель `zimat` — интерфейсная (`INTERFACE`): она передаёт проекту путь к заголовкам и стандарт C++17.

## Быстрый пример

```cpp
#include <zimat/zimat.hpp>
#include <iostream>

int main() {
    // По умолчанию индексы строк и столбцов начинаются с 1.
    zimat::matrix<int> a(2, 2);
    zimat::matrix<int> b(2, 2);

    a(1, 1) = 1;
    a(1, 2) = 2;
    a(2, 1) = 3;
    a(2, 2) = 4;

    b(1, 1) = 5;
    b(1, 2) = 6;
    b(2, 1) = 7;
    b(2, 2) = 8;

    const auto sum = a + b;
    const auto product = a * b;
    const auto scaled = a * 2;

    std::cout << "Сумма: " << sum(1, 1) << '\n';
    std::cout << "Произведение: " << product(1, 1) << '\n';
    std::cout << "Умножение на число: " << scaled(2, 2) << '\n';
}
```

Матрица хранится построчно. Например, матрица

```text
1 2 3
4 5 6
```

хранится как последовательность `1, 2, 3, 4, 5, 6`.

## Создание матрицы и индексация

```cpp
zimat::matrix<double> values(3, 4);      // 3 строки, 4 столбца
zimat::matrix<int> zero_based(2, 2, 0);  // индексы начинаются с 0

values(1, 1) = 1.5;
zero_based(0, 0) = 42;
```

Третий аргумент конструктора задаёт начальный индекс строк и столбцов. Его также можно изменить через `set_base_numeric`.

Основные методы получения информации:

```cpp
auto rows = values.get_rows();
auto cols = values.get_cols();
auto first_index = values.get_base_numeric();
```

`get_data()` возвращает константную ссылку на внутренний вектор элементов в row-major порядке.

## Сборка примера

Из корневого каталога проекта выполните:

```bash
cmake -S . -B build
cmake --build build
```

После сборки пример `basic_usage` будет находиться в каталоге сборки. Команда запуска зависит от генератора CMake и операционной системы.

## Структура проекта

```text
include/
└── zimat/
    ├── zimat.hpp          # зонтичный заголовок
    ├── core/
    │   └── matrix.hpp     # класс матрицы и базовый интерфейс
    ├── ops/
    │   └── arithmetic.hpp # арифметические операции
    └── linalg/
        └── determinant.hpp # экспериментальная заготовка
examples/
└── basic_usage.cpp
```

## Планы развития

- Проверка совместимости размеров матриц с понятными исключениями.
- Определитель с выбором алгоритма и документированными ограничениями методов.
- Преобразования матриц к треугольному виду.
- Обратная матрица и матричные разложения.
- Тесты и расширенные примеры.

## Лицензия

Проект распространяется по лицензии, указанной в файле [LICENSE](LICENSE).



