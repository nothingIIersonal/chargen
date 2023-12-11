#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

const char chartable[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
const size_t chartable_size = 62;

int gen(char *len_c)
{
    srand(time(NULL));

    const int64_t len = atoll(len_c) + 1LL;
    if (len < 2)
    {
        fprintf(stderr, "<len> can't be less than 1\n");
        return -1;
    }

    char *str = (char *)malloc(len * sizeof(*str));
    if (str == NULL)
    {
        fprintf(stderr, "Can't allocate enough memory\n");
        return -1;
    }

    uint64_t i = 0;
    for (i = 0; i < len - 1; ++i)
    {
        str[i] = chartable[rand() % chartable_size];
    }
    str[i] = '\0';

    printf("%s\n", str);

    free(str);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return printf("Usage: %s <len>", argv[0]);
    }

    return gen(argv[1]);
}