struct Obj_16fa90 {
    char pad[0x14];
    char m14;
    char Set(char v);
};

char Obj_16fa90::Set(char v) {
    m14 = v;
    return 1;
}
