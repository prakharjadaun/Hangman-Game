#include<iostream>                //for cin and cout
#include<string.h>                //for strcpy() function
#include<stdlib.h>                //for rand() function
#include<time.h>                  //for time() function and srand() function
using namespace std;             

class Hangman
{
    string name;                        //name of the player
    char SixLetters[7];                 //for storing the random generated word 
    char Output[6];

    public:
        Hangman()
        {
            Output[0] = '_';
            Output[1] = '_';
            Output[2] = '_';
            Output[3] = '_';
            Output[4] = '_';
            Output[5] = '_';
        }

        void intro();                            //to print the introduction to the game
        void InputUserName();                    //to input the user name
        void WordGenerator();                    //to generate a siz letter word
        void main_algo();                        //to execute the main algo
        char CheckPresence(char var);            //to check the presence the of the input character
        void DisplayHangman(int num);            //to dislay the hangman 
        void PrintLetters();                     //to display the Letters one by one

};


void Hangman::intro()
{
    cout<<"\t\t\t\t-------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t*******************************************************************************************"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t                  H   A   N   G   M   A   N          G   A   M   E                         "<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t*******************************************************************************************"<<endl;
    cout<<"\t\t\t\t-------------------------------------------------------------------------------------------"<<endl;
    DisplayHangman(6);
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t\t                     -------------------------------------------------                      "<<endl;
    cout<<"\t\t\t\t                      ***********************************************                       "<<endl;
    cout<<"\t\t\t\t                                     R    U   L   E   S                                     "<<endl;
    cout<<"\t\t\t\t                      ***********************************************                       "<<endl;
    cout<<"\t\t\t\t                     -------------------------------------------------                      "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\n1. You have to enter your name!";
    cout<<"\n2. You will be provided 6 letter blank word";
    cout<<"\n3. Then you have to guess the characters of that word";
    cout<<"\n4. Each time you wll be asked for a charcter!";
    cout<<"\n4. If you guessed it right, then it will be filled in the blank sapces";
    cout<<"\n5. Else hangman will be on its one way closer to be hanged";
    cout<<"\n6  If you guessed all the six letters before the man get hangs, you will win the game";
    cout<<"\n7  Else the man will be hanged!";
}

void Hangman::InputUserName()
{
    cout<<endl<<"Enter Your Name : ";
    cin>>name;
}

void Hangman::WordGenerator()
{
    char WORD[41][7];
    int n;
    strcpy(WORD[0],"attach");
    strcpy(WORD[1],"borrow");
    strcpy(WORD[2],"church");
    strcpy(WORD[3],"double");
    strcpy(WORD[4],"extent");
    strcpy(WORD[5],"freeze");
    strcpy(WORD[6],"galaxy");
    strcpy(WORD[7],"number");
    strcpy(WORD[8],"people");
    strcpy(WORD[9],"salmon");
    strcpy(WORD[10],"append");
    strcpy(WORD[11],"sunset");
    strcpy(WORD[12],"zigzag");
    strcpy(WORD[13],"marble");
    strcpy(WORD[14],"enough");
    strcpy(WORD[15],"banana");
    strcpy(WORD[16],"laptop");
    strcpy(WORD[17],"gender");
    strcpy(WORD[18],"income");
    strcpy(WORD[19],"cactus");
    strcpy(WORD[20],"thomas");
    strcpy(WORD[21],"winter");
    strcpy(WORD[22],"disney");
    strcpy(WORD[23],"doctor");
    strcpy(WORD[24],"forest");
    strcpy(WORD[25],"season");
    strcpy(WORD[26],"friend");
    strcpy(WORD[27],"little");
    strcpy(WORD[28],"tomato");
    strcpy(WORD[29],"spirit");
    strcpy(WORD[30],"health");
    strcpy(WORD[31],"cousin");
    strcpy(WORD[32],"wealth");
    strcpy(WORD[33],"action");
    strcpy(WORD[34],"ground");
    strcpy(WORD[35],"mirror");
    strcpy(WORD[36],"google");
    strcpy(WORD[37],"dinner");
    strcpy(WORD[38],"casino");
    strcpy(WORD[39],"wallet");
    strcpy(WORD[40],"attack");
    
    srand(time(0));
    n=rand()%40;
    strcpy(SixLetters,WORD[n]);
}

void Hangman::main_algo()
{
    char ch,var;
    int n=1;
    cout<<"Your word : __ __ __ __ __ __"<<endl;
    while(1)
    {
        cout<<"Enter the character : ";
        cin>>ch;
        var=CheckPresence(ch);
        if(var==ch)
        {
            PrintLetters();
        }
        else
        {
            
            cout<<"\t\t\t\t\t\t\tW    R   O   N   G       G   U   E   S   S   !";
            DisplayHangman(n);
            PrintLetters();
            if(n==6)
            {
                cout<<endl<<name<<" you have lost the game !"<<endl;
                cout<<"Your Word was : "<<SixLetters<<endl;
                exit(0);
            }
            n++;
        }
    }
}

char Hangman::CheckPresence(char var)
{
    int check=0;
    for(int i=0;SixLetters[i]!='\0';i++)
    {
        if(var==SixLetters[i])
        {
            Output[i]=SixLetters[i];
            check=1;
        }
    }
    if(check==0)
    {
        return '/';
    }
    else
    {
        return var;
    }
    
}

void Hangman::PrintLetters()
{
    int count=0;
    cout<<endl<<"Your Word : ";
    for(int i=0;i<6;i++)
    {
        if(Output[i]=='_')
        {
            cout<<"__ ";
            count++;
        }
        else
        {
            cout<<Output[i]<<" ";
        }
        
    }
    cout<<endl;
    if(count==0)
    {
        cout<<endl<<name<<" you have won the game !"<<endl;
        exit(0);
    }
}

void Hangman::DisplayHangman(int num)
{
    char a=' ',b=' ',c=' ',d=' ',e=' ',f=' ';
    if(num==1)
    {
        a='0';
    }
    else if(num==2)
    {
        a='0';
        b='|';
    }
    else if(num==3)
    {
        a='0';
        b='|';
        c='/';
    }
    else if(num==4)
    {
        a='0';
        b='|';
        c='/';
        d='\\';
    }
    else if(num==5)
    {
        a='0';
        b='|';
        c='/';
        d='\\';
        e='/';
    }
    else if(num==6)
    {
        a='0';
        b='|';
        c='/';
        d='\\';
        e='/';   
        f='\\';     
    }
    
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t____________________________"<<endl;
    cout<<"\t\t\t\t\t\t\t\t|                          |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t|                          |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t|                          "<<a<<endl;
    cout<<"\t\t\t\t\t\t\t\t|                         "<<c<<b<<d<<endl;
    cout<<"\t\t\t\t\t\t\t\t|                          "<<b<<" "<<endl;
    cout<<"\t\t\t\t\t\t\t\t|                         "<<e<<" "<<f<<endl;
    cout<<"\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"\t\t\t\t\t\t\t------------------"<<endl;       
}