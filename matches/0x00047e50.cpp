struct Target {
    char pad[12];
    int mField;
    bool Set(int value);
};

bool Target::Set(int value) {
    mField = value;
    return true;
}
