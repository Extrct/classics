
#ifndef rbt_h
#define rbt_h

enum Color : char {
    BLACK = 0,
    RED = 1
};

struct rbtNode{
    rbtNode(int dat, bool clr){data = dat; color = clr; left = right /*= parent*/ = nullptr;};
    int data;
    bool color;
    rbtNode* left;
    rbtNode* right;
    //rbtNode* parent;
};

class Rbt{
public:
    Rbt(){root = nullptr;};
    ~Rbt(){freeNode(root);root = nullptr;};
    void insertNode(int dat);
    void deleteNode(int dat);
    void print();
private:
    inline bool isRed(rbtNode* node);
    //inline rbtNode* getUncle(rbtNode* node);
    rbtNode* min(rbtNode* node);
    inline void invertColor(rbtNode* node);
    rbtNode* balance(rbtNode* node);
    rbtNode* insertNode(int dat, rbtNode* node);
    rbtNode* deleteNode(int dat, rbtNode* node);
    rbtNode* deleteMin(rbtNode* node);
    rbtNode* redShiftLeft(rbtNode* node);
    rbtNode* redShiftRight(rbtNode* node);
    rbtNode* rotateLeft(rbtNode* node);
    rbtNode* rotateRight(rbtNode* node);
    void freeNode(rbtNode* node);
    void printInOrder(rbtNode* node);
    void printPreOrder(rbtNode* node);
    void printPostOrder(rbtNode* node);
    rbtNode* root;
};

bool Rbt::isRed(rbtNode* node){
    if(node == nullptr) return false; // null leaves count as black
    return node->color == RED;
}

rbtNode* Rbt::balance(rbtNode* node){
    if (isRed(node->right)){
        node = rotateLeft(node);
    }
    if (isRed(node->left) && isRed(node->left->left)){
        node = rotateRight(node);
    }
    if (isRed(node->left) && isRed(node->right)){
        invertColor(node);
    }
    return node;
}

rbtNode* Rbt::rotateLeft(rbtNode* node){
    if(node == nullptr)return nullptr;
    rbtNode* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    // RB changes
    temp->color = temp->left->color;
    temp->left->color = RED;
    return temp;
}

rbtNode* Rbt::rotateRight(rbtNode* node){
    if(node == nullptr)return nullptr;
    rbtNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    // RB changes
    temp->color = temp->right->color;
    temp->right->color = RED;
    return temp;
}


// Assuming that node is red and both node->left and node->left->left
// are black, make node->left or one of its children red.
rbtNode* Rbt::redShiftLeft(rbtNode* node){
    invertColor(node);
    if (isRed(node->right->left)) {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
        invertColor(node);
    }
    return node;
}

// Assuming that node is red and both node->right and node->right->left
// are black, make node->right or one of its children red.
rbtNode* Rbt::redShiftRight(rbtNode* node){
    invertColor(node);
    if (isRed(node->left->left)){
        node = rotateRight(node);
        invertColor(node);
    }
    return node;
}

// Switches colors of node and its children if children
// are the same color and opposite to node's color
void Rbt::invertColor(rbtNode* node){
    node->color = !node->color;
    node->left->color = !node->left->color;
    node->right->color = !node->right->color;
}

rbtNode* Rbt::min(rbtNode* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

rbtNode* Rbt::insertNode(int dat, rbtNode* node){
    if(node == nullptr){
        return node = new rbtNode(dat,RED);
    }else if(dat <= node->data){
        node->left = insertNode(dat, node->left);
    }else{
        node->right = insertNode(dat, node->right);
    }
    
    if(isRed(node->right) && !isRed(node->left)){
        node = rotateLeft(node);
    }
    if(isRed(node->left) && isRed(node->left->left)){
        node = rotateRight(node);
    }
    if(isRed(node->left) && isRed(node->right)){
        invertColor(node);
    }
    return node;
//    if (isRed(h.right) && !isRed(h.left))      h = rotateLeft(h);
//    if (isRed(h.left)  &&  isRed(h.left.left)) h = rotateRight(h);
//    if (isRed(h.left)  &&  isRed(h.right))     flipColors(h);

}

void Rbt::insertNode(int dat){
    root = insertNode(dat, root);
    root->color = BLACK;
}

rbtNode* Rbt::deleteMin(rbtNode* node) {
    if(node->left == nullptr) return nullptr;
    if(!isRed(node->left) && !isRed(node->left->left)){
        node = redShiftLeft(node);
    }
    node->left = deleteMin(node->left);
    return balance(node);
}

rbtNode* Rbt::deleteNode(int dat, rbtNode* node){
    //if(node == nullptr) return nullptr;
    if(dat <= node->data)  {
        if(!isRed(node->left) && !isRed(node->left->left))
            node = redShiftLeft(node);
        node->left = deleteNode(dat, node->left);
    }else{
        if(isRed(node->left)) node = rotateRight(node);
        if(dat == node->data && node->right == nullptr) return nullptr;
        if(!isRed(node->right) && !isRed(node->right->left)) node = redShiftRight(node);
        if(dat == node->data) {
            rbtNode* temp = min(node->right);
            node = temp;
            node->data = temp->data;
            // h.val = get(h.right, min(h.right).key);
            // h.key = min(h.right).key;
            node->right = deleteMin(node->right);
        }
        else node->right = deleteNode(dat, node->right);
    }
    return balance(node);
}

void Rbt::deleteNode(int dat){
    // if both children of root are black, set root to red
    if(!isRed(root->left) && !isRed(root->right)){
        root->color = RED;
    }
    root = deleteNode(dat, root);
    if(root != nullptr) root->color = BLACK;
}

void Rbt::freeNode(rbtNode* node){
    if(node != nullptr){
        freeNode(node->left);
        freeNode(node->right);
        delete node;
    }
}

void Rbt::print(){
    printInOrder(root);
    std::cout<<"\n";
    printPreOrder(root);
    std::cout<<"\n";
    printPostOrder(root);
    std::cout<<"\n";
}

void Rbt::printInOrder(rbtNode* node){
    if(node == nullptr)return;
    printInOrder(node->left);
    std::cout<<node->data<<"  ";
    printInOrder(node->right);
}

void Rbt::printPreOrder(rbtNode* node){
    if(node == nullptr)return;
    std::cout<<node->data<<"  ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void Rbt::printPostOrder(rbtNode* node){
    if(node == nullptr)return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout<<node->data<<"  ";
}

#endif /* rbt_h */
