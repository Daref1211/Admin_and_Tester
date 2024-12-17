#include <iostream>  
#include "Emploeers.h"  
#include "Admin.h"  
#include "Menu.h"  

using namespace std;

bool Auth(string filename, string login, string pass, string& id) {
    string tmp_login, tmp_pass, tmp_id;
    fstream file_read(filename, ios::in);
    bool protect = false;
    while (!file_read.eof()) {
        file_read >> tmp_login >> tmp_pass >> tmp_id;
        if (tmp_login == login && tmp_pass == pass) {
            id = tmp_id;
            protect = true;
            break; 
        }
    }
    return protect;
}

int main() {
    setlocale(LC_ALL, "Ru");
    string login, pass, id;
    int choice{};
    Menu menu;

    while (true) {
        cout << "Добро пожаловать!" << endl << endl << endl << endl;
        cout << "Выберите действие:" << endl << endl;
        cout << "1 ~ Показать логотип" << endl;
        cout << "2 ~ Авторизоваться" << endl;
        cout << "3 ~ Выход" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            menu.showLogo();
            cout << endl << endl << endl;
            break;

        case 2:
            cout << "Введите ваш логин > ";
            cin >> login;
            cout << "Введите ваш пароль > ";
            cin >> pass;

            if (Auth("Emploeers_pass.txt", login, pass, id)) {
                Emploeers employeers(id);
                employeers.show();
            }
            else if (Auth("Admin_pass.txt", login, pass, id)) {
                Admin admin(id);
                admin.show();
            }
            else {
                cout << "Ошибка: неверный логин или пароль!" << endl;
            }
            break;

        case 3:
            system("cls");
            cout << "Выход из программы." << endl;

        default:
            cout << "Ошибка: такого пункта нет в меню!" << endl;
            break;
        }

        system("pause");
        system("cls");
    }


}