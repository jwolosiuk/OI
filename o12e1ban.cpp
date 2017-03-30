#include <iostream>
#include <vector>
using namespace std;

bool cantBe[10004];
vector<int> miejsca[10];

int bin_search(int znak, int atLeast){
    if(miejsca[znak].size()==0) return -1;
    int p=0;
    int k=miejsca[znak].size()-1;
    while(p<k){
        int s = (p+k)/2;
        if(miejsca[znak][s]>=atLeast){
            k=s;
        } else {
            p=s+1;
        }
    }
    int x=miejsca[znak][p];
    return x>=atLeast?x:-1;
}

int main(){
    int n;
    cin >> n;
    bool destroy=false;
    for(int i=0;i<n;i++){
        int len;
        cin >> len;
        char znak;
        for(int j=0;j<len;j++){
            cin >> znak;
            miejsca[znak-'0'].push_back(j);
        }
        for(int a=0;a<10;a++){
            int ia=-1;
            bool dea=false;
            if(miejsca[a].size()!=0){
                ia=miejsca[a][0];
            } else {
                dea=true;
            }
            for(int b=0;b<10;b++){
                int ib=bin_search(b,ia);
                bool deb=false;
                if(ib==-1 or dea){
                    deb=true;
                }
                for(int c=0;c<10;c++){
                    int ic=bin_search(c,ib);
                    bool dec = false;
                    if(ic==-1 or deb) dec=true;
                    for(int d=0;d<10;d++){
                        int id=bin_search(d,ic);
                        int key = 1000*a + 100*b + 10*c + d;
                        if(id==-1 or dec) cantBe[key]=true;
                    }
                }
            }
        }

        for(int j=0;j<10;j++){
            miejsca[j].clear();
        }
    }
    int licznik = 0;
    for(int i=0;i<10000;i++){
        if(!cantBe[i]) licznik++;
    }
    cout << licznik;
}
