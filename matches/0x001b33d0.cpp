struct Entry {
    int a[4];
    int b[4];
    int c[37];
};
extern Entry gEntries[13];
void __cdecl FUN_001b33d0(int row, int col, int a, int b, int c) {
    if (row >= 0 && row < 13 && col >= 0 && col < 4) {
        gEntries[row].a[col] = a;
        gEntries[row].b[col] = b;
        gEntries[row].c[col] = c;
    }
}