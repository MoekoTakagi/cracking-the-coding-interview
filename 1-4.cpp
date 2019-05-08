#include <string>
#include <iostream>

std::string ReplaceBlank(const std::string& str, int& num) {
	int counter = 0;
	for (const auto s : str) {
		if (counter == num) {
			break;
		}
		if (s == ' ') {
			--num;
		}
		++counter;
	}

	std::string result;
	counter = 0;
	for (const auto s : str) {
		if (counter == num) {
			return result;
		}
		if (s == ' ') {
			result += "%20";
		}else {
			result += s;
			++counter;
		}
	}
	return result;
}

int main() {
	const std::string str = "Mr John Smith     ";
	int num = 13;
	std::cout << ReplaceBlank(str, num) << std::endl;
}