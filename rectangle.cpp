#include "rectangle.h"
#include "iostream"
#include "cmath"
#include "limits"

using namespace std;

// Функция для очистки буфера ввода
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функция для получения положительного числа
double getPositive(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cout << "Не сегодня, браток. Введи положительное число" << endl;
            clearInput();
        } else {
            clearInput();
            return value;
        }
    }
}

void rectangleMenu() {
    int choice;
    double length, width;

    while(true) {
        cout << "\n === ПРЯМОУГОЛЬНИК ===" << endl;
        cout << "\n 1. Найти периметр" << endl;
        cout << "\n 2. Найти площадь" << endl;
        cout << "\n 3. Найти длину диагонали" << endl;
        cout << "\n 0. Вернуться в меню" << endl;
        cout << "\n Чё те, братуха?" << endl;

        cin >> choice;

        if (cin.fail()) {
            cout << "Число введи, братан" << endl;
            clearInput();
            continue;
        }
        
        //Вводим стороны прямоугольника
        cout << "\nВведите длину прямоугольника:";
        length = getPositive("");
        cout << "\nВведите ширину прямоугольника:";
        width = getPositive("");

        switch (choice) {
            case 1: {
                double perimeter = 2 * (length + width);
                cout << "\nПериметр прямоугольника: " << perimeter << endl;
                break;
            }
            case 2: {
                double area = length * width;
                cout << "\nПлощадь прямоугольника: " << area << endl;
                break;
            }
            case 3: {
                double diagonal = sqrt(length * length + width * width);
                cout << "\nДлина диагонали прямоугольника: " << diagonal << endl;
                break;
            }
            case 0: {
                break;
            }
            default:
                cout << "Не так, братан. Пробуй ещё" << endl;
        }
    }
}