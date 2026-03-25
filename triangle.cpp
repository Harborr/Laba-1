#include "triangle.h"
#include "iostream"
#include "cmath"
#include "limits"

using namespace std;

// Функция для очистки буфера ввода
void clearInputTriangle() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функция для получения положительного числа
double getPositiveNumberTriangle(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail() || value <= 0) {
            cout << "Ошибка: введите положительное число!" << endl;
            clearInputTriangle();
        } else {
            clearInputTriangle();
            return value;
        }
    }
}

// Проверка существования треугольника
bool isValidTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void triangleMenu() {
    int choice;
    double a, b, c;
    
    while (true) {
        cout << "\n===ТРЕУГОЛЬНИК===" << endl;
        cout << "1. Найти периметр" << endl;
        cout << "2. Найти площадь (по формуле Герона)" << endl;
        cout << "3. Проверить на равнобедренность" << endl;
        cout << "0. Вернуться в главное меню" << endl;
        cout << "Чё те, браткА? ";
        
        cin >> choice;
        
        if (cin.fail()) {
            cout << "Не это, братан. Введи число" << endl;
            clearInputTriangle();
            continue;
        }
        
        if (choice == 0) {
            break;
        }
        
        // Вводим стороны треугольника
        cout << "\nВведите длину первой стороны: ";
        a = getPositiveNumberTriangle("");
        cout << "Введите длину второй стороны: ";
        b = getPositiveNumberTriangle("");
        cout << "Введите длину третьей стороны: ";
        c = getPositiveNumberTriangle("");
        
        // Проверяем, существует ли треугольник
        if (!isValidTriangle(a, b, c)) {
            cout << "\nОшибка: Треугольник с такими сторонами не существует!" << endl;
            cout << "Проверьте, что сумма любых двух сторон больше третьей." << endl;
            continue;
        }
        
        switch (choice) {
            case 1: {
                double perimeter = a + b + c;
                cout << "\nПериметр треугольника: " << perimeter << endl;
                break;
            }
            case 2: {
                // Формула Герона
                double p = (a + b + c) / 2; // полупериметр
                double area = sqrt(p * (p - a) * (p - b) * (p - c));
                cout << "\nПлощадь треугольника: " << area << endl;
                break;
            }
            case 3: {
                if (a == b || a == c || b == c) {
                    cout << "\nТреугольник является равнобедренным!" << endl;
                    if (a == b && b == c) {
                        cout << "Более того, это равносторонний треугольник." << endl;
                    } else {
                        if (a == b) cout << "Равные стороны: a и b = " << a << endl;
                        else if (a == c) cout << "Равные стороны: a и c = " << a << endl;
                        else cout << "Равные стороны: b и c = " << b << endl;
                    }
                } else {
                    cout << "\nТреугольник не является равнобедренным." << endl;
                }
                break;
            }
            default:
                cout << "Чёт ты накосячил. Давай снова по-другому" << endl;
        }
    }
}
