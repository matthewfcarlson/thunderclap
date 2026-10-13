struct O {
    char pad[0x48];
    int m;
    bool Set(int x);
};
bool O::Set(int x) {
    m = x;
    return true;
}
