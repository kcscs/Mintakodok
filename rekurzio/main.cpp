#include <iostream>
#include <windows.h>
#define TESZT_DB 10000000
#define TESZT_DB_FIB 100000
#define TESZT_DB_BIN 1000
#define TESZT_DB_BIN2 10000000
using namespace std;

long long int N, K;

long long int fakt(long long int n){
    if(n == 0)
        return 1;
    else
        return n*fakt(n-1);
}

long long int faktIterativ(long long int n){
    long long int f = 1;
    for(int i = 2; i <= n; ++i)
        f *= i;
    return f;
}

long long int fib(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}

long long int fibIterativ(int n){
    long long int elozo = 0;
    long long int kov = 1;
    long long int fib;
    for(int i = 2; i <= n; ++i){
        fib = elozo+kov;
        elozo = kov;
        kov = fib;
    }

    return fib;
}

long long int binom(int n, int k){
    if(k == 0 || k == n)
        return 1;
    return binom(n-1,k-1)+binom(n-1,k);
}

long long int binom2(int n, int k){
    if(k == 0)
        return 1;
    return (binom2(n,k-1)*(n-k+1))/k;
}

long long int binomIterativ(int n, int k){
    long long int db = 1;
    for(int i = 0; i < k; ++i){
        db = (db*(n-i))/(i+1);
    }
    return db;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>N;
    cout<<N<<"! = "<<fakt(N)<<endl;

    cout<<TESZT_DB<<"-szer lefuttatva:"<<endl;
    DWORD kezd = GetTickCount();
    for(int i = 0; i < TESZT_DB; ++i)
        fakt(N);
    cout<<"rekurziv: "<<(GetTickCount() - kezd)<<" ms"<<endl;

    kezd = GetTickCount();
    for(int i = 0; i < TESZT_DB; ++i)
        faktIterativ(N);
    cout<<"iterativ: "<<(GetTickCount() - kezd)<<" ms"<<endl;

    cout<<"\n---\n\n";
    cin>>N;
    cout<<N<<". fibonacci szam: "<<fib(N)<<" "/*<<fibIterativ(N)*/<<endl;
    cout<<TESZT_DB_FIB<<"-szer lefuttatva:"<<endl;
    kezd = GetTickCount();
    for(int i = 0; i < TESZT_DB_FIB; ++i)
        fib(N);
    cout<<"rekurziv: "<<(GetTickCount() - kezd)<<" ms"<<endl;

    kezd = GetTickCount();
    for(int i = 0; i < TESZT_DB_FIB; ++i)
        fibIterativ(N);
    cout<<"iterativ: "<<(GetTickCount() - kezd)<<" ms"<<endl;

    cout<<"\n---\n\n";
    cin>>N>>K;
    cout<<N<<" alatt "<<K<<": "<<binom(N,K)/*<<" "<<binom2(N,K)<<" "<<binomIterativ(N,K)/*<<fibIterativ(N)*/<<endl;
    cout<<TESZT_DB_BIN<<"-szer lefuttatva:"<<endl;
    kezd = GetTickCount();
    for(int i = 0; i < TESZT_DB_BIN; ++i)
        binom(N,K);
    cout<<"binom1: "<<(GetTickCount() - kezd)<<" ms"<<endl;
    kezd = GetTickCount();
    for(int i = 0; i < TESZT_DB_BIN; ++i)
        binom2(N,K);
    cout<<"binom2: "<<(GetTickCount() - kezd)<<" ms"<<endl;
    kezd = GetTickCount();
    for(int i = 0; i < TESZT_DB_BIN; ++i)
        binomIterativ(N,K);
    cout<<"iterativ: "<<(GetTickCount() - kezd)<<" ms"<<endl;

    cout<<TESZT_DB_BIN2<<"-szer lefuttatva:"<<endl;
    kezd = GetTickCount();
    for(int i = 0; i < TESZT_DB_BIN2; ++i)
        binom2(N,K);
    cout<<"binom2: "<<(GetTickCount() - kezd)<<" ms"<<endl;
    kezd = GetTickCount();
    for(int i = 0; i < TESZT_DB_BIN2; ++i)
        binomIterativ(N,K);
    cout<<"iterativ: "<<(GetTickCount() - kezd)<<" ms"<<endl;
    return 0;
}
