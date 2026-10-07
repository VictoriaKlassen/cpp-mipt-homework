#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Error: Wrong number of arguments!\n");
        return 1;
    }

    char left[100], op[100], right[100], extra[100];

    int count = sscanf(argv[1], " %99s %99s %99s %99s",
                       left, op, right, extra);

    if (count != 3)
    {
        printf("Error: Wrong format!\n");
        return 1;
    }

    if (op[1] != '\0' ||
        (op[0] != '+' && op[0] != '-' &&
         op[0] != '*' && op[0] != '/' && op[0] != '%'))
    {
        printf("Error: Invalid operator!\n");
        return 1;
    }

    int a, b;
    char tail;

    if (sscanf(left, "%d%c", &a, &tail) != 1 ||
        sscanf(right, "%d%c", &b, &tail) != 1)
    {
        printf("Error: Operands should be integers!\n");
        return 1;
    }

    if ((op[0] == '/' || op[0] == '%') && b == 0)
    {
        printf("Error: Division by zero!\n");
        return 1;
    }

    switch (op[0])
    {
        case '+':
            printf("%d\n", a + b);
            break;

        case '-':
            printf("%d\n", a - b);
            break;

        case '*':
            printf("%d\n", a * b);
            break;

        case '/':
            printf("%d\n", a / b);
            break;

        case '%':
            printf("%d\n", a % b);
            break;
    }

    return 0;
}
