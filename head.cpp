#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include "head.hpp"
using namespace std;

void clear()
{
    cout << "\033[2J\033[1;1H";
}
bool is_yellow(string i, char j)
{
    for (int s = 0; s < i.length(); s++)
    {
        if (i[s] == j)
        {
            return true;
        }
    }
    return false;
}

words::words()
{
    update_word();
    win = false;
}
string words::check_guess()
{
    string tmp;
    transform(tmp_guess.begin(), tmp_guess.end(), tmp_guess.begin(), ::toupper);
    if (tmp_guess == todays_word)
    {
        win = true;
    }
    for (int i = 0; i < tmp_guess.length(); i++)
    {
        tmp = tmp + "[";
        if (tmp_guess[i] == todays_word[i])
        {
            tmp = tmp + "\033[102m\033[30m";
            tmp = tmp += tmp_guess[i];
        }
        else if (is_yellow(todays_word, tmp_guess[i]))
        {
            tmp = tmp + "\033[103m\033[30m";
            tmp = tmp += tmp_guess[i];
        }
        else
        {
            tmp = tmp + "\033[41m\033[30m";
            tmp = tmp += tmp_guess[i];
        }
        tmp = tmp + "\033[39m\033[49m";
        tmp = tmp + "]";
    }
    tmp = tmp + "\n---------------";
    return tmp;
}
string words::display_word()
{
    update_word();
    return todays_word;
}
void words::update_word()
{
    time_t tp = time(NULL);
    int i = (tp / 86400) - 19115;
    string tmp;
    fstream word_list;
    word_list.open("wordlist(updated).txt", ios::in);
    for (int j = 0; j < i; j++)
    {
        getline(word_list, tmp);
    }
    todays_word = tmp;
}
void words::display_guesses()
{
    for (int i = 0; i < past_guesses.size(); i++)
    {
        cout << past_guesses[i] << "\n";
    }
}
void words::test()
{
    string tmp;
    cout << todays_word << "\n";
    for (int i = 0; i < 7; i++)
    {
        clear();
        display_guesses();
        make_guess();
    }
}
void words::make_guess()
{
    if (!win)
    {
        if (past_guesses.size() == 6)
        {
            cout << "The Word Was: " << todays_word << "\n";
            cin.get();
        }
        else
        {
            cout << "Your Guess: ";
            cin >> tmp_guess;
            if (tmp_guess.length() != 5)
            {
                cout << "5 Characters Please\n";
                make_guess();
            }
            past_guesses.push_back(check_guess());
        }
    }
    else
    {
        cout << "You Win!\n";
    }
}
