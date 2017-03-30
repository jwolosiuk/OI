#include <iostream>
#include <algorithm>
using namespace std;

int karty[1000006];

int main(){
    int ile;
    cin >> ile;
    for(int i=0;i<ile;i++){
        cin >> karty[i];
    }
    sort(karty,karty+ile);
    int wynik = karty[0];
    for(int i=1;i<ile;i++){
        wynik = max(wynik,karty[i]-wynik);
    }
    cout << wynik;

}
