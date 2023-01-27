#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double power_fun(double base,int n)
    {
        double ans;
        if(n==0) return 1.0;
        if(n==1) return base;

        ans = power_fun(base,n/2);

        if(n&1)//odd
        return ans*ans*base;
        
        return ans*ans;        
    }

    double myPow(double base, int n)
    {
        if(n<0)
        return 1.0/power_fun(base,abs(n));
        
        return power_fun(base,n);
    }
};
int main(){
    return 0;
}