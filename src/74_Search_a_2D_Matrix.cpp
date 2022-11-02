class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> first;
        for(int i = 0; i < matrix.size(); i++){
            first.push_back(matrix[i][0]);
        }
        int index = nearSearch(first, target);
        if(first[index] == target) return true;
        if(target <= matrix[index][matrix[index].size() - 1]) return biSearch(matrix[index], target);
        else return false;
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
    int nearSearch(vector<int> arr, int target){
        int left = 0, right = arr.size() - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(arr[mid] == target) return mid;
            else if(arr[mid] < target){
                if(mid < arr.size() - 1 && arr[mid+1] > target) return mid;
                else if(mid == arr.size() - 1) return mid;
                left = mid + 1;
            }
            else{
                if(mid > 0 && arr[mid-1] < target) return mid - 1;
                else if(mid == 0) return mid;
                right = mid - 1;
            }
        }
        return (left + right) >> 1;
    }
};