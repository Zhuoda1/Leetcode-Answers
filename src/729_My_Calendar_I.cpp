class MyCalendar {
public:
    set<pair<int,int>> books;
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        auto lb = books.lower_bound({start,end});
        if(lb != books.end() && lb->first < end) return false;
        if(lb != books.begin() && start < (--lb)->second) return false;
        books.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */