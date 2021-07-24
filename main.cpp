#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <math.h>

// 1. ----------------------------------------------------
void bubble_sort_2_dim_arr(int* arr, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1; ++j) {
            if (arr[j] > arr[j + 1]) {  // swap
                int t =  arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}


void printArray(char Free_text [], int* array, const int row, const int col) {
       std::cout << Free_text << "\t";

       for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {

                printf("%2d", array[j + (i * row)]);
                if (j < 2)
                    printf(",");
            }
            printf("\t");
        }

        printf("\n");
}

// 3. ----------------------------------------------------
double f(double t)
{
    return sqrt(fabs(t)) + 5 * pow(t, 3);
}


// https://en.wikipedia.org/wiki/TPK_algorithm
void TPK_algorithm (void){

    double a[11] = {0}, y;

    printf("Введите 11 чисел\n");
    for (int i = 0; i < 11; i++){
        scanf("%lf", &a[i]);
    }


    for (int i = 10; i >= 0; i--) {
        y = f(a[i]);
        if (y > 400)
            printf("%d TOO LARGE\n", i);
        else
            printf("%d %.16g\n", i, y);
    }
}





//======================================================================================================
int main(int argc, char *argv[])
{
    QCoreApplication q(argc, argv);

//  1.  Реализовать пузырьковую сортировку двумерного массива например,
//      массив 1,9,2 5,7,6 4,3,8 должен на выходе стать 1,2,3 4,5,6 7,8,9

    int arr [3][3]= { {1,9,2}, {5,7,6}, {4,3,8} };

    printArray((char*) "Before sorting:", *arr, 3, 3);

    bubble_sort_2_dim_arr (*arr, 9);

    printArray((char*) "After sorting:", *arr, 3, 3);
    printf("\n");


//  3.  Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С
    TPK_algorithm ();

    printf("\n");
    return 0;
}

