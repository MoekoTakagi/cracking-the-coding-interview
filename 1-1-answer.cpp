#include <string>
#include <iostream>
#include <array>

// constで受け取らないとコピーコストが発生する
// 参照渡しで受け取る
// 配列使わず vector / array
// 範囲for文使う
bool IsUniq(const std::string& c) {
	if (c.size() > 256) {
		return false;
	}

	std::array<char, 256> result;
	for (const auto& x : c) {
		++result[x];
		if (result[x] > 1) {
			std::cout << x << std::endl;
			return false;
		}
	}
	return true;
} 

int main() {
	std::cout << IsUniq("abcssb") << std::endl;
}
