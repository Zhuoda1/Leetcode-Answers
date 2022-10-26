struct DLinkedNode{
    int key,val;
    DLinkedNode *next;
    DLinkedNode *prev;
    DLinkedNode() : key(0), val(0), next(nullptr), prev(nullptr) {};
    DLinkedNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {};
};

class LRUCache {
public:
    int size, cap;
    DLinkedNode *head;
    DLinkedNode *tail;
    unordered_map<int, DLinkedNode*> cache;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if(cache.count(key)){
            DLinkedNode *node = cache[key];
            moveToHead(node);
            node->val = value;

        }
        else{
            //add node
            DLinkedNode *node = new DLinkedNode(key, value);
            addToHead(node);
            cache[key] = node;
            size++;
            if(size > cap){
                //del lru node
                DLinkedNode *del = delTail();
                cache.erase(del->key);
                delete del;
                size--;
            }
        }
    }

    void addToHead(DLinkedNode *node){
        node->prev = head;
        node->next= head->next;
        head->next->prev = node;
        head->next = node;
    }

    void delNode(DLinkedNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode *node){
        delNode(node);
        addToHead(node);
    }

    DLinkedNode* delTail(){
        DLinkedNode *node = tail->prev;
        delNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */