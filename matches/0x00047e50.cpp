struct Target_47e50 {
    char pad[12];
    int mField;
    bool Set(int value);
};

bool Target_47e50::Set(int value) {
    mField = value;
    return true;
}
