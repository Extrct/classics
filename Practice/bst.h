
#ifndef bst_h
#define bst_h
#include <queue>

struct bstNode{
    bstNode(){data = -1;left = right = nullptr;};
    int data;
    bstNode* left;
    bstNode* right;
};

class Bst{
public:
    Bst(){root = nullptr;};
    ~Bst(){freeNode(root);root = nullptr;};
    void insertNode(int dat);
    void deleteNode(int dat);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
    void printLevelOrder();
private:
    bstNode* insertNode(int dat, bstNode* node);
    bstNode* deleteNode(int dat, bstNode* node);
    bstNode* min(bstNode* node);
    void freeNode(bstNode* node);
    void printInOrder(bstNode* node);
    void printPreOrder(bstNode* node);
    void printPostOrder(bstNode* node);
    bstNode* root;
};

void Bst::insertNode(int dat){
    root = insertNode(dat, root);
}

bstNode* Bst::insertNode(int dat, bstNode* node){
    if(node == nullptr){
        node = new bstNode();
        node->data = dat;
    }else if(dat <= node->data){
        node->left = insertNode(dat, node->left);
    }else{
        node->right = insertNode(dat, node->right);
    }
    return node;
}

void Bst::deleteNode(int dat){
    root = deleteNode(dat, root);
}

bstNode* Bst::deleteNode(int dat, bstNode* node){
    if(node == nullptr){
        return node;
    }else if(dat < node->data){
        node->left = deleteNode(dat, node->left);
    }else if(dat > node->data){
        node->right = deleteNode(dat, node->right);
    }else{
        if(node->left == nullptr && node->right == nullptr){
            delete node;
            node = nullptr;
        }else if(node->left == nullptr){
            bstNode* temp = node;
            node = node->right;
            delete temp;
        }else if(node->right == nullptr){
            bstNode* temp = node;
            node = node->left;
            delete temp;
        }else{
            bstNode* temp = min(node->right);
            node->data = temp->data;
            node->right = deleteNode(temp->data, node->right);
        }
    }
    return node;
}

bstNode* Bst::min(bstNode *node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

void Bst::freeNode(bstNode* node){
    if(node != nullptr){
        freeNode(node->left);
        freeNode(node->right);
        delete node;
    }
}

void Bst::printInOrder(){
    printInOrder(root);
    std::cout<<"\n";
}

void Bst::printPreOrder(){
    printPreOrder(root);
    std::cout<<"\n";
}

void Bst::printPostOrder(){
    printPostOrder(root);
    std::cout<<"\n";
}

//notice we dont need a wrapper function because it's iterative not recursive
void Bst::printLevelOrder(){
    if(root == nullptr)return;
    std::queue<bstNode*> q;
    q.push(root);
    while(!q.empty()){
        bstNode* temp = q.front();
        q.pop();
        std::cout<<temp->data<<"  ";
        if(temp->left != nullptr){
            q.push(temp->left);
        }
        if(temp->right != nullptr){
            q.push(temp->right);
        }
    }
    std::cout<<"\n";
}

void Bst::printInOrder(bstNode* node){
    if(node == nullptr)return;
    printInOrder(node->left);
    std::cout<<node->data<<"  ";
    printInOrder(node->right);
}

void Bst::printPreOrder(bstNode* node){
    if(node == nullptr)return;
    std::cout<<node->data<<"  ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void Bst::printPostOrder(bstNode* node){
    if(node == nullptr)return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout<<node->data<<"  ";
}



#endif
