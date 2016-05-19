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
    clock_t t_ini, t_fin;
    double secs;
    int tam, precio;
    cin>>tam;
    vector<int> precios(tam+1);
    for(int i = 1; i <= tam; i++)
    {
        //cin>>precio;
        //precios[i] = precio;
        precios[i] = i;
    }
    t_ini = clock();
    cout<<"Max: "<<cut_rod(precios,tam)<<endl;
    t_fin = clock();
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    cout<<"tiempo "<< secs * 1000.0<<endl;
    return 0;
}
