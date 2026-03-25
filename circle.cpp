#include "circle.h"
#include "iostream"
#include "cmath"
#include "limits"

using namespace std;

// Функция для очистки буфера ввода
void clearCircleInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функция для получения положительного числа
double getPositiveCircleNumber(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail() || value <= 0) {
            cout << "Ошибка: введите положительное число!" << endl;
            clearCircleInput();
        } else {
            clearCircleInput();
            return value;
        }
    }
}

// Функция для получения угла (0-360)
double getAngle(const string& prompt) {
    double angle;
    while (true) {
        cout << prompt;
        cin >> angle;
        
        if (cin.fail() || angle <= 0 || angle > 360) {
            cout << "Ошибка: введите угол от 0 до 360 градусов!" << endl;
            clearCircleInput();
        } else {
            clearCircleInput();
            return angle;
        }
    }
}

void circleMenu() {
    int choice;
    double radius, angle;
    const double PI = 3.14159265358979323846;
    
    while (true) {
        cout << "\n=== ОКРУЖНОСТЬ ===" << endl;
        cout << "1. Найти длину окружности" << endl;
        cout << "2. Найти площадь круга" << endl;
        cout << "3. Найти площадь кругового сектора" << endl;
        cout << "0. Покинуть программу." << endl;
        cout << "Те чё, братан?: ";
        
        cin >> choice;
        
        if (cin.fail()) {
            cout << "Число введи, братан" << endl;
            clearCircleInput();
            continue;
        }
        
        if (choice == 0) {
            break;
        }
        
        // Для первых двух пунктов нужен только радиус
        if (choice == 1 || choice == 2) {
            cout << "\nВведите радиус окружности: ";
            radius = getPositiveCircleNumber("");
            
            switch (choice) {
                case 1: {
                    double circumference = 2 * PI * radius;
                    cout << "\nДлина окружности: " << circumference << endl;
                    break;
                }
                case 2: {
                    double area = PI * radius * radius;
                    cout << "\nПлощадь круга: " << area << endl;
                    break;
                }
            }
        }
        // Для сектора нужны радиус и угол
        else if (choice == 3) {
            cout << "\nВведите радиус окружности: ";
            radius = getPositiveCircleNumber("");
            cout << "Введите угол сектора (в градусах, 0-360): ";
            angle = getAngle("");
            
            // Площадь сектора = (π * r² * угол) / 360
            double sectorArea = (PI * radius * radius * angle) / 360.0;
            cout << "\nПлощадь кругового сектора: " << sectorArea << endl;
            cout << "(Угол сектора: " << angle << "°)" << endl;
        }
        else {
            cout << "Не так, братуха. Пробуй ещё" << endl;
        }
    }
}
