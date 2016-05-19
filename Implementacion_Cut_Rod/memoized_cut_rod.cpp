#include <iostream>
#include <vector>
#define INF -999999

using namespace std;


int memoized_cut_rod_aux(vector<int>& p, int n, vector<int>& r)
{
    int q;
    if(r[n] >= 0)
    {
        return r[n];
    }
    if(n == 0)
    {
        q = 0;
    }
    else
    {
        q = INF;
        for(int i = 1; i <= n; i++)
        {
            q = max(q,p[i]+memoized_cut_rod_aux(p,n-i,r));
        }
    }
    r[n] = q;
    return q;
}

int memoized_cut_rod(vector<int>& p, int n)
{
    vector<int> r(n+1);
    for(int i = 0; i <= n; i++)
    {
        r[i] = INF;
    }
    return memoized_cut_rod_aux(p,n,r);
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
    cout<<"Max: "<<memoized_cut_rod(precios,tam)<<endl;
    return 0;
}
