#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t ppid = getppid();
	printf("Parent process ID: %u\n", ppid);
	return (0);
}
