/*****************************************************************************************
                                    TIC  TAC  TOE  GAME
*****************************************************************************************/
#include<iostream>
#include<cstdlib>
using namespace std;

class Tic_Tac_Toe
{
public:
    char combination[9]= {'1','2','3','4','5','6','7','8','9'}, turn;
    int space_left = 9, position,count=0;
    string name;
    
    void get_name(int n ,char ch)
    {
        cout<<"Enter player "<<n<<" name (For '"<<ch<<"'):" ;
        cin>>name;
    }    

    char random_turn()
    {
        srand(time(NULL)); // srand function ensures that we get rand number every time

        //int n = rand(); //Gives us any random number for example 6895742
        //cout<<n<<endl;
        //cout<<n%2<<endl; //by doing n%2 we could get reminder of 1 or 0

        if(rand()%2)
        {
            return 'X';
        }
        return 'O';
    }

    int winner()
    {
    if((combination[0] == turn && combination[1] == turn && combination[2] == turn) ||
            (combination[3] == turn && combination[4] == turn && combination[5] == turn) ||
            (combination[6] == turn && combination[7] == turn && combination[8] == turn) ||
            (combination[0] == turn && combination[3] == turn && combination[6] == turn) ||
            (combination[1] == turn && combination[4] == turn && combination[7] == turn) ||
            (combination[2] == turn && combination[5] == turn && combination[8] == turn) ||
            (combination[0] == turn && combination[4] == turn && combination[8] == turn) ||
            (combination[2] == turn && combination[4] == turn && combination[6] == turn))
    {
        if(turn=='X')
        {
            count++;
        }
        else{
            count--;
        }        
        return 1;
    }
    return 0;
    }

    void fill_space()
    {
        if(combination[position-1]!='X' && combination[position-1]!='O')
        {
            combination[position-1]=turn;
            space_left--;
        }
    }

    void display()
    {
        for(int i = 0; i<9; i++)
        {
            if(i==0||i==3||i==6)
            {
                cout<<"  "<<combination[i]<<"  |  "<<combination[i+1]<<"  |  "<<combination[i+2]<<"  "<<endl;
            }
        }
        cout<<endl<<endl;
    }
    
    void decide_winner(Tic_Tac_Toe p1,Tic_Tac_Toe p2)
    {
        if(count==1||count==2||count==3)
        {
            cout<<endl<<"Congratulations!"<<endl;
            cout<<"Final winner is "<<p1.name<<endl;
        }
        else if(count==-1||count==-2||count==-3)
        {
            cout<<endl<<"Congratulations!"<<endl;
            cout<<"Final winner is "<<p2.name<<endl;
        }
        else
        {
            cout<<endl<<"Match draw"<<endl;
        }            
    } 
       
    void restart()
    {
        char a='1';
        turn=NULL;
        space_left=9;
        for(int i = 0;i < 9;i++)
        {
            combination[i]=a;
            a++;
        }  
          
    }    
        
};


int main()
{
    Tic_Tac_Toe player1,player2,win;
    int round=1; 
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"          Welcome to TIC TAC TOE Game..."<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    
    player1.get_name(1,'X');
    player2.get_name(2,'O');
    
    for(int i = 0;i < 3;i++){
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"                       ROUND "<<round<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        win.turn = win.random_turn();

        while(win.space_left!=0)
        {
            win.display();

            //!winner(combination,turn)&&get_position(position,turn);

            if(win.winner())
            {
                if(win.turn=='X')
                {
                    cout<<"Round "<<round<<" Winner is "<<player1.name<<endl;
                }
                else
                {
                    cout<<"Round "<<round<<" Winner is "<<player2.name<<endl;
                } 
                break;
            }
            
            else
            {
                win.turn=win.turn=='X'?'O':'X';
                if(win.turn=='X')
                {
                    cout<<player1.name<<" 's turn"<<endl;
                }
                else
                {
                    cout<<player2.name<<" 's turn"<<endl;
                }  
                  
                cout<<"Enter position for "<<win.turn<<endl;
                cin>>win.position;

                if(win.position > 0 && win.position <= 9 && win.combination[win.position-1] != 'X' && win.combination[win.position-1] != 'O')
                {
                    win.fill_space();
                }
                else
                {
                    win.turn=win.turn=='X'?'O':'X';
                    cout << "Invalid position. Please choose an empty cell." << endl;
                    continue;
                }
            }
        }
        
        if(win.space_left==0 && !win.winner())
        {
            cout<<"DRAW"<<endl;
        }else if(win.space_left==0 && win.winner()) // for special case winning for example position sequence=(1,2,3,5,4,6,8,9,7)
        {
            if(win.turn=='X')
            {
                cout<<"Round "<<round<<" Winner is "<<player1.name<<endl;
            }
            else
            {
                cout<<"Round "<<round<<" Winner is "<<player2.name<<endl;
            }        

        }
        
        if(i == 2)
        {
            win.decide_winner(player1,player2);
        }    
        win.restart();
        round++;
    }
    return 0;
}
    