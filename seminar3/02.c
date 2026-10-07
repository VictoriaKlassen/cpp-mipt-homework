#include <stdio.h>

int main()
{
    for (int code = 32; code <= 126; ++code)
    {
        printf("Symbol = %c, Code = %i\n", code, code);
    }

    return 0;
}
