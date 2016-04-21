#include <iostream>
#include <math.h>
#include<vector>
int tam;
using namespace std;


void inter(vector<int> &A,int a, int b)
{
    int tem=A[a];
    A[a]=A[b];
    A[b]=tem;
}

int parent(int i)
{
    return (i-1)/2;
}

int left(int i)
{
    return 2*(i+1)-1;
}

int right(int i)
{
    return 2*(i+1);
}
void MaxHeapify(vector<int> &a,int i)
{
    int l=left(i);
    int r=right(i);
    int largest;
    if (l<tam and a[l]>a[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if (r<tam and a[r]>a[largest])
    {
        largest=r;
    }
    if (largest!=i)
    {
        inter(a,i,largest);
        MaxHeapify(a,largest);
    }
}

int heap_maximum(vector<int> &lista)
{
    return lista[0];
}

int heap_extract_maximun(vector<int> &a)
{
    if (tam<1)
    {
            cout<<"Error underflow"<<endl;
            return -1;
    }
    int max=a[0];
    a[0]=a[tam];
    tam--;
    MaxHeapify(a,0);
    return max;
}

void heap_increase_key(vector<int> &a, int i, int key)
{
    if (key<a[i])
    {
        cout<<"Error: La nueva llave es menor"<<endl;
        return;
    }
    a[i]=key;
    while (i>0 and a[parent(i)]<a[i])
    {
        inter(a,i,parent(i));
        i=parent(i);
    }
}

void max_heap_insert(vector<int> &a,int key)
{
    tam++;
    a.push_back(-1);
    heap_increase_key(a,tam-1,key);
}

void imprimir(vector<int> a)
{
    cout<<"Lista: "<<endl;
    for (int f=0;f<tam;f++){
        cout<<a[f]<<" ";
        }
        cout<<endl;
}


int main()
{
    vector<int> priority;
    int tam1;
    cout<<"Introduce numero de elementos a insertar: ";
    cin>>tam1;
    tam=0;
    srand(time(NULL));
    int temp;
    for(int i=0;i<tam1;i++)
    {
        temp=(rand()%tam1)*2+1+i;
        max_heap_insert(priority,temp);
        cout<<"Insertar: "<<temp<<endl;
        imprimir(priority);
        cout<<endl;
    }

    cout<<"Extraer maximo\n"<<"Maximo: "<<heap_extract_maximun(priority)<<endl;
    imprimir(priority);
    cout<<endl;

    cout<<"Extraer maximo\n"<<"Maximo: "<<heap_extract_maximun(priority)<<endl;
    imprimir(priority);
    cout<<endl;

    cout<<"Extraer maximo\n"<<"Maximo: "<<heap_extract_maximun(priority)<<endl;
    imprimir(priority);
    cout<<endl;

    cout<<"Obtener maximo\n"<<"Maximo: "<<heap_maximum(priority)<<endl;
}
