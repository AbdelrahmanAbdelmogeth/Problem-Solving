class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    int length;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> key_pointer_map;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert_at_front(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        head = new Node(INT_MIN, INT_MIN);
        tail = new Node(INT_MIN, INT_MIN);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (key_pointer_map.find(key) == key_pointer_map.end())
            return -1;

        Node* node_ptr = key_pointer_map[key];
        remove(node_ptr);
        insert_at_front(node_ptr);
        return node_ptr->val;
    }

    void put(int key, int value) {
        // If key exists, update and move to front
        if (key_pointer_map.find(key) != key_pointer_map.end()) {
            Node* existing_node = key_pointer_map[key];
            existing_node->val = value;
            remove(existing_node);
            insert_at_front(existing_node);
            return;
        }

        // If cache is full, remove LRU node
        if (length == capacity) {
            Node* node_to_delete = tail->prev;
            remove(node_to_delete);
            key_pointer_map.erase(node_to_delete->key);
            delete node_to_delete;
            length--;
        }

        // Insert new node
        Node* new_node = new Node(key, value);
        insert_at_front(new_node);
        key_pointer_map[key] = new_node;
        length++;
    }

    ~LRUCache() {
        // Clean up all nodes
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};