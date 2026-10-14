struct Obj_114f60 {
    char pad[0x18];
    int mFlag;
    bool SetFlag(int v);
};
bool Obj_114f60::SetFlag(int v) {
    mFlag = v;
    return true;
}
