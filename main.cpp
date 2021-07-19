#include <QCoreApplication>
//#include <iostream>
#include <stdio.h>


// 1. ----------------------------------------------------
void dec_to_bin_recursively (int number){

    if (number > 0){

        dec_to_bin_recursively(number / 2);

        printf("%d", number % 2);
    }
    else {}

}

// 2. ----------------------------------------------------
int iterative_exponentiation (int a, int b){

    int result = 1;

    for (int i = 0; i < b; ++i) {
        result *= a;
    }

    return result;
}

// 3. ----------------------------------------------------
int recursive_exponentiation(int a, int b){

    if (b > 0){
        return a * recursive_exponentiation (a , --b);
    }
    else {}

    return 1;
}


// 4. ----------------------------------------------------
int recursive_exponentiation_even (int num, int exp){

    if ( exp % 2 == 0 ){        // even
        num *= num;
        exp /= 2;
        return recursive_exponentiation(num, exp);
    }
    else {
        exp--;
        return exp * recursive_exponentiation(num, exp);
    }
}


// 5. ----------------------------------------------------
//          0 ----X----
//          |          |
//          Y          Y
//          |          |
//          |          |
//           ----X---- N
//
// Always start at 0.0


//            Y  X
    const int obstacle [8][8] = { {0,0,1,0,0,0,0,0},      // 1 - obstacle; 0 - free
                                  {0,0,0,1,0,0,0,0},
                                  {0,0,0,0,1,0,0,0},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,1,0,0,1,0},
                                  {0,0,1,0,0,1,0,1},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0} };

int routes(int x, int y) {


    if (obstacle [y][x] == 1)       // add my code for obstacle
        return 0;

    if (x == 0 && y == 0)
        return 0;
    else if (x == 0 ^ y == 0)
        return 1;
    else
        return routes(x, y - 1) + routes(x - 1, y);
}






//======================================================================================================
int main(int argc, char *argv[])
{
    QCoreApplication q(argc, argv);

//    1.Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
    int dec = 142;
    printf("dec = %d to bin = 0b", dec);
    dec_to_bin_recursively (dec);


//    2. Реализовать функцию возведения числа [a] в степень [b]:
    int a = 12;
    int b = 5;
    printf("\n\niterative:   num[a] = %d, exp[b] = %d; result =%d", a, b, iterative_exponentiation (a, b));


//    3. Рекурсивно.
    printf("\nrecursively: num[a] = %d, exp[b] = %d; result =%d", a, b, recursive_exponentiation (a, b));


//    4. Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно возвести число, чётная,
//      основание возводится в квадрат, а показатель делится на два, а если степень нечётная - результат умножается на основание,
//      а показатель уменьшается на единицу)
    printf("\n\nrecursively even: num[a] = %d, exp[b] = %d; result =%d", a, b, recursive_exponentiation_even (a, b));



//    5. Реализовать нахождение количества маршрутов шахматного короля с препятствиями
//      (где единица - это наличие препятствия, а ноль - свободная для хода клетка)
     printf("\n");

     const int sizeX = 8;
     const int sizeY = 8;
     for (int y = 0; y < sizeY; ++y) {
         for (int x = 0; x < sizeX; ++x) {
             printf("%5d", routes(x, y));
         }
         printf("\n");
     }




    printf("\n");
    return 0;
}

