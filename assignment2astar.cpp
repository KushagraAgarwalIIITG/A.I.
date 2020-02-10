/*   State Space:- An 8x8 matrix with any arrangement of n<=8 queens
 * Initial State:- No queens on the board(i.e., all entries are null)
 *
 * Action:- Add a new queen in an empty column
 * Goal state:- 8 Queens placed on the board such that all queens are in non-attacking position
 *
 * Cost:- One per queen placed
 * Heuristic Function:- Number of feaisble blocks(so that queen can be palced) int the current state.
 *
 * by:- Kushagra Agarwal
 * Roll no:- 1801096
 * B.Tech 2nd Year CSE
 */


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,vector<vector<int>>> p;




// checking safe position for queen
bool positionCheck(vector<vector<int>> &v,int row, int col){
    int i, j;
    // checking safe position in the  left
    for (i = 0; i < col; i++)
        if (v[row][i])
            return false;
    // checking safe postion in the left upward
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (v[i][j])
            return false;
    // checking safe positon in the left downward
    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (v[i][j])
            return false;
    //if the position is safe then return true
    return true;
}



// counting number of feasible blocks in current state
// storing positon of queen in array pe(row)and q(colm).
// now checking blocks if feasible or not and increasing count if feasible;
int heuristicFunction(vector<vector<int>> &v)
{
    int a,b,count=0;
  vector<int> pe,q;
  vector<vector<int>> temp(8,vector<int>(8,0));
  for( a=0;a<8;a++){
        for(b=0;b<8;b++){
             if(v[a][b]==1)
                  {pe.push_back(a);
                   q.push_back(b);}
        }
  }
  int k = pe.size();
  int h,fl=0,j = q.size();

   for( a=0;a<8;a++){
       fl=0;
        for(b=0;b<8;b++){
            for( h=0;h<k;h++){
                if(a==pe[h])
                    {fl=1;
                     break;}
            }
            if(fl==1)continue;
            for( h=0;h<k;h++){
                if(b==q[h])
                    {fl=1;
                        break;}
            }
            if(fl==1)continue;
             for( h=0;h<k;h++){
                 if(abs(a-pe[h]) == abs(b-q[h]))
                     {  fl==1;
                        break;}
             }

            if(fl==0)
                count++;
        }
   }

  return count;

}


void sovleastar(priority_queue<p,vector<p>,greater<p>> &open, vector<vector<int>> &v){
    // push blank chess board and cost = 0 in open
    open.push(make_pair(0,v));
    int k = 1;
    while(!open.empty()){
        for(int j = 0; j < 8; ++j){
            p storePair = open.top();
            vector<vector<int>> vec = storePair.second;
            if(storePair.first!=0)
                  { int u = heuristicFunction(vec);
                    storePair.first -= u;
                  }
            int t = storePair.first;
            if(positionCheck(vec,j,t)){
                if(t == 7){
                     vec[j][t] = 1;
                     //print index
                     cout << "solution :"<<k << endl;
                     ++k;
                     // print all possible solution of 8 queen
                     for(auto it : vec){
                        for(auto i : it){
                            cout << i << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }else{
                    vec[j][t] = 1;
                    //push new pair into open

                   int y = heuristicFunction(vec);
                   y=y+(t+1);// t+1 act as g(n) and y as h(n)
                    open.push(make_pair(y,vec));// y is priority of that stae
                }
            }
        }
        open.pop();
    }
}


int main(){
    //priority queue for storing pairs (cost and pointer to chess board)
    priority_queue<p,vector<p>,greater<p>> open;
    // creating 8X8 chess board
    vector<vector<int>> v(8,vector<int>(8,0));
    sovleastar(open,v);
    return 0;
}
