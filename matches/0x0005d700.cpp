struct Obj_5d700 {
    char pad[12];
    int m;
    bool Set(int x);
};
bool Obj_5d700::Set(int x) {
    m = x;
    return true;
}
