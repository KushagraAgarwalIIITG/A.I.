#include <bits/stdc++.h>
#include <math.h>
#include <windows.h>

using namespace std;
struct node{
  int value;//
  int depth;//
  int i;//stick onePlayerGame  ya twoPlayerGame
};

node t[54];
node f[54];


node minimax(int n,int depth,bool player,int alpha,int beta)
{  node g,j,label1;
   j.value=0;j.depth=0;j.i=0;
   if(n==1)
    {
        if(player)
        {
             g.value = -10;
             g.depth = depth;
             g.i = 0;
             return g;
        }
        else
         {
             g.value = 10;
             g.depth = depth;
             g.i =0;
             return g;
        }
    }
    int i;
    if(player)
    {  int maxx=-999;
       int minn=999;
        for(i=3;i>=1;i--)
        {  
		if(n-i>=1)
            {
            j= minimax(n-i,depth+1,false,alpha,beta);
            if(j.value>=maxx && j.value!=0)
            {  if(j.value==maxx)
                { if(j.depth<minn)
                    {
                    g.value=j.value;
                    g.depth=j.depth;
                    g.i = i;
                    }
                }
               else
                   {
                    maxx=j.value;
                    g.value=j.value;
                    g.depth=j.depth;
                    g.i = i;
                    }
              //  if(j.value==10) //remove comment to get output for big numbers
                   // break;
            }
            alpha=max(alpha,j.value);
            if(beta<alpha)
                break;
           }
        }
     return g;
    }
    else
    {
        int minn =999;
       int maxx=999;
        for(i=3;i>=1;i--)
        { if(n-i>=1)
            {
              j= minimax(n-i,depth+1,true,alpha,beta);
           if(j.value<=maxx && j.value!=0)
            {  if(j.value==maxx)
                { if(j.depth<minn)
                    {
                    g.value=j.value;
                    g.depth=j.depth;
                    g.i = i;
                    }
                }
               else
                   {
                    maxx=j.value;
                    g.value=j.value;
                    g.depth=j.depth;
                    g.i = i;
                    }
                //if(g.value==-10)
                    //break;
            }
            beta=min(beta,j.value);

            if(beta < alpha )
                break;

           }
        }

     return g;
    }
}

void AIvsAI(int n)
{
    cout<<"TOSS"<<endl;
    srand(time(0));

    int pickup1,cpu,i = rand()%2;

    if(i==0)
        cout<<"CPU 1 WON TOSS"<<endl;
    else
        cout<<"CPU 2 WON TOSS"<<endl;

    cout<<"-----------------------------start-----------------------------"<<endl;

 while(1){

    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==1)
               cout<<"CPU 2 WON,CPU 1 LOST "<<endl;
          else
               cout<<"CPU 1 WON,CPU 2 LOST "<<endl;
      }
      if(n==1){
        if(i==0)
           cout<<"CPU 2 WON,CPU 1 LOST "<<endl;
        else
           cout<<"CPU 1 WON,CPU 2 LOST "<<endl;
      }
    break;
    }
    if(i==0)
     {
        cout<<"CPU 1'S CHANCE "<<endl;
        node res;
        res = minimax(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU 1 SELECTS : "<<res.i<<" STICKS"<<endl;
        n=n-res.i;
        cout<<"REMAINING STICKS :  "<<n<<endl;
     }
     else
       {
        node res;
        cout<<"CPU 2'S CHANCE'"<<endl;
        res = minimax(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU 2 SELECTS : "<<res.i<<" STICKS"<<endl;
        n=n-res.i;
         cout<<"REMAING STICKS :  "<<n<<endl;
       }


    Sleep(2000);
    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==0)
               cout<<"CPU2 WON,CPU 1 LOST "<<endl;
          else
               cout<<"CPU 1 WON,CPU 2 LOST "<<endl;
      }
      if(n==1){
        if(i==1)
           cout<<"CPU2 WON,CPU 1 LOST"<<endl;
        else
           cout<<"CPU 1 WON,CPU 2 LOST "<<endl;
      }
    break;
    }


   if(i==1)
     {
           node res;
        cout<<"CPU 1'S CHANCE"<<endl;
        res = minimax(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU 1 selects : "<<res.i<<endl;
        n=n-res.i;
         cout<<"Remaining Sticks :  "<<n<<endl;
     }
     else
       {
        node res;
        cout<<"CPU 2 chance "<<endl;
        res = minimax(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU 2 selects : "<<res.i<<endl;
        n=n-res.i;
         cout<<"Remaining Sticks :  "<<n<<endl;
       }
  }

}

