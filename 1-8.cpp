#include <string>
#include <iostream>

bool IsSubstring(const std::string& s1, const std::string& s2) {
	return true;
}

bool IsRotatedString(const std::string& s1, const std::string& s2) {
	const std::string& s1s1 = s1 + s1;

	int len_s1 = s1.size();
	if (len_s1 != s2.size() && len_s1 > 0) {
		return false;
	}

	if (IsSubstring(s1s1, s2)) {
		return true;
	}

	return false;
}

int main() {
	std::cout << IsRotatedString("waterbottle", "erbottlewat") << std::endl;
}