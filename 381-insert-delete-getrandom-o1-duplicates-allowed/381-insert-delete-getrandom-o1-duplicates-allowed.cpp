class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int,unordered_set<int>> mp;
    RandomizedCollection() {
        
    }
    
     bool insert(int val) {
        bool flag = !mp.count(val);
        v.push_back(val);
        mp[val].insert(v.size()-1);
        return flag;
    }
    
    bool remove(int val) {
        if(!mp.count(val))
            return false;
        if(v.back() == val){
            mp[val].erase(v.size()-1);
            v.pop_back();
            if(mp[val].size() == 0)
                mp.erase(val);
            return true;
        }
        int x = *mp[val].begin();
        v[x] = v.back();
        mp[v.back()].erase(v.size()-1);
        mp[v.back()].insert(x);
        v.pop_back();
        mp[val].erase(x);
        if(mp[val].size() == 0)
            mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */