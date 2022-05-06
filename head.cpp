#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include "head.hpp"
using namespace std;

words::words(){
    update_word();
    win=false;
}
void words::update_word(){
    time_t tp=time(NULL);
    int i=(tp/86400)-19116;
    string tmp;
    fstream word_list;
    word_list.open("wordlist(updated).txt",ios::in);
    for(int j=0;j<i;j++){
        getline(word_list,tmp);
    }
    todays_word=tmp;
}
void words::display_guesses(){
    for(int i=0;i<past_guesses.size();i++){
        cout<<past_guesses[i]<<"\n";
    }
}
void words::test(){
    string tmp;
    cout<<todays_word<<"\n";
    for(int i=0;i<5;i++){
        display_guesses();
        make_guess();
    }
}
void words::make_guess(){
    if(!win){
        if(past_guesses.size()>=5){
            cout<<"The Word Was: "<<todays_word<<"\n";
            cin.get();
        }
        else{
            cout<<"Your Guess: ";
            cin>>past_guesses[past_guesses.size()];
        }
    }
    else{
        cout<<"You Win!\n";
    }
}

