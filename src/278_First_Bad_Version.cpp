// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right){
            int mid = left + (right - left) / 2;
            bool first = isBadVersion(mid), second = isBadVersion(mid + 1);
            if(!first && second) return mid + 1;
            else if (first && second) right = mid;
            else left = mid + 1;
        }
        return isBadVersion((left + right)/2) ? (left + right)/2 : -1;
    }
};