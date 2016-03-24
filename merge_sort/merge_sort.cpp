
#include <iostream>

using namespace std;

void merge(int *A, int p, int q, int r)
{
    cout<<"P: "<<p<<" q: " <<q<<"R: "<<r<<endl;
       int n1=q-p+1;
    cout<<"n1: "<<n1<<endl;
    int n2=r-q;
    cout<<"n2: "<<n2<<endl;
    int L[n1+1];
    int R[n2+1];
    int i,j;
    cout<<"L"<<endl;
    for (i=0;i<n1;i++)
    {
        L[i]=A[p+i];
        cout<<L[i]<<endl;
    }
    cout<<"R"<<endl;
    for (j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
        cout<<R[j]<<endl;
    }

    L[n1]=99999999;
    R[n2]=99999999;
    i=0;
    j=0;
    for (int k=p;k<=r;k++)
    {
	if (L[i]<=R[j])
	{
		A[k]=L[i];
		i++;
	}
	else
	{
		A[k]=R[j];
		j++;
	}
    }
}

void merge_sort(int *puntero_lista,int p,int r)
{
    if (p<r)
    {
        int q=(p+r)/2;
        merge_sort(puntero_lista,p,q);
        merge_sort(puntero_lista,q+1,r);
        merge(puntero_lista,p,q,r);
    }
}

int main()
{
    int tam;
    cin>>tam;
    int lista[tam];

    for(int i=0;i<tam;i++)
    {
        cin>>lista[i];
    }

    cout<<"Lista: "<<endl;
    for(int i=0;i<tam;i++)
    {
       cout<<lista[i]<<endl;
    }

    merge_sort(lista,0,tam-1);
    cout<<"\nLista ordenada: "<<endl;
    for (int i=0;i<tam;i++)
    {
        cout<<lista[i]<<endl;
    }
}
