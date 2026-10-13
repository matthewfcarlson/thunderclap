struct Obj {
    char pad[0x28];
    int value;
    char Set(int x);
};
char Obj::Set(int x) {
    value = x;
    return 1;
}
