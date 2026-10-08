int __stdcall FUN_000f76c0(short *p)
{
    short *q = p;
    if (*q == 0) return 0;
    do { q++; } while (*q != 0);
    if (q == p) return 0;
    q--;
    while (q >= p && (*q == 10 || *q == 13)) {
        *q = 0;
        q--;
    }
    return (int)((char *)q - (char *)p + 2) >> 1;
}