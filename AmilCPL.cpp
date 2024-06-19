#include <iostream>
#include <string>

using namespace std;


class book {
public:
    string name;
    string author;
public:
    void see() {

    }
    void set_name() {
        cout << "Введите название книги: ";
        cin >> name;
    }
    void set_author() {
        cout << "Введите автора: ";
        cin >> author;
    }
    string get_name() {
        return name;
    }
    string get_author() {
        return author;
    }
};
 
class member :public book {
public:
    book borrowedBooks[1];
    string nameOfOtdel;
    int number_of_book = 0;
public:
    void add() {
          for (int i = 0; i < 10; i++) {
                cout << "Название новой книги: ";
                cin >> borrowedBooks[i].name;
                cout << "Автор новой книги: ";
                cin >> borrowedBooks[i].author;
                number_of_book++;
            }
            cout << endl;
        if (number_of_book + 1 <= 10) {
            number_of_book++;
            cout << "Введите данные новой книги\n\n";
            cout << "Название: ";
            cin >> borrowedBooks[number_of_book - 1].name;
            cout << "Автор: ";
            cin >> borrowedBooks[number_of_book - 1].author;
            cout << endl;
            cout << "Новая книга успешно добавлена!" << endl;
        }
        else cout << "Недостаточно памяти для добавления нового объекта!" << endl << endl;
    }
    void del() {
        int number_of_deleted_item;
        cout << "Введите номер удаляемой записи: ";
        cin >> number_of_deleted_item;
        number_of_deleted_item--;
        for (int i = number_of_deleted_item; i < number_of_book - 1; i++)
            borrowedBooks[i] = borrowedBooks[i + 1];
        number_of_book--;
        cout << "Запись удалена!" << endl << endl;
    }
    void show() {
        for (int i = 0; i < number_of_book; i++) {
            cout << borrowedBooks[i].name << " " << borrowedBooks[i].author << endl;
        }
        cout << endl;
    }
    string get_nameOfOtdel() {
        return nameOfOtdel;
    }
};


class library :public member {
    member books[1];
    string nameOfLibrary;
    int members = 0;
public:
    void set_nameOfLibrary() {
        cout << "Название библиотеки: ";
        cin >> nameOfLibrary;
    }

    string get_nameOfLibrary() {
        return nameOfLibrary;
    }
    void addOtdel() {
        for (int i = 0; i < 10; i++) {
            cout << "Название новой книги: ";
            cin >> books[i].nameOfOtdel;
            members++;
        }
        cout << endl;
        if (members + 1 <= 10) {
            members++;
            cout << "Название отделa: ";
            cin >> books[members - 1].nameOfOtdel;
            cout << "Новый отдел успешно добавлен!" << endl;
        }
        else cout << "Недостаточно памяти для добавления нового объекта!" << endl << endl;
    }
    void delOtdel() {
        int number_of_deleted_otdel;
        cout << "Введите номер удаляемой записи: ";
        cin >> number_of_deleted_otdel;
        number_of_deleted_otdel--;
        for (int i = number_of_deleted_otdel; i < members - 1; i++)
            books[i] = books[i + 1];
        members--;
        cout << "Отдел удален!" << endl << endl;
    }
    void show() {
        for (int i = 0; i < members; i++) {
            cout << books[i].nameOfOtdel << endl;
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int kod;
    library n1;
    member n2;
    n1.set_nameOfLibrary();
    n1.get_nameOfLibrary();
    do {
        cout << "1. Добавить книгу" << endl;
        cout << "2. Удалить книгу" << endl;
        cout << "3. Просмотр" << endl;
        cout << "0. Выход" << endl;
        cin >> kod;
        switch (kod) {
        case 1: n2.add();  break;
        case 2: n2.del(); break;
        case 3: n2.show(); break;
        case 0: exit(0);
        }
    } while (kod != 0);
    return 0;
}