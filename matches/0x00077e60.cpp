struct X {
    char pad[32];
    int m;
    bool Set(int v);
};

bool X::Set(int v) {
    m = v;
    return true;
}