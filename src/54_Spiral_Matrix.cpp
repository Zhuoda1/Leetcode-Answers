class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, btm = matrix.size() - 1;
        int dir = 1;
        vector<int> ans;
        while(left <= right && top <= btm){
            if(dir == 1){
                for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
                top++;
                dir = 2;
            }
            else if(dir == 2){
                for(int i = top; i <= btm; i++) ans.push_back(matrix[i][right]);
                right--;
                dir = 3;
            }
            else if(dir == 3){
                for(int i = right; i >= left; i--) ans.push_back(matrix[btm][i]);
                btm--;
                dir = 4;
            }
            else if(dir == 4){
                for(int i = btm; i >= top; i--) ans.push_back(matrix[i][left]);
                left++;
                dir = 1;
            }
        }
        return ans;
    }
};