struct Obj {
    char pad[0x14];
    int value;
    unsigned char Set(int x);
};

unsigned char Obj::Set(int x) {
    value = x;
    return 1;
}
