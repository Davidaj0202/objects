#include <iostream>
#include "head.hpp"
using namespace std;

int main()
{
    cout << "Number: ";
    int i;
    cin >> i;
    numbers fizzbuzz;
    fizzbuzz.display(i);
}