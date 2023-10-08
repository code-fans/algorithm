#include <iostream>
using namespace std;

int main(){
    freopen("data/input.txt", "r", stdin);
    int a,b,c;
    while ( cin >> a){
        cin >> b >> c;
        cout << a << " " << b << " " << c << endl;
    }
    
    fclose(stdin);
    return 0;
}