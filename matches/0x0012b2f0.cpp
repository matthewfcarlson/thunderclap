struct Src {
    int a, b, c;
};
struct Obj {
    char pad[0x20];
    int x, y, z;
    bool operator=(const Src* s);
};
bool Obj::operator=(const Src* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}
