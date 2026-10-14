struct Obj_192770 {
    char pad[12];
    int mValue;
    bool Set(int value);
};

bool Obj_192770::Set(int value) {
    mValue = value;
    return true;
}
