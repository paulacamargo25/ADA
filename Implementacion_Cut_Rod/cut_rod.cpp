#include <iostream>
#include <vector>
#define INF -999999

using namespace std;

int cut_rod(vector<int>& p, int n)
{
    int q;
    if(n == 0)
    {
        return 0;
    }
    q = INF;
    for(int i = 1; i <= n; i++)
    {
        q = max(q,p[i]+cut_rod(p,n-i));
    }
    return q;
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
    cout<<"Max: "<<cut_rod(precios,tam)<<endl;
    return 0;
}
