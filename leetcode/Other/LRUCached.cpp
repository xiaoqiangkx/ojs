class LRUCache{
public:
    typedef list<pair<int, int> >::iterator ll_iter;
    typedef map<int, list<pair<int, int> >::iterator>::iterator mm_iter;
    LRUCache(int capacity) {
        this->capacity = capacity;
        cnt = 0;
    }
    
    int get(int key) {
        mm_iter it = mm.find(key);
        
        if (it == mm.end()) {
            return -1;
        } else {
            ll_iter lit = it->second;
            int value = lit->second;
            llist.erase(lit);
            mm.erase(key);
            llist.push_back(*lit);
            mm[key] = --llist.end();
            return value;
        }
    }
    
    void set(int key, int value) {
        mm_iter it = mm.find(key);
        
        if (it == mm.end()) {
            if (cnt == capacity) {
                ll_iter del_iter = llist.begin();
                llist.pop_front();
                mm.erase(del_iter->first);
            } else {
                ++cnt;
            }
        } else {
            llist.erase(it->second);
            mm.erase(key);
        }
        
        llist.push_back(make_pair(key, value));
        mm[key] = --llist.end();

    }

private:
    int capacity;
    int cnt;
    list<pair<int, int> > llist;
    map<int, list<pair<int, int> >::iterator> mm;
};
