//
//  Node.h
//

#ifndef _NODE_H_
#define _NODE_H_

// AATree node
template <class T>
class Node
{
public:
    // Constructor (private, only for friends)
    Node(const T & theData = T(), Node * lch = NULL, Node * rch = NULL, int lev = 0)
    : data(theData), left(lch), right(rch), level(lev) {}
    
    T data;
    Node *left;
    Node *right;
    int level;
};

#endif
