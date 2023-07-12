class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = N2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;
            int mid1 = (N1 + N2) / 2 - mid2;
            
            double L1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
            double R1 = (mid1 == N1) ? INT_MAX : nums1[mid1];
            double R2 = (mid2 == N2) ? INT_MAX : nums2[mid2];
            
            if (L1 > R2) lo = mid2 + 1;
            else if (L2 > R1) hi = mid2 - 1;
            else return (N1 + N2) % 2 ? min(R1,R2) : (max(L1,L2) + min(R1, R2)) / 2;
        }
    return -1;
    }
};