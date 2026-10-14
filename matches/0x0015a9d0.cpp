struct X_15a9d0 {
    char pad[0x30];
    int m30;
    bool Set(int v);
};
bool X_15a9d0::Set(int v) {
    m30 = v;
    return true;
}
