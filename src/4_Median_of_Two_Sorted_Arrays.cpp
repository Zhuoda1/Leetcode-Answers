class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        double ans;
        int i = 0, j = 0;
        int cnt = 0;
        if((size1 + size2) & 1){
            int target = (size1 + size2 + 1) >> 1;
            while(i < size1 && j < size2){
                if(nums1[i] < nums2[j]) ans = nums1[i], i++, cnt++;
                else ans = nums2[j], j++, cnt++;
                if(cnt == target) return ans;
            }
            while(i < size1){
                ans = nums1[i];
                i++;
                cnt++;
                if(cnt == target) return ans;
            }
            while(j < size2){
                ans = nums2[j];
                j++;
                cnt++;
                if(cnt == target) return ans;
            }
        }
        else{
            int target = (size1 + size2) >> 1;
            while(i < size1 && j < size2){
                if(nums1[i] < nums2[j]) ans = nums1[i], i++, cnt++;
                else ans = nums2[j], j++, cnt++;
                if(cnt == target) {
                    if(i < size1 && j < size2 && nums1[i] < nums2[j]) return (ans + nums1[i]) / 2.0;
                    else if(j >= size2) return (ans + nums1[i]) / 2.0;
                    else return (ans + nums2[j]) / 2.0; 
                }
            }
            while(i < size1){
                ans = nums1[i];
                i++;
                cnt++;
                if(cnt == target) return (ans + nums1[i]) / 2.0;
            }
            while(j < size2){
                ans = nums2[j];
                j++;
                cnt++;
                if(cnt == target) return (ans + nums2[j]) / 2.0;
            }
        }
        return ans;
    }
};