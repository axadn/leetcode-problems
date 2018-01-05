/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

/** My Approach:
I will store items in linked lists for O(1) removal and appending.

A hash will map how many times an item has been accessed to its list,
allowing nodes O(1) access to their lists.

A list of lists will allow me to keep the frequency "buckets" in order, and easily insert/ delete
buckets as needed in 0(1) time.

Finally, there will be an additional hash map mapping an object's key to its node in its list.
This way, we can look up items by key in 0(1) time.
**/

template<class T>
struct LNode{
    int key;
    T val;
    LNode* prev;
    LNode* next;
    int frequency;
    LNode(int key, T val) :key(key), val(val) , prev(NULL), next(NULL), frequency(0){}
};

template<class T>
class List{
public:
    T* tail;
    T* head;
    List(T* first) : tail(first), head(first){}
    List() : tail(NULL), head(NULL){}

    void push_back(T* node){
        if(tail == NULL){
            head = node;
        }
        else{
            tail->next = node;
             node->prev = tail;
        }
        tail = node;
    }
    void push_front(T* node){
        if(head == NULL){
            tail = node;
        }
        else{
            head->prev = node;
            node->next = head;
        }
        head = node;
    }
    void pop_front(){
        disconnectNode(head);
    }
    bool empty(){
        return tail == NULL;
    }
    void disconnectNode(T* node){
       if(node == head){
          head = node->next;
       }
       if(node == tail){
          tail = node->prev;
       }
       if(node->prev != NULL){
           node->prev->next = node->next;
       }
       if(node->next != NULL){
            node->next->prev = node->prev;
      }
      node-> next = NULL;
      node-> prev = NULL;
    }
};

class LFUCache {
public:
    int capacity;
    LFUCache(int capacity): size(0) , currentMin(0) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(lookup.count(key) == 1){
            updateFrequency(lookup[key]);
            return lookup[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;
        if(lookup.count(key) == 0){
            if(size == capacity){
                eject();
                return put(key, value);
            }
            LNode<int>* node = new LNode<int>(key, value);
            if(frequencyMap.count(0) == 0){
                List<LNode<int>>* newList = new List<LNode<int>>(node);
                LNode<List<LNode<int>>*>* newNode = new LNode<List<LNode<int>>*>(0,newList);
                frequencyList.push_front(newNode);
                frequencyMap[0] = newNode;
            }
            else{
               frequencyList.head->val->push_back(node);
            }
            lookup[key] = node;
            ++size;
        }
        else{
            lookup[key]->val = value;
            updateFrequency(lookup[key]);
            //frequencyMap[lookup[key]->frequency]->val->disconnectNode(lookup[key]);
            //frequencyMap[lookup[key]->frequency]->val->push_back(lookup[key]);
        }

    }
private:
    int currentMin;
    int size;
    unordered_map<int, LNode<List<LNode<int>>*>*> frequencyMap;
    List<LNode<List<LNode<int>>*>> frequencyList;
    unordered_map<int, LNode<int>*> lookup;

    void eject(){
        List<LNode<int>>* firstList = frequencyList.head->val;
        LNode<int>* minNode = firstList->head;
        firstList->pop_front();
        if(firstList->empty()){
          delete firstList;
          frequencyMap.erase(minNode->frequency);
          frequencyList.pop_front();
        }
        lookup.erase(minNode->key);
        delete minNode;
        --size;
    }
    void updateFrequency(LNode<int>* node){
      LNode<List<LNode<int>>*>* freqListNode = frequencyMap[node->frequency];
      freqListNode->val->disconnectNode(node);
      if(freqListNode->next == NULL || freqListNode->next->key != node->frequency + 1){
        List<LNode<int>>* newList = new List<LNode<int>>(node);
        LNode<List<LNode<int>>*>* newNode = new LNode<List<LNode<int>>*>(node->frequency + 1, newList);
        if(freqListNode->next == NULL){
          frequencyList.push_back(newNode);
        }
        else{
          newNode->next = freqListNode->next;
          newNode->prev = freqListNode;
          freqListNode->next = newNode;
          newNode->next->prev = newNode;
        }
        frequencyMap[node->frequency + 1] = newNode;
      }
      else{
        freqListNode->next->val->push_back(node);
      }
      if(freqListNode->val->empty()){
          frequencyList.disconnectNode(freqListNode);
          delete freqListNode->val;
          delete freqListNode;
          frequencyMap.erase(node->frequency);
      }
      ++node->frequency;

    }
};
