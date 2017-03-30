#include <iostream>
#include <vector>
using namespace std;

int wagi[1000006];
int from[1000006];
int to[1000006];

int perm[1000006];
int odw[1000006];
vector<int> dlugosci;
vector<long long int> sumyWag;
vector<int> minima;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int najm=7000;
    for(int i=1;i<=n;i++){
        cin>> wagi[i];
        najm=min(najm,wagi[i]);
    }
    for(int i=1;i<=n;i++){
        cin>> from[i];
    }
    for(int i=1;i<=n;i++){
        cin>> to[i];
        perm[from[i]]=to[i];
    }
    for(int i=1;i<=n;i++){
        int j=i;
        int licznik = 0;
        long long int suma = 0;
        int minimum = 70000;
        while(odw[j]==0){
            licznik++;
            suma+=wagi[j];
            minimum=min(wagi[j],minimum);
            odw[j]=i;
            j=perm[j];
        }
        if(licznik>0){
            dlugosci.push_back(licznik);
            sumyWag.push_back(suma);
            minima.push_back(minimum);
        }
    }
    long long int w=0;
    for(int i=0;i<dlugosci.size();i++){
        w+=min(sumyWag[i]+(dlugosci[i]-2)*minima[i],sumyWag[i]+minima[i]+(dlugosci[i]+1)*najm);
    }
    cout << w;
}
