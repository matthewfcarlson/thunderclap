struct X_17f7c0 {
    char pad[12];
    int value;
    bool Set(int x);
};
bool X_17f7c0::Set(int x) {
    value = x;
    return true;
}
