#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int main()
{
    int size;
    int i, b, c;

    scanf("%d", &size);

    int hight[size], sub = 0;
    int minleft[size], minright[size], mindef[size];

    for (i = 0; i < size; i++)
    {
        scanf("%d", &hight[i]);
    }
    minleft[0] = hight[0];
    for (i = 1; i < size; i++)
    {
        minleft[i] = max(minleft[i - 1], hight[i]);
    }
    minright[size - 1] = hight[size - 1];
    for (i = size - 2; i >= 0; i--)
    {
        minright[i] = max(minright[i + 1], hight[i]);
    }
    for (i = 0; i < size; i++)
    {
        mindef[i] = -max(-minright[i], -minleft[i]);
    }
    for (i = 0; i < size; i++)
    {
        if (mindef[i] > hight[i]) {
            sub++;
        }
    }

    printf("%d\n", sub);

    return 0;
}
