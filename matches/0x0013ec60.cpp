struct Obj_13ec60 {
    char pad[0x48];
    int value;
    bool Set(int v);
};
bool Obj_13ec60::Set(int v) {
    value = v;
    return true;
}
