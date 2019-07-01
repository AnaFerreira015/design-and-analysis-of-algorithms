#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int size, decrease, atual;
    int i, b, head, max;
    char num[500000], aux;

    while (scanf("%d%d", &size, &decrease) && size != 0 && decrease != 0)
    {
        max = size - decrease;
        getchar();
        for (i = 0, head = 0; i < size; i++)
        {
            scanf("%c", &aux);
            while (head >= 1 && decrease && num[head - 1] < aux)
            {
                head--;
                decrease--;
            }
            if (head < max)
            {
                num[head] = aux;
                head++;
            }
        }
        num[head] = '\0';
        printf("%s\n", num);
    }

    return 0;
}
