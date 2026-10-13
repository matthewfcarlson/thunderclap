struct Obj {
    char pad[0x15];
    char m15;
    char SetByte(unsigned char v);
};

char Obj::SetByte(unsigned char v) {
    m15 = v;
    return 1;
}
