#include<bits/stdc++.h>
using  namespace std;
void sort012(vector<int> &a){
    int p0=0,p1=0,p2=a.size()-1;
    while(p1<=p2){
        switch(a[p1]){
            case 0:
                swap(a[p0],a[p1]);
                p0++;
                p1++;
                break;
            case 1:
                p1++;
                break;
            case 2:
                swap(a[p1],a[p2]);
                p2--;
                break;
        }
    }
}
void display(vector<int> &a){
    for(int i=0;i<a.size();i++){
        cout << a[i] <<" ";
    }
}
int main(){
int n;
cin >> n;
vector<int> a(n);
for(int i = 0; i < n; i++){
    cin >> a[i];
}
sort012(a);
display(a);
    return 0;
}