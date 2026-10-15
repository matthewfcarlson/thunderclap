struct Entry {
    int a, b, c, d, e, f;
};
extern Entry gEntries[6];
void FUN_00044c60(int index, int a, int b, int c, int d, int e, int f) {
    if (index >= 0 && index < 6) {
        gEntries[index].a = a;
        gEntries[index].b = b;
        gEntries[index].c = c;
        gEntries[index].d = d;
        gEntries[index].e = e;
        gEntries[index].f = f;
    }
}