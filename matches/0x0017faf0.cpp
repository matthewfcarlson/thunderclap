struct Obj_17faf0 {
    char pad[0x48];
    int mValue;
    bool Set(int value);
};

bool Obj_17faf0::Set(int value) {
    mValue = value;
    return true;
}
