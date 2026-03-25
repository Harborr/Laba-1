# include "iostream"
# include "limits"
# include "rectangle.h"
# include "triangle.h"
# include "circle.h"

using namespace std;

// Функция для очистки буфера ввода
void clearMainInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Функция отображения главного меню

void showMainMenu() {
    cout << "\n==================" << endl;
    cout << " КАЛЬКУЛЯТОР 30000" << endl;
    cout << "\n==================" << endl;
    cout << " 1. Прямоугольник" << endl;
    cout << " 2. Треугольник" << endl;
    cout << " 3. Окружность" << endl;
    cout << " 0. Выход из программы" << endl;
}

int main(){
    int choice;

    cout << "Добро пожаловать в КАЛЬКУЛЯТОР 30000!" << endl;

    while (true) {
        showMainMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Число введи, братан" << endl;
            clearMainInput();
            continue;
        }

        switch (choice) {
            case 1:
                rectangleMenu(); // Вызов меню прямоугольника
                break;
            case 2:
                triangleMenu(); // Вызов меню треугольника
                break;
            case 3:
                circleMenu(); // Вызов меню окружности
                break;
            case 0:
                cout << "\nСпасибо за использование КАЛЬКУЛЯТОР 30000" << endl;
                return 0;         
        }
    }

    return 0;
}