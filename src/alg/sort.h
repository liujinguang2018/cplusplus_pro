#ifndef __SORT_H__
#define __SORT_H__

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
using namespace std;

// template <typename T>
// void my_swap(T &a, T &b)
// {
//     T t = a;
//     a = b;
//     b = t;
// }

template <typename T>
T *generate_random_numbers(int n)
{
    T *array = new T[n];
    if (array != NULL)
    {
        srand((unsigned)time(NULL));

        for (int i = 0; i < n; i++)
        {
            array[i] = rand();
        }
    }

    return array;
}

template <typename T>
void display_sorted_array(T array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
}

template <typename T>
bool is_array_sorted(T array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (array[i] < array[i - 1])
        {
            return false;
        }
    }

    return true;
}

template <typename T>
void insert_sort(T data[], int n)
{
    for (int i = 1, j; i < n; ++i)
    {
        T tmp = data[i];

        for (j = i; j > 0 && tmp < data[j - 1]; j--)
        {
            data[j] = data[j - 1];
        }
        data[j] = tmp;
    }
}

template <typename T>
void selection_sort(T data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j, least;
        for (j = i + 1, least = i; j < n; j++)
        {
            if (data[j] < data[least])
            {
                least = j;
            }
        }

        if (least != i)
        {
            swap(data[i], data[least]);
            // T tmp = data[i];
            // data[i] = data[least];
            // data[least] = tmp;
        }
    }
}

template <typename T>
void bubble_sort(T data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (data[j] < data[j - 1])
            {
                swap(data[j], data[j - 1]);
                // T tmp = data[j];
                // data[j] = data[j - 1];
                // data[j - 1] = tmp;
            }
        }
    }
}

//在冒泡排序的基础上，通过比较元素彼此之间的步长位置这种方式先对数据进行
//预处理，在每次移动中，步长会越来越小，直至它等于1
//这一理念就是在正式排序前先将一些大元素移至数组底部
template <typename T>
void comb_sort(T data[], int n)
{
    int step = n, j, k;
    while ((step = int(step / 1.3)) > 1) //phase 1
    {
        for (j = n - 1; j > step; j--)
        {
            k = j - step;
            if (data[j] < data[k])
            {
                swap(data[j], data[k]);
            }
        }
    }

    bool again = true;
    for (int i = 0; i < n - 1 && again; i++)
    {
        for (j = n - 1, again = false; j > i; --j)
        {
            if (data[j] < data[j - 1])
            {
                swap(data[j], data[j - 1]);
                again = true;
            }
        }
    }
}

#endif
