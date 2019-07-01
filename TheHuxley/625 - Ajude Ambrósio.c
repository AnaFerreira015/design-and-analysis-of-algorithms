#include <stdio.h>
#include <stdlib.h>

void update(int tree[], int i, int f, int ie, int dif, int p)
{
    if (i > ie || f < ie)
    {
        return;
    }
    tree[p] += dif;

    if (i != f)
    {
        int middle = (i + f) / 2;
        update(tree, i, middle, ie, dif, p * 2);
        update(tree, middle + 1, f, ie, dif, p * 2 + 1);
    }
}
int get_sum(int elements[], int i, int f, int ie, int fe, int p)
{
    if (i <= ie && f >= fe)
    {
        return elements[p];
    }
    if (ie > f || fe < i)
    {
        return 0;
    }
    int middle = (ie + fe) / 2;

    return get_sum(elements, i, f, ie, middle, p * 2) + get_sum(elements, i, f, middle + 1, fe, p * 2 + 1);
}

int construct_tree(int elements[], int tree[], int i, int f, int p)
{
    if (i == f)
    {
        tree[p] = elements[i] % 2;
        return tree[p];
    }
    tree[p] = construct_tree(elements, tree, i, (i + f) / 2, p * 2) + construct_tree(elements, tree, 1 + (i + f) / 2, f, p * 2 + 1);
    return tree[p];
}

void main()
{
    int size, comands;
    int o, x, y, dif;
    int i, b, c;
    int segment_tree[500000];

    scanf("%d", &size);

    int elements[size + 1];
    for (i = 1; i <= size; i++)
    {
        scanf("%d", &elements[i]);
    }
    construct_tree(elements, segment_tree, 1, size, 1);
    scanf("%d", &comands);

    for (i = 0; i < comands; i++)
    {
        scanf("%d%d%d", &o, &x, &y);
        if (o == 1)
        {
            printf("%d\n", y - x + 1 - get_sum(segment_tree, x, y, 1, size, 1));
        }
        else if (o == 2)
        {
            printf("%d\n", get_sum(segment_tree, x, y, 1, size, 1));
        }
        else
        {
            dif = y % 2 - elements[x] % 2;
            elements[x] = y;
            if (dif)
            {
                update(segment_tree, 1, size, x, dif, 1);
            }
        }
    }
}