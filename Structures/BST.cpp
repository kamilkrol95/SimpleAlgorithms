// BST tree

#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

// BST Tree
struct BSTnode{
    int val;
    BSTnode* parent;
    BSTnode* left;
    BSTnode* right;
};

BSTnode* newNode(int v){
    BSTnode* tmp = new BSTnode;
    tmp->parent = tmp->left = tmp->right = NULL;
    tmp->val = v;
    return tmp;
}

void addNode(BSTnode*& root, int val){
    BSTnode* tmp = newNode(val);

    if(root == NULL){
        root = new BSTnode;
        root = tmp;
        return;
    } 
    
    BSTnode* tmpRoot = root;
    BSTnode* tmpParent = NULL;

    while(tmpRoot != NULL){
        tmpParent = tmpRoot;        
        if(tmpRoot->val < val) tmpRoot = tmpRoot->right;
        else tmpRoot = tmpRoot->left;
    }   

    tmp->parent = tmpParent;
    if(tmpParent == NULL) root = tmp;
    else if(tmpParent->val < val) tmpParent->right = tmp;
    else tmpParent->left = tmp;
}

BSTnode* makeBST(int n, int range){
    int x;
    BSTnode* tree = NULL;
    for(int i = 0; i < n; i++){
        x = rand()%range;
        // cin >> x;
        addNode(tree,x);    
    }
    return tree;
}

void inOrder(BSTnode* root){
    if(root->left != NULL) inOrder(root->left);
    printf("%d ",root->val);
    if(root->right != NULL) inOrder(root->right);
}

BSTnode* minNode(BSTnode* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

int minVal(BSTnode* root){
    return minNode(root)->val;
}

BSTnode* maxNode(BSTnode* root){
    while(root->right != NULL)
        root = root->right;
    return root;
}

int maxVal(BSTnode* root){
    return maxNode(root)->val;
}

BSTnode* search(BSTnode* root, int value){
    if(root == NULL) return root;
    if(root->val == value) return root;
    if(root->val < value) return search(root->right,value);
    else return search(root->left,value);
}

BSTnode* predecessor(BSTnode* node){
    if(node->left != NULL) return maxNode(node->left); 
    BSTnode* tmp = node->parent;
    while(tmp != NULL && tmp->left == node){
        node = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

BSTnode* successor(BSTnode* node){
    if(node->right != NULL) return minNode(node->right);
    BSTnode* tmp = node->parent;
    while(tmp != NULL && tmp->right == node){
        node = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

// TABLE

void makeTab(int* tab, int n, int range){
    for(int i = 0; i < n; i++)
        tab[i] = rand()%range;
}

void printTab(int* tab, int n){
    for(int i = 0; i < n; i++)
        printf("%d ",tab[i]);
    printf("\n");
}

void sortTab(int* tab, int n, int range){
    int* counters = new int[range];
    int* result = new int[n];

    for(int i = 0; i < range; i++) counters[i] = 0;
    for(int i = 0; i < n; i++) counters[tab[i]]++;
    for(int i = 1; i < range; i++) counters[i] += counters[i-1];
    for(int i = n-1; i >= 0; i--) result[--counters[tab[i]]] = tab[i];

    for(int i = 0; i < n; i++)
        tab[i] = result[i];

    delete [] counters;
    delete [] result;
}
// TABLE <-> BST

void tabToBST(BSTnode*& root, int* tab, int n, int l, int r){
    int mid = (l+r)/2;
    addNode(root,tab[mid]);
    if(l != mid) tabToBST(root,tab,n,l,mid);
    if(mid+1 != r) tabToBST(root,tab,n,mid+1,r);
    return;
}

void BSTtoTab(BSTnode* root, int* tab, int n){
    BSTnode* node = minNode(root);
    int i = 0;
    while(node != NULL){
        tab[i++] = node->val;
        node = successor(node);
    }
}

int sumInRange(BSTnode* root, int minVal, int maxVal){
    BSTnode* minNode = search(root,minVal);
    BSTnode* maxNode = search(root,maxVal);
    int sum = 0;
    while(minNode != maxNode){
        sum += minNode->val;
        minNode = successor(minNode);
    }
    sum += maxNode->val;
    return sum;
}

int main(){
    srand(time(NULL));
    int n, range = 20;
    cin >> n;
    
    // MAKE TREE
    BSTnode* tree = NULL;
    tree = makeBST(n,range);
    inOrder(tree);
    printf("\n");
    
    // MAKE TABLE
    int* tab = new int[n];
    makeTab(tab,n,range);
    sortTab(tab,n,range);
    printTab(tab,n);

    // MIN / MAX (BSTnode)
    printf("MIN: %d\n",minNode(tree)->val);
    printf("MAX: %d\n",maxNode(tree)->val);

    // MIN / MAX VALUE (INT)
    // printf("MIN VAL: %d\n",minVal(tree));
    // printf("MAX VAL: %d\n",maxVal(tree));

    // // SEARCH FUNCTION
    // int x;
    // printf("Find (?): ");
    // scanf("%d",&x);
    // if(search(tree,x) == NULL) printf("NOT FOUND %d!\n",x);
    // else printf("Found: %d\n",search(tree,x)->val);

    // PREDECESSOR / SUCCESSOR
    // printf("PRED: %d\n",predecessor(search(tree,x))->val);
    // printf("SUCC: %d\n",successor(search(tree,x))->val);
    printf("MIN2: %d\n",successor(minNode(tree))->val);
    printf("MAX2: %d\n",predecessor(maxNode(tree))->val);

    // TABLE <-> TREE 
    BSTnode* newTree = NULL;
    tabToBST(newTree,tab,n,0,n);
    printf("New BST: \n");
    inOrder(newTree);

    int* newTab = new int[n];
    BSTtoTab(tree,newTab,n);
    printf("\nNew Table:\n");
    printTab(newTab,n);
    
    int min, max;
    printf("?  ");
    scanf("%d %d",&min,&max);
    printf("Sum in range: %d\n",sumInRange(tree,min,max));
    delete tree;
    delete [] tab;
    delete newTree;
    delete [] newTab;
}