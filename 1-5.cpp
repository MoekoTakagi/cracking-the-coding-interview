#include <string>
#include <iostream>

std::string ZipString(const std::string& str) {
	std::string str_zipped = str[0];
	int counter = 0;
	std::string str_prev;

	for (const auto& s : str) {
		if (str_zipped == s) {
			++counter;
		} else {
			str_zipped += counter;
			str_zipped += s;
			counter = 0;			
		}
		str_prev = s;
	}
	return str_prev.size() < str.size() ? str_prev : str;
}

int main() {
	const std::string str = "aabcccccaaa";
	std::cout << ZipString(str) << std::endl;
}