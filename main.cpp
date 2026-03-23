# include "iostream"
# include "limits"
# include "rectangle.h"

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
            case 2:
            return 0;
            case 0:
            cout << "\nСпасибо за использование КАЛЬКУЛЯТОР 30000" << endl;         
    }
}

return 0;
}