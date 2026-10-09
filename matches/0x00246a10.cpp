struct Inner {
    char pad[0x1c];
    int F1();
    int F2();
};
struct Outer {
    char pad[0x1c];
    Inner* p;
};
bool target(Outer* self, int* out) {
    int x = self->p->F1();
    int y = self->p->F2();
    *out = y - x;
    return true;
}