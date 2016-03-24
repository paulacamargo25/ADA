
#include <iostream>

using namespace std;
void insert_sort(int *a,int tam)
{
    int key;
    int i;
    for (int j=2;j<tam;j++)
    {
        key=a[j];
        i=j-1;
        while (i>-1 and a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }

}



int main()
{
    int tam;
    cout<<"Introduce el tamaño: ";
    cin>>tam;
    int a[tam];
    cout<<"Introduce los datos:"<<endl;
    for (int h=0;h<tam;h++)
    {
        cin>>a[h];
    }
    insert_sort(a,tam);
    cout<<"Lista ordenada:"<<endl;
    for (int h=0;h<tam;h++)
    {

        cout<<a[h]<<endl;
    }
    return 0;
}
