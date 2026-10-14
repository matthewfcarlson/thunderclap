struct Obj_1a2900 {
    char pad[0x109];
    unsigned char value;
    char Set(unsigned char v);
};

char Obj_1a2900::Set(unsigned char v) {
    value = v;
    return 1;
}
