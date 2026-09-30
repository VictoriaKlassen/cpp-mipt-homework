#include <stdio.h>

enum shape
{
    ROCK,
    PAPER,
    SCISSORS
};

enum result
{
    LOSS,
    DRAW,
    WIN
};

void print_shape(enum shape s)
{
    switch (s)
    {
        case ROCK:
            printf("Rock");
            break;
        case PAPER:
            printf("Paper");
            break;
        case SCISSORS:
            printf("Scissors");
            break;
    }
}

void print_result(enum result r)
{
    switch (r)
    {
        case LOSS:
            printf("Loss");
            break;
        case DRAW:
            printf("Draw");
            break;
        case WIN:
            printf("Win");
            break;
    }
}

enum shape get_strength(enum shape s)
{
    switch (s)
    {
        case ROCK:
            return SCISSORS;
        case PAPER:
            return ROCK;
        case SCISSORS:
            return PAPER;
    }

    return ROCK;
}

enum result get_result(enum shape a, enum shape b)
{
    if (a == b)
        return DRAW;

    if (get_strength(a) == b)
        return WIN;

    return LOSS;
}

int main()
{
    enum shape a = ROCK;
    enum shape b = SCISSORS;

    print_shape(a);
    printf(" vs ");
    print_shape(b);
    printf(": ");
    print_result(get_result(a, b));
    printf("\n");

}
