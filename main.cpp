#include <QCoreApplication>
//#include <iostream>
#include <stdio.h>
#include <math.h>

void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}




// 1. ----------------------------------------------------

void mediana_and_replace(int* array, int size){

    if (array[0] > array[size / 2])
        swapInt(&array[0] , &array[size / 2]);

    if (array[size / 2] > array[size])
        swapInt(&array[size / 2] , &array[size]);

    if (array[0] > array[size / 2])
        swapInt(&array[0] , &array[size / 2]);

    //printf("mediana - %3d, %3d, %3d\n", array[0], array[size / 2], array[size]);
}


void qs (int* arr, int first, int last) {
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}



void InsertionSort(int* array, int size)
{
    int newElement, location;

    for (int i = 1; i < size; i++)
    {
        newElement = array[i];
        location = i - 1;
        while(location >= 0 && array[location] > newElement)
        {
            array[location+1] = array[location];
            location = location - 1;
        }
        array[location+1] = newElement;
    }
}


void ImprovedSort (int* arr, int size){

    if (size <= 10){
        InsertionSort(arr, size);
    }
    else{
        mediana_and_replace(arr, size-1);
        qs(arr, 0, size - 1);
    }
}



//======================================================================================================
int main(int argc, char *argv[])
{
    QCoreApplication q(argc, argv);


//  1.  Описать в коде улучшенный алгоритм быстрой сортировки
    printf("Improved Sort:\n");

    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);

    ImprovedSort (arr, SZ);

    printIntArray(arr, SZ, 3);
    printf("\n");




    return 0;
}

