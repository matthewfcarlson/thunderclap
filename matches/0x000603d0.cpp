struct X {
    char pad[0xbc];
    int m;
    bool Set(int);
};

bool X::Set(int v) {
    m = v;
    return true;
}
