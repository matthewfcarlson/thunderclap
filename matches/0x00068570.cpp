struct X {
    char pad[0x14];
    int m14;
    bool Fn(int x);
};

bool X::Fn(int x) {
    m14 = x;
    return true;
}
