#include <string>
#include <algorithm>
#include <iostream>

bool IsAnagram(std::string& s1, std::string& s2) {
	if (s1.size() != s2.size()) {
		return false;
	}
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	return s1 == s2;
}

int main() {
	std::string a = "abc";
	std::string b = "bcaa";
	std::cout << IsAnagram(a, b) << std::endl;
}