struct X {
    char pad[0x28];
    int field;
    bool Fn(int a);
};
bool X::Fn(int a) {
    field = a;
    return true;
}
