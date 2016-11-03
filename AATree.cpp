//
//  AATree.cpp
//

#include "AATree.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
template <class T>
AATree<T>::AATree()
{
    // TODO: Create sentinel node (i.e. bottomNode)
    // assign the sentinel node to root, lastNode, and deletedNode
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
template <class T>
AATree<T>::~AATree()
{
    // TODO: Remove any nodes
    // don't forget to deallocate bottomNode
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
// TODO: isEmpty() method
template <class T>
bool AATree<T>::isEmpty()
{

}
#endif

/* **************************************************************** */

#if FIND || ALL
// TODO: find() method
template <class T>
bool AATree<T>::find(const T & x)
{

}
#endif

/* **************************************************************** */

#if FINDNODE || ALL
// TODO: findNode() private method - iterative
template <class T>
Node<T> *AATree<T>::findNode(Node<T> *node, const T &x)
{

}
#endif

/* **************************************************************** */

#if FINDMIN || ALL
// TODO: findMin() method
template <class T>
const T& AATree<T>::findMin()
{

}
#endif

/* **************************************************************** */

#if FINDMINNODE || ALL
// TODO: findMinNode() private method
template <class T>
Node<T> *AATree<T>::findMinNode(Node<T> *node)
{

}
#endif

/* **************************************************************** */

#if FINDMAX || ALL
// TODO: findMax() method
template <class T>
const T& AATree<T>::findMax()
{

}
#endif

/* **************************************************************** */

#if FINDMAXNODE || ALL
// TODO: findMaxNode() private method
template <class T>
Node<T> *AATree<T>::findMaxNode(Node<T> *node)
{

}
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
template <class T>
void AATree<T>::insert(const T &x)
{

}
#endif

/* **************************************************************** */

#if INSERTNODE || ALL
// TODO: insertNode() private method
template <class T>
bool AATree<T>::find(const T & x)
{

}
#endif

/* **************************************************************** */

#if REMOVE || ALL
// TODO: remove() method
template <class T>
void AATree<T>::insertNode(Node<T> *&node, const T &x)
{

}
#endif

/* **************************************************************** */

#if REMOVENODE || ALL
// TODO: removeNode() private method
template <class T>
void AATree<T>::removeNode(Node<T> *&node, const T &x)
{

}
#endif

/* **************************************************************** */

#if SKEW || ALL
// TODO: skew() private method
template <class T>
void AATree<T>::skew(Node<T> *&node)
{

}
#endif

/* **************************************************************** */

#if SPLIT || ALL
// TODO: split() private method
template <class T>
void AATree<T>::split(Node<T> *&node)
{

}
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
// TODO: makeEmpty() method
template <class T>
void AATree<T>::makeEmpty()
{

}
#endif

/* **************************************************************** */

#if REMOVEALLNODES || ALL
// TODO: removeAllNodes() private method
template <class T>
void AATree<T>::removeAllNodes(Node<T> *node)
{

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
