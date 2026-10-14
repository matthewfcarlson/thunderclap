struct Obj {
    char pad[0x10];
    int m;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m = x;
    return true;
}