struct Obj {
    char pad[0x20];
    int m20;
    char Set(int x);
};

char Obj::Set(int x) {
    m20 = x;
    return 1;
}