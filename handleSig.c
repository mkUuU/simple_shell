#include <unistd.h>
/**
 * sigint_handler - handles the terminate signal
 * @s: signal number
 */
void sigint_handler(int __attribute__((unused)) s)
{
	write(1, "\n($) ", 5);
}
