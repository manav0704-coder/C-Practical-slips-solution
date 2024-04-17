#include <stdio.h>
#include <stdlib.h>
#include <istream>
#include <conio.h>
#include <ctype.h>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    int num;
    ofstream f1("even.txt"),f2("odd.txt"); 


    if (argc == 1)
        printf("No command line arguments found.\n");

    else
    {
        for(int i = 1; i < argc; i++)
        {
            num = atoi(argv[i]);
            if(num%2==0)
            {
                f1<<num;
            }
            else
            {
                f2<<num;
            }
        }
    }
    return 0;
}
