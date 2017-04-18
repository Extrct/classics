
#ifndef avl_h
#define avl_h

struct avlNode{
    avlNode(){data = -1; height = 1; left = right = nullptr;};
    int data;
    unsigned int height;
    avlNode* left;
    avlNode* right;
};

class Avl{
public:
    Avl(){root = nullptr;};
    ~Avl(){freeNode(root);root = nullptr;};
    void insertNode(int dat);
    void deleteNode(int dat);
    void print();
private:
    void freeNode(avlNode* node);
    void setHeight(avlNode* node);
    inline unsigned int height(avlNode* node);
    avlNode* rotateRight(avlNode* node);
    avlNode* rotateLeft(avlNode* node);
    avlNode* balanceNode(avlNode* node);
    inline int getBalance(avlNode* node);
    avlNode* min(avlNode* node);
    avlNode* insertNode(int dat, avlNode* node);
    avlNode* deleteNode(int dat, avlNode* node);
    void printInOrder(avlNode* node);
    void printPreOrder(avlNode* node);
    void printPostOrder(avlNode* node);
    avlNode* root;
};

avlNode* Avl::insertNode(int dat, avlNode* node){
    if(node == nullptr){
        node = new avlNode();
        node->data = dat;
        return node;
    }else if(dat <= node->data){
        node->left = insertNode(dat, node->left);
    }else{
        node->right = insertNode(dat,node->right);
    }
    return balanceNode(node);
}

avlNode* Avl::min(avlNode* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

avlNode* Avl::deleteNode(int dat, avlNode *node){
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
            avlNode* temp = node;
            node = node->right;
            delete temp;
        }else if(node->right == nullptr){
            avlNode* temp = node;
            node = node->left;
            delete temp;
        }else{
            avlNode* temp = min(node->right);
            node->data = temp->data;
            node->right = deleteNode(temp->data, node->right);
        }
    }
    return balanceNode(node);
}

avlNode* Avl::balanceNode(avlNode* node){
    if(node == nullptr)return nullptr;
    setHeight(node);
    int bal = getBalance(node);
    if(bal == 2){
        //if heavy on the left
        if(getBalance(node->left) < 0){
            //and if kinked to the right
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }else if(bal == -2){
        //if heavy on the right
        if(getBalance(node->right) > 0){
            //and if kinked to the left
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }else{
        return node;
    }
}

inline int Avl::getBalance(avlNode* node){
    return height(node->left) - height(node->right);
}

avlNode* Avl::rotateLeft(avlNode* node){
    if(node == nullptr)return nullptr;
    avlNode* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    setHeight(node);
    setHeight(temp);
    return temp;
}

avlNode* Avl::rotateRight(avlNode* node){
    if(node == nullptr)return nullptr;
    avlNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    setHeight(node);
    setHeight(temp);
    return temp;
}

void Avl::setHeight(avlNode *node){
    if(node == nullptr)return;
    if(height(node->left) > height(node->right)){
        node->height = height(node->left) + 1;
    }else{
        node->height = height(node->right) + 1;
    }
    //node->height = height(node->left) > height(node->right) ? height(node->left) + 1 : height(node->right) + 1;
}

inline unsigned int Avl::height(avlNode* node){
    return node != nullptr ? node->height : 0;
}

void Avl::freeNode(avlNode* node){
    if(node != nullptr){
        freeNode(node->left);
        freeNode(node->right);
        delete node;
    }
}

void Avl::insertNode(int dat){
    root = insertNode(dat, root);
}

void Avl::deleteNode(int dat){
    root = deleteNode(dat, root);
}

void Avl::print(){
    printInOrder(root);
    std::cout<<"\n";
    printPreOrder(root);
    std::cout<<"\n";
    printPostOrder(root);
    std::cout<<"\n";
}

void Avl::printInOrder(avlNode* node){
    if(node == nullptr)return;
    printInOrder(node->left);
    std::cout<<node->data<<"  ";
    printInOrder(node->right);
}

void Avl::printPreOrder(avlNode* node){
    if(node == nullptr)return;
    std::cout<<node->data<<"  ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void Avl::printPostOrder(avlNode* node){
    if(node == nullptr)return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout<<node->data<<"  ";
}

#endif /* avl_h */
