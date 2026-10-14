struct Obj_68b80 {
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool Obj_68b80::Set(int v) {
    mValue = v;
    return true;
}
