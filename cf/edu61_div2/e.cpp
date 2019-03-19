#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10;
const int M=2e3+5;
int main(){
    bool dp[4000];
    int g=0;
    ll w,a[10],sum=0,sum2=0;
    cin>>w;
    for(int i=1;i<=8;i++){
        cin>>a[i];
        sum+=a[i]*i;
        sum2+=max(a[i]-100,0ll)*i;
        if(a[i]>100){
            if(g==0)g=i;
            else g=__gcd(g,i);
        }
    }
    if(sum<=w){
        cout<<sum<<endl;
        return 0;
    }
    memset(dp,0,szieof(dp));
    dp[0]=1;
    for(int i=1;i<=8;i++){
        for(int j=1j<=min(a[i],100);j++){
            for(int k=3800;k>=i;k--){
                dp[k]=dp[k]|dp[k-i];
            }
        }
    }
    for(ll ans=w;ans>=0;ans--){
        for(int i=0;i<=3800;i++){
            if(dp[i]){
                if(i+sum2>=ans){
                    if(g==0){
                        if(i==ans){
                            cout<<ans<<endl;
                            return 0;
                        }
                    }
                    else{
                        if((ans-i)%g==0){
                            cout<,ans<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}