//
// Created by 钟东 on 17/1/9.
//

#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

#include <iostream>

using namespace std;

#define MAXITEMS 10

typedef struct item {
    char petName[20];
    char petKind[20];
} Item;

typedef struct node {
    Item item;
    struct node *left;
    struct node *right;

    node(Item item) : item(item), left(NULL), right(NULL) {}
} Node;

typedef struct tree {
    Node *root;
    int size;
} Tree;

typedef struct pair {
    Node *parent;
    Node *child;
} Pair;

//  初始化树
void InitializeTree(Tree *pTree) {
    pTree->root = NULL;
    pTree->size = 0;
}

//  树是否为空
bool TreeIsEmpty(const Tree *pTree) {
    return (pTree->size == 0);
}

//  树是否为满
bool TreeIsFull(const Tree *pTree) {
    return (pTree->size == MAXITEMS);
}

//  比较左边的节点
bool ToLeft(const Item *item1, const Item *item2) {
    int comp;
    if ((comp = strcmp(item1->petName, item2->petName)) < 0) {
        return true;
    } else if (comp == 0 && 
            strcmp(item1->petKind, item2->petKind) < 0) {
        return true;
    } else {
        return false;
    }
}

//  比较右边的节点
bool ToRight(const Item *item1, const Item *item2) {
    int comp;
    if ((comp = strcmp(item1->petName, item2->petName)) > 0) {
        return true;
    } else if (comp == 0 &&
            strcmp(item1->petKind, item2->petKind) > 0) {
        return true;
    } else {
        return false;
    }
}

//  搜索相同节点
Pair SeekItem(const Item *item, const Tree *pTree) {
    Pair look;
    look.parent = NULL;
    look.child = pTree->root;
    while (look.child != NULL) {
        if (ToLeft(item, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->left;
        } else if (ToRight(item, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->right;
        } else {
            break;
        }
    }
    return look;
}

//  添加节点遍历树
void AddNode(Node *newNode, Node *root) {
    if (ToLeft(&newNode->item, &root->item)) {
        if (root->left == NULL) {
            root->left = newNode;
        } else {
            AddNode(newNode, root->left);
        }
    } else if (ToRight(&newNode->item, &root->item)) {
        if (root->right == NULL) {
            root->right = newNode;
        } else {
            AddNode(newNode, root->right);
        }
    } else {
        exit(0);
    }
}

//  添加节点
bool AddItem(const Item *item, Tree *pTree) {
    if (TreeIsFull(pTree)) {
        cout << "Tree is full." << endl;
        return false;
    }
    if (SeekItem(item, pTree).child != NULL) {
        cout << "Same item." << endl;
        return false;
    }
    ++pTree->size;
    Node *newNode = new Node(*item);
    if (pTree->root == NULL) {
        pTree->root = newNode;
    } else {
        AddNode(newNode, pTree->root);
    }
    return true;
}

//  是否存在相同节点
bool InTree(const Item *item, const Tree *pTree) {
    return (SeekItem(item, pTree).child != NULL);
}



// 树是否为满

#endif //LEETCODE_TREE_H
