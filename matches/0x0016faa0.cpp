struct Obj_16faa0 {
    char pad[0xc];
    int m;
    char Set(int v);
};

char Obj_16faa0::Set(int v) {
    int x = v;
    m = x;
    return 1;
}
