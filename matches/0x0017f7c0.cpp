struct X {
    char pad[12];
    int value;
    bool Set(int x);
};
bool X::Set(int x) {
    value = x;
    return true;
}
