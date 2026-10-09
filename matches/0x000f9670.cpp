class Table { public: int Find(int a, int b); };
int Table::Find(int a, int b) {
    int i = 0;
    do {
        int x = ((int*)this)[i * 4];
        int y = ((int*)this)[i * 4 + 1];
        if (a == x && b == y) return ((int*)this)[i * 4 + 2];
        ++i;
    } while (i < 128);
    return 0;
}