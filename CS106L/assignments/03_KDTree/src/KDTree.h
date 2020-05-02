/**
 * File: KDTree.h
 * Author: (your name here)
 * ------------------------
 * An interface representing a kd-tree in some number of dimensions. The tree
 * can be constructed from a set of data and then queried for membership and
 * nearest neighbors.
 */

#ifndef KDTREE_INCLUDED
#define KDTREE_INCLUDED

#include "Point.h"
#include "BoundedPQueue.h"
#include <stdexcept>
#include<cmath>
#include<vector>
#include<iostream>
#include<unordered_map>

// "using namespace" in a header file is conventionally frowned upon, but I'm
// including it here so that you may use things like size_t without having to
// type std::size_t every time.
using namespace std;

template <size_t N, typename ElemType>
class KDTree {
public:
    // Constructor: KDTree();
    // Usage: KDTree<3, int> myTree;
    // ----------------------------------------------------
    // Constructs an empty KDTree.
    KDTree();

    // Destructor: ~KDTree()
    // Usage: (implicit)
    // ----------------------------------------------------
    // Cleans up all resources used by the KDTree.
    ~KDTree();
    
    // KDTree(const KDTree& rhs);
    // KDTree& operator=(const KDTree& rhs);
    // Usage: KDTree<3, int> one = two;
    // Usage: one = two;
    // -----------------------------------------------------
    // Deep-copies the contents of another KDTree into this one.
    KDTree(const KDTree& rhs);
    KDTree& operator=(const KDTree& rhs);
    
    // size_t dimension() const;
    // Usage: size_t dim = kd.dimension();
    // ----------------------------------------------------
    // Returns the dimension of the points stored in this KDTree.
    size_t dimension() const;
    
    // size_t size() const;
    // bool empty() const;
    // Usage: if (kd.empty())
    // ----------------------------------------------------
    // Returns the number of elements in the kd-tree and whether the tree is
    // empty.
    size_t size() const;
    bool empty() const;
    
    // bool contains(const Point<N>& pt) const;
    // Usage: if (kd.contains(pt))
    // ----------------------------------------------------
    // Returns whether the specified point is contained in the KDTree.
    bool contains(const Point<N>& pt) const;
    
    // void insert(const Point<N>& pt, const ElemType& value);
    // Usage: kd.insert(v, "This value is associated with v.");
    // ----------------------------------------------------
    // Inserts the point pt into the KDTree, associating it with the specified
    // value. If the element already existed in the tree, the new value will
    // overwrite the existing one.
    void insert(const Point<N>& pt, const ElemType& value);
    
    // ElemType& operator[](const Point<N>& pt);
    // Usage: kd[v] = "Some Value";
    // ----------------------------------------------------
    // Returns a reference to the value associated with point pt in the KDTree.
    // If the point does not exist, then it is added to the KDTree using the
    // default value of ElemType as its key.
    ElemType& operator[](const Point<N>& pt);
    
    // ElemType& at(const Point<N>& pt);
    // const ElemType& at(const Point<N>& pt) const;
    // Usage: cout << kd.at(v) << endl;
    // ----------------------------------------------------
    // Returns a reference to the key associated with the point pt. If the point
    // is not in the tree, this function throws an out_of_range exception.
    ElemType& at(const Point<N>& pt);
    const ElemType& at(const Point<N>& pt) const;
    
    // ElemType kNNValue(const Point<N>& key, size_t k) const
    // Usage: cout << kd.kNNValue(v, 3) << endl;
    // ----------------------------------------------------
    // Given a point v and an integer k, finds the k points in the KDTree
    // nearest to v and returns the most common value associated with those
    // points. In the event of a tie, one of the most frequent value will be
    // chosen.
    ElemType kNNValue(const Point<N>& key, size_t k) const;

private:
    // TODO: Add implementation details here.
    struct Node{
        Point<N> key;
        ElemType value;
        Node* left;
        Node* right;
        Node(Point<N> _key, ElemType _value = ElemType()): key(_key), value(_value),left(NULL),right(NULL){}
    };
    Node* root;
    size_t cur_size;

