class MyHashSet {
public:
    /* Initialize your data structure here */
    vector <int> mp;
    MyHashSet() {
        vector <int> mp = this->mp;
        this->mp.assign(1000100, 0);
    }
    
    void add(int key) {
        this->mp[key] = 1;
    }

    void remove(int key) {
        this->mp[key] = 0;
    }
    
    /* Returns true if this set contains the specific element */
    bool contains(int key) {
        return this->mp[key];
    }

    /*
     * Your MyHashSet object will be instantiated and called as
     * My HashSet* obj = My HashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     * */
        
}
