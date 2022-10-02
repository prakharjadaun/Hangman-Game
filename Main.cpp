#include<iostream>
#include "Hangman.cpp"
using namespace std;

int main()
{
    Hangman man;
    man.intro();
    man.InputUserName();
    cout<<endl<<"Generating a six letter word........!"<<endl;
    man.WordGenerator();
    man.main_algo();
    return 0;
}