struct Obj {
    char pad[0x10];
    int mValue;
    unsigned char Set(int v);
};

unsigned char Obj::Set(int v) {
    mValue = v;
    return 1;
}
