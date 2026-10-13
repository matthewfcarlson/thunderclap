struct Obj {
    char pad[0x48];
    int value;
    bool Set(int v);
};
bool Obj::Set(int v) {
    value = v;
    return true;
}
