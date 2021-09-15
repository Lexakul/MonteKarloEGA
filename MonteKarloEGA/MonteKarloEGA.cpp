#include <iostream>
#include <bitset>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

//si- итые кодировки
//s - множество кодировок

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    int i = 0; //счетчик
    int S = 0; // Пространство поиска
    int L = 15; //Длина кодировки
    int M = 0; // Кол-во строк
    int X[10]; //Массив не бинарный
    string Y[10]; //Массив бинарный

    int P = 0; //Приспособленность
    int N = 0; //Число шагов
    int max = 0;
    string maxS = "";



    cout << "Введите кол-во строк N" << endl; //Вводим кол-во строк
    cin >> M;

    while  (i < M) // Заносим значения в строку не бинарное (натур число)
    {
        cout << "Введите S в пределах от 0 до ((2 ^ L) - 1) || [0 до 32767]" << endl;
        cin >> S; //Вводим натур число
        if ((S > -1) && (S <= 32767))
        {
            X[i] = S; // Заносим натур число в X[i] строку
            bitset<15> nat(S); //bitset<15> название переменной(S) | bitset переводит натур число в бинар с ограничением в 15 бит. Если число больше переходит переполнение поэтому делаем ограничение    
            cout << "бинарный код числа:" << nat.to_string<char>() << endl;
            Y[i] = nat.to_string<char>(); //занесение в массив строк бинарный код
            i++;
        }
       

    }
    cout << "Введеные натуральные числа" << endl;
    for (int i = 0; i < M; i++) { cout << X[i] << endl; } // вывод небинарного строкового массива
    cout << "Бинарные значения" << endl;
    for (int i = 0; i < M; i++) { cout << Y[i] << endl; } // вывод бинарного строкового массива


    cout << "Введите число шагов" << endl;
    cin >> N;
    /*for (int i=0; i < N; i++)
    {
        if (i < N)
        {
            string b = Y[rand() % M]; // выбор случайного значения (случайной строки в массиве)
            cout << "выбор случайного значения    " << b << endl;
            P = rand() % 10; // случайное задание приспосоьленности
            cout << "приспособленность " << P << endl;
            if (P > max)
            {
                maxS = Y[i];
                max = P;
            }
           // i++;
            cout << "i= " << i << endl;
            cout << "maxS= " << maxS << endl;
            cout << "max= " << max << endl;
        }

    }*/
    i = 0;

    while (i < N)
    {
        
            string b = Y[rand() % M]; // выбор случайного значения (случайной строки в массиве)
            cout << "выбор случайного значения    " << b << endl;
            P = rand() % 10; // случайное задание приспосоьленности
            cout << "приспособленность " << P << endl;
            if (P > max)
            {
                maxS = Y[i];
                max = P;
            }
            i++;
            cout << "i= " << i << endl;
            cout << "maxS= " << maxS << endl;
            cout << "max= " << max << endl;
        

    }

}
