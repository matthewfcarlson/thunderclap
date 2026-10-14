struct Obj_123880 {
    char pad[0x15];
    char m15;
    char SetByte(unsigned char v);
};

char Obj_123880::SetByte(unsigned char v) {
    m15 = v;
    return 1;
}
