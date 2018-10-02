#include <iostream>
#include <stdlib.h>

int my_atoi(const char* str)
{
	if (!str) {
		return 0;
	}

	bool postive = true;
	int val = 0;
	int len = strlen(str);
	int start = 0;
	while (str[start] == ' ') {
		start++;
	}

	if (str[start] == '+' || str[start] == '-') {
		postive = str[start] == '+';
		start++;
	}

	for (int i = start; i < len; i++) {
		if (!isdigit(str[i])) {
			return postive? val: 0 - val;
		}
		int gaurd = val * 10;
		// overflow check
		if (gaurd / 10 != val) {
			return postive? INT_MAX: INT_MIN;
		}
		val *= 10;
		// overflow check
		if (val > INT_MAX - (str[i] - '0')) {
			return postive? INT_MAX: INT_MIN;
		}
		val += str[i] - '0';
	}

	return postive? val: 0 - val;
}

int test_my_atoi()
{
	if (my_atoi("") != 0) {
		return -1;
	}

	if (my_atoi(" 1234") != 1234) {
		return -1;
	}

	if (my_atoi("+1234") != 1234) {
		return -1;
	}

	if (my_atoi("  +1234") != 1234) {
		return -1;
	}

	if (my_atoi("-1234 ") != -1234) {
		return -1;
	}

	if (my_atoi("  -1234 ") != -1234) {
		return -1;
	}

	if (my_atoi(" 1234adfr ") != 1234) {
		return -1;
	}

	if (my_atoi(" aa123 ") != 0) {
		return -1;
	}

	if (my_atoi("3147483647") != INT_MAX) {
		return -1;
	}

	if (my_atoi("-3147483648") != INT_MIN) {
		return -1;
	}

	return 0;
}

int main(int argc, const char *argv[])
{
	if (-1 == test_my_atoi()) {
		std::cout << "my_atoi test fail" << std::endl;
		return -1;
	}

	return 0;
}
