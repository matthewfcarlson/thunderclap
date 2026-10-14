struct X {
    char pad[0xc];
    int value;
    bool Fn(int a);
};

bool X::Fn(int a) {
    value = a;
    return true;
}
