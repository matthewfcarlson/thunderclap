struct T {
    int a;
    int b;
    int c;
};
struct S {
    char pad[0x2c];
    int x;
    int y;
    int z;
    bool Set(const T* p);
};
bool S::Set(const T* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
