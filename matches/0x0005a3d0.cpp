struct Obj_5a3d0 {
    char pad[0x34];
    char m34;
    char Fn(int value);
};

char Obj_5a3d0::Fn(int value) {
    m34 = (char)value;
    return 1;
}
