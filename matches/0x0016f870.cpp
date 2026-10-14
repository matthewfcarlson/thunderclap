struct X {
    char pad[0x1c];
    int mField;
    bool Set(int value);
};

bool X::Set(int value) {
    mField = value;
    return true;
}
