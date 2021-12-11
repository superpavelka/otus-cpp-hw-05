#include "matrix.h"
#include <cassert>
#include <iostream>

int main()
{
    // example
    std::cout << "EXAMPLE" << std::endl;

    // бесконечная матрица int заполнена значениями -1 
    Matrix<int, -1> matrix;
    assert(matrix.size() == 0); // все ячейки свободны 

    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);

    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);

    // выведется одна строка 
    // 100100314 
    for (auto c : matrix)
    {
        int x;
        int y;
        int v;
        std::tie(x, y, v) = c;
        std::cout << x << y << v << std::endl;
    }

    // task
    std::cout << std::endl;
    std::cout << "TASK" << std::endl;
    std::cout << std::endl;

    const int size = 10;
    const int min = 1;
    const int max = 8;

    Matrix<int, 0> matrix2;

    for (int i = 0; i < size; ++i) 
        matrix2[i][i] = i;

    for (int i = 0; i < size; ++i)
        matrix2[i][size - (i + 1)] = size - (i + 1);

    std::cout << "Matrix from [" << min << "," << min << "] to [" << max << "," << max << "]" << std::endl;
    for (int i = min; i <= max; ++i)
    {
        for (int j = min; j <= max; ++j)
            std::cout << matrix2[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << std::endl;   

    for (auto c : matrix2) 
    {
        int x;
        int y;
        int v;
        std::tie(x, y, v) = c;
        std::cout << "M[" << x << "][" << y << "] = " << v << std::endl;
    }
    std::cout << "M.size() = " << matrix2.size() << std::endl;
    std::cout << std::endl;

    const int i = 100;
    const int j = 100;
    const int k = 100;

    std::cout << "Matrix with dim = 3 :" << std::endl;
    Matrix<int, 0, 3> matrix3;
    matrix3[i][j][k] = 123;
    std::cout << "M[" << i << "][" << j << "][" << k << "] = " << matrix3[i][j][k] << std::endl;
    std::cout << "M.size() = " << matrix3.size() << std::endl;
    std::cout << std::endl;

    std::cout << "Canonical :" << std::endl;
    std::cout << "((matrix[100][100] = 314) = 0) = 217;" << std::endl;
    ((matrix[i][j] = 314) = 0) = 217;
    std::cout << "M[" << i << "][" << j << "] = " << matrix[100][100] << std::endl;
    std::cout << std::endl;   

    return 0;
}