#include <iostream>

class TreeNode {
public:
	// 複雑な初期化があれば{}の中で行う
	TreeNode() : left(nullptr), right(nullptr) {}

	// デフォルトデストラクタは書かなくても生成される
	// delete this->left; をやる必要があるのは nullptrで初期化していないとき
	// スマートポインタはデストラクタを自動で呼び出してくれる。デストラクタ内でdelete明示的に書かなくてよい。
	~TreeNode() {}

	TreeNode *left;
	TreeNode *right;
};

int CalcHeight(TreeNode* root) {
	// NULLとの比較は0と比較しているのと同義
	// 数字とNULLを比較できないときがあるからnullptrを使う
	if (root == nullptr) {
		return 0;
	}
	// rootを初期化して渡さないと、`でたらめアドレスの値->でたらめのアドレス` の値を参照しているから, segmentation fault.
	int left_height = CalcHeight(root->left);
	if (left_height == -1) {
		return -1;
	}
	int right_height = CalcHeight(root->left);
	if (right_height == -1) {
		return -1;
	}
	if (std::abs(left_height - right_height) > 1) {
		return -1;
	}

	return std::max(left_height, right_height) + 1;
}

bool IsEquilibrium(TreeNode* root) {
	if (CalcHeight(root) == -1) {
		return false;
	}
	return true;
}

int main() {
	// 初期化しないと、初期値がnullの保証がない。
	// ポインタの場合はとくに、初期化しておく。 
	// = new TreeNode()すると新しいオブジェクトができる
	// TreeNode *root = new TreeNode();

	// ローカル変数として宣言・定義している
	TreeNode root;
	root.left = new TreeNode();
	root.left->left = new TreeNode();
	std::cout << IsEquilibrium(&root) << std::endl;
}

// ポインタは メモリ解放を、delete root のように行う
// ローカル変数はスコープを抜けるとデストラクタが呼ばれる（所有権）

