struct Obj_123a10 {
    char pad[0x1c];
    unsigned char m1c;
    unsigned char Set(unsigned char v);
};
unsigned char Obj_123a10::Set(unsigned char v) {
    m1c = v;
    return 1;
}
