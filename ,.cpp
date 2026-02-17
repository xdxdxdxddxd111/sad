#include <iostream>
#include <cstdarg> 

int sumDigits(int n) {
    if (n < 10) return n;
    return (n % 10) + sumDigits(n / 10);
}

int countEven(int arr[], int size) {
    if (size == 0) return 0;
    int isEven = (arr[size - 1] % 2 == 0) ? 1 : 0;
    return isEven + countEven(arr, size - 1);
}

double average(int count, ...) {
    va_list args;
    va_start(args, count);
    double sum = 0.0;
    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, double);
    }
    va_end(args);
    return sum / count;
}

void pointerExample() {
    int value = 42;
    int* ptr = &value;
    *ptr = 100;
    std::cout << "Значение после изменения через указатель: " << value << std::endl;
}

void question7() {
    int a = 10;
    int* p = &a;
    (*p)++;
    std::cout << "Ответ на вопрос 7: " << a << std::endl;
}

void question10() {
    int arr[3] = {1, 2, 3};
    int* p = arr;
    std::cout << "Ответ на вопрос 10: " << *(p + 1) << std::endl;
}

void dynamicArrayExample() {
    int* arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }
    std::cout << "Динамический массив: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr; 
}

void incByValue(int x) { x++; }
void incByRef(int& x) { x++; }
void incByPtr(int* x) { (*x)++; }

void testPassingMethods() {
    int a = 5;
    incByValue(a); 
    incByRef(a);   
    incByPtr(&a);  
    std::cout << "Результат передачи параметров: " << a << std::endl; 
}

double add(double a, double b) { return a + b; }
double multiply(double a, double b) { return a * b; }

void functionPointerExample() {
    double (*funcPtr)(double, double);
    funcPtr = add;
    std::cout << "Сложение через указатель: " << funcPtr(3.0, 4.0) << std::endl; 
    funcPtr = multiply;
    std::cout << "Умножение через указатель: " << funcPtr(3.0, 4.0) << std::endl; 
}

double plus(double a, double b) { return a + b; }
double minus(double a, double b) { return a - b; }
double mult(double a, double b) { return a * b; }
double divide(double a, double b) { return b != 0 ? a / b : 0; }

void functionArrayExample() {
    double (*operations[4])(double, double) = {plus, minus, mult, divide};
    std::cout << "Операции через массив указателей:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << operations[i](10.0, 2.0) << " ";
    }
    std::cout << std::endl;
}

void applyToEach(int arr[], int size, void (*func)(int&)) {
    for (int i = 0; i < size; ++i) {
        func(arr[i]);
    }
}

void increment(int& x) { x++; }

void higherComplexityExample() {
    int data[] = {1, 2, 3, 4, 5};
    int size = 5;
    applyToEach(data, size, increment);
    std::cout << "Массив после применения функции: ";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Контрольная работа. Вариант 1 ===\n\n";

    std::cout << "Часть 1. Рекурсия:\n";
    std::cout << "Сумма цифр 12345: " << sumDigits(12345) << std::endl;
    int nums[] = {1, 2, 3, 4, 5, 6};
    std::cout << "Чётных чисел: " << countEven(nums, 6) << std::endl;

    std::cout << "\nЧасть 2. Переменное число аргументов:\n";
    std::cout << "Среднее: " << average(4, 1.0, 2.0, 3.0, 4.0) << std::endl;

    std::cout << "\nЧасть 3. Указатели:\n";
    pointerExample();
    question7();

    std::cout << "\nЧасть 4. nullptr и арифметика указателей:\n";
    question10();

    std::cout << "\nЧасть 5. const и динамическая память:\n";
    dynamicArrayExample();

    std::cout << "\nЧасть 6. Передача параметров:\n";
    testPassingMethods();

    std::cout << "\nЧасть 7. Указатели на функции:\n";
    functionPointerExample();
    functionArrayExample();

    std::cout << "\nЧасть 8. Повышенная сложность:\n";
    higherComplexityExample();

    return 0;
}
