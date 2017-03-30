#include <iostream>
using namespace std;

int tab[300005];
int maxInt = 1000000009;

int bin_s(int k, int co) {
    int p=0;
    while(p<k) {
        int c = (p+k)/2+1;
        if(co <= tab[c]) p = c;
        else k = c - 1;
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(0);
    int najm;
    int n,wrzuca;
    cin >> n >> wrzuca;
    tab[0] = 2*maxInt;
    najm=tab[0];
    for(int i=1;i<=n;i++) {
        int now;
        cin >> now;
        najm = min(najm,now);
        tab[i]=najm;
    }
    int wynik=n+1;
    for(int i=0;i<wrzuca;i++) {
        int now;
        cin >> now;
        if(wynik == 0) break;
        wynik = bin_s(wynik-1,now);
    }
    cout << wynik;
}
