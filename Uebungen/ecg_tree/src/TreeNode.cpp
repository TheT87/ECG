//
// Created by Tobi on 29.04.2019.
//

#include "TreeNode.h"
#include <string>
#include <vector>
#include <iostream>



TreeNode::TreeNode() {};

TreeNode::TreeNode(std::string iTextContent, std::string iTagName) :
        textContent(iTextContent),
        tagName(iTagName),
        parent(nullptr)
{}

int TreeNode::countNodesRec(TreeNode *root, int& count)
{
    TreeNode *parent = root;
    TreeNode *child = nullptr;

    for(int it = 0; it < parent->childrenNumber(); it++)
    {
        child = parent->getChild(it);
        count++;
        //std::cout<<child->getTextContent()<<" Number : "<<count<<std::endl;
        if(child->childrenNumber() > 0)
        {
            countNodesRec(child, count);
        }
    }

    return count;
}

void TreeNode::appendChild(TreeNode *child)
{
    child->setParent(this);
    children.push_back(child);
}

void TreeNode::setParent(TreeNode *theParent)
{
    parent = theParent;
}

void TreeNode::popBackChild()
{
    children.pop_back();
}

void TreeNode::removeChild(int pos)
{
    if(children.size() > 0) {
        children.erase(children.begin()+ pos);
    }
    else {
        children.pop_back();
    }
}

bool TreeNode::hasChildren()
{
    if(children.size() > 0)
        return true;
    else
        return false;
}

bool TreeNode::hasParent()
{
    if(parent != nullptr)
        return true;
    else
        return false;
}

TreeNode * TreeNode::getParent()
{
    return parent;
}

TreeNode* TreeNode::getChild(int pos)
{
    if(children.size() < pos)
        return nullptr;
    else
        return children[pos];
}

int TreeNode::childrenNumber()
{
    return children.size();
}

int TreeNode::grandChildrenNum()
{
    int t = 0;

    if(children.size() < 1)
    {
        return 0;
    }

    countNodesRec(this, t);

    return t;
}

std::string TreeNode::getTextContent()
{
    return textContent;
}

std::string TreeNode::getTagName()
{
    return tagName;
}