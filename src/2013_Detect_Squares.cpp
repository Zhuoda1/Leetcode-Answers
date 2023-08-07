class DetectSquares {
public:
    map<pair<int,int>,int>mp;
    DetectSquares() {
        
    }
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    int count(vector<int> point) {
        int count=0;
        int x1 = point[0];
        int y1 = point[1];
        
        for(auto it:mp){
            int x2 = (it.first).first;
            int y2 = (it.first).second;
            
            if(x1!=x2 && y1!=y2 && abs(x1-x2)==abs(y1-y2) && mp.find({x1,y2})!=mp.end() && mp.find({x2,y1})!=mp.end()){
                int c1 = mp[{x2,y2}];
                int c2 = mp[{x2,y1}];
                int c3 = mp[{x1,y2}];
                
                count += c1*c2*c3;
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */