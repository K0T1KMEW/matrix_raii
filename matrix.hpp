#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class Matrix {
public:
    Matrix(std::istream& input);
    ~Matrix();
    Matrix(uint32_t rows, uint32_t columns);
    Matrix operator+(Matrix& _operator);
    Matrix operator*(Matrix& _operator);
    void print();
private:
    uint32_t rows;
    uint32_t columns;
    std::vector<std::vector<int>> data;
};