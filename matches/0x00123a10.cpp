struct Obj {
    char pad[0x1c];
    unsigned char m1c;
    unsigned char Set(unsigned char v);
};
unsigned char Obj::Set(unsigned char v) {
    m1c = v;
    return 1;
}
