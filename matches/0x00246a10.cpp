struct Inner_246a10 {
    char pad[0x1c];
    int F1();
    int F2();
};
struct Outer_246a10 {
    char pad[0x1c];
    Inner_246a10* p;
};
bool target(Outer_246a10* self, int* out) {
    int x = self->p->F1();
    int y = self->p->F2();
    *out = y - x;
    return true;
}