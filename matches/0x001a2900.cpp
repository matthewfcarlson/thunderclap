struct Obj {
    char pad[0x109];
    unsigned char value;
    char Set(unsigned char v);
};

char Obj::Set(unsigned char v) {
    value = v;
    return 1;
}
