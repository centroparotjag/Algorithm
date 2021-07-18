#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number = 0;
    int Check_Status = 1;

    //------- Input of number ------
    printf("Enter a number to check: ");
    std::cin >> number;



    // brute force %
    for (int i = 2; i < number; ++i){
        if ( number % i == 0 ) {				// Not natural check
            Check_Status = 0;
            break;
        }
    }


    if ( Check_Status && number > 1){
        printf("%d - Yes: This number is natural prime\n", number);
    }
    else {
        printf("%d - No: This is not a natural prime number.\n", number);
    }



    return a.exec();
}
