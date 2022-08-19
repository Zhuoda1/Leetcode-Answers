class quickSortSolution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        quickSort(nums, l, r);
        return nums;
    }
private:
    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int left = l;
        int right = r;
        int p = nums[l];
        while(left < right){
            while(nums[right] >= p && left < right) right--;
            while(nums[left] <= p && left < right) left++;
            swap(nums[left], nums[right]);
        }
        swap(nums[l], nums[left]);
        quickSort(nums, l, left-1);
        quickSort(nums, left+1, r);
    }
};

class mergeSortSolution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        MergeSort(nums, l, r);
        return nums;
    }
private:
    void MergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = (l + r) >> 1;
        MergeSort(nums, l, mid);
        MergeSort(nums, mid+1, r);
        Merge(nums, l, mid, r);
    }
    void Merge(vector<int>& nums, int l, int mid, int r){
        int i = l, j = mid + 1;
        int *temp = new int[r-l+1];
        int k = 0;
        while(i <= mid && j <= r){
            if(nums[i] < nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid){
            temp[k++] = nums[i++];
        }
        while(j <= r){
            temp[k++] = nums[j++];
        }
        k = 0;
        while(l <= r){
            nums[l++] = temp[k++];
        }
        delete []temp;
    }
};