#include <iostream>
#include <cstdlib>

using namespace std;

int around;
char getChar(int);
void Draw(int[]);
int checkWin(int[]);
int miniMax(int[],int,int);
void botPlay(int[]);
void player(int[]);
int countn=0;
int main()
{
    cout<<endl;
    cout<<"\t-------------"<<endl;
    cout<<"\t|  GAME XO  |"<<endl;
    cout<<"\t-------------\n"<<endl;
    cout<<"\tYOU:X , BOT:O\n"<<endl;
    int strat;
    int num[9]={0};
    //Draw(num);
    cout<<"\tPlay 1st or 2nd : ";
    cin>>strat;
    for(int i=0;i<9&&checkWin(num)==0;i++){
        if((i+strat)%2==0){
           botPlay(num);
        }
        else{
            //system("cls");
            Draw(num);
            player(num);
        }
    }
    switch(checkWin(num)) {
        case 0:
            //system("cls");
            Draw(num);
            cout<<"\tA draw. How droll.\n";
            break;
        case -10:
            //system("cls");
            Draw(num);
            cout<<"\tYou lose.\n";
            break;
        case 10:
            //system("cls");
            Draw(num);
            cout<<"\tYou win. Inconceivable!\n";
            break;
    }
    return 0;
}

char getChar(int num)
{
    switch (num)
    {
    case 10:
        return 'X';
    case -10:
        return 'O';
    case 0:
        return ' ';
    }
}

void Draw(int num[9])
{
    cout<<endl;
    cout<<"\t "<<getChar(num[0])<<" | "<<getChar(num[1])<<" | "<<getChar(num[2])<<endl;
    cout<<"\t---+---+---"<<endl;
    cout<<"\t "<<getChar(num[3])<<" | "<<getChar(num[4])<<" | "<<getChar(num[5])<<endl;
    cout<<"\t---+---+---"<<endl;
    cout<<"\t "<<getChar(num[6])<<" | "<<getChar(num[7])<<" | "<<getChar(num[8])<<endl;
    cout<<endl;
   // cout<<countn<<endl;
}

int checkWin(int num[9])
{
    int wins[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(int i=0;i<8;i++){
        if(num[wins[i][0]] != 0 &&
           num[wins[i][0]] == num[wins[i][1]] &&
           num[wins[i][0]] == num[wins[i][2]])
            return num[wins[i][0]];
    }
    return 0;
}

void botPlay(int num[9])
{
    around=0;
    int level=0;
    int pos = -1;
    int minValue = 10000;
    for(int i=0;i<9;i++){
        if(num[i]==0){
            num[i]=-10;
            int value=miniMax(num,10,level);
            num[i]=0;
            if(minValue>value){
                minValue=value;
                pos=i;
            }
        }
    }
    num[pos]=-10;
}

void player(int num[9])
{
    int pos;
    do {
        cout<<"\tInput move 1-9 : ";
        cin>>pos;
        cout<<endl;
    } while (num[pos-1]!=0 || pos>9 || pos < 1);
    num[pos-1] = 10;
}

int miniMax(int num[9],int Bot,int level)
{
    //Draw(num);
    //countn++;
    int maxValue,minValue;
    int winner = checkWin(num);
    if(winner == -10)
        return level+winner;
    else if (winner == 10)
        return winner-level;
//    around++;
//    cout<<"\around : "<<around;
//    Draw(num);
    if(Bot==-10){
        int pos = -1;
        minValue = 1000;
        for(int i=0;i<9;i++){
            if(num[i]==0){
                num[i]=Bot;
                int value=miniMax(num,10,level+1);
                if(minValue>value){
                    minValue=value;
                    pos=i;
                }
                level-1;
                num[i]=0;
            }
        }
        if(pos==-1) return 0;
        return minValue;
    }
    else if(Bot==10){
        int pos = -1;
        maxValue = -10000;
        for(int i=0;i<9;i++){
            if(num[i]==0){
                num[i]=Bot;
                int value=miniMax(num,-10,level+1);
                if(maxValue<value){
                    maxValue=value;
                    pos=i;
                }
                level-1;
                num[i]=0;
            }
        }
        if(pos==-1) return 0;
        return maxValue;
    }
}





