#include <string>
#include <algorithm>
#include <iostream>
#include <array>

bool IsAnagram(std::string& s1, std::string& s2) {
	if (s1.size() != s2.size()) {
		return false;
	}
	std::array<char, 256> c1 = {}; // {}つけないと初期化されない？
	std::array<char, 256> c2 = {};
	for (const auto& x : s1) {
		++c1[x];
	}
	for (const auto& x : s2) {
		++c2[x];
	}

	return c1 == c2;
}

int main() {
	std::string a = "abc"; // 参照渡しにすると、そのままだとエラー
	std::string b = "bca";
	std::cout << IsAnagram(a, b) << std::endl;
}
