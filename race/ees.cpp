#include <iostream>
using namespace std;
int main()
{
    int a,ans=0,ans1=0,ans2=0;
    cin>>a;
    int b=a%4;
    ans=b/2;
    ans1=b%2;
    ans2=a/4-ans-ans1;
    cout<<ans<<' '<<ans1<<' '<<ans2<<endl;
    return 0;
}