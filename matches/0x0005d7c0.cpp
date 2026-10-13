class X {
    char pad[12];
    int m;
    bool f(int x);
};
bool X::f(int x) {
    m = x;
    return true;
}
