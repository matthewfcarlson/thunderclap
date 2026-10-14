// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000cb7d0 @ 0x000cb7d0
extern float DAT_0040a464;
// equiv-conv: FUN_000cb7d0 ecx edx stack
void FUN_000cb7d0(float *a, float *b, float limit)
{
    volatile float av = *b - *a;
    *(volatile unsigned int *)&av &= 0x7fffffff;
    if (av <= 9.99999975e-06f)
        return;
    double d = *b - *a;
    volatile float nl = -limit;
    if (d >= nl) {
        if (d <= limit)
            *a = (float)(d + *a);
        else
            *a = limit + *a;
    } else {
        if (d > limit)
            *a = limit + *a;
        else
            *a = nl + *a;
    }
}
