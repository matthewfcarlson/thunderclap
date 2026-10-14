struct Obj {
    char pad[0x5c];
    int mFlag;
    bool SetFlag(int value);
};

bool Obj::SetFlag(int value) {
    mFlag = value;
    return true;
}
