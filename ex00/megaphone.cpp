#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j] != '\0'; j++)
			{
				// 使用<cctype>中的 std::toupper 将字符转为大写
				std::cout << static_cast<char>(std::toupper(av[i][j]));
			}
			// 每个arg之间的1个空格
			if (i < ac - 1)
				std::cout << " ";
		}
	}
	// 无论如何，最后都必须以换行符结尾
	std::cout << std::endl;
	return 0;
}
