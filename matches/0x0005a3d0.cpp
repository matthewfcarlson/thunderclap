struct Obj {
    char pad[0x34];
    char m34;
    char Fn(int value);
};

char Obj::Fn(int value) {
    m34 = (char)value;
    return 1;
}
