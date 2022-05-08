#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void clear();

class words
{
private:
    string todays_word;
    vector<string> past_guesses;
    bool win;
    string tmp_guess;

public:
    words();
    string check_guess();
    string display_word();
    void update_word();
    void display_guesses();
    void make_guess();
    void test();
};