    Node* findNode(const Point<N>& key) const;
    void DeleteNode(Node* node);
    void kNNSearchHelper(const Node* curr, size_t level, BoundedPQueue<ElemType>& bp, const Point<N>& key, size_t k) const;
    Node* copyTree(Node* rhs);
};

/** KDTree class implementation details */

template <size_t N, typename ElemType>
KDTree<N, ElemType>::KDTree() {
    // TODO: Fill this in.
    root = NULL;
    cur_size = 0;
}

template <size_t N, typename ElemType>
KDTree<N, ElemType>::~KDTree() {
    // TODO: Fill this in.
    DeleteNode(root);
    cur_size = 0;
}

template <size_t N, typename ElemType>
size_t KDTree<N, ElemType>::dimension() const {
    // TODO: Fill this in.
    return N;
}

// TODO: finish the implementation of the rest of the KDTree class
template <size_t N, typename ElemType>
size_t KDTree<N, ElemType>::size() const{
    return cur_size;
}

template <size_t N, typename ElemType>
bool KDTree<N, ElemType>::empty() const{
    if(cur_size == 0) return true;
    else return false;
}

template <size_t N, typename ElemType>
void KDTree<N, ElemType>::insert(const Point<N>& pt, const ElemType& value){
    int layer = 0;
    Node* curNode = root;
    Node* preNode = NULL;
    enum direction{left, right};
    enum direction dir;
    while(1){
        if(!curNode){
            Node* newNode =  new Node(pt,value);
            if(curNode == root) {root = newNode;   cur_size++;}
            else{
                if(dir == left) preNode->left = newNode;
                else preNode->right = newNode;
                cur_size++;
            }
            return;
        }
        else{
            if(pt == curNode->key){curNode->value = value; return;}
            else {
                if(pt[layer] < curNode->key[layer]){
                        //cout<<"left..."<<endl;
                        layer = (layer + 1) % N;
                        preNode = curNode;
                        curNode = curNode->left;
                        dir = left;
                }
                else if(pt[layer] >= curNode->key[layer]){
                        //cout<<"right..."<<endl;
                        layer = (layer + 1) % N;
                        preNode = curNode;
                        curNode = curNode->right;
                        dir = right;
                }
                }
        }
    }

}

template <size_t N, typename ElemType>
bool KDTree<N, ElemType>::contains(const Point<N>& pt) const{
    return findNode(pt) != NULL;
}

template <size_t N, typename ElemType>
ElemType& KDTree<N, ElemType>::operator[](const Point<N>& pt){
    int layer = 0;
    Node* curNode = root;
    Node* preNode = NULL;
    enum direction{left, right};
    enum direction dir;
    while(1){
        if(!curNode){
            Node* newNode =  new Node(pt);
            //newNode->value = pt;
            if(curNode == root) {root = newNode;  cur_size++;}
            else{
                if(dir == left) preNode->left = newNode;
                else preNode->right = newNode;
                cur_size++;
            }
            return newNode->value;
        }
        else{
            if(pt == curNode->key){return curNode->value;}
            else {
                if(pt[layer] < curNode->key[layer]){
                        //cout<<"left..."<<endl;
                        layer = (layer + 1) % N;
                        preNode = curNode;
                        curNode = curNode->left;
                        dir = left;
                }
                else if(pt[layer] >= curNode->key[layer]){
                        //cout<<"right..."<<endl;
                        layer = (layer + 1) % N;
                        preNode = curNode;
                        curNode = curNode->right;
                        dir = right;
                }
                }
        }
    }
}

template <size_t N, typename ElemType>
ElemType& KDTree<N, ElemType>::at(const Point<N>& pt){
    Node* curNode = findNode(pt);
    if(curNode != NULL) return curNode->value;
    else{
        throw out_of_range("The point does not exist.");
    }
}

