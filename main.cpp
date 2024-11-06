#include "logger.hpp"
#include "matrix.hpp"
 
int main() {
    try {
        Logger logger("operations.log");

        std::cout << "enter the matrix size and elements (from console): \n";
        Matrix mat1(std::cin);
        mat1.print();

        std::string filename;
        std::cout << "enter filename for the second matrix: ";
        std::cin >> filename;

        std::ifstream fileInput(filename);
        if (!fileInput.is_open()) {
            throw std::runtime_error("err: unable to open file for the second matrix.");
        }

        Matrix mat2(fileInput);
        mat2.print();

        char operation;
        std::cout << "enter operation (+ or *): ";
        std::cin >> operation;

        if (operation == '+') {
            Matrix result = mat1 + mat2;
            std::cout << "result of addition:\n";
            result.print();
            logger.log("performed addition");
        }
        else if (operation == '*') {
            Matrix result = mat1 * mat2;
            std::cout << "result of multiplication:\n";
            result.print();
            logger.log("performed multiplication");
        }
        else {
            std::cerr << "err: invalid operation." << std::endl;
            return 1;
        }

        fileInput.close();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}