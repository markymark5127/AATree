//
//  AATree.cpp
//

#include <stddef.h>
#include "AATree.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
template <class T>
AATree<T>::AATree()
{
    // TODO: Create sentinel node (i.e. bottomNode)
    // assign the sentinel node to root, lastNode, and deletedNode
    bottomNode = new Node<T>();
    bottomNode->right = bottomNode;
    bottomNode->left = bottomNode;
    bottomNode->data = -1;
    bottomNode->level = 0;
    root = bottomNode;
    lastNode = bottomNode;
    deletedNode = bottomNode;

}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
template <class T>
AATree<T>::~AATree()
{
    // TODO: Remove any nodes
    // don't forget to deallocate bottomNode
    removeAllNodes(root);
    delete bottomNode;
}
#endif

/* **************************************************************** */


template <class T>
Node<T>* rotateWithLeftChild( Node<T> *k2 )
{
    Node<T> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    return k1;
}

/* **************************************************************** */


template <class T>
Node<T>* rotateWithRightChild( Node<T> *k1 )
{
    Node<T> *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    return k2;
}

/* **************************************************************** */


#if ISEMPTY || ALL
// TODO: isEmpty() method
template <class T>
bool AATree<T>::isEmpty()
{
    if(root == bottomNode) { return true; }
    return false;
}
#endif

/* **************************************************************** */

#if FIND || ALL
// TODO: find() method
template <class T>
bool AATree<T>::find(const T & x)
{
    if(findNode(root,x)->data != -1) { return true; }
    return false;

}
#endif

/* **************************************************************** */

#if FINDNODE || ALL
// TODO: findNode() private method - iterative
template <class T>
Node<T> *AATree<T>::findNode(Node<T> *node, const T &x)
{
    while( node != bottomNode and node->data != x)
    {
        if( x < node->data){node = node->left;}
        else {node = node->right;}
    }
    return node;
}
#endif

/* **************************************************************** */

#if FINDMIN || ALL
// TODO: findMin() method
template <class T>
const T& AATree<T>::findMin()
{
    return findMinNode(root)->data;
}
#endif

/* **************************************************************** */

#if FINDMINNODE || ALL
// TODO: findMinNode() private method
template <class T>
Node<T> *AATree<T>::findMinNode(Node<T> *node)
{
    while( node->left != bottomNode){ node = node->left;}
    return node;
}
#endif

/* **************************************************************** */

#if FINDMAX || ALL
// TODO: findMax() method
template <class T>
const T& AATree<T>::findMax()
{
    return findMaxNode(root)->data;
}
#endif

/* **************************************************************** */

#if FINDMAXNODE || ALL
// TODO: findMaxNode() private method
template <class T>
Node<T> *AATree<T>::findMaxNode(Node<T> *node)
{
    while( node->right != bottomNode){node = node->right;}
    return node;
}
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
template <class T>
void AATree<T>::insert(const T &x)
{
    insertNode(root,x);
}
#endif

/* **************************************************************** */

#if INSERTNODE || ALL
// TODO: insertNode() private method
template <class T>
void AATree<T>::insertNode(Node<T> *&t, const T &x)
{
    if(t == bottomNode)
    {
        t = new Node<T>(x, bottomNode, bottomNode,1);
    }
    else
    {
        if(x<t->data)
        {
            insertNode(t->left,x);
        }
        else if(x > t->data)
        {
            insertNode(t->right,x);
        }
        skew(t);
        split(t);
    }

}
#endif

/* **************************************************************** */

#if REMOVE || ALL
// TODO: remove() method
template <class T>
void AATree<T>::remove(const T &x)
{
    removeNode(root , x);
}
#endif

/* **************************************************************** */

#if REMOVENODE || ALL
// TODO: removeNode() private method
template <class T>
void AATree<T>::removeNode(Node<T> *&t, const T &x)
{
    if(t != bottomNode)
    {
        lastNode = t;
        //1 search down tree and set last and deleted
        if(x < t->data)
        {
            removeNode(t->left,x);
        }
        else
        {
            deletedNode = t;
            removeNode(t->right,x);
        }
        //2 at the bottom of the tree remove element if present
        if(t == lastNode && deletedNode != bottomNode && x==deletedNode->data)
        {
            deletedNode->data = t->data;
            deletedNode = bottomNode;
            t=t->right;
            delete lastNode;
        }
        //3 on the way back rebalance
        else if((t->left->level < t->level-1) || (t->right->level < t->level-1))
        {
            t->level=t->level-1;
            if(t->right->level >  t->level)
            {
                t->right->level = t->level;
            }
            skew(t);
            skew(t->right);
            skew(t->right->right);
            split(t);
            split(t->right);
        }
    }
}
#endif

/* **************************************************************** */

#if SKEW || ALL
// TODO: skew() private method
template <class T>
void AATree<T>::skew(Node<T> *&t)
{

    if ( t->left->level == t->level )
        t = rotateWithLeftChild( t );

}
#endif

/* **************************************************************** */

#if SPLIT || ALL
// TODO: split() private method
template <class T>
void AATree<T>::split(Node<T> *&t)
{
    if( t->right->right->level == t->level )
    {
        t = rotateWithRightChild( t );
        t->level++;
    }
}
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
// TODO: makeEmpty() method
template <class T>
void AATree<T>::makeEmpty()
{
    removeAllNodes(root);
    root = bottomNode;
}
#endif

/* **************************************************************** */

#if REMOVEALLNODES || ALL
// TODO: removeAllNodes() private method
template <class T>
void AATree<T>::removeAllNodes(Node<T> *node)
{
    if(!isEmpty())
    {
        if (node->left != bottomNode)
            removeAllNodes(node->left);
        // Process Left Subtree
        if (node->right != bottomNode)
            removeAllNodes(node->right);
        // Process Right Subtree
        remove(node->data);
    }
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
// Print tree
template <class T>
void AATree<T>::printTree(){
    if (root != bottomNode)
    {
        printNodesInOrder(root);
        std::cout << std::endl;
    } else {
        std::cout << "Empty Tree" << std::endl;
        std::cout << std::endl;
    }
}

// Print tree using level order traversal
template <class T>
void AATree<T>::printNodesInOrder(Node<T> * node)
{
    Node<T>* q[100];
    int head = 0;
    int tail = 0;
    q[0] = root;
    tail++;
    
    while (head != tail)
    {
        Node<T> *n = q[head];
        head++;
        std::cout << "Node " << n->data << " at level " << n->level << std::endl;
        if (n->left != bottomNode)
        {
            std::cout << "  " << n->data << " left child: " << n->left->data << std::endl;
            q[tail] = n->left;
            tail++;
        }
        if (n->right != bottomNode)
        {
            std::cout << "  " << n->data << " right child: " << n->right->data << std::endl;
            q[tail] = n->right;
            tail++;
        }
    }
}
#endif

template class AATree<int>;
