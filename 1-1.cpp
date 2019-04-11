#include <string>
#include <iostream>

bool IsUniq(std::string c) {
	if (c.size() > 256) {
		return false;
	}
	char result[256] = {};
	for (int i = 0; i < c.size(); ++i) {
		++result[c[i]];
		if (result[c[i]] > 1) {
			std::cout << c[i] << std::endl;
			return false;
		}
	}
	return true;
} 

int main() {
	std::cout << IsUniq("abcssb") << std::endl;
}

