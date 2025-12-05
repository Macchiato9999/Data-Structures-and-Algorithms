


// -------------------------- 使用模板（对应考试要求） --------------------------




#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
// 二叉树节点模板类
template <class ElemType>
struct BinTreeNode {
    ElemType data;               // 节点存储的数据
    BinTreeNode* leftChild;      // 左孩子指针
    BinTreeNode* rightChild;     // 右孩子指针
    // 构造函数（可选，便于初始化）
    BinTreeNode(const ElemType& val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
};

// 二叉树模板类
template <class ElemType>
class BinaryTree {
public:
    // 构造函数：初始化空树（避免root为野指针）
    BinaryTree() : root(nullptr) {}
    // 设置根节点（用于构建二叉树）
    void SetRoot(BinTreeNode<ElemType>* node) {
        root = node;
    }
    // 对外遍历接口（统一处理空树提示，避免递归中重复打印）
    void PreOrder(void(*visit)(const ElemType&)) const {
        if (root == nullptr) {
            cout << "二叉树为空！" << endl;
            return;
        }
        PreOrderHelp(root, visit);
    }

    void InOrder(void(*visit)(const ElemType&)) const {
        if (root == nullptr) {
            cout << "二叉树为空！" << endl;
            return;
        }
        InOrderHelp(root, visit);
    }

    void PostOrder(void(*visit)(const ElemType&)) const {
        if (root == nullptr) {
            cout << "二叉树为空！" << endl;
            return;
        }
        PostOrderHelp(root, visit);
    }

    void LevelOrder(void(*visit)(const ElemType&)) const {
        if (root == nullptr) {
            cout << "二叉树为空！" << endl;
            return;
        }
        LevelOrderHelp(root, visit);
    }

    // -------------------------- 非递归遍历对外接口 --------------------------
    void PreOrder_2(void(*visit)(const ElemType&)) const {
        if (root == nullptr) {
            cout << "二叉树为空！" << endl;
            return;
        }
        PreOrderHelp_2(root, visit);
    }

    void InOrder_2(void(*visit)(const ElemType&)) const {
        if (root == nullptr) {
            cout << "二叉树为空！" << endl;
            return;
        }
        InOrderHelp_2(root, visit);
    }

