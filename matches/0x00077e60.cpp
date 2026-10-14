struct X_77e60 {
    char pad[32];
    int m;
    bool Set(int v);
};

bool X_77e60::Set(int v) {
    m = v;
    return true;
}