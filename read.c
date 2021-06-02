#include <syscall.h>
#include <unistd.h>
#include <unistdio.h>

int main(void)
{
	char buf[100];
	int n;

	n = read(0, buf, 100);
	printf("%i", n);
	while (n > 0)
	{
		write(1, buf, n);
		n = read(0, buf, 100);
		printf("%i", n);
	}
	return (0);
}
