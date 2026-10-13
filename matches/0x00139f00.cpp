struct Obj {
    char pad[0x2c];
    int m2c;
    bool Fn(int x);
};
bool Obj::Fn(int x) {
    m2c = x;
    return true;
}
