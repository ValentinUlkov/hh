// hh.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

bool Check(int* a, int val, int n) {
    bool mark = true;
    for (int i = 0; i < n; i++) {
        if (val == a[i]) {
            mark = false;
            break;
        }
    }

    return mark;
}

vector<vector<int>>ArrayOfArrays(int n) {
    int column;

    vector<vector<int>>Array;
    Array.resize(n);

    int* length = new int[n];
    int x = 0;

    for (int i = 0; i < n; i++) {
        column = rand() % 31 - 1;
        if (x != 0) {
            bool flag = Check(length, column, x);
            while (!flag) {
                column = rand() % 31 - 1;
                flag = Check(length, column, x);
            }
        }

        length[x] = column;
        x++;
        Array[i].resize(column);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Array[i].size(); j++) {
            Array[i][j] = rand();
        }
    }
    //сортировка чётных пузырьком
    for (int i = 0; i < n - 2; i += 2) {
        for (int j = Array[i].size() - 1; j > 0; j--) {
            for (int s = 0; s < j; s++) {
                if (Array[i][s] > Array[i][s + 1]) {
                    swap(Array[i][s], Array[i][s + 1]);
                }
            }
        }
    }
    //сортировка нечётных
    for (int i = 1; i < n - 1; i += 2) {
        for (int j = Array[i].size() - 1; j > 0; j--) {
            for (int s = 0; s < j; s++) {
                if (Array[i][s] < Array[i][s + 1]) {
                    swap(Array[i][s], Array[i][s + 1]);
                }
            }
        }
    }

    return Array;
}

int main()
{
    int n, col;
    cin >> n;

    vector<vector<int>>Vec = ArrayOfArrays(n);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
