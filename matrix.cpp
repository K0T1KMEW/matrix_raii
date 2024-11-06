#include "Matrix.hpp"

Matrix::Matrix(std::istream& stream) {
    if (!(stream >> rows >> columns)) {
        throw std::runtime_error("err: invalid matrix size format.");
    }

    data.resize(rows, std::vector<int>(columns));

    for (uint32_t i = 0; i < rows; ++i) {
        for (uint32_t j = 0; j < columns; ++j) {
            if (!(stream >> data[i][j])) {
                throw std::runtime_error("err: invalid matrix data format or insufficient data.");
            }
        }
    }

    std::cout << "matrix read successfully.\n";
}

Matrix::~Matrix() {
    std::cout << "matrix destroyed.\n";
}

Matrix::Matrix(uint32_t rows, uint32_t columns) : rows(rows), columns(columns), data(rows, std::vector<int>(columns)) {}

Matrix Matrix::operator+(Matrix& other) {
    if (rows != other.rows || columns != other.columns) {
        throw std::invalid_argument("err: matrices must be of the same size for addition.");
    }
    std::cout << "adding matrices of size " << rows << "x" << columns << std::endl;

    Matrix result(rows, columns);
    for (uint32_t i = 0; i < rows; ++i) {
        for (uint32_t j = 0; j < columns; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }   

    return result;
}

Matrix Matrix::operator*(Matrix& other) {
    if (columns != other.rows) {
        throw std::invalid_argument("err: matrices must be compatible for multiplication.");
    }
    std::cout << "multiplying matrices of sizes " << rows << "x" << columns << " and " << other.rows << "x" << other.columns << std::endl;

    Matrix result(rows, other.columns);
    for (uint32_t i = 0; i < rows; ++i) {
        for (uint32_t j = 0; j < other.columns; ++j) {
            result.data[i][j] = 0;
            for (uint32_t k = 0; k < columns; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

void Matrix::print(){
    for (auto& row : data) { //ссылка на объект типа std::vector<int>
        for (auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}
