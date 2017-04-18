
#ifndef dlist_h
#define dlist_h

struct dlistNode{
    int data;
    dlistNode* next;
    dlistNode* prev;
};

class DoublyLinkedList {
public:
    DoublyLinkedList(){ head = tail = nullptr;};
    void pushHead(int dat);
    void pushTail(int dat);
    void popHead();
    void popTail();
    void insertPost(int dat, int indexValue);
    void deleteNode(int dat);
    void reverse();
    void sort();
    void print();
    bool empty();
private:
    void swap(dlistNode* a, dlistNode* b);
    dlistNode* head;
    dlistNode* tail;
};

void DoublyLinkedList::pushHead(int dat){
    dlistNode* newNode = new dlistNode;
    newNode->data = dat;
    newNode->next = newNode->prev = nullptr;
    if(empty()){
        head = tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return;
}

void DoublyLinkedList::pushTail(int dat){
    dlistNode* newNode = new dlistNode;
    newNode->data = dat;
    newNode->next = newNode->prev = nullptr;
    if(empty()){
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return;
}

void DoublyLinkedList::popHead(){
    dlistNode* temp = head;
    //size 0
    if(empty()){
        std::cout<<"cannot remove node from empty string\n";
        return;
    }
    //size 1
    if(head->next == nullptr){
        head = tail = nullptr;
        delete temp;
        return;
    }
    head->next->prev = nullptr;
    head = head->next;
    delete temp;
    return;
}

void DoublyLinkedList::popTail(){
    dlistNode* temp = tail;
    //size 0
    if(empty()){
        std::cout<<"cannot remove node from empty string\n";
        return;
    }
    //size 1
    if(tail->prev == nullptr){
        head = tail = nullptr;
        delete temp;
        return;
    }
    tail->prev->next = nullptr;
    tail = tail->prev;
    delete temp;
    return;
}

void DoublyLinkedList::insertPost(int dat, int indexValue){
    if(empty()){
        std::cout<<"can't insert into empty list\n";
        return;
    }
    if(tail->data == indexValue){
        pushTail(dat);
        return;
    }
    dlistNode* newNode = new dlistNode;
    newNode->data = dat;
    newNode->next = newNode->prev = nullptr;
    
    dlistNode* curr = head;
    while(curr->next != nullptr){
        if(curr->data == indexValue)break;
        curr = curr->next;
    }
    if(curr->next == nullptr){
        std::cout<<"indexValue not found\n";
        return;
    }
    curr->next->prev = newNode;
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next = newNode;
    return;
}

void DoublyLinkedList::deleteNode(int dat){
    //size 0
    if(empty()){
        std::cout<<"cannot remove node from empty string\n";
        return;
    }
    //size 1 handled in popHead,popTail
    if(head->data == dat){
        popHead();
        return;
    }
    if(tail->data == dat){
        popTail();
        return;
    }
    
    dlistNode* curr = head;
    while(curr != nullptr){
        if(curr->data == dat)break;
        curr = curr->next;
    }
    if(!curr){
        std::cout<<"int not found\n";
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    return;
}

void DoublyLinkedList::swap(dlistNode* a, dlistNode* b){
    int temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
    return;
}

void DoublyLinkedList::sort(){
    //size 0,1
    if(empty() || head->next == nullptr){
        return;
    }
    //size 2
    if(head->next == tail){
        if(head->data > tail->data){
            swap(head,tail);
        }
        return;
    }
    
    for(dlistNode* i = head; i != nullptr; i = i->next){
        for(dlistNode* j = i; j != nullptr; j = j->next){
            if(i->data > j->data)swap(i,j);
        }
    }
    return;
}

void DoublyLinkedList::reverse(){
    dlistNode* a = head;
    dlistNode* b = tail;
    if(empty()){
        std::cout<<"cannot reverse empty list\n";
        return;
    }
    while(a != b && a->prev != b){
        swap(a,b);
        a = a->next;
        b = b->prev;
    }
    return;
}

void DoublyLinkedList::print(){
    if(head == nullptr){
        std::cout<<"empty\n";
        return;
    }
    dlistNode* curr = head;
    std::cout<<"_<--";
    while(curr->next != nullptr){
        std::cout << curr->data << "<-->";
        curr = curr->next;
    }
    std::cout<<curr->data<<"-->_\n";
    return;
}

bool DoublyLinkedList::empty(){
    return head == nullptr;
}

#endif /* dlist_h */
