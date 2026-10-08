#include <iostream>
using namespace std;

int main()
{
    system("chcp 65001");
    int choice;

    cout << "1. Сумма цифр массива" << endl;
    cout << "2. Среднее арифметическое положительных" << endl;
    cout << "3. Максимальный отрицательный элемент" << endl;
    cout << "4. Самое часто встречающееся число" << endl;
    cout << "5. Максимальный элемент на нечетном индексе, делящийся на 3" << endl;
    cout << "6. Максимальный четный и минимальный нечетный" << endl;
    cout << "7. Два массива" << endl;
    cout << "Выберите задание: ";
    cin >> choice;

    if (choice == 1)
    {
        int a[] = { 12, 104, 81 };
        int size = 3;
        int sum = 0;

        for (int i = 0; i < size; i++)
        {
            int x = a[i];

            while (x > 0)
            {
                sum += x % 10;
                x /= 10;
            }
        }

        cout << "Сумма цифр: " << sum << endl;
    }

    else if (choice == 2)
    {
        int a[] = { -5, 10, 3, -2, 7, 0 };
        int size = 6;

        int sum = 0;
        int count = 0;

        for (int i = 0; i < size; i++)
        {
            if (a[i] > 0)
            {
                sum += a[i];
                count++;
            }
        }

        if (count > 0)
            cout << "Среднее: " << (double)sum / count << endl;
        else
            cout << "Положительных элементов нет" << endl;
    }

    else if (choice == 3)
    {
        int a[] = { -10, 5, -3, -8, 7, -1 };
        int size = 6;

        int maxNegative = 0;
        int position = -1;

        for (int i = 0; i < size; i++)
        {
            if (a[i] < 0)
            {
                if (position == -1 || a[i] > maxNegative)
                {
                    maxNegative = a[i];
                    position = i;
                }
            }
        }

        if (position != -1)
        {
            cout << "Максимальный отрицательный: " << maxNegative << endl;
            cout << "Позиция: " << position << endl;
        }
        else
        {
            cout << "Отрицательных элементов нет" << endl;
        }
    }

    else if (choice == 4)
    {
        int a[] = { 2, 5, 2, 7, 5, 2, 8, 5 };
        int size = 8;

        int number = a[0];
        int maxCount = 0;

        for (int i = 0; i < size; i++)
        {
            int count = 0;

            for (int j = 0; j < size; j++)
            {
                if (a[i] == a[j])
                    count++;
            }

            if (count > maxCount)
            {
                maxCount = count;
                number = a[i];
            }
        }

        cout << "Чаще всего встречается: " << number << endl;
        cout << "Количество: " << maxCount << endl;
    }

    else if (choice == 5)
    {
        int a[] = { 4, 9, 12, 15, 7, 21, 30 };
        int size = 7;

        int max = 0;
        bool found = false;

        for (int i = 1; i < size; i += 2)
        {
            if (a[i] % 3 == 0)
            {
                if (!found || a[i] > max)
                {
                    max = a[i];
                    found = true;
                }
            }
        }

        if (found)
            cout << "Максимальный элемент: " << max << endl;
        else
            cout << "Такого элемента нет" << endl;
    }

    else if (choice == 6)
    {
        int a[] = { 8, 3, 12, 7, 4, 9 };
        int size = 6;

        int maxEven = 0;
        int minOdd = 0;

        int maxEvenPos = -1;
        int minOddPos = -1;

        for (int i = 0; i < size; i++)
        {
            if (a[i] % 2 == 0)
            {
                if (maxEvenPos == -1 || a[i] > maxEven)
                {
                    maxEven = a[i];
                    maxEvenPos = i;
                }
            }

            if (a[i] % 2 != 0)
            {
                if (minOddPos == -1 || a[i] < minOdd)
                {
                    minOdd = a[i];
                    minOddPos = i;
                }
            }
        }

        if (maxEvenPos == -1 || minOddPos == -1)
        {
            for (int i = 0; i < size; i++)
                a[i] = 0;
        }
        else
        {
            int temp = a[maxEvenPos];
            a[maxEvenPos] = a[minOddPos];
            a[minOddPos] = temp;
        }

        for (int i = 0; i < size; i++)
            cout << a[i] << " ";

        cout << endl;
    }

    else if (choice == 7)
    {
        int a[] = { 1, 2, 3, 4, 5 };
        int b[] = { 3, 4, 5, 6, 7 };

        int sizeA = 5;
        int sizeB = 5;

        cout << "а) Есть в обоих массивах: ";

        for (int i = 0; i < sizeA; i++)
        {
            for (int j = 0; j < sizeB; j++)
            {
                if (a[i] == b[j])
                {
                    cout << a[i] << " ";
                    break;
                }
            }
        }

        cout << endl;

        cout << "б) Есть только в одном массиве: ";

        for (int i = 0; i < sizeA; i++)
        {
            bool found = false;

            for (int j = 0; j < sizeB; j++)
            {
                if (a[i] == b[j])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << a[i] << " ";
        }

        for (int i = 0; i < sizeB; i++)
        {
            bool found = false;

            for (int j = 0; j < sizeA; j++)
            {
                if (b[i] == a[j])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << b[i] << " ";
        }

        cout << endl;
    }

    else
    {
        cout << "Неверный выбор" << endl;
    }

    return 0;
}