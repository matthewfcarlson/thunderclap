struct Obj_133240 {
    char pad[0x18];
    int value;
    bool Set(int x);
};

bool Obj_133240::Set(int x) {
    value = x;
    return true;
}
