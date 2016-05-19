#include <iostream>
#include <vector>
#define INFI -9999999

using namespace std;

int bottom_up_cut_rod(vector<int>& p, int n)
{
    vector<int> r(n+1);
    int q;
    r[0] = 0;
    for(int j = 1; j <= n; j++)
    {
        q = INFI;
        for(int i = 1; i <= j; i++)
        {
            q = max(q,p[i]+r[j-i]);
        }
        r[j] = q;
    }
    return r[n];
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
    cout<<"Max: "<<bottom_up_cut_rod(precios,tam)<<endl;
    return 0;
}
