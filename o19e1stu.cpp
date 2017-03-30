#include <iostream>
using namespace std;

long long int n;
long long int lopaty;
long long int topo[1000006];
long long int topo_w[1000006];
long long int prawe[1000006];
long long int lewe[1000006];
long long int te_le[1000006];
long long int te_pr[1000006];

long long int wygl(long long int diff){
    long long int koszt=0;
    topo_w[1]=topo[1];
    long long int last=topo[1];
    for(long long int i=2;i<=n;i++){
        last=min(last+diff,topo[i]);
        topo_w[i]=last;
    }
    last=topo_w[n];
    koszt = topo[n]-topo_w[n];
    for(long long int i=n-1;i>0;i--){
        last=min(last+diff,topo_w[i]);
        topo_w[i]=last;
        koszt += topo[i]-topo_w[i];
    }
    return koszt;
}

void licz(long long int diff) {
    for(long long int i=0;i<=n;i++){
        prawe[i]=0;
        lewe[i]=0;
        te_le[i]=0;
        te_pr[i]=0;
    }

    for(long long int i=2;i<=n;i++){
        int ile_calych=topo_w[i]/diff;
        te_le[i]+=diff;
        te_le[min(i+ile_calych,n+1)]-=diff;
        lewe[min(i+ile_calych,n+1)]+=topo_w[i]%diff;

        te_pr[i+1]-=diff;
        te_pr[max(1,i-ile_calych+1)]+=diff;
        prawe[max(0,i-ile_calych)]+=topo_w[i]%diff;

    }
    long long int sumap = 0;
    long long int sumal = 0;
    for(long long int i=1;i<=n;i++){
        sumap+=te_pr[i];
        prawe[i]+=sumap;
        sumal+=te_le[i];
        lewe[i]+=sumal;
    }

}

long long int check(long long int diff) {
    long long int koszt=0;;
    if(diff == 0) {
        for(long long int i=1;i<=n;i++){
            koszt+=topo[i];
        }
        if(koszt>lopaty) return -1;
        return 1;
    }
    koszt = wygl(diff);
    long long int piramida =0;
    for(long long int i=1;i<=n;i++){
        piramida+=max((long long int)0,topo_w[i]-(i-1)*diff);
    }
    if(koszt + piramida <= lopaty) return 1;
    for(long long int i=2;i<=n;i++){
        piramida+=prawe[i];
        piramida-=lewe[i-1];
        if(koszt + piramida <= lopaty) return i;
    }
    return -1;
}

long long int bin_s(long long int k) {
    long long int p = 0;
    while(p<k) {
        long long int c=(p+k)/2;
        if(check(c)==-1){
            p = c+1;
        } else {
            k=c;
        }
    }
    return k;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> lopaty;
    long long int maks = 0;
    for(long long int i=1;i<=n;i++) {
        cin >> topo[i];
        maks = max(topo[i],maks);
    }
    long long int diff = bin_s(maks);
    cout << check(diff) << " "<< (diff);
}
