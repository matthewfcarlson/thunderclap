struct X {
    char pad[12];
    int m;
    bool Set(int value);
};
bool X::Set(int value) {
    m = value;
    return true;
}