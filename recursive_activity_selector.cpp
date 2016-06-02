vector<int> recursive_activity_selector(vector<int> s,vector<int> f,int k,int n)
{
    int m=k+1;
    while (m<n and s[m]<f[k])
    {
        m=m+1;
    }
    vector<int> res;
    if (m<n)
    {
        res.push_back(s[m]);
        vector<int> aux=recursive_activity_selector(s,f,m,n);
        for(int i=0;i<aux.size();i++)
        {
            res.push_back(aux[i]);
        }
        return res;
    }
    else
    {
        return res;
    }
}

int main()
{
    int s1[11]={1,3,0,5,3,5,6,8,8,2,12};
    int f1[11]={4,5,6,7,9,9,10,11,12,14,16};
    vector<int> s (s1, s1 + sizeof(s1) / sizeof(int) );
    vector<int> f (f1, f1 + sizeof(f1) / sizeof(int) );
    vector<int> t=recursive_activity_selector(s,f,-1,11);
    for(int i=0;i<t.size();i++)
    {
        cout<<t[i]<<endl;
    }

    return 0;
}
