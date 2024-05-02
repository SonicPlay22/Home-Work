#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
    static int count;

public:
    String() : String(80) {}

    String(int size) {
        str = new char[size + 1];
        str[0] = '\0';
        count++;
    }

    String(const char* user_string) : String(strlen(user_string)) {
        strcpy_s(str, strlen(user_string) + 1, user_string);
    }

    ~String() {
        delete[] str;
        count--;
    }

    void input() {
        cout << "Enter string : ";
        cin.getline(str, 80);
    }

    void Print() {
        cout << "String: " << str << endl;
    }

    static int Count() {
        return count;
    }

    void Find() {
        int element_index;
        cout << "Enter index : " << endl;
        cin >> element_index;

        cout << str[element_index] << endl;;
    }
};

int String::count = 0;

int main() {
    String string1;
    String string2("DOOM");
    String string3(80);

    string2.Print();
    string3.input();
    string3.Print();

    string3.Find();
    
    cout << "Number of String objects created: " << String::Count() << endl;

    return 0;
}