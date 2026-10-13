struct Obj {
    char pad[12];
    int value;
    unsigned char Set(int x);
};
unsigned char Obj::Set(int x) {
    value = x;
    return 1;
}
