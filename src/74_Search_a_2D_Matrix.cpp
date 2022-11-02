class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index = nearSearch(matrix, target);
        if(index < 0) return false;
        return biSearch(matrix[index], target);
    }
    bool biSearch(vector<int> arr, int target){
        int left = 0, right = arr.size() - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(arr[mid] == target) return true;
            else if(arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
    int nearSearch(vector<vector<int>> arr, int target){
        int left = -1, right = arr.size() - 1;
        while(left < right){
            int mid = (left + right + 1) >> 1;
            if(arr[mid][0] <= target){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};