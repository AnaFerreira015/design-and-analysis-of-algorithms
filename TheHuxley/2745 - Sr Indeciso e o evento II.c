
#include <stdio.h>
#include <stdlib.h>
// TODO: corrigir código
void modify(int segment_tree[], int p, int value, int n)
{ 
    for (segment_tree[p += n] = value; p > 1; p >>= 1)
        segment_tree[p >> 1] = segment_tree[p] + segment_tree[p ^ 1];
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
    int n, i, q, pos_i, pos_f;
    char req;
    int segment_tree[500000];

    scanf("%d", &n);
    int elements[n + 1];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &elements[i]);
    }
    construct_tree(elements, segment_tree, 1, n, 1);

    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%c%d%d", &req, &pos_i, &pos_f);
        if (req == 'Q')
        {
            int s = get_sum(segment_tree, pos_i, pos_f, 1, n, 1);
            printf("%d\n", s);
        }
        else if (req == 'U')
        {
            modify(segment_tree, pos_f, pos_i, n);
        }
    }
}