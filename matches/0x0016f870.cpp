struct X_16f870 {
    char pad[0x1c];
    int mField;
    bool Set(int value);
};

bool X_16f870::Set(int value) {
    mField = value;
    return true;
}
