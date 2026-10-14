struct X_68570 {
    char pad[0x14];
    int m14;
    bool Fn(int x);
};

bool X_68570::Fn(int x) {
    m14 = x;
    return true;
}
