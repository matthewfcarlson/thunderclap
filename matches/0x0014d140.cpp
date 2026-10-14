struct Obj_14d140 {
    char pad[0x18];
    int value;
    char Fn(int x);
};

char Obj_14d140::Fn(int x) {
    value = x;
    return 1;
}
