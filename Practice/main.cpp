
#include <iostream>
#include "rbt.h"
#include "avl.h"
#include "bst.h"
#include "list.h"
#include "dlist.h"
#include "utility.h"
#include "sort.h"

int main(int argc, const char * argv[]) {
//    SinglyLinkedList nlist;
//    for(int i = 0; i < 4; ++i){
//        nlist.appendNode(i);
//    }
//    nlist.printList();
//    //delete first node
//    nlist.deleteNode(0);
//    
//    nlist.printList();
//    //delete middle node
//    nlist.deleteNode(2);
//    
//    nlist.printList();
//    //delete nonexistent node
//    nlist.deleteNode(4);
//    
//    nlist.printList();
//    //delete final node
//    nlist.deleteNode(3);
//    
//    nlist.printList();
//    //delete only node
//    nlist.deleteNode(1);
//    
//    nlist.printList();
//    
//    SinglyLinkedList plist;
//    SinglyLinkedList qlist;
//    SinglyLinkedList rlist;
//    SinglyLinkedList slist;
//    for(int i = 0; i < 6; ++i){
//        plist.appendNode(i);
//    }
//    plist.printList();
//    
//    //split middle node
//    qlist = plist.split(3);
//    plist.printList();
//    qlist.printList();
//    
//    //split last node
//    rlist = qlist.split(5);
//    qlist.printList();
//    rlist.printList();
//    
//    //split nonexistent node;
//    slist = plist.split(6);
//    
//    //split first node;
//    slist = plist.split(0);
//    plist.printList();
//    slist.printList();
    
//    DoublyLinkedList a,b;
//    for(int i = 0; i < 4; ++i){
//        a.pushHead(i);
//        b.pushTail(i);
//    }
//    std::cout<<"testing insert():\n";
//    b.print();
//    b.insertPost(6,0);
//    b.insertPost(4,3);
//    b.insertPost(5,1);
//    b.insertPost(7,8);
//    b.print();
//    std::cout<<"testing pop():\n";
//    a.print();
//    a.popHead();
//    a.popTail();
//    a.print();
//    std::cout<<"testing delete():\n";
//    b.print();
//    b.deleteNode(6);
//    b.deleteNode(5);
//    b.deleteNode(4);
//    b.deleteNode(7);
//    b.print();
//    DoublyLinkedList a,b,c;
//    for(int i = 0; i < 4; ++i){
//        a.pushHead(i);
//    }
//    b.pushHead(3);
//    b.pushHead(7);
//    b.pushHead(1);
//    b.pushHead(4);
//    b.pushHead(6);
//    b.pushHead(8);
//    b.pushHead(0);
//    b.pushHead(5);
//    b.pushHead(2);
//    c.pushHead(0);
//    c.pushHead(1);
//    std::cout<<"testing swap() and reverse():\n";
//    a.print();
//    a.reverse();
//    a.print();
//    a.popTail();
//    a.print();
//    a.reverse();
//    a.print();
//    a.popHead();
//    a.print();
//    a.reverse();
//    a.print();
//    a.popHead();
//    a.print();
//    a.reverse();
//    a.print();
//    a.popHead();
//    a.print();
//    a.reverse();
//    std::cout<<"testing sort():\n";
//    b.print();
//    b.sort();
//    b.print();
//    c.print();
//    c.sort();
//    c.print();
//    c.popHead();
//    c.print();
//    c.sort();
//    c.print();
//    c.popHead();
//    c.print();
//    c.sort();
//    a.reverse();
//    a.print();
//    a.insertPost(3, 4);
//    a.print();
//    
//    a.pushTail(5);
//    a.pushHead(6);
//    a.deleteNode(3);
//    a.print();
//    a.sort();
//    a.print();
//    a.reverse();
//    a.popHead();
//    a.popTail();
//    a.print();
    
//    Bst a;
    
    // Avl a;
    // a.insertNode(5);
    // a.insertNode(1);
    // a.insertNode(3);
    // a.print();
    // a.insertNode(2);
    // a.insertNode(7);
    // a.insertNode(6);
    // a.print();
    // a.deleteNode(7);
    // a.deleteNode(1);
    // a.deleteNode(2);
    // a.print();
    
    // Avl b;
    // for(int i = 0; i < 15; ++i){
    //     b.insertNode(i);
    // }
    // b.print();
    
//    a.printInOrder(a);
//    a.printPreOrder();
//    a.printPostOrder();
//    a.printLevelOrder();
//
//    std::cout<<"\n";
//    a.deleteNode(5);
//    a.deleteNode(7);
//    a.deleteNode(1);
//    
//    a.printInOrder();
//    a.printPreOrder();
//    a.printPostOrder();
//    a.printLevelOrder();

//    Rbt rbt;
//    for(int i = 0; i < 15; ++i){
//        rbt.insertNode(i);
//    }
//    rbt.print();
    
//    std::cout<< binaryEqualsHex("110101101","0x1AD");
    
    int p,q;
    std::cout << "p: ";
    std::cin >> p;
    std::cout << "q: ";
    std::cin >> q;
    
//    std::cout << "powRecursive: " << powRecursive(p,q) << std::endl;
//    std::cout << "powerOf: " << powerOf(p,q) << std::endl;
//    std::cout << "mult: " << mult(p,q) << std::endl;
    std::cout << "multQuick: " << multQuick(p,q) << std::endl;
//    std::cout << "add: " << add(p,q) << std::endl;
//    std::cout << "sub: " << sub(p,q) << std::endl;
    
//    std::vector<int> list;
//    for(int i = 0; i < 10; ++i){
//        list.push_back(rand() % 100);
//    }
//    
//    printVector(list);
//    insertionSort(list);
//    printVector(list);

    return 0;
}
