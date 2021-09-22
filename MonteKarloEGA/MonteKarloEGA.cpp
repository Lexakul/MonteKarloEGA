#include <iostream>
#include <bitset>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;
// строка в длину 15 символов бинарная. если в дисятич перевести то будет от 0 до 32767
// взять строку переделать в десетерич. 

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    int e = 0; //Признак повторяющейся строки
    int i = 0; //счетчик
    int S = 0; // Пространство поиска
    int L = 15; //Длина кодировки
    int M = 32; // Кол-во строк
    int X[32767]; //Массив не бинарный
    string Y[32767]; //Массив бинарный
    string U[32]; //Массив на проверку приспосоьленностей

    int P = 0; //Приспособленность
    int N = 0; //Число шагов
    int max = 0;
    string maxS = "";


    while  (i < M) // Заносим значения в строку не бинарное (натур число)
    {

            X[i] = S; // Заносим натур число в X[i] строку
            S = S + 1;
            bitset<15> nat(S); //bitset<15> название переменной(S) | bitset переводит натур число в бинар с ограничением в 15 бит. Если число больше переходит переполнение поэтому делаем ограничение    
            Y[i] = nat.to_string<char>(); //занесение в массив строк бинарный код
            i++;
    }


    cout << "Введите число шагов" << endl;
    cin >> N;
    i = 0;

    while (i < N)
    {
            e = 0;
            string b = Y[rand() % M]; // выбор случайного значения (случайной строки в массиве)
            cout << "выбор случайного значения    " << b << endl;

            for (int k = 0; k < M; k++)
            {

                if (U[k] == b)
                {
                    e = 1;
                    break;
                }

            }
            U[i] = b;
            if (!e)
            {
                P = rand() % 10; // случайное задание приспособленности
                cout << "приспособленность " << P << endl;
            }
            
                if (P > max)
                {
                    cout << "МАКС МЕНЯЕТСЯ" << endl;
                    maxS = Y[i];
                    max = P;
                }

                i++;
                cout << "i= " << i << endl;
                cout << "maxS= " << maxS << endl;
                cout << "max= " << max << endl;

            
    }

}
