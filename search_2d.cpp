#include<bits/stdc++.h>
using namespace std;
 void display(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j <matrix[i].size();j++){
            cout<< matrix[i][j] <<" ";
        }
        cout<<endl;
    }
  }
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        if(row<0){
            return false;
        }
        int c = matrix[0].size() - 1;
        int r=0;
        while(c>=0 && r<=row){
            if(target == matrix[r][c]){
                return true;
            }else if(target>matrix[r][c]){
                r++;
            }else if(target<matrix[r][c]){
                c--;
            }
        }
        return false;
    }
    int main() {
        int m,n;
cin >> m >> n;
vector<vector<int>> matrix(m,vector<int>(n));
for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
        cin >>matrix[i][j];
    }
}
int target ;
cin >> target;
cout<<searchMatrix(matrix, target);
        return 0;
    }