struct S {
    int a, b, c;
};
struct T {
    char pad[16];
    S s;
    bool operator=(const S* p);
};
bool T::operator=(const S* p) {
    s.a = p->a;
    s.b = p->b;
    s.c = p->c;
    return true;
}