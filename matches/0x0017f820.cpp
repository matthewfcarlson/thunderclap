struct Obj {
    char pad[0x20];
    int m;
    bool Fn(int a);
};
bool Obj::Fn(int a) {
    m = a;
    return true;
}