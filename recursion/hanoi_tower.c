#include <stdio.h>

void solve_hanoi(unsigned int n, char from, char by, char to);

int main(void)
{
    unsigned int input;

    scanf("%u", &input);
    solve_hanoi(input, 'A', 'B', 'C');
    return 0;
}

void solve_hanoi(unsigned int n, char from, char by, char to)
{
    if (n == 1)
    {
        printf("%d : %c -> %c\n", n, from, to);
        return;
    }
    solve_hanoi(n - 1, from, to, by);
    printf("%d : %c -> %c\n", n, from, to);
    solve_hanoi(n - 1, by, from, to);
}