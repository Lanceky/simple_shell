#include "main.h"
void display_prompt(void)
{
write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}

