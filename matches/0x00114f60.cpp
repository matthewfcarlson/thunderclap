struct Obj {
    char pad[0x18];
    int mFlag;
    bool SetFlag(int v);
};
bool Obj::SetFlag(int v) {
    mFlag = v;
    return true;
}
