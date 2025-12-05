


// -------------------------- 未使用模板 --------------------------




#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//一，二叉树

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	//构造
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};
};//二叉树结点


//1.遍历
//  DFS
//  先序遍历
//  递归
void preorderRecur(TreeNode* root) {
	if (root != nullptr) {
		cout << root->val<<" ";
		preorderRecur(root->left);
		preorderRecur(root->right);
	}
}
//  迭代（用栈原因：栈能暂存 “待处理的右子树”，等左子树处理完后再弹栈处理。）
vector<int>preorderTter(TreeNode* root) {
	vector<int>res;
	if (root == nullptr) return res;
	else {
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty())
		{
			TreeNode* cur = stk.top();
			stk.pop();
			res.push_back(cur->val);
			if (cur->right)stk.push(cur->right);
			if (cur->left)stk.push(cur->left);
		}
		return res;
	}
}

//  中序遍历
//递归
void inorderRecur(TreeNode* root) {
	if (root != nullptr) {
		inorderRecur(root->left);
		cout << root->val<<" ";
		inorderRecur(root->right);
	}
}
//非递归
vector<int>inorderTter(TreeNode* root) {
	vector<int>res;
	if (root == nullptr) return res;
	else {
		stack<TreeNode*> stk;
		TreeNode* cur = root;
		while (cur!=nullptr||!stk.empty())
		{
			while(cur != nullptr) {
				stk.push(cur);
				cur = cur->left;
			}
			cur = stk.top();
			stk.pop();
			res.push_back(cur->val);
			cur = cur->right;
		}
		return res;
	}
}

//  后序遍历
//  递归
void postorderRecur(TreeNode* root) {
	if (root != nullptr) {
		postorderRecur(root->left);
		postorderRecur(root->right);
		cout << root->val<<" ";
	}
}
//非递归
vector<int>postorderTter(TreeNode* root) {
	vector<int>res;
	if (root == nullptr) return res;
	stack<TreeNode*> st1, st2; // 两个栈
	st1.push(root); // 第一步：根结点1入栈1

	// 第一阶段：用栈1生成「根→右→左」的顺序，存入栈2
	while (!st1.empty()) {
		// 1. 弹出栈1顶结点
		TreeNode* curr = st1.top();
		st1.pop();
		// 2. 把弹出的结点存入栈2（先存根，再存右，最后存左）
		st2.push(curr);

		// 3. 栈是“后进先出”，先压左孩子，再压右孩子（保证右孩子先被处理）
		if (curr->left != nullptr) {
			st1.push(curr->left);
		}
		if (curr->right != nullptr) {
			st1.push(curr->right);
		}
	}

	// 第二阶段：弹出栈2，顺序就是「左→右→根」（后序）
	while (!st2.empty()) {
		TreeNode* curr = st2.top();
		st2.pop();
		res.push_back(curr->val);
	}
	return res; 
}

//层序遍历
//双层vector存储

vector<vector<int>> levelOrder2D(TreeNode* root) {
	vector<vector<int>> res;
	if (root == nullptr)return res;
	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty()) {
		int levelSize = q.size(); // 当前层节点数
		vector<int> levelRes;     // 存储当前层结果
		for (int i = 0; i < levelSize; i++) {
			TreeNode* cur = q.front();
			q.pop();
			levelRes.push_back(cur->val);
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
		res.push_back(levelRes);
	}
	return res;
}

int main() {
	// 构建二叉树：
	 //       1
	 //      / \
     //     2   3
	 //    / \
     //   4   5
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

    // 测试前序遍历
    cout << "前序递归遍历：";
    preorderRecur(root); // 输出：12453
    cout << endl;

	cout << "中序递归遍历：";
	inorderRecur(root); // 输出：42513
	cout << endl;

	cout << "后序递归遍历：";
	postorderRecur(root); // 输出：45231
	cout << endl;

	vector<vector<int>> res = levelOrder2D(root);
	// 打印结果：
	cout << "层序递归遍历："<<endl;
	for (auto& level : res) {
		for (int val : level) cout << val << " ";
		cout << endl;
	} // 输出：1 23 45

    return 0;
}