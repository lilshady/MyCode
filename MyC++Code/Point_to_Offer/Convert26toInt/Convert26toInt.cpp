#include <iostream>
#include <string>
#include <cstdlib>

void validate(std::string input)
{
	for (int i = 0 ; i < input.length(); ++i)
	{
		if (input[i] < 'A' || input[i] > 'Z')
			throw std::exception("invalid input");
	}
}

int Convert26toInt(std::string input)
{
	int Base = 'A' - 1;
	validate(input);
	int sum = 0;
	for (int i = 0 ; i < input.length(); ++i)
	{  
		sum *= 26;
		sum += input[i] - Base;
		
	}
	return sum;

}

int main()
{
	try
	{
		std::cout << Convert26toInt("ABC") << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");

}