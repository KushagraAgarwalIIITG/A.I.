#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void fitness_function(int a[],int n, int array[4])
{
    int i,p,q,r,fit = 0;
      for(i=0;i<n;i++)
      {
          p =  abs(a[j]-array[0]);
          q =  abs(a[j]-array[1]);
          r =  abs(a[j]-array[2]);

          
		  if(p>q)
		  {
			  if(q>r)
			  {
				  fit=fit+r;
			  }
			  else
			  {
				  fit=fit+q;
			  }
		  }
		  else if(p>r)
		  {
			  fit=fit+r;
		  }
		  else
		  {
			  fit=fit+p;
		  }
      }
      array[3]=fit;
}

void chrom(int a[],int n,int arr[][4],int m)
{   /* chromosome is a array of length 3, where each block contains group representative of that group. group representative which is nearest to a element
      will contain that element in the group  */

    srand(time(0));
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        {
            k = rand()%n;
            arr[i][j] = a[k];
        }
    }

     for(i=0;i<m;i++)
     {
         fitness_function(a,n,arr[i]);
     }

}

void selection_cross_mutation(int a[],int n,int arr[][4],int m)
{
    srand(time(0));
    int i,t,k,j,w;
    int arr1[m][4];
    for(i=0;i<m/2;i++)
    {   /* parent selection using tournament selection */
        int maxi=0;
        for(t=0;t<20;t++)
           { w = rand()%m;
             if(arr[w][3]>maxi)
             {   maxi = arr[w][3];
                 k=w;}
           }
        maxi =0;
        for(t=0;t<20;t++)
           { w = rand()%m;
             if(arr[w][3]>maxi)
             {   maxi = arr[w][3];
                 j=w;}
           }

           /* parent selection using tournament selection .
                      parent are k and j                    */

           /* WE ARE DOING CROSS OVER HERE */
         int c = rand()%3;

         for(t=0;t<=c;t++)
         {
             arr1[i][t] = arr[k][t];
             arr1[m-i-1][t] = arr[j][t];
         }
         for(t=c+1;t<=2;t++)
         {
             arr1[i][t] = arr[j][t];
             arr1[m-i-1][t] = arr[k][t];
         }
         /********* crossover*******************/
    }
     // now new generation is created
    /********* mutating any y chromosomes from the new generation*****************/
    int y = rand()%m;


    for(i=0;i<y;i++)
    {
        int g,h,r;
        g = rand()%m;
        h = rand()%3;
        r = rand()%n;
        arr1[g][h] = a[r];
    }
    for(i=0;i<m;i++)
     {
         fitness_function(a,n,arr1[i]);
     }

     for(i=0;i<m;i++)
     {
          for(t=0;t<4;t++)
          {
              arr[i][t]=arr1[i][t];
          }
     }

     /**************new generation in arr[][]*************************/

}

int main()
{
    srand(time(0));
    cout<<"Enter no. of students: "<<endl;
    int i,j,n;
    cin>>n;

    int a[n];
    for(i=0;i<n;i++)
     {
         a[i] = rand()%101+1;                // array of marks of n students
     }
    int population[50][4];                    // populationulation of 50 individual

    chrom(a,n,population,50);

  
    int gmi = 99999999;
    int globalmin[4];
    int itr = 2000;
    int mi = 99999999;
    while(itr-- || ((mi-gmi)>0) )
    {
    int minimum[4];

    for(i=0;i<50;i++)
    {
        if(population[i][3] < mi)
        {
            mi = population[i][3];
            minimum[0] = population[i][0];
            minimum[1] = population[i][1];
            minimum[2] = population[i][2];
            minimum[3] = population[i][3];
        }
    }

    if(mi<gmi)
    {
        gmi = mi;
        globalmin[0] = minimum[0];
        globalmin[1]=minimum[1];
        globalmin[2]=minimum[2];
        globalmin[3]=minimum[3];
    }

     selection_cross_mutation(a,n,population,50);


     //cout<<itr<<" : "<<endl;
     //cout<<mi<<endl;

    }


    vector <pair<int,int>> g1,g2,g3;
     int p,q,r;
      for(j=0;j<n;j++)
      {
          p =  abs(a[j]-globalmin[0]);
          q =  abs(a[j]-globalmin[1]);
          r =  abs(a[j]-globalmin[2]);

         
		  if(p>q)
		  {
			  if(q>r)
			  {
				  g3.push_back(make_pair(a[j],j));
			  }
			  else
			  {
				g2.push_back(make_pair(a[j],j));
			  }
		  }
		  else if( p>r)
		  {
			  g3.push_back(make_pair(a[j],j));
		  }
		  else
		  {
			  g1.push_back(make_pair(a[j],j));
			  
		  }
		  
      }


    cout<<"-----------group 1:"<<globalmin[0]<<" group 2:"<<globalmin[1]<<" group 3 : "<<globalmin[2]<<" fitness_function : "<<globalmin[3]<<" "<<"----------------"<<endl;
    cout<<"STUDENTS IN THE GROUP 1"<<endl;
    for(j=0;j<g1.size();j++)
    {
        cout<<"NUMBER OF THE STUDENT  "<<g1[j].second<<" MARKS: "<<g1[j].first<<endl;
    }
    cout<<"STUDENTS IN THE GROUP 2"<<endl;
    for(j=0;j<g2.size();j++)
    {
        cout<<"nUMBER OF STUDENT  "<<g2[j].second<<" MARKS: "<<g2[j].first<<endl;
    }
    cout<<"STUDENTS IN THE GROUP 3"<<endl;
    for(j=0;j<g3.size();j++)
    {
        cout<<"NUMBER OF THE STUDENT  "<<g3[j].second<<" MARKS: "<<g3[j].first<<endl;
    }


   




    return 0;
}