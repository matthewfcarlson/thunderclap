struct Obj {
    char pad[12];
    int m;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m = x;
    return true;
}
