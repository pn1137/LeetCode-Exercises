/*
  Design HashMap

  Design a HashMap without using any built-in hash table libraries.

  To be specific, your design should include these functions:

  put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
  get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
  remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

  Example:

  MyHashMap hashMap = new MyHashMap();
  hashMap.put(1, 1);          
  hashMap.put(2, 2);         
  hashMap.get(1);            // returns 1
  hashMap.get(3);            // returns -1 (not found)
  hashMap.put(2, 1);          // update the existing value
  hashMap.get(2);            // returns 1 
  hashMap.remove(2);          // remove the mapping for 2
  hashMap.get(2);            // returns -1 (not found) 

  Note:

  All keys and values will be in the range of [0, 1000000].
  The number of operations will be in the range of [1, 10000].
  Please do not use the built-in HashMap library.
*/

///Runtime: 88 ms         // 97.13%
///Memory Usage: 44.9 MB  // 94.85%

struct Node {
    int key;
    int value;
    Node* next;
    
    Node(int m_key, int m_val, Node* m_next) : 
        key(m_key), value(m_val), next(m_next) {
        
    }
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : map(numHashElements, nullptr) {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);  // Get hash value        
        
        if (map[h] == nullptr)  // Create the head node for a hash value
        {
            map[h] = new Node(key, value, nullptr);
        }
        else
        {
            Node* node = map[h];
            Node* prev;
            while (node != nullptr)
            {
                if (node->key == key)   // Node found
                {
                    node->value = value;
                    return;
                }
                
                prev = node;
                node = node->next;
            }
            
            // Node not found, append a new node
            prev->next = new Node(key, value, nullptr);
        }   
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        Node* node = map[h];
        
        while (node != nullptr)
        {
            if (node->key == key)   // Node found
            {
                return node->value;
            }
            
            node = node->next;
        }
        
        return -1;  // Node not found
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        Node* node = map[h];
        Node* prev = nullptr;
        
        while (node != nullptr)
        {
            if (node->key == key)   // Node found
            {
                if (prev != nullptr)
                {
                    prev->next = node->next;
                    
                }
                else    // Head node
                {
                    map[h] = node->next;
                }
                
                delete node;
                return;
            }
            
            prev = node;
            node = node->next;
        }
    }
    
private:
    int numHashElements = 1000;
    vector<Node*> map;
    
    // Hash value calculation function
    int hash(int key)
    {
        return (key % numHashElements);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */