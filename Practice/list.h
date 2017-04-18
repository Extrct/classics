
#ifndef list_h
#define list_h

struct listNode{
    int data;
    listNode* next;
};

class SinglyLinkedList{
public:
    SinglyLinkedList(){head = nullptr;};
    void appendNode(int dat);
    void deleteNode(int dat);
    SinglyLinkedList split(int dat);
    void printList();
    bool empty();
private:
    listNode* head;
};

void SinglyLinkedList::appendNode(int dat){
    listNode* newNode = new listNode;
    newNode->data = dat;
    newNode->next = nullptr;
    
    if(empty()){
        head = newNode;
        return;
    }
    listNode* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void SinglyLinkedList::deleteNode(int dat){
    //size 0
    if(empty()){
        std::cout<< "empty\n";
        return;
    }
    listNode* temp = head;
    //size 1
    if(temp->next == nullptr){
        if(temp->data == dat){
            head = nullptr;
            delete temp;
        }else{
            std::cout<< "int not found\n";
        }
        return;
    }
    listNode* prev = head;
    while(temp != nullptr){
        if(temp->data == dat)break;
        prev = temp;
        temp = temp->next;
    }
    if(!temp){
        std::cout<< "int not found\n";
        return;
    }
    //if dat == first node in list
    if(temp == head){
        head = temp->next;
        delete temp;
        return;
    }
    prev->next = temp->next;
    delete temp;
    return;
}

SinglyLinkedList SinglyLinkedList::split(int dat){
    SinglyLinkedList newList;
    //size 0
    if(empty()){
        std::cout << "can't split empty list\n";
        return newList;
    }
    listNode* temp = head;
    listNode* prev = head;
    while(temp != nullptr){
        if(temp->data == dat)break;
        prev = temp;
        temp = temp->next;
    }
    if(!temp){
        std::cout<<"can't split, int not found\n";
        return newList;
    }
    //if dat == first node in list
    if(temp == head){
        newList.head = temp;
        head = nullptr;
        return newList;
    }
    newList.head = temp;
    prev->next = nullptr;
    return newList;
}

void SinglyLinkedList::printList(){
    if(empty()){
        std::cout<< "empty\n";
        return;
    }
    listNode* temp = head;
    while(temp != nullptr){
        std::cout << temp->data << "-->";
        temp = temp->next;
    }
    std::cout << "_\n";
    return;
}

bool SinglyLinkedList::empty(){
    return head == nullptr;
}



#endif
