struct Obj {
    char pad[0x34];
    int value;
    char Set(int v);
};

char Obj::Set(int v) {
    value = v;
    return 1;
}
