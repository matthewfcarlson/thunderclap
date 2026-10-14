struct O {
    char pad[0x6c];
    int m;
    bool Set(int x);
};
bool O::Set(int x) {
    m = x;
    return true;
}
