struct X_685b0 {
    char pad[12];
    int m;
    bool Set(int value);
};
bool X_685b0::Set(int value) {
    m = value;
    return true;
}