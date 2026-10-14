struct Obj_14d100 {
    char pad[0x10];
    int m;
    bool Set(int x);
};

bool Obj_14d100::Set(int x) {
    m = x;
    return true;
}