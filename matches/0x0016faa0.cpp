struct Obj {
    char pad[0xc];
    int m;
    char Set(int v);
};

char Obj::Set(int v) {
    int x = v;
    m = x;
    return 1;
}
