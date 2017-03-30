#include <iostream>
using namespace std;

int gdzie[1000006];
int dojscie[1000006];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> gdzie[i];
    }
    int j;
    int cykle = 0;
    for(int i=1;i<=n;i++){

        j=i;
        while(dojscie[j]==0){
            dojscie[j]=i;
            j=gdzie[j];
        }
        if(dojscie[j]==i)
            cykle++;

    }
    cout << cykle;
}
