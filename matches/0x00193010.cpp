struct Obj {
    char pad[0x34];
    int m34;
    char Set(int v);
};
char Obj::Set(int v) {
    m34 = v;
    return 1;
}
