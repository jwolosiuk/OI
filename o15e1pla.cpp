#include <iostream>
#include <vector>
using namespace std;

vector<long long int> stos;

int main(){
    ios_base::sync_with_stdio(false);
    long long int wys =0;
    int n;
    cin >> n;
    int licz =0;
    for(int i=0;i<n;i++){
        cin >> wys;
        cin >> wys;
        while(stos.size()!=0 && stos.back()>wys)
            stos.pop_back();
        if(stos.size()==0 || stos.back()<wys){
            stos.push_back(wys);
            licz++;
        }
    }
    cout << licz;
}
