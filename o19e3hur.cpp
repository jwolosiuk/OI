#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long int dostawa[250004];
long long int zamow[250004];
long long int kolej[250004];
long long int sum[600005];
long long int ost[600005];

bool realize[250004];
int m;
int dwaDoM;

bool comparator(const long long& l, const long long& r){
    return zamow[l] < zamow[r];
}

void ustaw(long long i,long long v){
    i+=dwaDoM;
    sum[i]=v;
    if(v>0){
        ost[i]=i;
    } else {
        ost[i]=-1;
    }
    while(i>1){
        i/=2;
        sum[i]=sum[2*i]+sum[2*i+1];
        ost[i]=max(ost[2*i],ost[2*i+1]);
    }
}

long long int suma(long long i){
    i+=dwaDoM+1;
    long long int wynik=0;
    while(i>0){
        if(i%2==1){
            wynik+=sum[i-1];
        }
        i/=2;
    }
    return wynik;
}

long long int ostatniNiezerowy(long long i){
    i+=dwaDoM;
    long long int wynik=ost[i];
    while(i>1){
        if(i%2==1){
            wynik=max(wynik,ost[i-1]);
        }
        i/=2;
    }
    return wynik;
}

int main(){
    ios_base::sync_with_stdio(0);
    int dni;
    cin >> dni;
    m = ceil(log2(250000));
    dwaDoM=pow(double(2),m);

    for(int i=0;i<dni;i++){
        cin >> dostawa[i];
        ustaw(i,dostawa[i]);
    }

    for(int i=0;i<dni;i++){
        kolej[i]=i;
        cin >> zamow[i];
    }

    sort(kolej,kolej+dni,comparator);

    long long wynik = 0;
    for(int i=0;i<dni;i++){
        long long b = zamow[kolej[i]];
        long long a = suma(kolej[i]);
        if(a>=b){
            wynik++;
            realize[kolej[i]]=true;
            long long j = kolej[i];
            while(b>0){
                j=ostatniNiezerowy(j);
                if(b<=sum[j]){
                    ustaw(j-dwaDoM,sum[j]-b);
                    b=0;
                } else {
                    b-=sum[j];
                    ustaw(j-dwaDoM,0);
                }
                j-=dwaDoM;
            }
        }
    }
    cout << wynik << "\n";
    for(int i=0;i<dni;i++){
        if(realize[i]) cout << i+1 << " ";
    }
}
