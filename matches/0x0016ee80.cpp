struct X_16ee80 {
    char pad[0xc];
    int value;
    bool Fn(int a);
};

bool X_16ee80::Fn(int a) {
    value = a;
    return true;
}
