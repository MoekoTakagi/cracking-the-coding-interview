#include <iostream>

int InsertBits(int N, int M, int i, int j) {
	int all_ones = ~0;
	int left = all_ones << (j + 1);
	int right = ((1 << i) - 1);
	int mask = left | right;
	int n_cleared = N & mask;
	int m_shifted = M << i;
	return n_cleared | m_shifted;
}

int main() {
	int ans = InsertBits(0x400, 0x13, 2, 6);
	for (int i = 31; i >= 0; --i) {
		std::cout << ((ans >> i) & 0x1);
	}
	std::cout << std::endl;
}