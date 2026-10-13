struct Obj {
    char pad[0x28];
    int m28;
    char Set(int v);
};

char Obj::Set(int v) {
    m28 = v;
    return 1;
}
