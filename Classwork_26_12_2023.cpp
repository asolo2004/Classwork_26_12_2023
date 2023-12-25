#include <iostream>

// 2 задание начинается здесь
int getSize() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    return size;
}

void allocateMemory(double*& arr, int size) {
    arr = new double[size];
}

void fillArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Введите значение для ячейки " << i << ": ";
        std::cin >> arr[i];
    }
}


void showArray(double* arr, int size) {
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void freeMemory(double* arr) {
    delete[] arr;
}

void task2() {
    char contin;
    do {
        int size = getSize();
        double* arr; 
        allocateMemory(arr, size);
        fillArray(arr, size);
        showArray(arr, size);
        freeMemory(arr);

        std::cout << "Хотите продолжить? (y/n): ";
        std::cin >> contin;
    } while (contin == 'y');
}
       // 2 задание заканчивается здесь

       // 3 задание начинается здесь

int* fillArray(int size) {
    int* arr = new int[size];
    std::srand(std::time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100; 
    }
    return arr;
}

void swap(int* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void task3() {
    const int size = 12;
    int* array = fillArray(size);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    swap(array, size);

    std::cout << "Массив после обмена четных и нечетных элементов: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array; 
}
        // 3 задание заканчивается здесь
  
        // 4 задание начинается здесь
void fillRandom(int** array, int rows, int cols) {
    std::srand(std::time(nullptr));
    int temp;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp = std::rand() % 50;
            if (temp < 10) {
            array[i][j] = temp + 10;
            
            }
            else {
                array[i][j] = temp;
            }
        }
    }
}

void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void task4() {
    int rows, cols;
    std::cout << "Введите количество строк и столбцов(через пробел): ";
    std::cin >> rows >> cols;

    int** dynamicArray = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        dynamicArray[i] = new int[cols];
    }

    fillRandom(dynamicArray, rows, cols);

    std::cout << "Двумерный массив случайных чисел:" << std::endl;
    printArray(dynamicArray, rows, cols);


    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
}
// 4 задание заканчивается здесь

// 5 задание начинается здесь

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

void task5() {
    int x, y;
    char operation;

    int (*func)(int, int);

    std::cout << "Введите два целых числа и символ операции (+, -, *, /), разделенные пробелом(для выхода на месте операции напишите 0): ";
    std::cin >> x >> y >> operation;
    // Как я понял, для обработки пробела подходят строки (getline), но мы их не проходили, поэтому заменяю на ноль 
    while (operation != '0') {
        switch (operation) {
        case '+':
            func = &add;
            std::cout << "Результат сложения: " << func(x, y) << std::endl;
            break;
        case '-':
            func = &subtract;
            std::cout << "Результат вычитания: " << func(x, y) << std::endl;
            break;
        case '*':
            func = &multiply;
            std::cout << "Результат умножения: " << func(x, y) << std::endl;
            break;
        case '/':
            func = &divide;
            std::cout << "Результат деления: " << func(x, y) << std::endl;
            break;
        default:
            std::cout << "Неподдерживаемая операция." << std::endl;
        }
        std::cout << "Введите два целых числа и символ операции (+, -, *, /), разделенные пробелом: ";
        std::cin >> x >> y >> operation;
    }
}
// 5 задание заканчивается здесь
int main() {
    setlocale(LC_ALL, "Russian");
    task5();
    return 0;
}