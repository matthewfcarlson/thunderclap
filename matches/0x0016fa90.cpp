struct Obj_16fa90 {
    char pad[0x14];
    char m14;
    char SetClearOnBegin_0016fa90(char v);
};

char Obj_16fa90::SetClearOnBegin_0016fa90(char v) {
    m14 = v;
    return 1;
}
