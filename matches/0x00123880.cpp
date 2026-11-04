struct Obj_123880 {
    char pad[0x15];
    char m15;
    char SetUseGroundPoint_00123880(unsigned char v);
};

char Obj_123880::SetUseGroundPoint_00123880(unsigned char v) {
    m15 = v;
    return 1;
}
