struct Obj_237250 {
    char pad[0x14];
    int value;
    bool Set(int v);
};
bool Obj_237250::Set(int v) {
    value = v;
    return true;
}