    void PostOrder_2(void(*visit)(const ElemType&)) const {
        if (root == nullptr) {
            cout << "二叉树为空！" << endl;
            return;
        }
        PostOrderHelp_2(root, visit);
    }

private:
    BinTreeNode<ElemType>* root; // 二叉树根节点
    // 遍历递归辅助函数（DFS）
    void PreOrderHelp(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const;
    void InOrderHelp(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const;
    void PostOrderHelp(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const;

    // 遍历非递归辅助函数（DFS）
    void PreOrderHelp_2(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const;
    void InOrderHelp_2(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const;
    void PostOrderHelp_2(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const;
    
    // 层序遍历辅助函数（BFS）
    void LevelOrderHelp(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const;

};

//遍历

template<class ElemType>
void BinaryTree<ElemType>::PreOrderHelp(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&))const {
    if (r != nullptr) {
        (*visit)(r->data);
        PreOrderHelp(r->leftChild, visit);
        PreOrderHelp(r->rightChild, visit);
    }
}//前序；递归

template<class ElemType>
void BinaryTree<ElemType>::InOrderHelp(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const {
    if (r != nullptr)
    {
        InOrderHelp(r->leftChild, visit);
        (*visit)(r->data);
        InOrderHelp(r->rightChild, visit);
    }
}//中序：递归

template<class ElemType>
void BinaryTree<ElemType>::PostOrderHelp(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const{
    if (r != nullptr) {
        PostOrderHelp(r->leftChild, visit);
        PostOrderHelp(r->rightChild, visit);
        (*visit)(r->data);
    }
}//后序：递归

template<class ElemType>
void BinaryTree<ElemType>::PreOrderHelp_2(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const {
    stack<BinTreeNode<ElemType>*>stk;
    if (r != nullptr) {
        stk.push(r);
        while (!stk.empty()) {
            BinTreeNode<ElemType>* cur = stk.top();
            stk.pop();
            (*visit)(cur->data);
            if (cur->rightChild != nullptr)stk.push(cur->rightChild);
            if (cur->leftChild != nullptr)stk.push(cur->leftChild);
     }
    }
}//前序：非递归

template<class ElemType>
void BinaryTree<ElemType>::InOrderHelp_2(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const {
    stack<BinTreeNode<ElemType>*>stk;
    if (r != nullptr) {
        BinTreeNode<ElemType>* cur = r;
        while (cur != nullptr || !stk.empty()) {
            while (cur != nullptr) {
                stk.push(cur);
                cur = cur->leftChild;
            }
            cur = stk.top();
            stk.pop();
            (*visit)(cur->data);
            cur = cur->rightChild;
        }
    }
}//中序：非递归

template<class ElemType>
void BinaryTree<ElemType>::PostOrderHelp_2(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const {
    stack<BinTreeNode<ElemType>*>stk_1;
    stack<BinTreeNode<ElemType>*>stk_2;
    if (r != nullptr) {
        stk_1.push(r);
        while (!stk_1.empty()) {
            BinTreeNode<ElemType>* cur = stk_1.top();
            stk_1.pop();
            stk_2.push(cur);
            if (cur->leftChild != nullptr)stk_1.push(cur->leftChild);
            if (cur->rightChild != nullptr)stk_1.push(cur->rightChild);
        }
        while (!stk_2.empty()) {
            BinTreeNode<ElemType>* cur = stk_2.top();
            stk_2.pop();
            (*visit)(cur->data);
        }
    }
}//后序：非递归

template<class ElemType>
void BinaryTree<ElemType>::LevelOrderHelp(BinTreeNode<ElemType>* r, void(*visit)(const ElemType&)) const {
    queue<BinTreeNode<ElemType>*>q;
    BinTreeNode<ElemType>* cur = r;
    if (cur != nullptr) {
        q.push(r);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            (*visit)(cur->data);
            if (cur->leftChild != nullptr)q.push(cur->leftChild);
            if (cur->rightChild != nullptr)q.push(cur->rightChild);
        }
    }
}//层序

// 自定义访问函数：打印节点数据（可替换为其他逻辑，如计数、存储等）
template<class ElemType>
void PrintNode(const ElemType& val) {
    cout << val << " ";
}

// 测试代码
int main() {
    // 构建测试二叉树：
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    BinTreeNode<int>* n1 = new BinTreeNode<int>(1);
    BinTreeNode<int>* n2 = new BinTreeNode<int>(2);
    BinTreeNode<int>* n3 = new BinTreeNode<int>(3);
    BinTreeNode<int>* n4 = new BinTreeNode<int>(4);
    BinTreeNode<int>* n5 = new BinTreeNode<int>(5);

    n1->leftChild = n2;
    n1->rightChild = n3;
    n2->leftChild = n4;
    n2->rightChild = n5;

    // 初始化二叉树并设置根节点
    BinaryTree<int> tree;
    tree.SetRoot(n1);

    // -------------------------- 测试递归遍历 --------------------------
    cout << "===== 递归遍历 =====" << endl;
    cout << "前序遍历：";
    tree.PreOrder(PrintNode<int>);
    cout << endl;

    cout << "中序遍历：";
    tree.InOrder(PrintNode<int>);
    cout << endl;

    cout << "后序遍历：";
    tree.PostOrder(PrintNode<int>);
    cout << endl;

    // -------------------------- 测试非递归遍历 --------------------------
    cout << "\n===== 非递归遍历 =====" << endl;
    cout << "前序遍历：";
    tree.PreOrder_2(PrintNode<int>);
    cout << endl;

    cout << "中序遍历：";
    tree.InOrder_2(PrintNode<int>);
    cout << endl;

    cout << "后序遍历：";
    tree.PostOrder_2(PrintNode<int>);
    cout << endl;


    // -------------------------- 测试层序遍历 --------------------------
    cout << "\n===== 层序遍历 =====" << endl;
    cout << "层序遍历：";
    tree.LevelOrder(PrintNode<int>);
    cout << endl;

    // -------------------------- 测试空树 --------------------------
    BinaryTree<int> emptyTree;
    cout << "\n===== 空树测试 =====" << endl;
    cout << "空树前序（递归）：";
    emptyTree.PreOrder(PrintNode<int>);
    cout << "空树后序（非递归）：";
    emptyTree.PostOrder_2(PrintNode<int>);

    // 释放内存
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}