template <size_t N, typename ElemType>
const ElemType& KDTree<N, ElemType>::at(const Point<N>& pt) const{
    Node* curNode = findNode(pt);
    if(curNode != NULL) return curNode->value;
    else{
        throw out_of_range("The point does not exist.");
    }
}

template<size_t N, typename ElemType>
typename KDTree<N, ElemType>::Node* KDTree<N, ElemType>::findNode(const Point<N>& pt)const{
    int layer = 0;
    Node* curNode = root;
    while(1){
        if(!curNode){
            //cout<<"return NULL"<<endl;
            return curNode;
        }
        else{
            if(pt == curNode->key){return curNode;}
            else {
                if(pt[layer] < curNode->key[layer]){
                        //cout<<"left..."<<endl;
                        layer = (layer + 1) % N;
                        curNode = curNode->left;
                }
                else if(pt[layer] >= curNode->key[layer]){
                        //cout<<"right..."<<endl;
                        layer = (layer + 1) % N;
                        curNode = curNode->right;
                }
                }
        }
    }
}

template<size_t N, typename ElemType>
void KDTree<N, ElemType>::DeleteNode(Node* node){
    if(node == NULL) return;
    if(node->left) DeleteNode(node->left);
    if(node->right) DeleteNode(node->right);
    delete node;
}

template<size_t N, typename ElemType>
ElemType KDTree<N, ElemType>::kNNValue(const Point<N>& key, size_t k) const{
    BoundedPQueue<ElemType> bp(k);
    kNNSearchHelper(root, 0, bp, key, k);
    unordered_map<ElemType, size_t> freq;
    ElemType result;
    size_t freq_max = 0;
    while(!bp.empty()){
         ElemType tmp = bp.dequeueMin();
         if(++freq[tmp] > freq_max) {result = tmp; freq_max =freq[tmp]; }
    }
    return result;
}

template<size_t N, typename ElemType>
void KDTree<N, ElemType>::kNNSearchHelper(const Node* curr, size_t level,  BoundedPQueue<ElemType>& bp, const Point<N>& key, size_t k) const{
    if(curr == NULL) return;
    double priority = Distance(key, curr->key);
    bp.enqueue(curr->value,priority);
    //int level = 0;
    bool is_left = 1;
    if(key[level] < curr->key[level]){
        kNNSearchHelper(curr->left, (level+1)%N, bp, key, k);
    }
    else{
        is_left = 0;
        kNNSearchHelper(curr->right, (level+1)%N, bp, key, k);
    }
    if(bp.size() != bp.maxSize() ||
            fabs(key[level] - curr->key[level]) < bp.worst()){
        if(is_left) kNNSearchHelper(curr->right, (level+1)%N, bp, key, k);
        else kNNSearchHelper(curr->left, (level+1)%N, bp, key, k);
    }

}

//copy constructor
//don't need to delete the node, cause the tree does not exist.
template<size_t N, typename ElemType>
KDTree<N, ElemType>::KDTree(const KDTree& rhs){
    cur_size = rhs.cur_size;
    root = copyTree(rhs.root);
}

//assignment constructor
//防止重复对自身赋值出错
template<size_t N, typename ElemType>
KDTree<N, ElemType>& KDTree<N, ElemType>::operator=(const KDTree& rhs){
    if(this!=&rhs){
        DeleteNode(root);
        cur_size = rhs.cur_size;
        root = copyTree(rhs.root);
    }
    return *this;
}

//对空指针复制会直接出错
//因此要进程深度拷贝，生成新节点，再连接
template<size_t N, typename ElemType>
typename KDTree<N, ElemType>::Node* KDTree<N, ElemType>::copyTree(Node* rhs){
    if(rhs == NULL) return NULL;
    Node* root = new Node(rhs->key, rhs->value);
    root->left = copyTree(rhs->left);
    root->right = copyTree(rhs->right);
    return root;
}

#endif // KDTREE_INCLUDED
