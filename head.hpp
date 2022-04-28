#include <iostream>
#include <vector>
using namespace std;

class numbers{
    int num;
    bool is_fizz;
    bool is_buzz;
    public:
    int fizzbuzz();
    void loop(int i);
    void display(int i);
};