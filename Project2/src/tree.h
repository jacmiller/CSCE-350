/*
Title: Heapsort, Anagram Checker, BST
Conceived by: Christopher "Jacob" Miller
September 24th, 2018
*/

#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>

template<typename T>
struct BST_Node {
    T val;
    BST_Node *left;
    BST_Node *right;

    BST_Node(T v) : val(v), left(NULL), right(NULL) {}

    void insert(T v) {
        if (v > val) {
            if (right == NULL) right = new BST_Node<T>(v);
            else right->insert(v);
        } else {
            if (left == NULL) left = new BST_Node<T>(v);
            else left->insert(v);
        }
    }

};


template<typename T>
void delete_tree(BST_Node<T> *root) {
    if (root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}


//your work starts here
template<typename T>
int num_nodes(BST_Node<T> *root) {
    /*if (root == NULL)
        return 0;

    int res = 0;
    if (root->left && root->right)
        res++;

    res += (num_nodes(root->left) + num_nodes(root->right));
    return res;*/

    unsigned int count = 1; //+1 for root
    if (root->left != NULL) {
        count += num_nodes(root->left); //Counts left nodes recursively
    }
    if (root->right != NULL) {
        count += num_nodes(root->right); //Counts right nodes recursively
    }
    return count; //Returns count after adding
}
//int array [50];
//int index = 0;

template<typename T>
void storeInOrder(BST_Node<T> *node, std::vector<T> &V) {

    if (node == NULL)
        return;
    //first recursive on left subtree
    storeInOrder(node->left, V);

    V.push_back(node->val);

    //recursive on right subtree
    storeInOrder(node->right, V);


    //store node into integer array
    //array[index++] = node->val;
}


template<typename T>
bool has_duplicate_val(BST_Node<T> *root) {
    std::vector<T> V;
    storeInOrder(root, V);

    int i; //Declaring i to be accessed by 'inner' loop
    for (i = 0; i < V.size(); i++) { //Check each number in array
        for (int j = i + 1; j < V.size(); j++) { //Check rest of the numbers
            if (V[i] == V[j]) { //Return true if a duplicate is found
                return true;

            }

        }
    }
    return false;

}


template<typename T>
bool trees_identical(BST_Node<T> *a, BST_Node<T> *b) {
    //Checking if both trees are empty
    if (a == NULL && b == NULL)
        return 1;
    //If they're both not empty then compare
    if (a != NULL && b != NULL) {
        return //First check data of root nodes are equal
                (a->val == b->val && trees_identical(a->left, b->left) //Check left subtrees recursively
                 && trees_identical(a->right, b->right) //Check right subtrees recursively
                );
    }
    //One empty tree, another not which is false
    return 0;
}


#endif //TREE_H
