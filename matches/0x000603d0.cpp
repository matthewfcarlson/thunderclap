struct X_603d0 {
    char pad[0xbc];
    int m;
    bool Set(int);
};

bool X_603d0::Set(int v) {
    m = v;
    return true;
}
