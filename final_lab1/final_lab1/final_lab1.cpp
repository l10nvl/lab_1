#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main() {
    setlocale(0, "");
    start : cout << "Введите номер задания: ";
    int start;
    cin >> start;
    if (start == 1) {
        cout << "Введите тип данных, для которого необходимо вывести объем занимаемой памяти: int, short, long, char и т.д." << endl;
        while (true) {
            char button = _getch();
            if (button == 'q')
                return 0;
            else {
                string ans;
                cin >> ans;
                if (ans == "int") {
                    cout << "Размер int: " << sizeof(int) << " байт" << endl;
                }
                else if (ans == "short") {
                    cout << "Размер short: " << sizeof(short) << " байт" << endl;
                }
                else if (ans == "long") {
                    cout << "Размер long: " << sizeof(long) << " байт" << endl;
                }
                else if (ans == "float") {
                    cout << "Размер char: " << sizeof(float) << " байт" << endl;
                }
                else if (ans == "double") {
                    cout << "Размер char: " << sizeof(double) << " байт" << endl;
                }
                else if (ans == "long double") {
                    cout << "Размер char: " << sizeof(long double) << " байт" << endl;
                }
                else if (ans == "char") {
                    cout << "Размер char: " << sizeof(char) << " байт" << endl;
                }
                else if (ans == "bool") {
                    cout << "Размер char: " << sizeof(bool) << " байт" << endl;
                }
                else {
                    cout << "\033[31m" << "\033[1m" << "\033[5m";
                    cout << "Ошибка!" << endl;
                    cout << "\033[0m";
                }
            }
        }
    }
    else if (start == 2) {
        cout << "Чтобы начать работу нажмите любую клавишу, кроме q\n";
        while (true) {
            char button = _getch();
            if (button == 'q')
                return 0;
            else {
                int a;
                cout << "Введите число: ";
                cin >> a;

                HANDLE h;
                h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, (((15 << 1) | 14)));
                cout << "Двоичное представление в памяти типа int:";
                cout << "\033[0m";
                cout << " ";

                unsigned int mask = 1 << (sizeof(int) * 8 - 1);

                // Список для change битов
                int res[32] = {};
                for (int i = 1; i <= (sizeof(int) * 8); i++, mask >>= 1) {
                    if (i == 1) {
                        cout << "\033[1m\033[37m";
                        putchar(a & mask ? '1' : '0');
                        cout << "\033[0m";
                    }
                    else if (i > 1) {
                        cout << "\033[1m\033[31m";
                        putchar(a & mask ? '1' : '0');
                        cout << "\033[0m";
                    }
                    if (i == 1 or i % 8 == 0) {
                        cout << " ";
                    }
                    if (a & mask)
                        res[i - 1] = 1;
                    else
                        res[i - 1] = 0;

                }
                cout << endl;
                cout << "Если вы хотите поменять какие - либо биты местами, нажмите 1, иначе 0. " << endl;
                int chek;
                cin >> chek;
                if (chek == 0) {
                    continue;
                }
                //меняем  биты пока не будет введено 0
                int finish = 2;
                while (finish != 0) {
                    if (chek == 1) {
                        cout << "Введите номер первого бита: ";
                        int first_bit;
                        cin >> first_bit;
                        cout << endl;
                        cout << "Введите номер второго бита: ";
                        int second_bit;
                        cin >> second_bit;
                        cout << endl;

                        int bufer;
                        bufer = res[first_bit - 1];

                        res[first_bit - 1] = res[second_bit - 1];
                        res[second_bit - 1] = bufer;
                        for (int l = 1; l <= 32; l++) {
                            if (l == 1) {
                                cout << "\033[1m\033[37m";
                                cout << res[l - 1];
                                cout << "\033[0m";
                            }
                            else if (l > 1) {
                                cout << "\033[1m\033[31m";
                                cout << res[l - 1];
                                cout << "\033[0m";
                            }
                            if (l == 1 or l % 8 == 0) {
                                cout << " ";
                            }
                        }
                        cout << endl;
                        cout << "Если вы хотите еще раз поменять биты, нажмите 1, иначе 0:    ";
                        cin >> finish;
                    }
                    cout << endl;
                }

            }
        }
    }
    else if (start == 3) {
        cout << "Чтобы начать работу нажмите любую клавишу, кроме q\n";

        while (true) {
            char button = _getch();
            if (button == 'q')
                return 0;
            else {
                union {
                    float val1;
                    unsigned int b;
                };
                cout << "Введите число: ";
                cin >> val1;

                HANDLE h;
                h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, (((15 << 1) | 14)));
                cout << "Двоичное представление в памяти типа float:";
                cout << "\033[0m";
                cout << " ";


                unsigned int mask = 1 << (sizeof(float) * 8 - 1);
                // Список для change битов
                int res[32] = {};
                for (int i = 1; i <= sizeof(float) * 8; i++, mask >>= 1) {
                    if (i == 1) {
                        cout << (b & mask ? '1' : '0') << " ";
                    }
                    else if (i >= 2 && i <= 8) {
                        cout << "\033[34m";
                        putchar(b & mask ? '1' : '0');
                        cout << "\033[0m";
                        if (i == 8) {
                            cout << " ";
                        }
                    }
                    else {
                        cout << "\033[1m\033[31m";
                        putchar(b & mask ? '1' : '0');
                        cout << "\033[0m";
                        if (i % 8 == 0) {
                            cout << " ";
                        }
                    }
                    if (b & mask)
                        res[i - 1] = 1;
                    else
                        res[i - 1] = 0;
                }
                cout << endl;
                cout << "Если вы хотите поменять какие - либо биты местами, нажмите 1, иначе 0. " << endl;
                int chek;
                cin >> chek;
                if (chek == 0) {
                    continue;
                }
                //меняем  биты пока не будет введено 0
                int finish = 2;
                while (finish != 0) {
                    if (chek == 1) {
                        cout << "Введите номер первого бита: ";
                        int first_bit;
                        cin >> first_bit;
                        cout << endl;
                        cout << "Введите номер второго бита: ";
                        int second_bit;
                        cin >> second_bit;
                        cout << endl;

                        int bufer;
                        bufer = res[first_bit - 1];

                        res[first_bit - 1] = res[second_bit - 1];
                        res[second_bit - 1] = bufer;
                        for (int l = 1; l <= 32; l++) {
                            if (l == 1) {
                                cout << "\033[1m\033[37m";
                                cout << res[l - 1];
                                cout << "\033[0m";
                            }
                            if (l >= 2 and l <= 8) {
                                cout << "\033[34m";
                                cout << res[l - 1];
                                cout << "\033[0m";
                            }
                            if (l > 8) {
                                cout << "\033[31m";
                                cout << res[l - 1];
                                cout << "\033[0m";
                            }
                            if (l == 1 or l % 8 == 0) {
                                cout << " ";
                            }
                        }
                        cout << endl;
                        cout << "Если вы хотите еще раз поменять биты, нажмите 1, иначе 0:    ";
                        cin >> finish;
                    }
                    cout << endl;
                }
            }
            cout << endl;
        }
    }
    else if (start == 4) {
        cout << "Чтобы начать работу нажмите любую клавишу, кроме q\n";
        while (true) {
            char button = _getch();
            if (button == 'q')
                return 0;
            else {
                union {
                    double val1;
                    int b[2];
                };
                cout << "Введите число: ";
                cin >> val1;

                int now_bit = 0;


                HANDLE h;
                h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, (((15 << 1) | 14)));
                cout << "Двоичное представление в памяти типа double:";
                cout << "\033[0m";
                cout << " ";

                // Список для change битов
                int res[64] = {};

                for (int i = 1; i >= 0; i--) {
                    unsigned int mask = 1 << (sizeof(float) * 8 - 1);
                    for (int j = 1; j <= sizeof(float) * 8; j++, mask >>= 1) {
                        now_bit += 1;
                        if (now_bit == 1) {
                            cout << "\033[1m\033[37m";
                            putchar(b[i] & mask ? '1' : '0');
                            cout << "\033[0m";
                        }
                        if (now_bit >= 2 and now_bit <= 12) {
                            cout << "\033[1m\033[34m";
                            putchar(b[i] & mask ? '1' : '0');
                            cout << "\033[0m";
                        }
                        if (now_bit >= 13 and now_bit <= 64) {
                            cout << "\033[1m\033[31m";
                            putchar(b[i] & mask ? '1' : '0');
                            cout << "\033[0m";
                        }
                        if (now_bit == 1 or now_bit == 12)
                            cout << " ";
                        if (i == 1) {
                            if (b[i] & mask)
                                res[j - 1] = 1;
                            else
                                res[j - 1] = 0;
                        }
                        else {
                            if (b[i] & mask)
                                res[32 + j - 1] = 1;
                            else
                                res[32 + j - 1] = 0;
                        }
                    }
                }
                cout << endl;
                cout << "Если вы хотите поменять какие - либо биты местами, нажмите 1, иначе 0. " << endl;
                int chek;
                cin >> chek;
                if (chek == 0) {
                    continue;
                }
                //меняем  биты пока не будет введено 0
                int finish = 2;
                while (finish != 0) {
                    if (chek == 1) {
                        cout << "Введите номер первого бита: ";
                        int first_bit;
                        cin >> first_bit;
                        cout << endl;
                        cout << "Введите номер второго бита: ";
                        int second_bit;
                        cin >> second_bit;
                        cout << endl;

                        int bufer;
                        bufer = res[first_bit - 1];

                        res[first_bit - 1] = res[second_bit - 1];
                        res[second_bit - 1] = bufer;
                        for (int l = 1; l <= 63; l++) {
                            if (l == 1) {
                                cout << "\033[1m\033[37m";
                                cout << res[l - 1];
                                cout << "\033[0m";
                            }
                            if (l >= 2 and l <= 12) {
                                cout << "\033[34m";
                                cout << res[l - 1];
                                cout << "\033[0m";
                            }
                            if (l > 12) {
                                cout << "\033[31m";
                                cout << res[l - 1];
                                cout << "\033[0m";
                            }
                            if (l == 1 or l == 12) {
                                cout << " ";
                            }
                        }
                        cout << endl;
                        cout << "Если вы хотите еще раз поменять биты, нажмите 1, иначе 0:    ";
                        cin >> finish;
                    }
                    cout << endl;
                }
            }
            cout << endl;
        }
    }
}
