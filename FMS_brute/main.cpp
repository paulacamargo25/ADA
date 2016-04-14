#include <iostream>
#include <time.h>
using namespace std;

int* FMS_brute(int a[],int menor,int mayor)
{
    int sumatotal=-99999999999;
    int res[3];
    int izq;
    int der;
    for(int i=menor;i<mayor;i++)
    {
        int suma=0;
        for (int j=i;j<mayor;j++)
        {
            suma+=a[j];
            if (sumatotal<suma)
            {
                izq=i;
                der=j;
                sumatotal=suma;
            }
        }
    }
    res[0]=izq;
    res[1]=der;
    res[2]=sumatotal;
    return res;
}

int main()
{
    cout << "FMS" << endl;
    //         0   1   2  3  4   5  6  7   8  9 10 11  12 13 14 15
    int A[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int* a;
    int* b;
    int x,y,z;
    a=A;

    b=FMS_brute(a,0,16);

    x=b[0];
    y=b[1];
    z=b[2];
    cout<<"Indice menor: "<<x<<endl;
    cout<<"Indice mayor: "<<y<<endl;
    cout<<"Suma: "<<z<<endl;

    return 0;
}
