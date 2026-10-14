struct Obj_15abf0 {
    char pad[0x2c];
    int m2c;
    bool Set(int x);
};

bool Obj_15abf0::Set(int x) {
    m2c = x;
    return true;
}
