#include <iostream>
#include <vector>
#define INFI -9999999

using namespace std;

int extended_bottom_up_cut_rod(vector<int>& p, int n, vector<int>& s)
{
    vector<int> r(n+1);
    int q;
    r[0] = 0;
    for(int j = 1; j <= n; j++)
    {
        q = INFI;
        for(int i = 1; i <= j; i++)
        {
                if(q<(p[i]+r[j-i]))
                {
                   q=p[i]+r[j-i];
                   s[j]=i;
                }
        }
        r[j] = q;
    }
    return r[n];
}

void print_cut_rod_solution(vector<int>& p, int n)
{
    vector<int> s(n+1);
    extended_bottom_up_cut_rod(p,n,s);
    while (n>0)
    {
        cout<<s[n]<<" ";
        n=n-s[n];
    }

}

int main()
{
    int tam, precio;
    cin>>tam;
    vector<int> precios(tam+1);
    for(int i = 1; i <= tam; i++)
    {
        cin>>precio;
        precios[i] = precio;
    }
    cout<<"Sol: ";
    print_cut_rod_solution(precios,tam);
    return 0;
}
