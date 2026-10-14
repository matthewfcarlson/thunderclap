struct O {
    char p[0x10];
    int m;
    bool Set(int x);
};
bool O::Set(int x) {
    m = x;
    return true;
}
