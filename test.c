#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main() {
	char	*buf = malloc(BUFSZ);
	char	*mem = memchr(buf, 0, sizeof(buf));
	printf("%p == %p[%s]\n", &buf[sizeof(buf) - 1], mem, mem + 1);
	return 0;
}
