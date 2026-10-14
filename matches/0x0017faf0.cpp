struct Obj {
    char pad[0x48];
    int mValue;
    bool Set(int value);
};

bool Obj::Set(int value) {
    mValue = value;
    return true;
}
