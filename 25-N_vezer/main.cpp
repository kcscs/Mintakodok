#include <iostream>
#define MAX_N 100
using namespace std;

bool oszlop[MAX_N];
bool atlo_jl[MAX_N*2];
bool atlo_jf[MAX_N*2];

int sor[MAX_N]; //babuk helye soronkent
int N;
int db = 0;

bool megold(int s){ //sor indexe
    if(s == N){
        for(int i = 0; i < N; ++i)
            cout<<sor[i]+1<<' ';
        cout<<'\n';
        ++db;
        return false;
    }
    for(int i = 0; i < N; ++i){
        int jl = N-1-s+i;       ///bal also sarok 0
        int jf = N-1-s+N-1-i;   ///jobb also sarok 0
        if(!oszlop[i] && !atlo_jl[jl] && !atlo_jf[jf]){
            oszlop[i] = true;
            atlo_jl[jl] = true;
            atlo_jf[jf] = true;
            sor[s] = i;
            if(megold(s+1))
                return true;
            oszlop[i] = false;
            atlo_jl[jl] = false;
            atlo_jf[jf] = false;
        }
    }
    return false;
}

int main()
{
    cin>>N;
    megold(0);
    cout<<"db: "<<db<<'\n';
    return 0;
}
