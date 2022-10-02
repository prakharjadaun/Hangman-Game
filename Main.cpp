#include<iostream>
#include "Hangman.cpp"         
using namespace std;

//main function
int main()
{
    //creating an object of the Hangman class
    Hangman man;
    //calling the desired functions of the Hangman class
    man.intro();
    man.inputUsername();
    cout<<endl<<"Generating a six letter word........!"<<endl;
    man.wordGenerator();
    man.mainAlgo();
    return 0;
}