#include <iostream>

using namespace std;

int lotniska[1000006];
int dokad[1000006];
long long int trasa[1000006];

int main(){
    int n,s;
    cin >> n >> s;
    int maxi=0;
    long long int suma = 0;
    for(int i=0;i<n;i++){
        cin >> lotniska[i];
        suma += lotniska[i];
        maxi = max(lotniska[i],maxi);
    }
    int bak;
    for(int l=0;l<s;l++){
        scanf("%d", &bak);
        if(bak < maxi){
            printf("NIE\n");z
            continue;
        }

        int a=0;
        int b=0;
        long long int temp = 0;
        while(a<n){
            while(temp+lotniska[(b)]<=bak){
                temp+=lotniska[b];
                b++;
                b=b%n;
            }
            dokad[a]=b;
            trasa[a]=temp;
            temp-=lotniska[a];
            a++;
        }

        long long int teraz = 0;
        for(int i=0;i<n;i++)
            teraz=dokad[teraz];

        int start = teraz;
        teraz = start;
        int licznik = 0;
        temp = 0;

        while(temp<suma){
            licznik++;
            temp += trasa[teraz];
            teraz = dokad[teraz];
        }

        printf("%d\n", licznik);
    }
}
