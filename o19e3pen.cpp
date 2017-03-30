#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pr_przelo[1000006];
int pr_kw[1000006];

bool znane[1000006];
bool niejedn[1000006];

vector<int> nieuzyte;
vector<int> tezn;

vector<int> trzymacz;

int szef;
int ile;

vector<int> korzenie;

vector<int> drzewo[1000006];
vector<int> lepszedrzewo[1000006];

void podziel(int kor){
    int korV = pr_kw[kor];
    if(kor==szef && korV==0){
        korzenie.push_back(szef);
        for(int i=0;i<ile+1;i++){
            lepszedrzewo[i]=drzewo[i];
        }
    } else {
        bool upped=false;
        for(int i=0;i<drzewo[kor].size();i++){
            int syn=drzewo[kor][i];
            int synV=pr_kw[syn];
            if(synV==0) {
                if(korV!=0 && !upped){
                    upped=true;
                    korzenie.push_back(kor);
                }
                lepszedrzewo[kor].push_back(syn);
            }
            podziel(syn);
        }
    }

}

bool pierwszykor(int a, int b){
    return pr_kw[a]<pr_kw[b];
}

void poldfs(int kor){
    int dzieci=lepszedrzewo[kor].size();
    if(pr_kw[kor]==0){
        pr_kw[kor]=trzymacz.back();
        trzymacz.pop_back();
    }
    while(dzieci==1){
        int syn=lepszedrzewo[kor][0];
        pr_kw[syn]=trzymacz.back();
        trzymacz.pop_back();
        dzieci=lepszedrzewo[syn].size();
        syn=kor;
    }

}

int licz_dzieci(int kor){
    int licznik=0;
    for(int i=0;i<lepszedrzewo[kor].size();i++){
        licznik+=1;
        licznik+=licz_dzieci(lepszedrzewo[kor][i]);
    }
    return licznik;
}

int main() {
    ios_base::sync_with_stdio(false);
    ile=0;
    cin >> ile;
    for(int i=1;i<ile+1;i++){
        cin >> pr_przelo[i];
        cin >> pr_kw[i];
        if(pr_przelo[i]==i){
            szef=i;
        } else {
            drzewo[pr_przelo[i]].push_back(i);
        }
        znane[pr_kw[i]]=true;
    }
    for(int i=ile;i>=1;i--){
        if(znane[i]==0){
            nieuzyte.push_back(i);
            tezn.push_back(i);
        }
    }// 4 3 2
    podziel(szef);
    sort(korzenie.begin(),korzenie.end(),pierwszykor);

    for(int i=0;i<korzenie.size();i++){
        int kor=korzenie[i];
        int korV=pr_kw[kor];
        trzymacz.clear();
        int ile_trza=licz_dzieci(kor);
        if(korV==0){
            ile_trza+=1;
        }
        for(int i=0;i<ile_trza;i++){
            int ostatni = nieuzyte.back();
            nieuzyte.pop_back();
            trzymacz.push_back(ostatni);
        } // 2 3
        if(nieuzyte.size()==0 || nieuzyte.back()>korV){
                while(tezn.size()>0 && tezn.back()<korV){
                    tezn.pop_back();
            }
                poldfs(kor);
        } else {
            while(tezn.size()>0 && tezn.back()<korV){
                niejedn[tezn.back()]=true;
                tezn.pop_back();
            }
        }
    }

    for(int i=1;i<=ile;i++){
        if(niejedn[pr_kw[i]]==false){
            cout << pr_kw[i] << endl;
        } else {
            cout << 0<< endl;;
        }
    }

}
