#include<iostream>
using namespace std;
int p,q;// 2 so nguyen to ban dau
int e;//chon e phai la so du lon
int ucln(int a,int b)
{
    if(a==b) return a;
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return ucln(a-b,b);
    else return ucln(a,b-a);
}
int mahoa(int X,int e,int N)
{
    int mod=1;
    for(int i =1;i<=e;i++)
    {
        mod *=X;
        mod=mod%N;
    }
    return mod;
}
int giaima(int Y,int d,int N)
{
    int mod=1;
    for(int i =1;i<=d;i++)
    {
        mod *=Y;
        mod=mod%N;
    }
    return mod;
}
int nghichdaotheoMOD(int e,int N)
{
    int  i;
    for(i =1;i<N;i++ )
    {
        if((i*e)%N==1)
        break;
    }
    return i;
}
int main()
{
    //cout<<ucln(36,24)<<endl;
    //cout<<nghichdaotheoMOD(7,35)<<endl;
    std::cout<<"RSA voi p va q : "<<endl;
    std::cin>>p>>q;
    int M = (p-1)*(q-1);
    int N = p*q;
    int e;
    for(e = M/4;e<M;e++)
    {
        if(ucln(e,M)==1) break;
    }
    //cout<<"e la "<<e<<endl;
    int d = nghichdaotheoMOD(e,M);
   // cout<<" d la "<<d<<endl;
    std::cout<<" cong khai gom "<<e<<" "<<N<<endl;
    std::cout<<" bi mat gom "<<p<<" "<<q<<" "<<d<<endl;
    int Giatricanma = 100;
    int  ma = mahoa(Giatricanma,e,N);
    std::cout<<"Gia tri ma hoa cua 100 la "<<ma<<endl;
    std::cout<<"Gia tri gia ma la :"<<giaima(ma,d,N);
    return 0;
}