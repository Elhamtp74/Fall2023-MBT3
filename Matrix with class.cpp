#include <iostream>

// کلاس ماتریس
class Matrix {
private:
    int rows, cols;
    int** data;

public:
    // سازنده
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        // جلوگیری از ایجاد ماتریس با ابعاد نامعتبر
        if (rows <= 0 || cols <= 0) {
            std::cerr << "Invalid matrix dimensions." << std::endl;
            exit(EXIT_FAILURE);
        }

        // ایجاد آرایه دوبعدی برای نگهداری داده‌های ماتریس
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // ورودی ماتریس
    void inputMatrix() {
        std::cout << "Enter the elements of the matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter element at position " << i + 1 << "," << j + 1 << ": ";
                std::cin >> data[i][j];
            }
        }
    }

    // چاپ ماتریس
    void printMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // تابع جمع ماتریس
    Matrix add(const Matrix& other) const {
        // جلوگیری از جمع ماتریس‌های با ابعاد مختلف
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrix dimensions do not match for addition." << std::endl;
            exit(EXIT_FAILURE);
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // تابع تفریق ماتریس
    Matrix subtract(const Matrix& other) const {
        // جلوگیری از تفریق ماتریس‌های با ابعاد مختلف
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrix dimensions do not match for subtraction." << std::endl;
            exit(EXIT_FAILURE);
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    // تابع ضرب ماتریس
    Matrix multiply(const Matrix& other) const {
        // جلوگیری از ضرب ماتریس‌های با ابعاد نامعتبر
        if (cols != other.rows) {
            std::cerr << "Invalid matrix dimensions for multiplication." << std::endl;
            exit(EXIT_FAILURE);
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    // مخرب کردن اشاره‌گرهای آرایه
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
};

// تابع اصلی
int main() {
    // ایجاد ماتریس‌های ۲x۲ و ۳x۳
    Matrix matrix2x2_1(2, 2), matrix2x2_2(2, 2);
    Matrix matrix3x3_1(3, 3), matrix3x3_2(3, 3);

    // ورودی ماتریس‌ها
    matrix2x2_1.inputMatrix();
    matrix2x2_2.inputMatrix();
    matrix3x3_1.inputMatrix();
    matrix3x3_2.inputMatrix();

    // چاپ ماتریس‌ها
    std::cout << "Matrix 2x2_1:" << std::endl;
    matrix2x2_1.printMatrix();

    std::cout << "Matrix 2x2_2:" << std::endl;
    matrix2x2_2.printMatrix();

    std::cout << "Matrix 3x3_1:" << std::endl;
    matrix3x3_1.printMatrix();

    std::cout << "Matrix 3x3_2:" << std::endl;
    matrix3x3_2.printMatrix();

    // انجام عملیات‌ها و چاپ نتایج
    Matrix result_addition_2x2 = matrix2x2_1.add(matrix2x2_2);
    std::cout << "Addition (2x2):" << std::endl;
    result_addition_2x2.printMatrix();

    Matrix result_subtraction_2x2 = matrix2x2_1.subtract(matrix2x2_2);
    std::cout << "Subtraction (2x2):" << std::endl;
    result_subtraction_2x2.printMatrix();

    Matrix result_multiplication_2x2 = matrix2x2_1.multiply(matrix2x2_2);
    std::cout << "Multiplication (2x2):" << std::endl;
    result_multiplication_2x2.printMatrix();

    Matrix result_addition_3x3 = matrix3x3_1.add(matrix3x3_2);
    std::cout << "Addition (3x3):" << std::endl;
    result_addition_3x3.printMatrix();

    Matrix result_subtraction_3x3 = matrix3x3_1.subtract(matrix3x3_2);
    std::cout << "Subtraction (3x3):" << std::endl;
    result_subtraction_3x3.printMatrix();

    Matrix result_multiplication_3x3 = matrix3x3_1.multiply(matrix3x3_2);
    std::cout << "Multiplication (3x3):" << std::endl;
    result_multiplication_3x3.printMatrix();

    return 0;
}
