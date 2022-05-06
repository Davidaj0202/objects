#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class words
{
private:
    string todays_word;
    vector<string> past_guesses;
    bool win;
public:
    words();
    void update_word();
    void display_guesses();
    void make_guess();
    void test();
};