 #include<bits/stdc++.h>
 using namespace std;
 int trap(vector<int>& height) {
        int water = 0;
       int n = height.size();
       vector<int> lmax(n),rmax(n);
       lmax[0] = height[0];
       rmax[n-1] = height[n-1];
       for(int i=1;i<n;i++){
           lmax[i] = max(lmax[i-1],height[i]);
           rmax[n-i-1] = max(rmax[n-i],height[n-i-1]);
       }
       for(int i=1;i<n-1;i++){
            water+=min(lmax[i],rmax[i])-height[i];
       }
        return water;
    }
    int main() {
        int n;
        cin >> n;
        vector<int> height(n);
        for(int i=0;i<n;i++){
            cin >> height[i];
        }
        cout<<trap(height)<<endl;
        return 0;
    }