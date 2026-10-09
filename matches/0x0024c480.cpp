extern "C" unsigned char DAT_004cc254[];
extern "C" unsigned char DAT_004cc258[];

int FUN_0024c480(unsigned int *param_1, unsigned int param_2)
{
    unsigned int x = *param_1;
    int index = (int)(x << 28) >> 28;
    unsigned int m = (x >> 4);
    m &= 31;
    unsigned int d = *(unsigned int *)(DAT_004cc254 + index * 24);
    unsigned int s = m * *(unsigned int *)(DAT_004cc258 + index * 24);
    unsigned int q = param_2 / d;
    unsigned int r = param_2 % d;
    return (r * s) / d + q * s;
}
