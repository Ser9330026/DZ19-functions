// DZ19 functions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//*Домашнее задание 19 (Функции)*/


#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void print_arr(T arr[], const int length) {
    std::cout << '[';
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b]\n";
}

template <typename T>
void fill_arr(T arr[], const int length, T left, T rigth) {
    srand(time(NULL));
    for (int i = 0; i < length; i++)
        arr[i] = rand() % (rigth + 1 - left) + left;
}

/*Задача 1
Создайте функцию, которая
принимает два числа и возвращает их
наибольший общий делитель.*/

template <typename T>
int nod_num(T num1, T num2) {
    int remainder;
    while (num2 != 0) {
        remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }
    return num1;
}

/*Задача 2
Напишите функцию mirror_number,
которая принимает число и возвращает
его в отражённом виде.*/

template <typename T>
int mirror_number(T num) {
    int remainder;
    int reversNamber = 0;
    while (num != 0) {
        remainder = num % 10;
        reversNamber = reversNamber * 10 + remainder;
        num /= 10;
    }
    return reversNamber;
}

/*Задача 3
Создайте функцию, которая принимает
массив, его длину и число N. Функция
возвращает первую позицию числа N в
массиве, а также сортирует
все элементы, которые находятся справа от N.*/

template <typename T>
void line_arr(T arr[], const int length, T N) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == N) {
            for (int i = length - 1; i >= 0; i--) {
                for (int j = 0; j < i; j++) {
                    if (arr[j] > arr[j + 1])
                        std::swap(arr[j], arr[j + 1]);
                }
            }

        }
    }
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << '\t';
    //return arr[i];
}

/*Задача 4
Создайте функцию, которая принимает пустой
массив, его длину и два числа A и B, которые являются
началом и концом диапазона.Функция должна
заполнять массив случайными числами из указанного
диапазона.*/

template <typename T>
void empty_arr(T arr[], const int length, T A, T B) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        if (arr[i] < A && arr[i] > B) break;
        else arr[i] = rand() % (B - A) + A;
        //std::cout << arr[i] << '\t';
    }
}

//template <typename T>
//void buble_arr(T arr[], const int length) {

//}


int main() {
    setlocale(LC_ALL, "rus");
    int a = -50;
    int b = 50;
    const int SIZE = 10;
    int arr[SIZE];

    /*Создайте массив случайных чисел*/

    std::cout << "Массив: ";
    fill_arr(arr, SIZE, a, b);
    print_arr(arr, SIZE);

    /*Задача 1
    Создайте функцию, которая
    принимает два числа и возвращает их
    наибольший общий делитель.*/

    std::cout << "\nВведите два числа: ";
    int num1, num2;
    std::cin >> num1 >> num2;
    std::cout << "\nНОД: " << nod_num(num1, num2);

    /*Задача 2
    Напишите функцию mirror_number,
    которая принимает число и возвращает
    его в отражённом виде.*/

    std::cout << "\nВведите четырехзначное число: ";
    int numRev;
    std::cin >> numRev;
    std::cout << "\nЧисло в перевернутом виде: " << mirror_number(numRev);

    /*Задача 3
    Создайте функцию, которая принимает массив,
    его длину и число N. Функция возвращает
    первую позицию числа N в массиве, а также
    сортирует все элементы, которые
    находятся справа от N.*/

    std::cout << "\nМассив: ";
    fill_arr(arr, SIZE, a, b);
    print_arr(arr, SIZE);
    std::cout << "\nВедите число в массиве: ";
    int N;
    std::cin >> N;
    std::cout << "\nУпорядоченный массив: ";
    //buble_arr(arr, SIZE);
    line_arr(arr, SIZE, N);

    /*Задача 4
Создайте функцию, которая принимает пустой
массив, его длину и два числа A и B, которые являются
началом и концом диапазона.Функция должна
заполнять массив случайными числами из указанного
диапазона.*/

    std::cout << "\nВведите два числа: ";
    int A, B;
    std::cin >> A >> B;
    std::cout << "\nMассив случайных чисел из указанного диапазона: ";
    empty_arr(arr, SIZE, A, B);
    print_arr(arr, SIZE);
    return 0;
}