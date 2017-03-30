#include <iostream>
#include <algorithm>
using namespace std;

int ilosc[1000006];
int order[1000006];

int calosc[1000006];

bool comparator(const int& l, const int& r)
          {
           return ilosc[l] < ilosc[r];
          }

int main(){
    ios_base::sync_with_stdio(false);
    int colors,p,q;
    cin >> colors >> p >> q;
    int n=0;
    int maxi=0;
    int maxkol=0;
    for(int i=1;i<=colors;i++){
        order[i]=i;
        int ile;
        cin >> ile;
        n+=ile;
        ilosc[i]=ile;
        if(ile > maxi){
            maxi = ile;
            maxkol=i;
        }
    }

    bool canDo = true;
    if(maxi>(n-1)/2)
        canDo = false;
    if(n%2==1 && maxi == (n+1)/2 && p==q && p==maxkol)
        canDo =true;
    if(n%2==0 && maxi == n/2){
         if(p==maxkol or q==maxkol){
            canDo = true;
         }
         if(p==maxkol and q==maxkol){
            canDo = false;
            if(colors>=3) canDo=true;
         }
    }
    ilosc[p]--;
    ilosc[q]--;
    n-=2;
    if(n>-1 and (ilosc[p]<0 or ilosc[q]<0))
        canDo = false;

    if(!canDo){
        cout << 0;
        return 0;
    }
    sort(order,order+colors+1,comparator);



    int lenS1 = 0;
    int idx1 = 2;
    int lenS2 = 0;
    int idx2 = 1;
    for(int i=1;i<=colors;i++){
        int kolor = order[i];
        for(int i=0;i<ilosc[kolor];i++){
            if(lenS1<n/2){
                calosc[idx1]=kolor;
                lenS1++;
                idx1+=2;
            } else {
                calosc[idx2]=kolor;
                lenS2++;
                idx2+=2;
            }
        }
    }

    bool odwroc = false;
    bool wrzuc = false;
    int wrzucTo = 0;
    int p2=calosc[1];
    int q2=calosc[n];
    int pocz=0;

    if(p!=p2 && q!=q2){
            calosc[0]=p;
            calosc[n+1]=q;

    } else if((p==p2 && q!=p2 && p!=q2) || (q==q2 && p!=q2 && q!=p2)){
            calosc[0]=q;
            calosc[n+1]=p;
            odwroc=true;

    } else if((p==p2 && p2==q && q!=q2) or (p==p2 and p2==q2)) {
            calosc[n+1] = q;
            pocz = 1;
            wrzuc = true;
            wrzucTo = p;
    } else if((q==q2 && q2==p && p!=p2) or (q==p2 and p2==q2)){
            calosc[0] = p;
            n--;
            wrzuc = true;
            wrzucTo = q;
    }

    n+=2;

    if(odwroc){
        for(int i=n-1;i>=0;i--){
            cout << calosc[i] << " ";
        }
    } else {
        for(int i=pocz;i<n;i++){
            int next=i+1;
            cout << calosc[i] << " ";
            if(wrzuc && calosc[i]!=wrzucTo && calosc[next]!=wrzucTo){
                cout << wrzucTo << " ";
                wrzuc = false;
            }
        }
    }



}
