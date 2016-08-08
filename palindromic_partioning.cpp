#include <bits/stdc++.h>

using namespace std;

int minPalPartion(char *str)
{
    int n = strlen(str);

    int i, j, k, c[n][n] = {0}, l;
    bool p[n][n];

    for(i=0; i<n; i++)
    {
        c[i][i] = 0;
        p[i][i] = true;
    }

    for(l=2; l<=n; l++)
    {
        for(i=0; i<n-l+1; i++)
        {
            j = l-1+i;

            if(l == 2)
                p[i][j] = (str[i] == str[j]);

            else
                p[i][j] = (str[i] == str[j]) && p[i+1][j-1];

            if(p[i][j] == true)
                c[i][j] = 0;

            else
            {
                c[i][j] = INT_MAX;
                for(k=i; k<=j-1; k++)
                {
                    c[i][j] = min(c[i][j], 1+c[i][k]+c[k+1][j]);
                }
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(k=0; k<n; k++)
            cout<<c[i][k]<<" ";
        cout<<endl;
    }
    return c[0][n-1];
}

int main()
{
   char str[] = "ababbbabbababa";
   printf("Min cuts needed for Palindrome Partitioning is %d",
           minPalPartion(str));
   cout<<endl;
   return 0;
}