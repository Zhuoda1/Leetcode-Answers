class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {

    }

    void addNum(int num) {
        if(left.size() > right.size()){
            left.push(num);
            int tran = left.top();
            left.pop();
            right.push(tran);
        }
        else{
            right.push(num);
            int tran = right.top();
            right.pop();
            left.push(tran);
        }
    }

    double findMedian() {

        if((left.size() + right.size()) % 2 == 0){
            return (left.top() + right.top()) / 2.0;
        }
        else{
            if(left.size() > right.size()){
                return left.top();
            }
            else{
                return right.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */