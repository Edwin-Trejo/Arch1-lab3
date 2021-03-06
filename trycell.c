#include <stdio.h>

extern int tracer();    //extern method     Christian Gomez helped me implementing the tracer method

int trycell(int *x, int pos)
{
    int row = pos / 9;
    int col = pos % 9;
    int i, j, used = 0;

    if (pos == 81) return 1;
    if (x[pos]) return trycell(x, pos + 1);
    int t1 = tracer();      //creates t1 and defines it using an extern method
    printf("Entering position:%p\n",&t1);   //prints current position of tracer t1
    
    for (i = 0; i < 9; i++)
        used |= 1 << (x[i * 9 + col] - 1);

    for (j = 0; j < 9; j++)
        used |= 1 << (x[row * 9 + j] - 1);

    row = row / 3 * 3;
    col = col / 3 * 3;
    for (i = row; i < row + 3; i++)
        for (j = col; j < col + 3; j++)
            used |= 1 << (x[i * 9 + j] - 1);

    for (x[pos] = 1; x[pos] <= 9; x[pos]++, used >>= 1)
        if (!(used & 1) && trycell(x, pos + 1)) return 1;

    int t2 = tracer();      //creates t2 and defines it using an extern method
    printf("Leaving position:%p\n",&t2);   //prints current position of tracer t2
    
    x[pos] = 0;
    return 0;
}
