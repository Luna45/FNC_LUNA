#include "BST.hpp"
template <typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::minimum(BSTNode *t){
  while(t->left!=nullptr){
    t= t->left;
  }
  return t;
}
template <typename datatype>
datatype BST<datatype>::minimo(){
  return (minimum(root)->key);
}
template <typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::maximum(BSTNode *t){
  while(t->right!=nullptr){
    t= t->right;
  }
  return t;
}
template <typename datatype>
datatype BST<datatype>::maximo(){
  return (maximum(root)->key);
}

template <typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::predecessor(BSTNode *t){
  if(t->key != minimo()){
    if(t->left!=nullptr)
      return maximum(t->left);
    else{
      if(t->parent->right == t)
        return t->parent;
      else{
        while(t==t->parent->left)
          t=t->parent;
        return t;
      }
    }
  }
  return nullptr;
}
template <typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::successor(BSTNode *t){
  if(t->key != maximo()){
    if(t->right!=nullptr)
      return minimum(t->left);
    else{
      if(t->parent->left == t)
        return t->parent;
      else{
        while(t==t->parent->right)
          t=t->parent;
        return t;
      }
    }
  }
  return nullptr;
}

template <typename datatype>
BST<datatype>::~BST(){
  clear();
}
template <typename datatype>
void BST<datatype>::insert(BSTNode* &t, datatype x, BSTNode* parent){
  if(t==nullptr){
    t = new BSTNode;
    t -> key = x;
    t -> left = nullptr;
    t -> right = nullptr;
    t -> parent = parent;
  }
  else{
    if(t->key != x){
      if(x<t->key){
        insert(t->left, x, t);
      }
      else{
        insert(t->right, x, t);
      }
    }

  }
  if(t->parent == nullptr) cout << "Parent de " << t->key << " es: nullptr" << endl;
  else cout << "Parent de " << t->key << " es: " << t->parent -> key << endl;
}
template <typename datatype>
void BST<datatype>::insert(datatype x){
  cout << "I'm inserting " << x << endl;
  insert(root,x,nullptr);
}
// template <typename datatype>
// void BST<datatype>::remove(datatype y){
//
// }
template <typename datatype>
typename BST<datatype>::BSTNode* BST<datatype>::findNode(BSTNode *t, datatype k) const{
  if(t==nullptr) return nullptr;
  if(k==t->key) return t;
  if(k < t->key) return findNode(t->left, k);
  else return findNode(t->right, k);
}
template <typename datatype>
bool BST<datatype>::find(datatype k) const{
  if(findNode(root, k)==nullptr)
    return false;
  return true;
}

template <typename datatype>
void BST<datatype>::destroyRecursive(BSTNode *t){
  if(t!=nullptr){
    destroyRecursive(t->left);
    destroyRecursive(t->right);
    delete t;
  }
}
template <typename datatype>
void BST<datatype>::clear(){
  cout << "I'm destroying" << endl;
  destroyRecursive(root);
  root = nullptr;
}
template <typename datatype>
bool BST<datatype>::empty(){
  return root == nullptr;
}
template <typename datatype>
void BST<datatype>::display(BSTNode *t, int count){
  if(t!=nullptr){
    count++;
    display(t->left,count);
    cout << "(" << count-1 << ")" << t->key << " ";
    if(predecessor(t)==nullptr){
      cout << "pre" << " NULL ";
    }
    else
      cout << "pre" << predecessor(t)->key << " ";
    display(t->right,count);
  }

}
template <typename datatype>
void BST<datatype>::display(){
  display(root,0);
}