void twoPlayerGame(int n)
{   cout<<"TOSS"<<endl;
    srand(time(0));//TO GENRATE A RANDOM NUMBER
    //Sleep(2000);//so that output dont come instantly
    int pickup1,pickup2;
	int i = rand()%2;
//i=0 denotes the chance is of player1 and i=1 denotes the chance is of player 2
    if(i==0)
        cout<<"Player 1 won toss"<<endl;
    else
        cout<<"Player 2 won toss"<<endl;

    cout<<"--------THE GAME STARTS--------"<<endl;


    while(1){
  
    if(n==1 || n==0)
    { if(n==0)//there is no stick left so whoever previous chance was will lose i=1 denotes previous chance was of player 1 therefore player 1 loose
      {
          if(i==1)
               cout<<"Player 1 lost "<<endl;
          else
               cout<<"Player 2 lost "<<endl;
      }
      if(n==1){//for a single stick left
        if(i==0)
           cout<<"Player 1 lost "<<endl;
        else
           cout<<"Player 2 lost "<<endl;
      }
    break;
    }
  label1: if(i==0)//we are creating a labelel to handle wrong inputs i.e. any except 1,2,3
       cout<<"PLAYER 1'S CHANCE ' "<<endl;
    else
       cout<<"PLAYER 2'S CHANCE ' "<<endl;

    cin>>pickup1;//expecting the number of sticks to pickup
    if(pickup1<4 && pickup1>=1)
    n=n-pickup1;//DEDUCTING THE STICKS PICKED UP
    else
    { cout<<"INVALID MOVE"<<endl;
      goto label1;
    }
     cout<<"REMAINING STICKS TO BE PICKED :  "<<n<<endl;
   

    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==0)
               cout<<"PLAYER 2 WON, PLAYER 1 LOST "<<endl;
          else
               cout<<"PLAYER 1 WON,PLAYER 2 LOST "<<endl;
      }
      if(n==1){
        if(i==1)
           cout<<"PLAYER 2 WON,PLAYER 1 LOST "<<endl;
        else
           cout<<"PLAYER 1 WON, PLAYER 2 LOST "<<endl;
      }
    break;
    }

   label2: if(i==1)
       cout<<"PLAYER 1'S CHANCE'"<<endl;
    else
       cout<<"PLAYER 2'S CHANCE' "<<endl;

    cin>>pickup2;
    if(pickup2<4 && pickup2>=1)
    n=n-pickup2;
    else
    { cout<<"INVALID MOVE"<<endl;
      goto label2;
    }

     cout<<"REMAINING STICKS TO BE PICKED :  "<<n<<endl;
}
}


void onePlayerGame(int n)
{
    cout<<"TOSS"<<endl;
    srand(time(0));
    
    int pickup1,pickup2,cpu,i = rand()%2;

    if(i==0)
        cout<<"PLAYER WINS THE TOSS"<<endl;
    else
        cout<<"CPU WINS THE TOSS"<<endl;

    cout<<"--------START PICKING UP THE STICKS--------"<<endl;

 while(1){
   
    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==1)
               cout<<"CPU WON,PLAYER LOST "<<endl;
          else
               cout<<"PLAYER WON,CPU LOST "<<endl;
      }
      if(n==1){
        if(i==0)
           cout<<"CPU WON,PLAYER LOST "<<endl;
        else
           cout<<"PLAYER WON,CPU LOST "<<endl;
      }
    break;
    }
    if(i==0)
     {
        l:cout<<"PLAYER'S CHANCE TO PICK' "<<endl;
        cin>>pickup1;
        if(pickup1<4 && pickup1>=1)
        n=n-pickup1;
        else
        { cout<<"INVALID MOVE"<<endl;
          goto l;
        }
     }
     else
       {
        node res;
        cout<<"CPU'S CHANCE TO PICK' "<<endl;
        res = minimax(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU SELECTS : "<<res.i<<" STICKS"<<endl;
        n=n-res.i;
       }

     cout<<"REMAINING STICKS TO BE PICKED :  "<<n<<endl;
  
    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==0)
               cout<<"COMPUTER WON,PLAYER LOST "<<endl;
          else
               cout<<"PLAYER WON,CPU LOST  "<<endl;
      }
      if(n==1){
        if(i==1)
           cout<<"COMPUTER WON,PLAYER LOST "<<endl;
        else
           cout<<"PLAYER WON,CPU LOST  "<<endl;
      }
    break;
    }


   if(i==1)
     {
        label1:cout<<"PLAYER'S CHANCE TO PICK STICKS' "<<endl;
        cin>>pickup2;
        if(pickup2<4 && pickup2>=1)
        n=n-pickup2;
        else
        { cout<<"INVALID MOVE"<<endl;
          goto label1;
        }
     }
     else
       {
        node res;
        cout<<"CPU'S CHANCE TO PICK STICKS' "<<endl;
        res = minimax(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU HAS SELECTED  "<<res.i<<" STICKS"<<endl;
        n=n-res.i;
       }

        cout<<"Remaining Sticks :  "<<n<<endl;
  }


}




int main()
{ int i,j,n,l;
  cout<<"********************************************GAME*********************************************************"<<endl;
  cout<<"CHOOSE ANY OPTION 1,2,3"<<endl;
  cout<<"1.TWO PLAYER GAME"<<endl;
  cout<<"2. ONE VS COMPUTER  GAME"<<endl;
  cout<<"3. AI vs AI"<<endl;
  cin>>i;
  for(n=0;n<54;n++)
    {f[n].value=20;
    t[n].value=20;}

  cout<<"ENTER THE NUMBER OF STICKS"<<endl;
  cin>>n;
  node k;
  //Sleep(2000);
  cout<<"RULE :ENTER NUMBER BETWEEM 1 AND 3"<<endl;
  if(i==1)
     {
         twoPlayerGame(n);
         cout<<"***************************GAME OVER THANKS FOR PLAYING***************************"<<endl;

     }
  if(i==2)
     {
        onePlayerGame(n);
         cout<<"***************************GAME OVER THANKS FOR PLAYING***************************"<<endl;
     }

  if(i==3)
  {
      AIvsAI(n);
       cout<<"***************************GAME OVER THANKS FOR PLAYING***************************"<<endl;
  }

  return 0;
}
