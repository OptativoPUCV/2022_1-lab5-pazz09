#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {

    TreeMap * newMap = (TreeMap *)malloc(sizeof(TreeMap));
    newMap->root = NULL;
    newMap->current = NULL;
    newMap->lower_than = lower_than;
    return newMap;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
    /*
    Pair aux;

    TreeMap * a = NULL;
    TreeMap * b = tree->root;
    while (b != NULL){
        a = b;
    }
    */
    
    
}

TreeNode * minimum(TreeNode * x){
    TreeNode* aux = x;
    while(aux->left !=NULL){
        aux = aux->left;  
    }
    return aux;
}


void removeNode(TreeMap * tree, TreeNode* node) {
    /*

    if (tree == NULL || tree->root == NULL) return;

    if (node->left == node){
        if(node->left == NULL || node->right == NULL){
            if(node->left != NULL){
                node->left->parent = node->parent;
                node->parent->left = node->left;
                node = NULL;
            }
            if (node->right != NULL){
                node->right->parent = node->parent;
                node->parent->left = node->right;
                node = NULL;
            }
            else{
                node->parent->left = node->left;
                node = NULL;
            }


        }    
    
    }
    */




}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {

    TreeNode* aux = tree->root;

    while (aux != NULL){
        if ( tree->lower_than(key, aux->pair->key) == 1){
            aux = aux->left;

        }else if( tree->lower_than(aux->pair->key, key) == 1){
            aux = aux->right;

        }else{
            tree->current = aux;
            return aux->pair;
        } 
    }
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    TreeNode *new = tree->root;
    TreeNode *aux = tree->root;
    while (new != NULL){
        if (tree->lower_than(key, new->pair->key) == 1){

            if (aux == tree->root){
                aux = new;
            }
            new = new->left;
        }
        else{
            if (tree->lower_than(new->pair->key, key) == 1){
                new = new->right;
                if (aux == tree->root){
                    aux = new;
                }
                if (tree->lower_than(new->pair->key, aux->pair->key) == 1){
                    aux = new;
                }
            }
            else return new->pair;
        }
    }
    new = aux;
    return new->pair;
    
}

Pair * firstTreeMap(TreeMap * tree) {
    TreeNode* first=minimum(tree->root);
    tree->current=first;
    return first->pair;
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {

    /*
    TreeNode* a = tree->current;
    if (a->right != NULL){
        return minimun(a->right);
    }
    TreeNode *b = a->parent; 
    while (b != NULL && a == b->right){
        a = b;
        b = b->parent;
    }
    return b->pair;
    */
   return NULL;
}   
