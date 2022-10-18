class UndergroundSystem {
public:

    struct StartEndHash {
        int operator() (const pair<string,string>& x) const{
            return hash <string> () (x.first + x.second);
        }
    };

    unordered_map<pair<string,string>,pair<int,int>,StartEndHash> avg;
    unordered_map<int,pair<string,int>> in;

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        in[id] = make_pair(stationName,t);
    }

    void checkOut(int id, string stationName, int t) {
        string inst = in[id].first;
        avg[make_pair(inst,stationName)].first += t - in[id].second;
        avg[make_pair(inst,stationName)].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        return double (avg[make_pair(startStation, endStation)].first) / avg[make_pair(startStation, endStation)].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */