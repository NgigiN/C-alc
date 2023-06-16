#include <stdio.h>
#include <unistd.h> //getline
#include <string.h>
#include <stdlib.h>

int main()
{
	char *input_str = NULL, *input_copy = NULL;
	char *token; // this holds the array of tokens

	char *tokens[100];
	size_t input_length = 0;
	ssize_t getline_result;
	int count = 0;
	float result = 0;

	printf("Welcome to my calculator terminal\n");
	printf("Enter your simple problem below\n");

	while (1)
	{
		printf("C-alc :) ");
		getline_result = getline(&input_str, &input_length, stdin);

		if (getline_result == -1)
		{
			printf("Exit...\n");
			return (-1);
		}
		// if you press enter it's okay
		if (input_str[0] == '\n')
		{
			continue;
		}

		input_copy = strdup(input_str);
		token = strtok(input_copy, " \t\n");
		count = 0;

		while (token != NULL)
		{
			tokens[count] = token;
			count++;
			token = strtok(NULL, " \t\n");
		}

		if (count % 2 == 0)
		{
			printf("Invalid input: Missing operator or operand\n");
		}
		else
		{
			float result = atof(tokens[0]); // Convert the first token to a floating-point number

			for (int i = 1; i < count; i += 2)
			{
				float operand = atof(tokens[i + 1]); // Convert the next token to a floating-point number

				switch (tokens[i][0])
				{
				case '+':
					result += operand;
					break;
				case '-':
					result -= operand;
					break;
				case '*':
					result *= operand;
					break;
				case '/':
					result /= operand;
					break;
				}
			}

			printf("Result: %.2f\n", result);
		}
	}
}