//
// Created by Tobi on 29.04.2019.
//

#ifndef ECG_TREE_TREENODE_H
#define ECG_TREE_TREENODE_H




#include <string>
#include <vector>

class TreeNode
{
private:
    std::string textContent;
    std::string tagName;

    TreeNode *parent;

    std::vector<TreeNode *> children;

    int countNodesRec(TreeNode *root, int& count);

public:
    TreeNode();
    TreeNode(std::string iTextContent, std::string iTagName);

    void appendChild(TreeNode *child);
    void setParent(TreeNode *parent);

    void popBackChild();
    void removeChild(int pos);

    bool hasChildren();
    bool hasParent();

    TreeNode* getParent();
    TreeNode* getChild(int pos);

    int childrenNumber();
    int grandChildrenNum();

    std::string getTextContent();
    std::string getTagName();
};


#endif //ECG_TREE_TREENODE_H
