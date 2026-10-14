struct Obj_16f070 {
    char pad[0x5c];
    int mFlag;
    bool SetFlag(int value);
};

bool Obj_16f070::SetFlag(int value) {
    mFlag = value;
    return true;
}
