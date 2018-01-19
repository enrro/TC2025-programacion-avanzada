#include <stdio.h>

int main(int argc, char const *argv[])
{
	int nums[] = {3, 2, 4};

	int *data = twoSum(nums, 3, 6);

	printf("First: %d, second: %d\n", data[0], data[1]);

	free(data);
	return 0;
}
