struct Obj {
    char pad[0x18];
    int value;
    char Fn(int x);
};

char Obj::Fn(int x) {
    value = x;
    return 1;
}
