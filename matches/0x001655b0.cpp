struct X_1655b0 {
    char pad[0x10];
    int m;
    bool Set(int v);
};
bool X_1655b0::Set(int v) {
    m = v;
    return true;
}