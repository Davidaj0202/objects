#include <iostream>
#include <vector>
#include "head.hpp"
using namespace std;

int numbers::fizzbuzz()
{
    if (num % 3 == 0 && num % 5 == 0)
    {
        return 35;
    }
    else if (num % 3 == 0)
    {
        return 3;
    }
    else if (num % 5 == 0)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}
void numbers::loop(int i)
{
    for (int j = 0; j < i; j++)
    {
        num = j;
    }
}
void numbers::display(int i)
{
    for (int j = 1; j < i + 1; j++)
    {
        num = j;
        switch (fizzbuzz())
        {
        case 35:
            cout << "Fizzbuzz";
            break;
        case 3:
            cout << "Fizz";
            break;
        case 5:
            cout << "Buzz";
            break;
        default:
            cout << num;
            break;
        }
        cout << "";
    }
}
