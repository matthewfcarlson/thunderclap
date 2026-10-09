typedef unsigned short ushort;
void FUN_002f3ac0(ushort *a, int b, int c, ushort d)
{
    int i = (b - 1) / 2;
    if (c < b) {
        do {
            ushort v = a[i];
            if (v >= d) break;
            a[b] = v;
            b = i;
            i = (b - 1) / 2;
        } while (c < b);
    }
    a[b] = d;
}
