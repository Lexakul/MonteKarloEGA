#include <iostream>
#include <bitset>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;
// строка в длину 15 символов бинарная. если в дисятич перевести то будет от 0 до 32767
// взять строку переделать в десетерич. 

string R(int L)
{
    string X = "01"; // стринговый массив 0 1 чтобы брать из него
    string Y = ""; // пустой стринговый массив для заполнения
    for (int i = 0; i < L; i++) //создаем строчку длинна кодировки которой 15
    {
        Y = Y + X[rand() % 2]; // прибавлякм 0 или 1 беря из X. Получается случайное число от 0 до 32767
    }
    return Y;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    int e = 0; //Признак повторяющейся строки
    int i = 0; //счетчик
    int S = 0; // Пространство поиска
    int L = 15; //Длина кодировки
    //int M = 32; // Кол-во строк
    //string U[32]; //Массив на проверку приспосоьленностей
    int P = 0; //Приспособленность
    int N = 0; //Число шагов
    string* U;
    string M[32];
    int max = 0;
    string maxS = "";


    for (int i = 0; i < 32; i++) // Заполняем массив. Добавляем 32 случайные строки
    {

        M[i] = R(L);
    }

    cout << "Введите число шагов" << endl;
    cin >> N;
    U = new string[N];
    i = 0;

    while (i < N)
    {
        e = 0;
        string b = M[rand() % 32]; // выбор случайного значения (случайной строки в массиве)
        cout << "выбор случайного значения    " << b << endl;

        for (int k = 0; k < 32; k++) //проверяем присваивпли мы p-приспособленность
        {

            if (U[k] == b)  // проверяем попадалось ли это число?
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
            cout << "MAX МЕНЯЕТСЯ" << endl;
            maxS = U[i]; //M i 
            max = P;
        }

        i++;
        cout << "i= " << i << endl;
        cout << "maxS= " << maxS << endl;
        cout << "max= " << max << endl;


    }
    delete[]U;
}
