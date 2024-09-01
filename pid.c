#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid = getpid();
	printf("Process ID: %u\n", pid);
	return (0);
}
