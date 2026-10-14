typedef unsigned short ushort_2f3ac0;
void FUN_002f3ac0(ushort_2f3ac0* a, int b, int c, ushort_2f3ac0 d) {
    int i = (b - 1) / 2;
    if (c < b) {
        do {
            ushort_2f3ac0 v = a[i];
            if (v >= d)
                break;
            a[b] = v;
            b = i;
            i = (b - 1) / 2;
        } while (c < b);
    }
    a[b] = d;
}
