struct Obj {
    char pad[0xc4];
    int value;
    char Set(int x);
};

char Obj::Set(int x) {
    value = x;
    return 1;
}