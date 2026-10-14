struct Obj {
    char pad[0x14];
    char m14;
    char Set(char v);
};

char Obj::Set(char v) {
    m14 = v;
    return 1;
}
