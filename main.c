#include "main.h"
int main(void)
{
char *input;

while (1) /*infinite loop to keep the shell running lash */
{
	display_prompt(); /*display the shell prompt lash as defined in main.h*/
	input = read_input(); /*read user input*/

	if (!input) /*Handle CTRL+D (EOF)*/
	{
		write(STDOUT_FILENO, "\n", 1);
		break;
	}
	
	execute_command(input); /*execute the user input*/
	free_input(input); /*Free allocated memory*/

}
	return (0);
}
