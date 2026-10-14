struct T_61d90 {
    int a;
    int b;
    int c;
};
struct S_61d90 {
    char pad[0x2c];
    int x;
    int y;
    int z;
    bool Set(const T_61d90* p);
};
bool S_61d90::Set(const T_61d90* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
